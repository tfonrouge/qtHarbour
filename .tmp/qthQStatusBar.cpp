/*
 * $Id: qthQStatusBar.wip 126 2011-04-12 15:44:57Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QStatusBar>


/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QSTATUSBAR );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QWIDGET );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QSTATUSBAR )
{ "QSTATUSBAR", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QSTATUSBAR )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "QWIDGET", { HB_FS_PUBLIC }, { HB_FUNCNAME( QWIDGET ) }, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "S_REGISTERMETHODS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( S_REGISTERMETHODS )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS_1)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QSTATUSBAR )

HB_FUNC( QSTATUSBAR )
{
    qthClassObjCreator( symbols, 1 );
}

HB_FUNC_INITSTATICS()
{
    qthInitStatics( symbols, 1 );
}
/*
 * Wip: Class Creation & Object Instantiation Section END
 */

/*
 * Wip: Method's Declaration Section INIT
 */
HB_FUNC_STATIC( NEW )
{
    /*
     * _public_functions_ : QStatusBar ( QWidget * parent = 0 )
     */
    if( ( hb_pcount() <= 1 ) && qth_Is( 1, "QWidget", QTH_DEFAULT ) )
    {
        QWidget* parent = hb_param( 1, HB_IT_OBJECT ) ? qth_parPtr<QWidget>( 1 ) : ( QWidget* ) 0;
        qth_itemPushReturn( QtH::QStatusBar, new QStatusBar( parent ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ADDPERMANENTWIDGET )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_functions_ : void  addPermanentWidget ( QWidget * widget, int stretch = 0 )
         */
        if( ( hb_pcount() <= 2 ) && qth_IsObject( 1, "QWidget" ) && qth_Is( 2, HB_IT_INTEGER, QTH_DEFAULT ) )
        {
            int stretch = hb_param( 2, HB_IT_INTEGER ) ? hb_parni( 2 ) : 0;
            p_statusBar->addPermanentWidget( static_cast<QWidget *>( qth_par_QthObject( 1 ) ), stretch );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ADDWIDGET )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_functions_ : void  addWidget ( QWidget * widget, int stretch = 0 )
         */
        if( ( hb_pcount() <= 2 ) && qth_IsObject( 1, "QWidget" ) && qth_Is( 2, HB_IT_INTEGER, QTH_DEFAULT ) )
        {
            int stretch = hb_param( 2, HB_IT_INTEGER ) ? hb_parni( 2 ) : 0;
            p_statusBar->addWidget( static_cast<QWidget *>( qth_par_QthObject( 1 ) ), stretch );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( CURRENTMESSAGE )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_functions_ : QString  currentMessage () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_statusBar->currentMessage() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( INSERTPERMANENTWIDGET )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_functions_ : int  insertPermanentWidget ( int index, QWidget * widget, int stretch = 0 )
         */
        if( ( hb_pcount() <= 3 ) && qth_Is( 1, HB_IT_INTEGER ) && qth_IsObject( 2, "QWidget" ) && qth_Is( 3, HB_IT_INTEGER, QTH_DEFAULT ) )
        {
            int stretch = hb_param( 3, HB_IT_INTEGER ) ? hb_parni( 3 ) : 0;
            hb_retni( p_statusBar->insertPermanentWidget( hb_parni( 1 ), static_cast<QWidget *>( qth_par_QthObject( 2 ) ), stretch ) );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( INSERTWIDGET )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_functions_ : int  insertWidget ( int index, QWidget * widget, int stretch = 0 )
         */
        if( ( hb_pcount() <= 3 ) && qth_Is( 1, HB_IT_INTEGER ) && qth_IsObject( 2, "QWidget" ) && qth_Is( 3, HB_IT_INTEGER, QTH_DEFAULT ) )
        {
            int stretch = hb_param( 3, HB_IT_INTEGER ) ? hb_parni( 3 ) : 0;
            hb_retni( p_statusBar->insertWidget( hb_parni( 1 ), static_cast<QWidget *>( qth_par_QthObject( 2 ) ), stretch ) );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ISSIZEGRIPENABLED )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_functions_ : bool  isSizeGripEnabled () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_statusBar->isSizeGripEnabled() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( REMOVEWIDGET )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_functions_ : void  removeWidget ( QWidget * widget )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QWidget" ) )
        {
            p_statusBar->removeWidget( static_cast<QWidget *>( qth_par_QthObject( 1 ) ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETSIZEGRIPENABLED )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_functions_ : void  setSizeGripEnabled ( bool )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_statusBar->setSizeGripEnabled( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( CLEARMESSAGE )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_slots_ : void  clearMessage ()
         */
        if( hb_pcount() == 0 )
        {
            p_statusBar->clearMessage();
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SHOWMESSAGE )
{
    QStatusBar* p_statusBar = static_cast<QStatusBar *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_statusBar )
    {
        /*
         * _public_slots_ : void  showMessage ( const QString & message, int timeout = 0 )
         */
        if( ( hb_pcount() <= 2 ) && qth_IsString( 1 ) && qth_Is( 2, HB_IT_INTEGER, QTH_DEFAULT ) )
        {
            QString message =  qth_par_QString( 1 );
            int timeout = hb_param( 2, HB_IT_INTEGER ) ? hb_parni( 2 ) : 0;
            p_statusBar->showMessage( message, timeout );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

/*
 * Wip: Method's Declaration Section END
 */

/*
 * Wip: Register Harbour Method's Section INIT
 */
HB_FUNC_STATIC( S_REGISTERMETHODS )
{
    HB_USHORT uiClass = hb_itemGetNI( hb_param( 1, HB_IT_NUMERIC ) );

    hb_clsAdd( uiClass, "NEW"                  , HB_FUNCNAME( NEW                   ) );
    hb_clsAdd( uiClass, "ADDPERMANENTWIDGET"   , HB_FUNCNAME( ADDPERMANENTWIDGET    ) );
    hb_clsAdd( uiClass, "ADDWIDGET"            , HB_FUNCNAME( ADDWIDGET             ) );
    hb_clsAdd( uiClass, "CURRENTMESSAGE"       , HB_FUNCNAME( CURRENTMESSAGE        ) );
    hb_clsAdd( uiClass, "INSERTPERMANENTWIDGET", HB_FUNCNAME( INSERTPERMANENTWIDGET ) );
    hb_clsAdd( uiClass, "INSERTWIDGET"         , HB_FUNCNAME( INSERTWIDGET          ) );
    hb_clsAdd( uiClass, "ISSIZEGRIPENABLED"    , HB_FUNCNAME( ISSIZEGRIPENABLED     ) );
    hb_clsAdd( uiClass, "REMOVEWIDGET"         , HB_FUNCNAME( REMOVEWIDGET          ) );
    hb_clsAdd( uiClass, "SETSIZEGRIPENABLED"   , HB_FUNCNAME( SETSIZEGRIPENABLED    ) );
    hb_clsAdd( uiClass, "CLEARMESSAGE"         , HB_FUNCNAME( CLEARMESSAGE          ) );
    hb_clsAdd( uiClass, "SHOWMESSAGE"          , HB_FUNCNAME( SHOWMESSAGE           ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */