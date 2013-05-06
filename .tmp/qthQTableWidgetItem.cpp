/*
 * $Id: qthQTableWidgetItem.wip 126 2011-04-12 15:44:57Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QTableWidgetItem>

#define ItemType                                QTableWidgetItem::ItemType
#define Type                                    QTableWidgetItem::Type
#define UserType                                QTableWidgetItem::UserType

/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QTABLEWIDGETITEM );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QTHBASE );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();
HB_FUNC_EXTERN( QTABLEWIDGET ); // REQUEST'ed Class
HB_FUNC_EXTERN( QSIZE ); // REQUEST'ed Class
HB_FUNC_EXTERN( QICON ); // REQUEST'ed Class
HB_FUNC_EXTERN( QVARIANT ); // REQUEST'ed Class
HB_FUNC_EXTERN( QBRUSH ); // REQUEST'ed Class

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QTABLEWIDGETITEM )
{ "QTABLEWIDGETITEM", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QTABLEWIDGETITEM )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "QTHBASE", { HB_FS_PUBLIC }, { HB_FUNCNAME( QTHBASE ) }, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "S_REGISTERMETHODS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( S_REGISTERMETHODS )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS_1)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL },
{ "QTABLEWIDGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( QTABLEWIDGET )}, NULL }, // REQUEST'ed Class
{ "QSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( QSIZE )}, NULL }, // REQUEST'ed Class
{ "QICON", {HB_FS_PUBLIC}, {HB_FUNCNAME( QICON )}, NULL }, // REQUEST'ed Class
{ "QVARIANT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QVARIANT )}, NULL }, // REQUEST'ed Class
{ "QBRUSH", {HB_FS_PUBLIC}, {HB_FUNCNAME( QBRUSH )}, NULL }  // REQUEST'ed Class
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QTABLEWIDGETITEM )

HB_FUNC( QTABLEWIDGETITEM )
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
     * _public_functions_ : QTableWidgetItem ( int type = Type )
     */
    if( ( hb_pcount() <= 1 ) && qth_Is( 1, HB_IT_INTEGER, QTH_DEFAULT ) )
    {
        int type = hb_param( 1, HB_IT_INTEGER ) ? hb_parni( 1 ) : Type;
        qth_itemPushReturn( QtH::QTableWidgetItem, new QTableWidgetItem( type ) );
        return;
    }
    /*
     * _public_functions_ : QTableWidgetItem ( const QString & text, int type = Type )
     */
    if( ( hb_pcount() <= 2 ) && qth_IsString( 1 ) && qth_Is( 2, HB_IT_INTEGER, QTH_DEFAULT ) )
    {
        QString text =  qth_par_QString( 1 );
        int type = hb_param( 2, HB_IT_INTEGER ) ? hb_parni( 2 ) : Type;
        qth_itemPushReturn( QtH::QTableWidgetItem, new QTableWidgetItem( text, type ) );
        return;
    }
    /*
     * _public_functions_ : QTableWidgetItem ( const QIcon & icon, const QString & text, int type = Type )
     */
    if( ( hb_pcount() <= 3 ) && qth_IsObject( 1, "QIcon" ) && qth_IsString( 2 ) && qth_Is( 3, HB_IT_INTEGER, QTH_DEFAULT ) )
    {
        const QIcon & icon = * static_cast<QIcon *>( qth_par_QthObject( 1 ) );
        QString text =  qth_par_QString( 2 );
        int type = hb_param( 3, HB_IT_INTEGER ) ? hb_parni( 3 ) : Type;
        qth_itemPushReturn( QtH::QTableWidgetItem, new QTableWidgetItem( icon, text, type ) );
        return;
    }
    /*
     * _public_functions_ : QTableWidgetItem ( const QTableWidgetItem & other )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QTableWidgetItem" ) )
    {
        const QTableWidgetItem & other = * static_cast<QTableWidgetItem *>( qth_par_QthObject( 1 ) );
        qth_itemPushReturn( QtH::QTableWidgetItem, new QTableWidgetItem( other ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( BACKGROUND )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QBrush  background () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QBrush, new QBrush( p_tableWidgetItem->background() ), "QBrush" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( CHECKSTATE )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : Qt::CheckState  checkState () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_tableWidgetItem->checkState() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( CLONE )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : virtual QTableWidgetItem *  clone () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemReturn( (PCPP_OBJECT) p_tableWidgetItem->clone(), "QTableWidgetItem" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( COLUMN )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : int  column () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_tableWidgetItem->column() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( DATA )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : virtual QVariant  data ( int role ) const
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_INTEGER ) )
        {
            qth_itemPushNewReturn( QtH::QVariant, new QVariant( p_tableWidgetItem->data( hb_parni( 1 ) ) ), "QVariant" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( FLAGS )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : Qt::ItemFlags  flags () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_tableWidgetItem->flags() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( FONT )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QFont  font () const
         */
        if( hb_pcount() == 0 )
        {
            // ! Don't know how to return type 'QFont'
            // qth_itemPushNewReturn( QtH::QFont, new QFont( p_tableWidgetItem->font() ), "QFont" );
            qth_errRT_UNKNOWNOBJ( "QTableWidgetItem::font", "Don't know how to return type 'QFont'" ) ;
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( FOREGROUND )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QBrush  foreground () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QBrush, new QBrush( p_tableWidgetItem->foreground() ), "QBrush" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ICON )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QIcon  icon () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QIcon, new QIcon( p_tableWidgetItem->icon() ), "QIcon" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ISSELECTED )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : bool  isSelected () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_tableWidgetItem->isSelected() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( READ )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : virtual void  read ( QDataStream & in )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QDataStream" ) )
        {
            p_tableWidgetItem->read( * static_cast<QDataStream *>( qth_par_QthObject( 1 ) ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ROW )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : int  row () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_tableWidgetItem->row() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETBACKGROUND )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setBackground ( const QBrush & brush )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QBrush" ) )
        {
            const QBrush & brush = * static_cast<QBrush *>( qth_par_QthObject( 1 ) );
            p_tableWidgetItem->setBackground( brush );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETCHECKSTATE )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setCheckState ( Qt::CheckState state )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Qt::CheckState" ) )
        {
            p_tableWidgetItem->setCheckState( (Qt::CheckState)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETDATA )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : virtual void  setData ( int role, const QVariant & value )
         */
        if( ( hb_pcount() == 2 ) && qth_Is( 1, HB_IT_INTEGER ) && qth_IsObject( 2, "QVariant" ) )
        {
            const QVariant & value = * static_cast<QVariant *>( qth_par_QthObject( 2 ) );
            p_tableWidgetItem->setData( hb_parni( 1 ), value );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETFLAGS )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setFlags ( Qt::ItemFlags flags )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Qt::ItemFlags" ) )
        {
            p_tableWidgetItem->setFlags( (Qt::ItemFlags)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETFONT )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setFont ( const QFont & font )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QFont" ) )
        {
            const QFont & font = * static_cast<QFont *>( qth_par_QthObject( 1 ) );
            p_tableWidgetItem->setFont( font );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETFOREGROUND )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setForeground ( const QBrush & brush )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QBrush" ) )
        {
            const QBrush & brush = * static_cast<QBrush *>( qth_par_QthObject( 1 ) );
            p_tableWidgetItem->setForeground( brush );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETICON )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setIcon ( const QIcon & icon )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QIcon" ) )
        {
            const QIcon & icon = * static_cast<QIcon *>( qth_par_QthObject( 1 ) );
            p_tableWidgetItem->setIcon( icon );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETSELECTED )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setSelected ( bool select )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_tableWidgetItem->setSelected( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETSIZEHINT )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setSizeHint ( const QSize & size )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QSize" ) )
        {
            const QSize & size = * static_cast<QSize *>( qth_par_QthObject( 1 ) );
            p_tableWidgetItem->setSizeHint( size );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETSTATUSTIP )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setStatusTip ( const QString & statusTip )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString statusTip =  qth_par_QString( 1 );
            p_tableWidgetItem->setStatusTip( statusTip );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETTEXT )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setText ( const QString & text )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString text =  qth_par_QString( 1 );
            p_tableWidgetItem->setText( text );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETTEXTALIGNMENT )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setTextAlignment ( int alignment )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_INTEGER ) )
        {
            p_tableWidgetItem->setTextAlignment( hb_parni( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETTOOLTIP )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setToolTip ( const QString & toolTip )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString toolTip =  qth_par_QString( 1 );
            p_tableWidgetItem->setToolTip( toolTip );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETWHATSTHIS )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : void  setWhatsThis ( const QString & whatsThis )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString whatsThis =  qth_par_QString( 1 );
            p_tableWidgetItem->setWhatsThis( whatsThis );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SIZEHINT )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QSize  sizeHint () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QSize, new QSize( p_tableWidgetItem->sizeHint() ), "QSize" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( STATUSTIP )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QString  statusTip () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_tableWidgetItem->statusTip() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TABLEWIDGET )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QTableWidget *  tableWidget () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemReturn( (PCPP_OBJECT) p_tableWidgetItem->tableWidget(), "QTableWidget" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TEXT )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QString  text () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_tableWidgetItem->text() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TEXTALIGNMENT )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : int  textAlignment () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_tableWidgetItem->textAlignment() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TOOLTIP )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QString  toolTip () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_tableWidgetItem->toolTip() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TYPE )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : int  type () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_tableWidgetItem->type() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( WHATSTHIS )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : QString  whatsThis () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_tableWidgetItem->whatsThis() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( WRITE )
{
    QTableWidgetItem* p_tableWidgetItem = static_cast<QTableWidgetItem *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_tableWidgetItem )
    {
        /*
         * _public_functions_ : virtual void  write ( QDataStream & out ) const
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QDataStream" ) )
        {
            p_tableWidgetItem->write( * static_cast<QDataStream *>( qth_par_QthObject( 1 ) ) );
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

    hb_clsAdd( uiClass, "NEW"             , HB_FUNCNAME( NEW              ) );
    hb_clsAdd( uiClass, "BACKGROUND"      , HB_FUNCNAME( BACKGROUND       ) );
    hb_clsAdd( uiClass, "CHECKSTATE"      , HB_FUNCNAME( CHECKSTATE       ) );
    hb_clsAdd( uiClass, "CLONE"           , HB_FUNCNAME( CLONE            ) );
    hb_clsAdd( uiClass, "COLUMN"          , HB_FUNCNAME( COLUMN           ) );
    hb_clsAdd( uiClass, "DATA"            , HB_FUNCNAME( DATA             ) );
    hb_clsAdd( uiClass, "FLAGS"           , HB_FUNCNAME( FLAGS            ) );
    hb_clsAdd( uiClass, "FONT"            , HB_FUNCNAME( FONT             ) );
    hb_clsAdd( uiClass, "FOREGROUND"      , HB_FUNCNAME( FOREGROUND       ) );
    hb_clsAdd( uiClass, "ICON"            , HB_FUNCNAME( ICON             ) );
    hb_clsAdd( uiClass, "ISSELECTED"      , HB_FUNCNAME( ISSELECTED       ) );
    hb_clsAdd( uiClass, "READ"            , HB_FUNCNAME( READ             ) );
    hb_clsAdd( uiClass, "ROW"             , HB_FUNCNAME( ROW              ) );
    hb_clsAdd( uiClass, "SETBACKGROUND"   , HB_FUNCNAME( SETBACKGROUND    ) );
    hb_clsAdd( uiClass, "SETCHECKSTATE"   , HB_FUNCNAME( SETCHECKSTATE    ) );
    hb_clsAdd( uiClass, "SETDATA"         , HB_FUNCNAME( SETDATA          ) );
    hb_clsAdd( uiClass, "SETFLAGS"        , HB_FUNCNAME( SETFLAGS         ) );
    hb_clsAdd( uiClass, "SETFONT"         , HB_FUNCNAME( SETFONT          ) );
    hb_clsAdd( uiClass, "SETFOREGROUND"   , HB_FUNCNAME( SETFOREGROUND    ) );
    hb_clsAdd( uiClass, "SETICON"         , HB_FUNCNAME( SETICON          ) );
    hb_clsAdd( uiClass, "SETSELECTED"     , HB_FUNCNAME( SETSELECTED      ) );
    hb_clsAdd( uiClass, "SETSIZEHINT"     , HB_FUNCNAME( SETSIZEHINT      ) );
    hb_clsAdd( uiClass, "SETSTATUSTIP"    , HB_FUNCNAME( SETSTATUSTIP     ) );
    hb_clsAdd( uiClass, "SETTEXT"         , HB_FUNCNAME( SETTEXT          ) );
    hb_clsAdd( uiClass, "SETTEXTALIGNMENT", HB_FUNCNAME( SETTEXTALIGNMENT ) );
    hb_clsAdd( uiClass, "SETTOOLTIP"      , HB_FUNCNAME( SETTOOLTIP       ) );
    hb_clsAdd( uiClass, "SETWHATSTHIS"    , HB_FUNCNAME( SETWHATSTHIS     ) );
    hb_clsAdd( uiClass, "SIZEHINT"        , HB_FUNCNAME( SIZEHINT         ) );
    hb_clsAdd( uiClass, "STATUSTIP"       , HB_FUNCNAME( STATUSTIP        ) );
    hb_clsAdd( uiClass, "TABLEWIDGET"     , HB_FUNCNAME( TABLEWIDGET      ) );
    hb_clsAdd( uiClass, "TEXT"            , HB_FUNCNAME( TEXT             ) );
    hb_clsAdd( uiClass, "TEXTALIGNMENT"   , HB_FUNCNAME( TEXTALIGNMENT    ) );
    hb_clsAdd( uiClass, "TOOLTIP"         , HB_FUNCNAME( TOOLTIP          ) );
    hb_clsAdd( uiClass, "TYPE"            , HB_FUNCNAME( TYPE             ) );
    hb_clsAdd( uiClass, "WHATSTHIS"       , HB_FUNCNAME( WHATSTHIS        ) );
    hb_clsAdd( uiClass, "WRITE"           , HB_FUNCNAME( WRITE            ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */