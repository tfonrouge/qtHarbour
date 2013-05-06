/*
 * $Id: qthQMessageBox.wip 126 2011-04-12 15:44:57Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QMessageBox>

#define ButtonRole                              QMessageBox::ButtonRole
#define Icon                                    QMessageBox::Icon
#define StandardButton                          QMessageBox::StandardButton
#define Ok                                      QMessageBox::Ok
#define Open                                    QMessageBox::Open
#define Save                                    QMessageBox::Save
#define Cancel                                  QMessageBox::Cancel
#define Close                                   QMessageBox::Close
#define Discard                                 QMessageBox::Discard
#define Apply                                   QMessageBox::Apply
#define Reset                                   QMessageBox::Reset
#define RestoreDefaults                         QMessageBox::RestoreDefaults
#define Help                                    QMessageBox::Help
#define SaveAll                                 QMessageBox::SaveAll
#define Yes                                     QMessageBox::Yes
#define YesToAll                                QMessageBox::YesToAll
#define No                                      QMessageBox::No
#define NoToAll                                 QMessageBox::NoToAll
#define Abort                                   QMessageBox::Abort
#define Retry                                   QMessageBox::Retry
#define Ignore                                  QMessageBox::Ignore
#define NoButton                                QMessageBox::NoButton
#define StandardButtons                         QMessageBox::StandardButtons

/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QMESSAGEBOX );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QDIALOG );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();
HB_FUNC_EXTERN( QPIXMAP ); // REQUEST'ed Class
HB_FUNC_EXTERN( QABSTRACTBUTTON ); // REQUEST'ed Class
HB_FUNC_EXTERN( QPUSHBUTTON ); // REQUEST'ed Class

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QMESSAGEBOX )
{ "QMESSAGEBOX", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QMESSAGEBOX )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "QDIALOG", { HB_FS_PUBLIC }, { HB_FUNCNAME( QDIALOG ) }, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "S_REGISTERMETHODS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( S_REGISTERMETHODS )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS_1)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL },
{ "QPIXMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( QPIXMAP )}, NULL }, // REQUEST'ed Class
{ "QABSTRACTBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( QABSTRACTBUTTON )}, NULL }, // REQUEST'ed Class
{ "QPUSHBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( QPUSHBUTTON )}, NULL }  // REQUEST'ed Class
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QMESSAGEBOX )

HB_FUNC( QMESSAGEBOX )
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
     * _public_functions_ : QMessageBox ( QWidget * parent = 0 )
     */
    if( ( hb_pcount() <= 1 ) && qth_Is( 1, "QWidget", QTH_DEFAULT ) )
    {
        QWidget* parent = hb_param( 1, HB_IT_OBJECT ) ? qth_parPtr<QWidget>( 1 ) : ( QWidget* ) 0;
        qth_itemPushReturn( QtH::QMessageBox, new QMessageBox( parent ) );
        return;
    }
    /*
     * _public_functions_ : QMessageBox ( Icon icon, const QString & title, const QString & text, StandardButtons buttons = NoButton, QWidget * parent = 0, Qt::WindowFlags f = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint )
     */
    if( ( hb_pcount() <= 6 ) && qth_IsIntType( 1, "Icon" ) && qth_IsString( 2 ) && qth_IsString( 3 ) && qth_IsIntType( 4, "StandardButtons", QTH_DEFAULT ) && qth_Is( 5, "QWidget", QTH_DEFAULT ) && qth_IsIntType( 6, "Qt::WindowFlags", QTH_DEFAULT ) )
    {
        QString title =  qth_par_QString( 2 );
        QString text =  qth_par_QString( 3 );
        QWidget* parent = hb_param( 5, HB_IT_OBJECT ) ? qth_parPtr<QWidget>( 5 ) : ( QWidget* ) 0;
        qth_itemPushReturn( QtH::QMessageBox, new QMessageBox( (Icon)  qth_par_IntType( 1 ), title, text, (StandardButtons) qth_par_IntType( 4, NoButton ), parent, (Qt::WindowFlags) qth_par_IntType( 6, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint ) ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ADDBUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  addButton ( QAbstractButton * button, ButtonRole role )
         */
        if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "QAbstractButton" ) && qth_IsIntType( 2, "ButtonRole" ) )
        {
            p_messageBox->addButton( static_cast<QAbstractButton *>( qth_par_QthObject( 1 ) ), (ButtonRole)  qth_par_IntType( 2 ) );
            hb_ret();
            return;
        }
        /*
         * _public_functions_ : QPushButton *  addButton ( const QString & text, ButtonRole role )
         */
        if( ( hb_pcount() == 2 ) && qth_IsString( 1 ) && qth_IsIntType( 2, "ButtonRole" ) )
        {
            QString text =  qth_par_QString( 1 );
            qth_itemReturn( (PCPP_OBJECT) p_messageBox->addButton( text, (ButtonRole)  qth_par_IntType( 2 ) ), "QPushButton" );
            return;
        }
        /*
         * _public_functions_ : QPushButton *  addButton ( StandardButton button )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "StandardButton" ) )
        {
            qth_itemReturn( (PCPP_OBJECT) p_messageBox->addButton( (StandardButton)  qth_par_IntType( 1 ) ), "QPushButton" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( BUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QAbstractButton *  button ( StandardButton which ) const
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "StandardButton" ) )
        {
            qth_itemReturn( (PCPP_OBJECT) p_messageBox->button( (StandardButton)  qth_par_IntType( 1 ) ), "QAbstractButton" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( BUTTONROLE )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : ButtonRole  buttonRole ( QAbstractButton * button ) const
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QAbstractButton" ) )
        {
            hb_retni( p_messageBox->buttonRole( static_cast<QAbstractButton *>( qth_par_QthObject( 1 ) ) ) );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( BUTTONS )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QList<QAbstractButton *>  buttons () const
         */
        if( hb_pcount() == 0 )
        {
            // ! Don't know how to return type 'QList'
            // qth_itemPushNewReturn( QtH::QList, new QList<QAbstractButton *>( p_messageBox->buttons() ), "QList<QAbstractButton *>" );
            qth_errRT_UNKNOWNOBJ( "QMessageBox::buttons", "Don't know how to return type 'QList'" ) ;
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( CLICKEDBUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QAbstractButton *  clickedButton () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemReturn( (PCPP_OBJECT) p_messageBox->clickedButton(), "QAbstractButton" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( DEFAULTBUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QPushButton *  defaultButton () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemReturn( (PCPP_OBJECT) p_messageBox->defaultButton(), "QPushButton" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( DETAILEDTEXT )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QString  detailedText () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_messageBox->detailedText() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ESCAPEBUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QAbstractButton *  escapeButton () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemReturn( (PCPP_OBJECT) p_messageBox->escapeButton(), "QAbstractButton" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ICON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : Icon  icon () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_messageBox->icon() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ICONPIXMAP )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QPixmap  iconPixmap () const
         */
        if( hb_pcount() == 0 )
        {
            qth_itemPushNewReturn( QtH::QPixmap, new QPixmap( p_messageBox->iconPixmap() ), "QPixmap" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( INFORMATIVETEXT )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QString  informativeText () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_messageBox->informativeText() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( OPEN )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  open ( QObject * receiver, const char * member )
         */
        if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "QObject" ) && qth_Is( 2, HB_IT_STRING ) )
        {
            const char * member = hb_parc( 2 );
            p_messageBox->open( static_cast<QObject *>( qth_par_QthObject( 1 ) ), member );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( REMOVEBUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  removeButton ( QAbstractButton * button )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QAbstractButton" ) )
        {
            p_messageBox->removeButton( static_cast<QAbstractButton *>( qth_par_QthObject( 1 ) ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETDEFAULTBUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setDefaultButton ( QPushButton * button )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QPushButton" ) )
        {
            p_messageBox->setDefaultButton( static_cast<QPushButton *>( qth_par_QthObject( 1 ) ) );
            hb_ret();
            return;
        }
        /*
         * _public_functions_ : void  setDefaultButton ( StandardButton button )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "StandardButton" ) )
        {
            p_messageBox->setDefaultButton( (StandardButton)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETDETAILEDTEXT )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setDetailedText ( const QString & text )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString text =  qth_par_QString( 1 );
            p_messageBox->setDetailedText( text );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETESCAPEBUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setEscapeButton ( QAbstractButton * button )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QAbstractButton" ) )
        {
            p_messageBox->setEscapeButton( static_cast<QAbstractButton *>( qth_par_QthObject( 1 ) ) );
            hb_ret();
            return;
        }
        /*
         * _public_functions_ : void  setEscapeButton ( StandardButton button )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "StandardButton" ) )
        {
            p_messageBox->setEscapeButton( (StandardButton)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETICON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setIcon ( Icon )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Icon" ) )
        {
            p_messageBox->setIcon( (Icon)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETICONPIXMAP )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setIconPixmap ( const QPixmap & pixmap )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QPixmap" ) )
        {
            const QPixmap & pixmap = * static_cast<QPixmap *>( qth_par_QthObject( 1 ) );
            p_messageBox->setIconPixmap( pixmap );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETINFORMATIVETEXT )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setInformativeText ( const QString & text )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString text =  qth_par_QString( 1 );
            p_messageBox->setInformativeText( text );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETSTANDARDBUTTONS )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setStandardButtons ( StandardButtons buttons )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "StandardButtons" ) )
        {
            p_messageBox->setStandardButtons( (StandardButtons)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETTEXT )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setText ( const QString & text )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString text =  qth_par_QString( 1 );
            p_messageBox->setText( text );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETTEXTFORMAT )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setTextFormat ( Qt::TextFormat format )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Qt::TextFormat" ) )
        {
            p_messageBox->setTextFormat( (Qt::TextFormat)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETWINDOWMODALITY )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setWindowModality ( Qt::WindowModality windowModality )
         */
        if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Qt::WindowModality" ) )
        {
            p_messageBox->setWindowModality( (Qt::WindowModality)  qth_par_IntType( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETWINDOWTITLE )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : void  setWindowTitle ( const QString & title )
         */
        if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
        {
            QString title =  qth_par_QString( 1 );
            p_messageBox->setWindowTitle( title );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( STANDARDBUTTON )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : StandardButton  standardButton ( QAbstractButton * button ) const
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QAbstractButton" ) )
        {
            hb_retni( p_messageBox->standardButton( static_cast<QAbstractButton *>( qth_par_QthObject( 1 ) ) ) );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( STANDARDBUTTONS )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : StandardButtons  standardButtons () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_messageBox->standardButtons() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TEXT )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : QString  text () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_messageBox->text() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TEXTFORMAT )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_functions_ : Qt::TextFormat  textFormat () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_messageBox->textFormat() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETVISIBLE )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _reimplemented_public_functions_ : virtual void  setVisible ( bool visible )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_LOGICAL ) )
        {
            p_messageBox->setVisible( hb_parl( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( EXEC )
{
    QMessageBox* p_messageBox = static_cast<QMessageBox *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_messageBox )
    {
        /*
         * _public_slots_ : int  exec ()
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_messageBox->exec() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_ABOUT )
{
    /*
     * _static_public_members_ : void  about ( QWidget * parent, const QString & title, const QString & text )
     */
    if( ( hb_pcount() == 3 ) && qth_IsObject( 1, "QWidget" ) && qth_IsString( 2 ) && qth_IsString( 3 ) )
    {
        QString title =  qth_par_QString( 2 );
        QString text =  qth_par_QString( 3 );
        QMessageBox::about( static_cast<QWidget *>( qth_par_QthObject( 1 ) ), title, text );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_ABOUTQT )
{
    /*
     * _static_public_members_ : void  aboutQt ( QWidget * parent, const QString & title = QString() )
     */
    if( ( hb_pcount() <= 2 ) && qth_IsObject( 1, "QWidget" ) && qth_IsString( 2, QTH_DEFAULT ) )
    {
        const QString& title = hb_param( 2, HB_IT_STRING | HB_IT_OBJECT ) ?  qth_par_QString( 2 ) : QString();
        QMessageBox::aboutQt( static_cast<QWidget *>( qth_par_QthObject( 1 ) ), title );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_CRITICAL )
{
    /*
     * _static_public_members_ : StandardButton  critical ( QWidget * parent, const QString & title, const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton )
     */
    if( ( hb_pcount() <= 5 ) && qth_IsObject( 1, "QWidget" ) && qth_IsString( 2 ) && qth_IsString( 3 ) && qth_IsIntType( 4, "StandardButtons", QTH_DEFAULT ) && qth_IsIntType( 5, "StandardButton", QTH_DEFAULT ) )
    {
        QString title =  qth_par_QString( 2 );
        QString text =  qth_par_QString( 3 );
        hb_retni( QMessageBox::critical( static_cast<QWidget *>( qth_par_QthObject( 1 ) ), title, text, (StandardButtons) qth_par_IntType( 4, Ok ), (StandardButton) qth_par_IntType( 5, NoButton ) ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_INFORMATION )
{
    /*
     * _static_public_members_ : StandardButton  information ( QWidget * parent, const QString & title, const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton )
     */
    if( ( hb_pcount() <= 5 ) && qth_IsObject( 1, "QWidget" ) && qth_IsString( 2 ) && qth_IsString( 3 ) && qth_IsIntType( 4, "StandardButtons", QTH_DEFAULT ) && qth_IsIntType( 5, "StandardButton", QTH_DEFAULT ) )
    {
        QString title =  qth_par_QString( 2 );
        QString text =  qth_par_QString( 3 );
        hb_retni( QMessageBox::information( static_cast<QWidget *>( qth_par_QthObject( 1 ) ), title, text, (StandardButtons) qth_par_IntType( 4, Ok ), (StandardButton) qth_par_IntType( 5, NoButton ) ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_QUESTION )
{
    /*
     * _static_public_members_ : StandardButton  question ( QWidget * parent, const QString & title, const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton )
     */
    if( ( hb_pcount() <= 5 ) && qth_IsObject( 1, "QWidget" ) && qth_IsString( 2 ) && qth_IsString( 3 ) && qth_IsIntType( 4, "StandardButtons", QTH_DEFAULT ) && qth_IsIntType( 5, "StandardButton", QTH_DEFAULT ) )
    {
        QString title =  qth_par_QString( 2 );
        QString text =  qth_par_QString( 3 );
        hb_retni( QMessageBox::question( static_cast<QWidget *>( qth_par_QthObject( 1 ) ), title, text, (StandardButtons) qth_par_IntType( 4, Ok ), (StandardButton) qth_par_IntType( 5, NoButton ) ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_WARNING )
{
    /*
     * _static_public_members_ : StandardButton  warning ( QWidget * parent, const QString & title, const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton )
     */
    if( ( hb_pcount() <= 5 ) && qth_IsObject( 1, "QWidget" ) && qth_IsString( 2 ) && qth_IsString( 3 ) && qth_IsIntType( 4, "StandardButtons", QTH_DEFAULT ) && qth_IsIntType( 5, "StandardButton", QTH_DEFAULT ) )
    {
        QString title =  qth_par_QString( 2 );
        QString text =  qth_par_QString( 3 );
        hb_retni( QMessageBox::warning( static_cast<QWidget *>( qth_par_QthObject( 1 ) ), title, text, (StandardButtons) qth_par_IntType( 4, Ok ), (StandardButton) qth_par_IntType( 5, NoButton ) ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_OK )
{
    /*
     * _static_public_members_ : Ok
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Ok", Ok );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_OPEN )
{
    /*
     * _static_public_members_ : Open
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Open", Open );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_SAVE )
{
    /*
     * _static_public_members_ : Save
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Save", Save );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_CANCEL )
{
    /*
     * _static_public_members_ : Cancel
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Cancel", Cancel );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_CLOSE )
{
    /*
     * _static_public_members_ : Close
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Close", Close );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_DISCARD )
{
    /*
     * _static_public_members_ : Discard
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Discard", Discard );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_APPLY )
{
    /*
     * _static_public_members_ : Apply
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Apply", Apply );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_RESET )
{
    /*
     * _static_public_members_ : Reset
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Reset", Reset );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_RESTOREDEFAULTS )
{
    /*
     * _static_public_members_ : RestoreDefaults
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "RestoreDefaults", RestoreDefaults );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_HELP )
{
    /*
     * _static_public_members_ : Help
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Help", Help );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_SAVEALL )
{
    /*
     * _static_public_members_ : SaveAll
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "SaveAll", SaveAll );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_YES )
{
    /*
     * _static_public_members_ : Yes
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Yes", Yes );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_YESTOALL )
{
    /*
     * _static_public_members_ : YesToAll
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "YesToAll", YesToAll );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_NO )
{
    /*
     * _static_public_members_ : No
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "No", No );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_NOTOALL )
{
    /*
     * _static_public_members_ : NoToAll
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "NoToAll", NoToAll );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_ABORT )
{
    /*
     * _static_public_members_ : Abort
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Abort", Abort );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_RETRY )
{
    /*
     * _static_public_members_ : Retry
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Retry", Retry );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_IGNORE )
{
    /*
     * _static_public_members_ : Ignore
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "Ignore", Ignore );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QMESSAGEBOX_E_NOBUTTON )
{
    /*
     * _static_public_members_ : NoButton
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QMessageBox::StandardButton", "NoButton", NoButton );
        hb_itemReturn( hb_stackSelfItem() );
        return;
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

    hb_clsAdd( uiClass, "NEW"               , HB_FUNCNAME( NEW                           ) );
    hb_clsAdd( uiClass, "ADDBUTTON"         , HB_FUNCNAME( ADDBUTTON                     ) );
    hb_clsAdd( uiClass, "BUTTON"            , HB_FUNCNAME( BUTTON                        ) );
    hb_clsAdd( uiClass, "BUTTONROLE"        , HB_FUNCNAME( BUTTONROLE                    ) );
    hb_clsAdd( uiClass, "BUTTONS"           , HB_FUNCNAME( BUTTONS                       ) );
    hb_clsAdd( uiClass, "CLICKEDBUTTON"     , HB_FUNCNAME( CLICKEDBUTTON                 ) );
    hb_clsAdd( uiClass, "DEFAULTBUTTON"     , HB_FUNCNAME( DEFAULTBUTTON                 ) );
    hb_clsAdd( uiClass, "DETAILEDTEXT"      , HB_FUNCNAME( DETAILEDTEXT                  ) );
    hb_clsAdd( uiClass, "ESCAPEBUTTON"      , HB_FUNCNAME( ESCAPEBUTTON                  ) );
    hb_clsAdd( uiClass, "ICON"              , HB_FUNCNAME( ICON                          ) );
    hb_clsAdd( uiClass, "ICONPIXMAP"        , HB_FUNCNAME( ICONPIXMAP                    ) );
    hb_clsAdd( uiClass, "INFORMATIVETEXT"   , HB_FUNCNAME( INFORMATIVETEXT               ) );
    hb_clsAdd( uiClass, "OPEN"              , HB_FUNCNAME( OPEN                          ) );
    hb_clsAdd( uiClass, "REMOVEBUTTON"      , HB_FUNCNAME( REMOVEBUTTON                  ) );
    hb_clsAdd( uiClass, "SETDEFAULTBUTTON"  , HB_FUNCNAME( SETDEFAULTBUTTON              ) );
    hb_clsAdd( uiClass, "SETDETAILEDTEXT"   , HB_FUNCNAME( SETDETAILEDTEXT               ) );
    hb_clsAdd( uiClass, "SETESCAPEBUTTON"   , HB_FUNCNAME( SETESCAPEBUTTON               ) );
    hb_clsAdd( uiClass, "SETICON"           , HB_FUNCNAME( SETICON                       ) );
    hb_clsAdd( uiClass, "SETICONPIXMAP"     , HB_FUNCNAME( SETICONPIXMAP                 ) );
    hb_clsAdd( uiClass, "SETINFORMATIVETEXT", HB_FUNCNAME( SETINFORMATIVETEXT            ) );
    hb_clsAdd( uiClass, "SETSTANDARDBUTTONS", HB_FUNCNAME( SETSTANDARDBUTTONS            ) );
    hb_clsAdd( uiClass, "SETTEXT"           , HB_FUNCNAME( SETTEXT                       ) );
    hb_clsAdd( uiClass, "SETTEXTFORMAT"     , HB_FUNCNAME( SETTEXTFORMAT                 ) );
    hb_clsAdd( uiClass, "SETWINDOWMODALITY" , HB_FUNCNAME( SETWINDOWMODALITY             ) );
    hb_clsAdd( uiClass, "SETWINDOWTITLE"    , HB_FUNCNAME( SETWINDOWTITLE                ) );
    hb_clsAdd( uiClass, "STANDARDBUTTON"    , HB_FUNCNAME( STANDARDBUTTON                ) );
    hb_clsAdd( uiClass, "STANDARDBUTTONS"   , HB_FUNCNAME( STANDARDBUTTONS               ) );
    hb_clsAdd( uiClass, "TEXT"              , HB_FUNCNAME( TEXT                          ) );
    hb_clsAdd( uiClass, "TEXTFORMAT"        , HB_FUNCNAME( TEXTFORMAT                    ) );
    hb_clsAdd( uiClass, "SETVISIBLE"        , HB_FUNCNAME( SETVISIBLE                    ) );
    hb_clsAdd( uiClass, "EXEC"              , HB_FUNCNAME( EXEC                          ) );
    hb_clsAdd( uiClass, "ABOUT"             , HB_FUNCNAME( QMESSAGEBOX_ABOUT             ) );
    hb_clsAdd( uiClass, "ABOUTQT"           , HB_FUNCNAME( QMESSAGEBOX_ABOUTQT           ) );
    hb_clsAdd( uiClass, "CRITICAL"          , HB_FUNCNAME( QMESSAGEBOX_CRITICAL          ) );
    hb_clsAdd( uiClass, "INFORMATION"       , HB_FUNCNAME( QMESSAGEBOX_INFORMATION       ) );
    hb_clsAdd( uiClass, "QUESTION"          , HB_FUNCNAME( QMESSAGEBOX_QUESTION          ) );
    hb_clsAdd( uiClass, "WARNING"           , HB_FUNCNAME( QMESSAGEBOX_WARNING           ) );
    hb_clsAdd( uiClass, "E_OK"              , HB_FUNCNAME( QMESSAGEBOX_E_OK              ) );
    hb_clsAdd( uiClass, "E_OPEN"            , HB_FUNCNAME( QMESSAGEBOX_E_OPEN            ) );
    hb_clsAdd( uiClass, "E_SAVE"            , HB_FUNCNAME( QMESSAGEBOX_E_SAVE            ) );
    hb_clsAdd( uiClass, "E_CANCEL"          , HB_FUNCNAME( QMESSAGEBOX_E_CANCEL          ) );
    hb_clsAdd( uiClass, "E_CLOSE"           , HB_FUNCNAME( QMESSAGEBOX_E_CLOSE           ) );
    hb_clsAdd( uiClass, "E_DISCARD"         , HB_FUNCNAME( QMESSAGEBOX_E_DISCARD         ) );
    hb_clsAdd( uiClass, "E_APPLY"           , HB_FUNCNAME( QMESSAGEBOX_E_APPLY           ) );
    hb_clsAdd( uiClass, "E_RESET"           , HB_FUNCNAME( QMESSAGEBOX_E_RESET           ) );
    hb_clsAdd( uiClass, "E_RESTOREDEFAULTS" , HB_FUNCNAME( QMESSAGEBOX_E_RESTOREDEFAULTS ) );
    hb_clsAdd( uiClass, "E_HELP"            , HB_FUNCNAME( QMESSAGEBOX_E_HELP            ) );
    hb_clsAdd( uiClass, "E_SAVEALL"         , HB_FUNCNAME( QMESSAGEBOX_E_SAVEALL         ) );
    hb_clsAdd( uiClass, "E_YES"             , HB_FUNCNAME( QMESSAGEBOX_E_YES             ) );
    hb_clsAdd( uiClass, "E_YESTOALL"        , HB_FUNCNAME( QMESSAGEBOX_E_YESTOALL        ) );
    hb_clsAdd( uiClass, "E_NO"              , HB_FUNCNAME( QMESSAGEBOX_E_NO              ) );
    hb_clsAdd( uiClass, "E_NOTOALL"         , HB_FUNCNAME( QMESSAGEBOX_E_NOTOALL         ) );
    hb_clsAdd( uiClass, "E_ABORT"           , HB_FUNCNAME( QMESSAGEBOX_E_ABORT           ) );
    hb_clsAdd( uiClass, "E_RETRY"           , HB_FUNCNAME( QMESSAGEBOX_E_RETRY           ) );
    hb_clsAdd( uiClass, "E_IGNORE"          , HB_FUNCNAME( QMESSAGEBOX_E_IGNORE          ) );
    hb_clsAdd( uiClass, "E_NOBUTTON"        , HB_FUNCNAME( QMESSAGEBOX_E_NOBUTTON        ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */
