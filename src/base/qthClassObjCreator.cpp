/*
 * $Id: qthClassObjCreator.cpp 127 2011-04-12 16:07:52Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include "hbxvm.h"

#define symbolTable_QTH_CLASSNAME    0
#define symbolTable___CLSLOCKDEF     1
#define symbolTable_NEW              2
#define symbolTable_HBCLASS          3
#define symbolTable_PARENTCLS        4
#define symbolTable_CREATE           4 + iNumParentCls
#define symbolTable_REGISTER         5 + iNumParentCls
#define symbolTable_HCLASS           6 + iNumParentCls
#define symbolTable___CLSUNLOCKDEF   7 + iNumParentCls
#define symbolTable_INSTANCE         8 + iNumParentCls
#define symbolTable___OBJHASMSG      9 + iNumParentCls
#define symbolTable_INITCLASS       10 + iNumParentCls
#define symbolTable_INITSTATICS     11 + iNumParentCls

/*
 qthClassObjCreator
 Teo. Mexico 2011
 */
void qthClassObjCreator( PHB_SYMB symbols, const int iNumParentCls )
{
    const char* szClsName = qth_symName( symbols + symbolTable_QTH_CLASSNAME );
    HB_BOOL fValue;

    do 
    {
        hb_xvmVFrame( 1, 0 );
        hb_xvmSFrame( symbols + symbolTable_INITSTATICS );
        hb_xvmPushStatic( 1 );
        hb_xvmPushNil();
        if( hb_xvmExactlyEqual() )
            break;
        if( hb_xvmPopLogical( &fValue ) )
            break;
        if( !fValue )
            goto return_metaObjInstance;
        hb_xvmPushFuncSymbol( symbols + symbolTable___CLSLOCKDEF );
        hb_xvmPushStaticByRef( 1 );
        if( hb_xvmFunction( 1 ) )
            break;
        if( hb_xvmPopLogical( &fValue ) )
            break;
        if( !fValue )
            goto return_metaObjInstance;
        
        hb_xvmSeqAlways();
        
        do 
        {
            int i;
            
            hb_xvmPushSymbol( symbols + symbolTable_NEW );
            hb_xvmPushFuncSymbol( symbols + symbolTable_HBCLASS );
            if( hb_xvmFunction( 0 ) )
                break;
            hb_xvmPushStringConst( szClsName, strlen( szClsName ) );
            for( i = 0; i < iNumParentCls; ++i )
            {
                hb_xvmPushSymbol( symbols + symbolTable_PARENTCLS + i );
            }
            hb_xvmArrayGen( iNumParentCls );
            hb_xvmPushSymbol( symbols + symbolTable_QTH_CLASSNAME );
            if( hb_xvmSend( 3 ) )
                break;
            hb_xvmPopLocal( 1 );
            hb_xvmPushSymbol( symbols + symbolTable_CREATE );
            hb_xvmPushLocal( 1 );
            if( hb_xvmSend( 0 ) )
                break;
            hb_stackPop();
            hb_xvmPushFuncSymbol( symbols + symbolTable_REGISTER );
            hb_xvmPushSymbol( symbols + symbolTable_HCLASS );
            hb_xvmPushLocal( 1 );
            if( hb_xvmSend( 0 ) )
                break;
            if( hb_xvmDo( 1 ) )
                break;
        } while( 0 );
        
        if( hb_xvmAlwaysBegin() )
            break;
        do 
        {
            hb_xvmPushFuncSymbol( symbols + symbolTable___CLSUNLOCKDEF );
            hb_xvmPushStaticByRef( 1 );
            hb_xvmPushLocal( 1 );
            if( hb_xvmDo( 2 ) )
                break;
        } while( 0 );
        
        if( hb_xvmAlwaysEnd() )
            break;
        
        hb_xvmPushSymbol( symbols + symbolTable_INSTANCE );
        hb_xvmPushLocal( 1 );
        if( hb_xvmSend( 0 ) )
            break;
        hb_xvmPopLocal( 1 );
        hb_xvmPushFuncSymbol( symbols + symbolTable___OBJHASMSG );
        hb_xvmPushLocal( 1 );
        hb_xvmPushStringConst( "InitClass", 9 );
        if( hb_xvmFunction( 2 ) )
            break;
        if( hb_xvmPopLogical( &fValue ) )
            break;
        if( !fValue )
            goto return_Instance;
        hb_xvmPushSymbol( symbols + symbolTable_INITCLASS );
        hb_xvmPushLocal( 1 );
        hb_xvmPushVParams();
        if( hb_xvmMacroSend( 1 ) )
            break;
        hb_stackPop();
        
    return_Instance: ;
        hb_xvmPushLocal( 1 );
        hb_xvmRetValue();
        break;
        
    return_metaObjInstance: ;
        hb_xvmPushSymbol( symbols + symbolTable_INSTANCE );
        hb_xvmPushStatic( 1 );
        if( hb_xvmSend( 0 ) )
            break;
        hb_xvmRetValue();
    } while( 0 );
}

/*
 qthInitStatics
 Teo. Mexico 2011
 */
void qthInitStatics( PHB_SYMB symbols, const int iNumParentCls )
{
    hb_xvmStatics( symbols + symbolTable_INITSTATICS, 1 );
}
