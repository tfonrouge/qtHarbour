/*
 * $Id: qth_classes.cpp 142 2012-08-06 17:50:54Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

static MAP_PHB_BASEARRAY hashPHB_BASEARRAY;
static MAP_QTHOBJECT hashQTHObject;

/*
 * constructor
 */
QTH_ITEM::QTH_ITEM( PCPP_OBJECT cppObj, PHB_ITEM p, bool refCount )
{
    deleteCppObj = true;
    this->refCount = refCount;

    qoutf("QTH_ITEM: ClassName: %s at %p", hb_clsName(hb_objGetClass(p)), cppObj );

    pSelf = hb_itemNew( NULL );

    if( p )
    {
        if( refCount )
        {
            hb_itemCopy( pSelf, p );
        }
        else
        {
            hb_itemRawCpy( pSelf, p );
            pSelf->type &= ~HB_IT_DEFAULT;
        }
    }
    else
    {
        qth_errRT_PARAM();
    }

    uiClass = hb_objGetClass( p );

    cppObjectPtr = cppObj;
    hbObjectArrayId = (HB_BASEARRAY *) hb_arrayId( p );
    isQObject = qth_ObjIsDerivedFrom( p, "QObject" );
    isQWidget = qth_ObjIsDerivedFrom( p, "QWidget" );
    isRawObject = ! ( isQObject || isQWidget );
    dynObject = NULL;

    hashPHB_BASEARRAY[ (HB_BASEARRAY *) hb_arrayId( p ) ] = this;
    hashQTHObject[ cppObj ] = this;
}

/*
 destructor
 Teo. Mexico 2010
 */
QTH_ITEM::~QTH_ITEM()
{
    hashPHB_BASEARRAY.erase( hashPHB_BASEARRAY.find( hbObjectArrayId ) );
    hashQTHObject.erase( hashQTHObject.find( cppObjectPtr ) );

    /* release codeblocks stored in event list */
    if( evtList.size() > 0 )
    {
        for( vector<PCONN_PARAMS>::iterator it = evtList.begin(); it < evtList.end(); it++ )
        {
            PCONN_PARAMS pConnParams = *it;
            if( pConnParams->pItmActionBlock )
            {
                hb_itemRelease( pConnParams->pItmActionBlock );
                pConnParams->pItmActionBlock = NULL;
            }
            delete pConnParams;
        }
    }

    if( deleteCppObj )
    {
        if( cppObjectPtr )
        {
            qoutf( "~QTH_ITEM: deleting cppObjectPtr, " );
            if( isRawObject )
            {
                qqoutf( "raw object: %s.", hb_clsName( uiClass ) );
                deleteRawObject();
            }
            else
            {
                QObject* obj = (QObject *) cppObjectPtr;
                qqoutf( "QObject: %s.", obj->metaObject()->className() );
                if( obj->parent() == NULL && ( !isQWidget || ( (QWidget *) obj )->parentWidget() == NULL ) )
                {
                    qqoutf(" deleting...");
                    obj->deleteLater();
                }
                else
                {
                    qqoutf(" keeping...");
                }
            }
        }
    }

    if( pSelf )
    {
        qoutf( "~QTH_ITEM: releasing %s HB Object: %s", refCount ? "" : "(fake)", hb_clsName( hb_objGetClass( pSelf ) ) );
        if( ! this->refCount )
        {
            hb_itemInit( pSelf );
        }
        hb_itemRelease( pSelf );
        pSelf = NULL;
    }    
}

/*
 deletetRawObject
 Teo. Mexico 2011
 */
void QTH_ITEM::deleteRawObject()
{
    switch (clsId)
    {
#include "../.tmp/qth_castDeleteObj.inc"
        default:
            qoutf("*** Need to implement deleting of '%s' objects...", hb_clsName(hb_objGetClass(pSelf)));
            qth_errRT_PARAM();
            break;
    }
}

/*
 get_HBObject
 Teo. Mexico 2011
 */
PHB_ITEM QTH_ITEM::get_HBObject()
{
    return pSelf;
}

/*
 hbo_SetRefCount
 Teo. Mexico 2011
 */
void QTH_ITEM::hbo_SetRefCount( const bool refCount )
{
    if( this->refCount != refCount )
    {
        this->refCount = refCount;

        if( refCount )
        {
            hb_gcRefInc( pSelf->item.asArray.value );
        }
        else
        {
            PHB_ITEM pCopy = hb_itemNew( NULL );
            hb_itemRawCpy( pCopy, pSelf );
            pCopy->type &= ~HB_IT_DEFAULT;
            hb_itemRelease( pSelf );
            pSelf = pCopy;
        }
    }
}

/*
 qth_itemPushNewReturn
 Teo. Mexico 2011
 */
void qth_itemPushNewReturn( QtH::clsTypes clsId, PCPP_OBJECT cppObj, const char* szClsName )
{
    PHB_DYNS pDynSym = hb_dynsymFindName( szClsName );
    
    /* as there is not HB object in QTH_ITEM map, then create it */
    if( pDynSym )
    {
        hb_vmPushDynSym( pDynSym );
        hb_vmPushNil();
        hb_vmDo( 0 );
        
        PQTH_ITEM qthItem = new QTH_ITEM( cppObj, hb_stackReturnItem(), false );
        qthItem->clsId = clsId;
    }
    else 
    {
        hb_errRT_BASE_SubstR( EG_NOFUNC, WXH_ERRBASE + 1, NULL, szClsName, HB_ERR_ARGS_BASEPARAMS );                  
    }
}

/*
 qth_itemPushReturn
 Teo. Mexico 2010
 */
PQTH_ITEM qth_itemPushReturn( QtH::clsTypes clsId, PCPP_OBJECT cppObj )
{
    PQTH_ITEM qthItem = NULL;
    PHB_ITEM pSelf = hb_stackSelfItem();

    if( pSelf && ( hashPHB_BASEARRAY.find( (HB_BASEARRAY *) hb_arrayId( pSelf ) ) == hashPHB_BASEARRAY.end() ) )
    {

        qthItem = new QTH_ITEM( cppObj, pSelf, false );
        qthItem->clsId = clsId;

        if( hb_stackReturnItem() != pSelf )
        {
            hb_itemReturn( pSelf );
        }
    }
    else
    {
        hb_errRT_BASE_SubstR( EG_ARG, WXH_ERRBASE + 4, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );                  
    }
    return qthItem;
}

/*
 * End Class qth_ObjParams
 */

/*
 * QTH functions
 */

/*
 qth_itemListDel_CPP
 Teo. Mexico 2010
 */
void qth_itemListDel_CPP( PCPP_OBJECT cppObj, bool bDeleteWxObj )
{
    PQTH_ITEM pQthItem = qth_itemListGet_PQTH_ITEM( cppObj );
    
    if( pQthItem )
    {
        pQthItem->deleteCppObj = bDeleteWxObj;
        delete pQthItem;
    }
}

/*
 qth_itemListGet_HB
 Teo. Mexico 2010
 */
PHB_ITEM qth_itemListGet_HB( PCPP_OBJECT cppObj )
{
    PHB_ITEM pSelf = NULL;
    
    if( cppObj )
    {
        PQTH_ITEM pQthItem = qth_itemListGet_PQTH_ITEM( cppObj );
        
        if( pQthItem )
        {
            pSelf = pQthItem->get_HBObject();
        }
    }
    return pSelf;
}

/*
 qth_itemListGet_PQTH_ITEM
 Teo. Mexico 2010
 */
PQTH_ITEM qth_itemListGet_PQTH_ITEM( PHB_ITEM pSelf )
{
    PQTH_ITEM pQthItem = NULL;
    
    if( pSelf && ( hashPHB_BASEARRAY.find( (HB_BASEARRAY *) hb_arrayId( pSelf ) ) != hashPHB_BASEARRAY.end() ) )
    {
        pQthItem = hashPHB_BASEARRAY[ (HB_BASEARRAY *) hb_arrayId( pSelf ) ];
    }
    
    return pQthItem;
}

/*
 qth_itemListGet_PQTH_ITEM
 Teo. Mexico 2010
 */
PQTH_ITEM qth_itemListGet_PQTH_ITEM( PCPP_OBJECT cppObj )
{
    PQTH_ITEM pQthItem = NULL;
    
    if( cppObj && ( hashQTHObject.find( cppObj ) != hashQTHObject.end() ) )
    {
        pQthItem = hashQTHObject[ cppObj ];
    }
    
    return pQthItem;
}

/*
 qth_itemListGet_CPP
 Teo. Mexico 2010
 */
PCPP_OBJECT qth_itemListGet_CPP( HB_USHORT arrayId, const char* inheritFrom )
{
    PCPP_OBJECT cppObj = NULL;

    if( inheritFrom == NULL || hb_clsIsParent( arrayId, inheritFrom ) )
    {
        if( hashPHB_BASEARRAY.find( (HB_BASEARRAY *) arrayId ) != hashPHB_BASEARRAY.end() )
        {
            cppObj = hashPHB_BASEARRAY[ (HB_BASEARRAY *) arrayId ]->cppObjectPtr;
        }
    }

    return cppObj;
}

/*
 qth_itemListGet_CPP
 Teo. Mexico 2010
 */
PCPP_OBJECT qth_itemListGet_CPP( PHB_ITEM pSelf, const char* inheritFrom )
{
    PCPP_OBJECT cppObj = NULL;

    if( inheritFrom == NULL || qth_ObjIsDerivedFrom( pSelf, inheritFrom ) )
    {
        if( pSelf && ( hashPHB_BASEARRAY.find( (HB_BASEARRAY *) hb_arrayId( pSelf ) ) != hashPHB_BASEARRAY.end() ) )
        {
            cppObj = hashPHB_BASEARRAY[ (HB_BASEARRAY *) hb_arrayId( pSelf ) ]->cppObjectPtr;
        }
    }

    return cppObj;
}

/*
 qth_itemListReleaseAll
 Teo. Mexico 2010
 */
void qth_itemListReleaseAll()
{
    MAP_QTHOBJECT::iterator it;
    
    while( ! hashQTHObject.empty() )
    {
        it = hashQTHObject.begin();
        it.value()->deleteCppObj = false;
        delete it.value();
        //qth_itemListDel_CPP( it->first );
    }
}

/*
 qth_itemReturn
 Teo. Mexico 2010
 */
void qth_itemReturn( CPP_OBJECT *cppObj, const char* szClsName, QTHI_FLAG qthiFlag )
{
    if( cppObj )
    {
        bool keepHBObject;
        bool deleteCppObj;

        switch ( qthiFlag ) 
        {
            case QTHI_TRANSFER:
                keepHBObject = true;
                deleteCppObj = false;
                break;
            case QTHI_TRANSFERBACK:
                keepHBObject = false;
                deleteCppObj = true;
                break;
            default:
                keepHBObject = false;
                deleteCppObj = false;
                break;
        }

        PQTH_ITEM qthItem = qth_itemListGet_PQTH_ITEM( cppObj );
        PHB_ITEM pSelf = NULL;

        if( qthItem == NULL && szClsName )
        {
            PHB_DYNS pDynSym = hb_dynsymFindName( szClsName );
            
            /* as there is not HB object in QTH_ITEM map, then create it */
            if( pDynSym )
            {
                hb_vmPushDynSym( pDynSym );
                hb_vmPushNil();
                hb_vmDo( 0 );
                
                pSelf = hb_stackReturnItem();
            }
            else 
            {
                hb_errRT_BASE_SubstR( EG_NOFUNC, WXH_ERRBASE + 1, NULL, szClsName, HB_ERR_ARGS_BASEPARAMS );                  
            }
        }

        if( qthItem )
        {
            PHB_ITEM pSelf = qthItem->get_HBObject();
            qthItem->deleteCppObj = deleteCppObj;
            
            qthItem->hbo_SetRefCount( keepHBObject );
            
            hb_itemReturn( pSelf );
        }
        else if( pSelf )
        {
            PQTH_ITEM qthItem = new QTH_ITEM( cppObj, pSelf, keepHBObject );

            qthItem->deleteCppObj = deleteCppObj;
        }
        else
        {
            qth_errRT_PARAM();
        }
    }
    else
    {
        hb_ret();
    }
}

/*
 qth_par_arrayInt
 Teo. Mexico 2010
 */
void qth_par_arrayInt( int param, int* arrayInt, const size_t len )
{

    if( HB_ISARRAY( param ) )
    {
        PHB_ITEM pArray = hb_param( param, HB_IT_ARRAY );
        PHB_ITEM pItm;
        HB_ULONG ulLen = min( (size_t) hb_arrayLen( pArray ), len );
        for( HB_ULONG ulI = 1; ulI <= ulLen; ulI++ )
        {
            pItm = hb_arrayGetItemPtr( pArray, ulI );
            if( hb_itemType( pItm ) == HB_IT_NUMERIC )
            {
                arrayInt[ ulI - 1 ] = hb_arrayGetNI( pArray, ulI );
            }
        }
    }

}
