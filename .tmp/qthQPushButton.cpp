/*
 * $Id: qthQPushButton.wip 126 2011-04-12 15:44:57Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QPushButton>

/*
 * Wip: Dump Section INIT
 */

#include <QWidget>
#include <QIcon>
/*
 * Wip: Dump Section END
 */


/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QPUSHBUTTON );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QABSTRACTBUTTON );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();
HB_FUNC_EXTERN( QSIZE ); // REQUEST'ed Class
HB_FUNC_EXTERN( QMENU ); // REQUEST'ed Class

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QPUSHBUTTON )
{ "QPUSHBUTTON", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QPUSHBUTTON )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "QABSTRACTBUTTON", { HB_FS_PUBLIC }, { HB_FUNCNAME( QABSTRACTBUTTON ) }, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "S_REGISTERMETHODS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( S_REGISTERMETHODS )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS_1)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL },
{ "QSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( QSIZE )}, NULL }, // REQUEST'ed Class
{ "QMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( QMENU )}, NULL }  // REQUEST'ed Class
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QPUSHBUTTON )

HB_FUNC( QPUSHBUTTON )
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
     * _public_functions_ : QPushButton ( QWidget * parent = 0 )
     */
    if( ( hb_pcount() <= 1 ) && qth_Is( 1, "QWidget", QTH_DEFAULT ) )
    {
        QWidget* parent = hb_param( 1, HB_IT_OBJECT ) ? qth_parPtr<QWidget>( 1 ) : ( QWidget* ) 0;
        qth_itemPushReturn( QtH::QPushButton, new QPushButton( parent ) );
        return;
    }
    /*
     * _public_functions_ : QPushButton ( const QString & text, QWidget * parent = 0 )
     */
    if( ( hb_pcount() <= 2 ) && qth_IsString( 1 ) && qth_Is( 2, "QWidget", QTH_DEFAULT ) )
    {
        QString text =  qth_par_QString( 1 );
        QWidget* parent = hb_param( 2, HB_IT_OBJECT ) ? qth_parPtr<QWidget>( 2 ) : ( QWidget* ) 0;
        qth_itemPushReturn( QtH::QPushButton, new QPushButton( text, parent ) );
        return;
    }
    /*
     * _public_functions_ : QPushButton ( const QIcon & icon, const QString & text, QWidget * parent = 0 )
     */
    if( ( hb_pcount() <= 3 ) && qth_IsObject( 1, "QIcon" ) && qth_IsString( 2 ) && qth_Is( 3, "QWidget", QTH_DEFAULT ) )
    {
        const QIcon & icon = * static_cast<QIcon *>( qth_par_QthObject( 1 ) );
        QString text =  qth_par_QString( 2 );
        QWidget* parent = hb_param( 3, HB_IT_OBJECT ) ? qth_parPtr<QWidget>( 3 ) : ( QWidget* ) 0;
        qth_itemPushReturn( QtH::QPushButton, new QPushButton( icon, text, parent ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( AUTODEFAULT )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_functions_ : bool  autoDefault () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_pushButton->autoDefault() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ISDEFAULT )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_functions_ : bool  isDefault () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_pushButton->isDefault() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ISFLAT )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_functions_ : bool  isFlat () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_pushButton->isFlat() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( MENU )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_functions_ : QMenu *  menu () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemReturn( (PCPP_OBJECT) p_pushButton->menu(), "QMenu" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETAUTODEFAULT )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_functions_ : void  setAutoDefault ( bool )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_pushButton->setAutoDefault( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETDEFAULT )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_functions_ : void  setDefault ( bool )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_pushButton->setDefault( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETFLAT )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_functions_ : void  setFlat ( bool )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_pushButton->setFlat( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETMENU )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_functions_ : void  setMenu ( QMenu * menu )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QMenu" ) )
        {
            p_pushButton->setMenu( static_cast<QMenu *>( qth_par_QthObject( 1 ) ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( MINIMUMSIZEHINT )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _reimplemented_public_functions_ : virtual QSize  minimumSizeHint () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QSize, new QSize( p_pushButton->minimumSizeHint() ), "QSize" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SIZEHINT )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _reimplemented_public_functions_ : virtual QSize  sizeHint () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QSize, new QSize( p_pushButton->sizeHint() ), "QSize" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SHOWMENU )
{
    QPushButton* p_pushButton = static_cast<QPushButton *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_pushButton )
    {
        /*
         * _public_slots_ : void  showMenu ()
         */
        if( hb_pcount() == 0 )
        {
            p_pushButton->showMenu();
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

    hb_clsAdd( uiClass, "NEW"            , HB_FUNCNAME( NEW             ) );
    hb_clsAdd( uiClass, "AUTODEFAULT"    , HB_FUNCNAME( AUTODEFAULT     ) );
    hb_clsAdd( uiClass, "ISDEFAULT"      , HB_FUNCNAME( ISDEFAULT       ) );
    hb_clsAdd( uiClass, "ISFLAT"         , HB_FUNCNAME( ISFLAT          ) );
    hb_clsAdd( uiClass, "MENU"           , HB_FUNCNAME( MENU            ) );
    hb_clsAdd( uiClass, "SETAUTODEFAULT" , HB_FUNCNAME( SETAUTODEFAULT  ) );
    hb_clsAdd( uiClass, "SETDEFAULT"     , HB_FUNCNAME( SETDEFAULT      ) );
    hb_clsAdd( uiClass, "SETFLAT"        , HB_FUNCNAME( SETFLAT         ) );
    hb_clsAdd( uiClass, "SETMENU"        , HB_FUNCNAME( SETMENU         ) );
    hb_clsAdd( uiClass, "MINIMUMSIZEHINT", HB_FUNCNAME( MINIMUMSIZEHINT ) );
    hb_clsAdd( uiClass, "SIZEHINT"       , HB_FUNCNAME( SIZEHINT        ) );
    hb_clsAdd( uiClass, "SHOWMENU"       , HB_FUNCNAME( SHOWMENU        ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */
