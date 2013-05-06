/*
 * $Id: qtharbour.cpp 149 2012-09-24 15:06:14Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QCoreApplication>

QtHarbour::QtHarbour()
{
}

/*
    qApp : emulates Qt macro qApp
    Teo. Mexico 2011
 */
HB_FUNC( QAPP )
{
    qth_itemReturn( qApp );
}

/*
 *
 */
HB_FUNC( QTH_BASEDESTRUCT )
{
    PHB_ITEM pSelf = hb_param( 1, HB_IT_OBJECT );
    PQTH_ITEM pQthItem = qth_itemListGet_PQTH_ITEM( pSelf );
    
    if( pQthItem )
    {
        delete pQthItem;
    }
}

/*
 * QTHBASE_COBJECTPTR
 * Teo. Mexico 2011
 */
HB_FUNC( QTHBASE_COBJECTPTR )
{
    void* ptr = qth_itemListGet_CPP( hb_stackSelfItem() );
    if( ptr )
    {
        hb_retptr( ptr );
    }
}

/*
 qth_derivedConstructor
 Teo. Mexico 2011
 */
bool qth_derivedConstructor()
{
    const char* szCtorName = "CTOR";

    if( hb_objHasMsg( hb_stackSelfItem(), szCtorName ) )
    {
        PHB_DYNS dynSymName = hb_dynsymGetCase( szCtorName );
        
        if( dynSymName )
        {
            hb_vmPushDynSym( dynSymName );
            hb_vmPush( hb_stackSelfItem() );
            hb_vmDo( 0 );
            return true;
        }
    }
    return false;
}

/*
 qth_errRT_PARAM
 Teo. Mexico 2011
 */
void qth_errRT_PARAM()
{
    hb_errRT_BASE( EG_ARG, 9999, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );    
}

/*
 qth_errRT_UNKNOWNOBJ
 Teo. Mexico 2011
 */
void qth_errRT_UNKNOWNOBJ( const char* szFuncName, const char* szErrorMsg )
{
    hb_errRT_BASE( EG_NOFUNC, 9999, szFuncName, szErrorMsg, HB_ERR_ARGS_SELFPARAMS );
}

/*
 qth_ObjIsDerivedFrom
 Teo. Mexico 2011
 */
bool qth_ObjIsDerivedFrom( PHB_ITEM pSelf, const char* szClsName )
{
    return hb_clsIsParent( hb_objGetClass( pSelf ), szClsName );
}

/*
 * PARAMETERS values
 */

/*
 qth_IsArray
 Teo. Mexico 2010
 */
bool qth_IsArray( const int iParam )
{
    PHB_ITEM pArray = hb_param( iParam, HB_IT_ARRAY );
    return pArray && hb_objGetClass( pArray ) == 0;
}

/*
 qth_IsIntType
 Teo. Mexico 2011
 */
bool qth_IsIntType( const int iParam, const char* szIntType, const uint uiFlags )
{
    bool lResult = false;

    if( ( ( uiFlags & QTH_DEFAULT ) && HB_ISNIL( iParam ) ) || hb_param( iParam, HB_IT_INTEGER ) )
    {
        lResult = true;
    }
    else
    {
        PHB_ITEM pItem = qth_par_ObjDerivedFrom( iParam, "QTHBASE" );

        if( pItem )
        {
            PHB_ITEM pEnumType = hb_objSendMsg( pItem, "E_GetEnumType", 0 );

            if( pEnumType )
            {
                lResult = strcmp( szIntType, hb_itemGetCPtr( pEnumType ) ) == 0;
            }
        }
    }
    return lResult;
}

/*
 qth_IsObject
 Teo. Mexico 2010
 */
bool qth_IsObject( const int iParam, const char* szClsName )
{
    bool lResult;

    if( szClsName )
    {
        lResult = qth_ObjIsDerivedFrom( hb_param( iParam, HB_IT_OBJECT ), szClsName );
    }
    else
    {
        PHB_ITEM pObject = hb_param( iParam, HB_IT_ARRAY );
        lResult = pObject && hb_objGetClass( pObject ) > 0;
    }
    return lResult;
}

/*
 qth_IsString
 Teo. Mexico 2011
 */
bool qth_IsString( const int iParam, const uint uiFlags )
{
    if( ( uiFlags & QTH_DEFAULT ) && HB_ISNIL( iParam ) )
    {
        return true;
    }
    if( hb_param( iParam, HB_IT_STRING ) != NULL )
    {
        return qth_Is( iParam, HB_IT_STRING, uiFlags );
    }
    return qth_Is( iParam, "QString" );
}

/*
 qth_IsVariant
 Teo. Mexico 2011
 */
bool qth_IsVariant( const int iParam )
{
    return hb_param( iParam, HB_IT_ANY );
}

/*
 qth_Is
 Teo. Mexico 2010
 */
bool qth_Is( const int iParam, const char* szClsName, const uint uiFlags )
{
    if( ( uiFlags & QTH_DEFAULT ) && HB_ISNIL( iParam ) )
    {
        return true;
    }

    return qth_Is( iParam, HB_IT_OBJECT, uiFlags ) && qth_IsObject( iParam, szClsName );
}

/*
 qth_Is
 Teo. Mexico 2010
 */
bool qth_Is( const int iParam, const long lhbType, const uint uiFlags )
{
    if( ( uiFlags & QTH_DEFAULT ) && HB_ISNIL( iParam ) )
    {
        return true;
    }
    
    /* when required param byref don't check for type */
    if( ( uiFlags & QTH_BYREF ) && HB_ISBYREF( iParam ) )
    {
        return true;
    }
    
    if( hb_param( iParam, lhbType ) == NULL )
    {
        return false;
    }
    
    if( ( uiFlags & QTH_SINGLECHAR ) && hb_parclen( iParam ) != 1 )
    {
        return false;
    }
    
    return true;
}

/*
 qth_par_IntType
 Teo. Mexico 2011
 */
int qth_par_IntType( const int iParam, int iDefaultValue )
{
    if( hb_param( iParam, HB_IT_INTEGER ) )
    {
        iDefaultValue = hb_parni( iParam );
    }
    else
    {
        PHB_ITEM pItem = qth_par_ObjDerivedFrom( iParam, "QTHBASE" );
        
        if( pItem )
        {
            PHB_ITEM pEnumValue = hb_objSendMsg( pItem, "E_GetEnumValue", 0 );
            
            if( pEnumValue )
            {
                iDefaultValue = hb_itemGetNI( pEnumValue );
            }
        }
    }
    return iDefaultValue;
}

/*
 qth_par_ObjDerivedFrom
 Teo. Mexico 2010
 */
PHB_ITEM qth_par_ObjDerivedFrom( const int iParam, const char* szClsName )
{
    PHB_ITEM pSelf = hb_param( iParam, HB_IT_OBJECT );
    
    if( pSelf && qth_ObjIsDerivedFrom( pSelf, szClsName ) )
    {
        return pSelf;
    }
    return NULL;
}

/*
 qth_par_QString
 Teo. Mexico 2010
 */
QString qth_par_QString( const int iParam )
{
    QString string;
    //string.fromAscii( hb_parc( iParam ), -1 );
    string = hb_parc( iParam );
    return string;
}

/*
 qth_par_SingleChar
 Teo. Mexico 2011
 */
char qth_par_SingleChar( const int iParam )
{
    return hb_parc( iParam )[ 0 ];
}

/*
 qth_par_QthItem
 Teo. Mexico 2010
 */
PQTH_ITEM qth_par_QthItem( const int iParam )
{
    PHB_ITEM pSelf = hb_param( iParam, HB_IT_OBJECT );
    PQTH_ITEM qthItem = NULL;
    
    if( pSelf )
    {
        qthItem = qth_itemListGet_PQTH_ITEM( pSelf );
    }
    return qthItem;
}

/*
 qth_par_QthObject
 Teo. Mexico 2010
 */
PCPP_OBJECT qth_par_QthObject( const int iParam, QTHI_FLAG qthiFlag )
{
    PCPP_OBJECT cppObj = NULL;

    if( hb_param( iParam, HB_IT_OBJECT ) )
    {
        PQTH_ITEM qthItem = qth_par_QthItem( iParam );

        if( qthItem )
        {
            qth_set_param_QthItemFlag( qthItem, qthiFlag );
            cppObj = qthItem->cppObjectPtr;
        }
    }
    return cppObj;
}

/*
 qth_par_QVariant
 Teo. Mexico 2011
 */
QVariant qth_par_QVariant( const int iParam )
{
    PHB_ITEM pItem = hb_param( iParam, HB_IT_ANY );
    PQTH_ITEM pqthItem = qth_itemListGet_PQTH_ITEM( pItem );

    switch( hb_itemType( pItem )  )
    {
        case HB_IT_STRING:
            return QVariant( hb_itemGetCPtr( pItem ) );
            break;
        case HB_IT_INTEGER:
            return QVariant( hb_itemGetNI( pItem ) );
            break;
        case HB_IT_OBJECT:
            if(pqthItem)
            {
                switch (pqthItem->clsId)
                {
                    case QtH::QSize :
                        return QVariant( *(QSize*) pqthItem->cppObjectPtr );
                        break;
                    case QtH::QPoint :
                        return QVariant( *(QPoint*) pqthItem->cppObjectPtr );
                        break;
                    default:
                        break;
                }
            }
            break;

        default:
            qoutf("undefined variant type...");
            qth_errRT_PARAM();
            break;
    }
    return 0;
}

/*
 qth_parConstRef_QStringList
 Teo. Mexico 2010
 */
const QStringList& qth_parConstRef_QStringList( const int iParam )
{
    QStringList* stringList = new QStringList;
    PHB_ITEM pArray = hb_param( iParam, HB_IT_ARRAY );
    
    if( pArray )
    {
        HB_ULONG ulLen = hb_arrayLen( pArray );
        for( HB_ULONG ulI = 1; ulI <= ulLen; ulI++ )
        {
            stringList->append( hb_arrayGetCPtr( pArray, ulI ) );
        }
    }
    return *stringList;
}

/*
 * RETURN values
 */

/*
 qth_ret_QString
 Teo. Mexico 2010
 */
void qth_ret_QString( const QString& string )
{
    hb_retc( string.toAscii() );
}

/*
 qth_ret_SingleChar
 Teo. Mexico 2011
 */
void qth_ret_SingleChar( const char c )
{
    hb_retclen( &c, 1 );
}

/*
 qth_par_WId
 Teo. Mexico 2011
 */
WId qth_par_WId( const int iParam )
{
#if defined( __MAC__ )
    return (WId) hb_parni( iParam );
#elif defined( __UNIX__ )
    return (WId) hb_parnl( iParam );
#else
    return (WId) hb_parptr( iParam );
#endif
}

/*
 qth_ret_WId
 Teo. Mexico 2010
 */
void qth_ret_WId( WId id )
{
#if defined( __MAC__ )
    hb_retni( id );
#elif defined( __UNIX__ )
    hb_retnl( id );
#else
    hb_retptr( id );
#endif
}

/*
 qth_stor_QString
 Teo. Mexico 2011
 */
void qth_stor_QString( const QString& string, const int iParam )
{
    if( HB_ISBYREF( iParam ) )
    {
        if( hb_param( iParam, HB_IT_STRING ) )
        {
            hb_storc( string.toAscii(), iParam );
        }
    }
}

/*
 qth_registerEnumClass
 Teo. Mexico 2011
 */
void qth_registerClassEnum( PHB_ITEM pSelf, const char* szEnumType, const char* szEnumName, const int iEnumValue )
{
    PHB_ITEM pEnumType = hb_itemNew( NULL );
    PHB_ITEM pEnumName = hb_itemNew( NULL );
    PHB_ITEM pEnumValue = hb_itemNew( NULL );
    
    hb_itemPutC( pEnumType, szEnumType );
    hb_itemPutC( pEnumName, szEnumName );
    hb_itemPutNI( pEnumValue, iEnumValue );
    hb_objSendMsg( pSelf, "SetEnum", 3, pEnumType, pEnumName, pEnumValue );
    hb_itemRelease( pEnumValue );
    hb_itemRelease( pEnumName );
    hb_itemRelease( pEnumType );
}

/*
 qth_set_param_QthItemFlag
 Teo. Mexico 2011
 */
void qth_set_param_QthItemFlag( PQTH_ITEM qthItem, QTHI_FLAG qthiFlag )
{
    switch ( qthiFlag ) 
    {
        /* there is not need to keep a (possible) copy of HB object */
        case QTHI_TRANSFER:
            qthItem->hbo_SetRefCount( true );
            qthItem->deleteCppObj = false; /* don't delete the C++ object, it belongs to someoneelse */
            break;
        case QTHI_TRANSFERBACK:
            qthItem->hbo_SetRefCount( false );
            qthItem->deleteCppObj = true; /* C++ object can be safely deleted, belongs to no one */
            break;

        default:
            break;
    }
}

/*
 qth_symName
 Teo. Mexico 2011
 */
const char* qth_symName( PHB_SYMB symbol )
{
    if( symbol )
    {
        return symbol->szName;
    }
    return (char *) 0;
}

/*
 * other functions
 */

/*
 qoutf
 Teo. Mexico 2010
 */
void qoutf( const char* format, ... )
{
    static char text[512];
    static PHB_DYNS s___qout = NULL;
    
    va_list argp;
    
    va_start( argp, format );
    vsprintf( text, format, argp );
    va_end( argp );
    
    if( s___qout == NULL )
    {
        s___qout = hb_dynsymGetCase( "QOUT" );
    }
    hb_vmPushDynSym( s___qout );
    hb_vmPushNil();
    hb_vmPushString( text, strlen( text ) );
    hb_vmDo( 1 );
}

/*
 qqoutf
 Teo. Mexico 2010
 */
void qqoutf( const char* format, ... )
{
    static char text[512];
    static PHB_DYNS s___qout = NULL;
    
    va_list argp;
    
    va_start( argp, format );
    vsprintf( text, format, argp );
    va_end( argp );
    
    if( s___qout == NULL )
    {
        s___qout = hb_dynsymGetCase( "QQOUT" );
    }
    hb_vmPushDynSym( s___qout );
    hb_vmPushNil();
    hb_vmPushString( text, strlen( text ) );
    hb_vmDo( 1 );
}
