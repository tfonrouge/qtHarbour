/*
 * $Id: qthQLabel.wip 126 2011-04-12 15:44:57Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QLabel>


/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QLABEL );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QFRAME );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();
HB_FUNC_EXTERN( QSIZE ); // REQUEST'ed Class
HB_FUNC_EXTERN( QPIXMAP ); // REQUEST'ed Class

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QLABEL )
{ "QLABEL", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QLABEL )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "QFRAME", { HB_FS_PUBLIC }, { HB_FUNCNAME( QFRAME ) }, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "S_REGISTERMETHODS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( S_REGISTERMETHODS )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS_1)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL },
{ "QSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( QSIZE )}, NULL }, // REQUEST'ed Class
{ "QPIXMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( QPIXMAP )}, NULL }  // REQUEST'ed Class
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QLABEL )

HB_FUNC( QLABEL )
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
     * _public_functions_ : QLabel ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
     */
    if( ( hb_pcount() <= 2 ) && qth_Is( 1, "QWidget", QTH_DEFAULT ) && qth_IsIntType( 2, "Qt::WindowFlags", QTH_DEFAULT ) )
    {
        QWidget* parent = hb_param( 1, HB_IT_OBJECT ) ? qth_parPtr<QWidget>( 1 ) : ( QWidget* ) 0;
        qth_itemPushReturn( QtH::QLabel, new QLabel( parent, (Qt::WindowFlags) qth_par_IntType( 2, 0 ) ) );
        return;
    }
    /*
     * _public_functions_ : QLabel ( const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0 )
     */
    if( ( hb_pcount() <= 3 ) && qth_IsString( 1 ) && qth_Is( 2, "QWidget", QTH_DEFAULT ) && qth_IsIntType( 3, "Qt::WindowFlags", QTH_DEFAULT ) )
    {
        QString text =  qth_par_QString( 1 );
        QWidget* parent = hb_param( 2, HB_IT_OBJECT ) ? qth_parPtr<QWidget>( 2 ) : ( QWidget* ) 0;
        qth_itemPushReturn( QtH::QLabel, new QLabel( text, parent, (Qt::WindowFlags) qth_par_IntType( 3, 0 ) ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ALIGNMENT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : Qt::Alignment  alignment () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_label->alignment() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( BUDDY )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : QWidget *  buddy () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemReturn( (PCPP_OBJECT) p_label->buddy(), "QWidget" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( HASSCALEDCONTENTS )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : bool  hasScaledContents () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_label->hasScaledContents() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( HASSELECTEDTEXT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
#if QT_VERSION >= 0x040700
        /*
         * _public_functions_ : bool  hasSelectedText () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_label->hasSelectedText() == true );
            return;
        }
#endif  /* QT_VERSION >= 0x040700 */
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( INDENT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : int  indent () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_label->indent() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( MARGIN )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : int  margin () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_label->margin() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( MOVIE )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : QMovie *  movie () const
         */
        if( hb_pcount() == 0 )
        {
            // ! Don't know how to return type 'QMovie'
            // qth_itemReturn( (PCPP_OBJECT) p_label->movie(), "QMovie" );
            qth_errRT_UNKNOWNOBJ( "QLabel::movie", "Don't know how to return type 'QMovie'" ) ;
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( OPENEXTERNALLINKS )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : bool  openExternalLinks () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_label->openExternalLinks() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( PICTURE )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : const QPicture *  picture () const
         */
        if( hb_pcount() == 0 )
        {
            // ! Don't know how to return type 'QPicture'
            // qth_itemReturn( (PCPP_OBJECT) p_label->picture(), "QPicture" );
            qth_errRT_UNKNOWNOBJ( "QLabel::picture", "Don't know how to return type 'QPicture'" ) ;
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( PIXMAP )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : const QPixmap *  pixmap () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemReturn( (PCPP_OBJECT) p_label->pixmap(), "QPixmap" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SELECTEDTEXT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
#if QT_VERSION >= 0x040700
        /*
         * _public_functions_ : QString  selectedText () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_label->selectedText() );
            return;
        }
#endif  /* QT_VERSION >= 0x040700 */
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SELECTIONSTART )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
#if QT_VERSION >= 0x040700
        /*
         * _public_functions_ : int  selectionStart () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_label->selectionStart() );
            return;
        }
#endif  /* QT_VERSION >= 0x040700 */
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETALIGNMENT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setAlignment ( Qt::Alignment )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Qt::Alignment" ) )
        {
            p_label->setAlignment( (Qt::Alignment)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETBUDDY )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setBuddy ( QWidget * buddy )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QWidget" ) )
        {
            p_label->setBuddy( static_cast<QWidget *>( qth_par_QthObject( 1 ) ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETINDENT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setIndent ( int )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_INTEGER ) )
        {
            p_label->setIndent( hb_parni( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETMARGIN )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setMargin ( int )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_INTEGER ) )
        {
            p_label->setMargin( hb_parni( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETOPENEXTERNALLINKS )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setOpenExternalLinks ( bool open )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_label->setOpenExternalLinks( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETSCALEDCONTENTS )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setScaledContents ( bool )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_label->setScaledContents( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETSELECTION )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
#if QT_VERSION >= 0x040700
        /*
         * _public_functions_ : void  setSelection ( int start, int length )
         */
        if( ( hb_pcount() == 2 ) && qth_Is( 1, HB_IT_INTEGER ) && qth_Is( 2, HB_IT_INTEGER ) )
        {
            p_label->setSelection( hb_parni( 1 ), hb_parni( 2 ) );
            hb_ret();
            return;
        }
#endif  /* QT_VERSION >= 0x040700 */
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETTEXTFORMAT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setTextFormat ( Qt::TextFormat )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Qt::TextFormat" ) )
        {
            p_label->setTextFormat( (Qt::TextFormat)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETTEXTINTERACTIONFLAGS )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setTextInteractionFlags ( Qt::TextInteractionFlags flags )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Qt::TextInteractionFlags" ) )
        {
            p_label->setTextInteractionFlags( (Qt::TextInteractionFlags)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETWORDWRAP )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : void  setWordWrap ( bool on )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_label->setWordWrap( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TEXT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : QString  text () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_label->text() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TEXTFORMAT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : Qt::TextFormat  textFormat () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_label->textFormat() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TEXTINTERACTIONFLAGS )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : Qt::TextInteractionFlags  textInteractionFlags () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_label->textInteractionFlags() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( WORDWRAP )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_functions_ : bool  wordWrap () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_label->wordWrap() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( HEIGHTFORWIDTH )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _reimplemented_public_functions_ : virtual int  heightForWidth ( int w ) const
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_INTEGER ) )
        {
            hb_retni( p_label->heightForWidth( hb_parni( 1 ) ) );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( MINIMUMSIZEHINT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _reimplemented_public_functions_ : virtual QSize  minimumSizeHint () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QSize, new QSize( p_label->minimumSizeHint() ), "QSize" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SIZEHINT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _reimplemented_public_functions_ : virtual QSize  sizeHint () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QSize, new QSize( p_label->sizeHint() ), "QSize" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( CLEAR )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_slots_ : void  clear ()
         */
        if( hb_pcount() == 0 )
        {
            p_label->clear();
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETMOVIE )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_slots_ : void  setMovie ( QMovie * movie )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QMovie" ) )
        {
            p_label->setMovie( static_cast<QMovie *>( qth_par_QthObject( 1 ) ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETNUM )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_slots_ : void  setNum ( int num )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_INTEGER ) )
        {
            p_label->setNum( hb_parni( 1 ) );
            hb_ret();
            return;
        }
        /*
         * _public_slots_ : void  setNum ( double num )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_DOUBLE ) )
        {
            p_label->setNum( hb_parnd( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETPICTURE )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_slots_ : void  setPicture ( const QPicture & picture )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QPicture" ) )
        {
            const QPicture & picture = * static_cast<QPicture *>( qth_par_QthObject( 1 ) );
            p_label->setPicture( picture );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETPIXMAP )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_slots_ : void  setPixmap ( const QPixmap & )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QPixmap" ) )
        {
            const QPixmap & p_QPixmap1 = * static_cast<QPixmap *>( qth_par_QthObject( 1 ) );
            p_label->setPixmap( p_QPixmap1 );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETTEXT )
{
    QLabel* p_label = static_cast<QLabel *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_label )
    {
        /*
         * _public_slots_ : void  setText ( const QString & )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString p_QString1 =  qth_par_QString( 1 );
            p_label->setText( p_QString1 );
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

    hb_clsAdd( uiClass, "NEW"                    , HB_FUNCNAME( NEW                     ) );
    hb_clsAdd( uiClass, "ALIGNMENT"              , HB_FUNCNAME( ALIGNMENT               ) );
    hb_clsAdd( uiClass, "BUDDY"                  , HB_FUNCNAME( BUDDY                   ) );
    hb_clsAdd( uiClass, "HASSCALEDCONTENTS"      , HB_FUNCNAME( HASSCALEDCONTENTS       ) );
    hb_clsAdd( uiClass, "HASSELECTEDTEXT"        , HB_FUNCNAME( HASSELECTEDTEXT         ) );
    hb_clsAdd( uiClass, "INDENT"                 , HB_FUNCNAME( INDENT                  ) );
    hb_clsAdd( uiClass, "MARGIN"                 , HB_FUNCNAME( MARGIN                  ) );
    hb_clsAdd( uiClass, "MOVIE"                  , HB_FUNCNAME( MOVIE                   ) );
    hb_clsAdd( uiClass, "OPENEXTERNALLINKS"      , HB_FUNCNAME( OPENEXTERNALLINKS       ) );
    hb_clsAdd( uiClass, "PICTURE"                , HB_FUNCNAME( PICTURE                 ) );
    hb_clsAdd( uiClass, "PIXMAP"                 , HB_FUNCNAME( PIXMAP                  ) );
    hb_clsAdd( uiClass, "SELECTEDTEXT"           , HB_FUNCNAME( SELECTEDTEXT            ) );
    hb_clsAdd( uiClass, "SELECTIONSTART"         , HB_FUNCNAME( SELECTIONSTART          ) );
    hb_clsAdd( uiClass, "SETALIGNMENT"           , HB_FUNCNAME( SETALIGNMENT            ) );
    hb_clsAdd( uiClass, "SETBUDDY"               , HB_FUNCNAME( SETBUDDY                ) );
    hb_clsAdd( uiClass, "SETINDENT"              , HB_FUNCNAME( SETINDENT               ) );
    hb_clsAdd( uiClass, "SETMARGIN"              , HB_FUNCNAME( SETMARGIN               ) );
    hb_clsAdd( uiClass, "SETOPENEXTERNALLINKS"   , HB_FUNCNAME( SETOPENEXTERNALLINKS    ) );
    hb_clsAdd( uiClass, "SETSCALEDCONTENTS"      , HB_FUNCNAME( SETSCALEDCONTENTS       ) );
    hb_clsAdd( uiClass, "SETSELECTION"           , HB_FUNCNAME( SETSELECTION            ) );
    hb_clsAdd( uiClass, "SETTEXTFORMAT"          , HB_FUNCNAME( SETTEXTFORMAT           ) );
    hb_clsAdd( uiClass, "SETTEXTINTERACTIONFLAGS", HB_FUNCNAME( SETTEXTINTERACTIONFLAGS ) );
    hb_clsAdd( uiClass, "SETWORDWRAP"            , HB_FUNCNAME( SETWORDWRAP             ) );
    hb_clsAdd( uiClass, "TEXT"                   , HB_FUNCNAME( TEXT                    ) );
    hb_clsAdd( uiClass, "TEXTFORMAT"             , HB_FUNCNAME( TEXTFORMAT              ) );
    hb_clsAdd( uiClass, "TEXTINTERACTIONFLAGS"   , HB_FUNCNAME( TEXTINTERACTIONFLAGS    ) );
    hb_clsAdd( uiClass, "WORDWRAP"               , HB_FUNCNAME( WORDWRAP                ) );
    hb_clsAdd( uiClass, "HEIGHTFORWIDTH"         , HB_FUNCNAME( HEIGHTFORWIDTH          ) );
    hb_clsAdd( uiClass, "MINIMUMSIZEHINT"        , HB_FUNCNAME( MINIMUMSIZEHINT         ) );
    hb_clsAdd( uiClass, "SIZEHINT"               , HB_FUNCNAME( SIZEHINT                ) );
    hb_clsAdd( uiClass, "CLEAR"                  , HB_FUNCNAME( CLEAR                   ) );
    hb_clsAdd( uiClass, "SETMOVIE"               , HB_FUNCNAME( SETMOVIE                ) );
    hb_clsAdd( uiClass, "SETNUM"                 , HB_FUNCNAME( SETNUM                  ) );
    hb_clsAdd( uiClass, "SETPICTURE"             , HB_FUNCNAME( SETPICTURE              ) );
    hb_clsAdd( uiClass, "SETPIXMAP"              , HB_FUNCNAME( SETPIXMAP               ) );
    hb_clsAdd( uiClass, "SETTEXT"                , HB_FUNCNAME( SETTEXT                 ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */