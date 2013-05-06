/*
 * $Id: qthQCoreApplication.wip 129 2011-04-19 18:22:34Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QCoreApplication>

#define Encoding                                QCoreApplication::Encoding
/*
 * Wip: Dump Section INIT
 */

static void qthApplication_Terminate( void* cargo )
{
    qth_itemListReleaseAll();
}

HB_CALL_ON_STARTUP_BEGIN( _end_ )
hb_vmAtExit( qthApplication_Terminate, NULL );
HB_CALL_ON_STARTUP_END( _end_ )

#define Encoding    QCoreApplication::Encoding
#define CodecForTr  QCoreApplication::CodecForTr

static int argc;
static char **argv;
static QCoreApplication* pQApp = NULL;

HB_FUNC_STATIC( NEW )
{
    if(!pQApp)
    {
        argc = hb_cmdargARGC();
        argv = hb_cmdargARGV();
        pQApp = new QCoreApplication( argc, argv );

        qth_itemPushReturn( QtH::QCoreApplication, pQApp );
    }
}
/*
 * Wip: Dump Section END
 */


/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QCOREAPPLICATION );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QOBJECT );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QCOREAPPLICATION )
{ "QCOREAPPLICATION", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QCOREAPPLICATION )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "QOBJECT", { HB_FS_PUBLIC }, { HB_FUNCNAME( QOBJECT ) }, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "S_REGISTERMETHODS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( S_REGISTERMETHODS )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS_1)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QCOREAPPLICATION )

HB_FUNC( QCOREAPPLICATION )
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
HB_FUNC_STATIC( FILTEREVENT )
{
    QCoreApplication* p_coreApplication = static_cast<QCoreApplication *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_coreApplication )
    {
        /*
         * _public_functions_ : bool  filterEvent ( void * message, long * result )
         */
        if( ( hb_pcount() == 2 ) && qth_Is( 1, HB_IT_POINTER ) && qth_Is( 2, HB_IT_LONG, QTH_BYREF ) )
        {
            void * message = hb_parptr( 1 );
            long result = hb_parnl( 2 );
            hb_retl( p_coreApplication->filterEvent( message, &result ) == true );
            if( HB_ISBYREF( 2 ) )
            {
                hb_stornl( result, 2 );
            }
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( NOTIFY )
{
    QCoreApplication* p_coreApplication = static_cast<QCoreApplication *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_coreApplication )
    {
        /*
         * _public_functions_ : virtual bool  notify ( QObject * receiver, QEvent * event )
         */
        if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "QObject" ) && qth_IsObject( 2, "QEvent" ) )
        {
            hb_retl( p_coreApplication->notify( static_cast<QObject *>( qth_par_QthObject( 1 ) ), static_cast<QEvent *>( qth_par_QthObject( 2 ) ) ) == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETEVENTFILTER )
{
    QCoreApplication* p_coreApplication = static_cast<QCoreApplication *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_coreApplication )
    {
#if IImplementIt
        /*
         * _public_functions_ : EventFilter  setEventFilter ( EventFilter filter )
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "EventFilter" ) )
        {
            // ! Don't know how to return type 'EventFilter'
            // qth_itemPushNewReturn( QtH::EventFilter, new EventFilter( p_coreApplication->setEventFilter( * static_cast<EventFilter *>( qth_par_QthObject( 1 ) ) ) ), "EventFilter" );
            qth_errRT_UNKNOWNOBJ( "QCoreApplication::setEventFilter", "Don't know how to return type 'EventFilter'" ) ;
            return;
        }
#endif  /* IImplementIt */
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( WINEVENTFILTER )
{
    QCoreApplication* p_coreApplication = static_cast<QCoreApplication *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_coreApplication )
    {
#if __WIN32__
        /*
         * _public_functions_ : virtual bool  winEventFilter ( MSG * msg, long * result )
         */
        if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "MSG" ) && qth_Is( 2, HB_IT_LONG, QTH_BYREF ) )
        {
            long result = hb_parnl( 2 );
            hb_retl( p_coreApplication->winEventFilter( static_cast<MSG *>( qth_par_QthObject( 1 ) ), &result ) == true );
            if( HB_ISBYREF( 2 ) )
            {
                hb_stornl( result, 2 );
            }
            return;
        }
#endif  /* __WIN32__ */
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( QUIT )
{
    QCoreApplication* p_coreApplication = static_cast<QCoreApplication *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_coreApplication )
    {
        /*
         * _public_slots_ : void  quit ()
         */
        if( hb_pcount() == 0 )
        {
            p_coreApplication->quit();
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_ADDLIBRARYPATH )
{
    /*
     * _static_public_members_ : void  addLibraryPath ( const QString & path )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString path =  qth_par_QString( 1 );
        QCoreApplication::addLibraryPath( path );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_APPLICATIONDIRPATH )
{
    /*
     * _static_public_members_ : QString  applicationDirPath ()
     */
    if( hb_pcount() == 0 )
    {
        qth_ret_QString( QCoreApplication::applicationDirPath() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_APPLICATIONFILEPATH )
{
    /*
     * _static_public_members_ : QString  applicationFilePath ()
     */
    if( hb_pcount() == 0 )
    {
        qth_ret_QString( QCoreApplication::applicationFilePath() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_APPLICATIONNAME )
{
    /*
     * _static_public_members_ : QString  applicationName ()
     */
    if( hb_pcount() == 0 )
    {
        qth_ret_QString( QCoreApplication::applicationName() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_APPLICATIONPID )
{
    /*
     * _static_public_members_ : qint64  applicationPid ()
     */
    if( hb_pcount() == 0 )
    {
        hb_retnll( QCoreApplication::applicationPid() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_APPLICATIONVERSION )
{
    /*
     * _static_public_members_ : QString  applicationVersion ()
     */
    if( hb_pcount() == 0 )
    {
        qth_ret_QString( QCoreApplication::applicationVersion() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_ARGUMENTS )
{
    /*
     * _static_public_members_ : QStringList  arguments ()
     */
    if( hb_pcount() == 0 )
    {
        // ! Don't know how to return type 'QStringList'
        // qth_itemPushNewReturn( QtH::QStringList, new QStringList( QCoreApplication::arguments() ), "QStringList" );
        qth_errRT_UNKNOWNOBJ( "QCoreApplication::arguments", "Don't know how to return type 'QStringList'" ) ;
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_CLOSINGDOWN )
{
    /*
     * _static_public_members_ : bool  closingDown ()
     */
    if( hb_pcount() == 0 )
    {
        hb_retl( QCoreApplication::closingDown() == true );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_EXEC )
{
    /*
     * _static_public_members_ : int  exec ()
     */
    if( hb_pcount() == 0 )
    {
        hb_retni( QCoreApplication::exec() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_EXIT )
{
    /*
     * _static_public_members_ : void  exit ( int returnCode = 0 )
     */
    if( ( hb_pcount() <= 1 ) && qth_Is( 1, HB_IT_INTEGER, QTH_DEFAULT ) )
    {
        int returnCode = hb_param( 1, HB_IT_INTEGER ) ? hb_parni( 1 ) : 0;
        QCoreApplication::exit( returnCode );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_FLUSH )
{
    /*
     * _static_public_members_ : void  flush ()
     */
    if( hb_pcount() == 0 )
    {
        QCoreApplication::flush();
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_HASPENDINGEVENTS )
{
    /*
     * _static_public_members_ : bool  hasPendingEvents ()
     */
    if( hb_pcount() == 0 )
    {
        hb_retl( QCoreApplication::hasPendingEvents() == true );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_INSTALLTRANSLATOR )
{
    /*
     * _static_public_members_ : void  installTranslator ( QTranslator * translationFile )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QTranslator" ) )
    {
        QCoreApplication::installTranslator( static_cast<QTranslator *>( qth_par_QthObject( 1 ) ) );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_INSTANCE )
{
    /*
     * _static_public_members_ : QCoreApplication *  instance ()
     */
    if( hb_pcount() == 0 )
    {
        qth_itemReturn( (PCPP_OBJECT) QCoreApplication::instance(), "QCoreApplication" );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_LIBRARYPATHS )
{
    /*
     * _static_public_members_ : QStringList  libraryPaths ()
     */
    if( hb_pcount() == 0 )
    {
        // ! Don't know how to return type 'QStringList'
        // qth_itemPushNewReturn( QtH::QStringList, new QStringList( QCoreApplication::libraryPaths() ), "QStringList" );
        qth_errRT_UNKNOWNOBJ( "QCoreApplication::libraryPaths", "Don't know how to return type 'QStringList'" ) ;
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_ORGANIZATIONDOMAIN )
{
    /*
     * _static_public_members_ : QString  organizationDomain ()
     */
    if( hb_pcount() == 0 )
    {
        qth_ret_QString( QCoreApplication::organizationDomain() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_ORGANIZATIONNAME )
{
    /*
     * _static_public_members_ : QString  organizationName ()
     */
    if( hb_pcount() == 0 )
    {
        qth_ret_QString( QCoreApplication::organizationName() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_POSTEVENT )
{
    /*
     * _static_public_members_ : void  postEvent ( QObject * receiver, QEvent * event )
     */
    if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "QObject" ) && qth_IsObject( 2, "QEvent" ) )
    {
        QCoreApplication::postEvent( static_cast<QObject *>( qth_par_QthObject( 1 ) ), static_cast<QEvent *>( qth_par_QthObject( 2 ) ) );
        hb_ret();
        return;
    }
    /*
     * _static_public_members_ : void  postEvent ( QObject * receiver, QEvent * event, int priority )
     */
    if( ( hb_pcount() == 3 ) && qth_IsObject( 1, "QObject" ) && qth_IsObject( 2, "QEvent" ) && qth_Is( 3, HB_IT_INTEGER ) )
    {
        QCoreApplication::postEvent( static_cast<QObject *>( qth_par_QthObject( 1 ) ), static_cast<QEvent *>( qth_par_QthObject( 2 ) ), hb_parni( 3 ) );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_PROCESSEVENTS )
{
    /*
     * _static_public_members_ : void  processEvents ( QEventLoop::ProcessEventsFlags flags = QEventLoop::AllEvents )
     */
    if( ( hb_pcount() <= 1 ) && qth_IsIntType( 1, "QEventLoop::ProcessEventsFlags", QTH_DEFAULT ) )
    {
        QCoreApplication::processEvents( (QEventLoop::ProcessEventsFlags) qth_par_IntType( 1, QEventLoop::AllEvents ) );
        hb_ret();
        return;
    }
    /*
     * _static_public_members_ : void  processEvents ( QEventLoop::ProcessEventsFlags flags, int maxtime )
     */
    if( ( hb_pcount() == 2 ) && qth_IsIntType( 1, "QEventLoop::ProcessEventsFlags" ) && qth_Is( 2, HB_IT_INTEGER ) )
    {
        QCoreApplication::processEvents( (QEventLoop::ProcessEventsFlags)  qth_par_IntType( 1 ), hb_parni( 2 ) );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_REMOVELIBRARYPATH )
{
    /*
     * _static_public_members_ : void  removeLibraryPath ( const QString & path )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString path =  qth_par_QString( 1 );
        QCoreApplication::removeLibraryPath( path );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_REMOVEPOSTEDEVENTS )
{
    /*
     * _static_public_members_ : void  removePostedEvents ( QObject * receiver )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QObject" ) )
    {
        QCoreApplication::removePostedEvents( static_cast<QObject *>( qth_par_QthObject( 1 ) ) );
        hb_ret();
        return;
    }
    /*
     * _static_public_members_ : void  removePostedEvents ( QObject * receiver, int eventType )
     */
    if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "QObject" ) && qth_Is( 2, HB_IT_INTEGER ) )
    {
        QCoreApplication::removePostedEvents( static_cast<QObject *>( qth_par_QthObject( 1 ) ), hb_parni( 2 ) );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_REMOVETRANSLATOR )
{
    /*
     * _static_public_members_ : void  removeTranslator ( QTranslator * translationFile )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QTranslator" ) )
    {
        QCoreApplication::removeTranslator( static_cast<QTranslator *>( qth_par_QthObject( 1 ) ) );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_SENDEVENT )
{
    /*
     * _static_public_members_ : bool  sendEvent ( QObject * receiver, QEvent * event )
     */
    if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "QObject" ) && qth_IsObject( 2, "QEvent" ) )
    {
        hb_retl( QCoreApplication::sendEvent( static_cast<QObject *>( qth_par_QthObject( 1 ) ), static_cast<QEvent *>( qth_par_QthObject( 2 ) ) ) == true );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_SENDPOSTEDEVENTS )
{
    /*
     * _static_public_members_ : void  sendPostedEvents ( QObject * receiver, int event_type )
     */
    if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "QObject" ) && qth_Is( 2, HB_IT_INTEGER ) )
    {
        QCoreApplication::sendPostedEvents( static_cast<QObject *>( qth_par_QthObject( 1 ) ), hb_parni( 2 ) );
        hb_ret();
        return;
    }
    /*
     * _static_public_members_ : void  sendPostedEvents ()
     */
    if( hb_pcount() == 0 )
    {
        QCoreApplication::sendPostedEvents();
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_SETAPPLICATIONNAME )
{
    /*
     * _static_public_members_ : void  setApplicationName ( const QString & application )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString application =  qth_par_QString( 1 );
        QCoreApplication::setApplicationName( application );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_SETAPPLICATIONVERSION )
{
    /*
     * _static_public_members_ : void  setApplicationVersion ( const QString & version )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString version =  qth_par_QString( 1 );
        QCoreApplication::setApplicationVersion( version );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_SETATTRIBUTE )
{
    /*
     * _static_public_members_ : void  setAttribute ( Qt::ApplicationAttribute attribute, bool on = true )
     */
    if( ( hb_pcount() <= 2 ) && qth_IsIntType( 1, "Qt::ApplicationAttribute" ) && qth_Is( 2, HB_IT_LOGICAL, QTH_DEFAULT ) )
    {
        bool on = hb_param( 2, HB_IT_LOGICAL ) ? hb_parl( 2 ) : true;
        QCoreApplication::setAttribute( (Qt::ApplicationAttribute)  qth_par_IntType( 1 ), on );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_SETLIBRARYPATHS )
{
    /*
     * _static_public_members_ : void  setLibraryPaths ( const QStringList & paths )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QStringList" ) )
    {
        const QStringList & paths = * static_cast<QStringList *>( qth_par_QthObject( 1 ) );
        QCoreApplication::setLibraryPaths( paths );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_SETORGANIZATIONDOMAIN )
{
    /*
     * _static_public_members_ : void  setOrganizationDomain ( const QString & orgDomain )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString orgDomain =  qth_par_QString( 1 );
        QCoreApplication::setOrganizationDomain( orgDomain );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_SETORGANIZATIONNAME )
{
    /*
     * _static_public_members_ : void  setOrganizationName ( const QString & orgName )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString orgName =  qth_par_QString( 1 );
        QCoreApplication::setOrganizationName( orgName );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_STARTINGUP )
{
    /*
     * _static_public_members_ : bool  startingUp ()
     */
    if( hb_pcount() == 0 )
    {
        hb_retl( QCoreApplication::startingUp() == true );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_TESTATTRIBUTE )
{
    /*
     * _static_public_members_ : bool  testAttribute ( Qt::ApplicationAttribute attribute )
     */
    if( ( hb_pcount() == 1 ) && qth_IsIntType( 1, "Qt::ApplicationAttribute" ) )
    {
        hb_retl( QCoreApplication::testAttribute( (Qt::ApplicationAttribute)  qth_par_IntType( 1 ) ) == true );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QCOREAPPLICATION_TRANSLATE )
{
    /*
     * _static_public_members_ : QString  translate ( const char * context, const char * sourceText, const char * disambiguation, Encoding encoding, int n )
     */
    if( ( hb_pcount() == 5 ) && qth_Is( 1, HB_IT_STRING ) && qth_Is( 2, HB_IT_STRING ) && qth_Is( 3, HB_IT_STRING ) && qth_IsIntType( 4, "Encoding" ) && qth_Is( 5, HB_IT_INTEGER ) )
    {
        const char * context = hb_parc( 1 );
        const char * sourceText = hb_parc( 2 );
        const char * disambiguation = hb_parc( 3 );
        qth_ret_QString( QCoreApplication::translate( context, sourceText, disambiguation, (Encoding)  qth_par_IntType( 4 ), hb_parni( 5 ) ) );
        return;
    }
    /*
     * _static_public_members_ : QString  translate ( const char * context, const char * sourceText, const char * disambiguation = 0, Encoding encoding = CodecForTr )
     */
    if( ( hb_pcount() <= 4 ) && qth_Is( 1, HB_IT_STRING ) && qth_Is( 2, HB_IT_STRING ) && qth_Is( 3, HB_IT_STRING, QTH_DEFAULT ) && qth_IsIntType( 4, "Encoding", QTH_DEFAULT ) )
    {
        const char * context = hb_parc( 1 );
        const char * sourceText = hb_parc( 2 );
        const char* disambiguation = hb_param( 3, HB_IT_STRING ) ? hb_parc( 3 ) : 0;
        qth_ret_QString( QCoreApplication::translate( context, sourceText, disambiguation, (Encoding) qth_par_IntType( 4, CodecForTr ) ) );
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

    hb_clsAdd( uiClass, "NEW"                  , HB_FUNCNAME( NEW                                    ) );
    hb_clsAdd( uiClass, "FILTEREVENT"          , HB_FUNCNAME( FILTEREVENT                            ) );
    hb_clsAdd( uiClass, "NOTIFY"               , HB_FUNCNAME( NOTIFY                                 ) );
    hb_clsAdd( uiClass, "SETEVENTFILTER"       , HB_FUNCNAME( SETEVENTFILTER                         ) );
    hb_clsAdd( uiClass, "WINEVENTFILTER"       , HB_FUNCNAME( WINEVENTFILTER                         ) );
    hb_clsAdd( uiClass, "QUIT"                 , HB_FUNCNAME( QUIT                                   ) );
    hb_clsAdd( uiClass, "ADDLIBRARYPATH"       , HB_FUNCNAME( QCOREAPPLICATION_ADDLIBRARYPATH        ) );
    hb_clsAdd( uiClass, "APPLICATIONDIRPATH"   , HB_FUNCNAME( QCOREAPPLICATION_APPLICATIONDIRPATH    ) );
    hb_clsAdd( uiClass, "APPLICATIONFILEPATH"  , HB_FUNCNAME( QCOREAPPLICATION_APPLICATIONFILEPATH   ) );
    hb_clsAdd( uiClass, "APPLICATIONNAME"      , HB_FUNCNAME( QCOREAPPLICATION_APPLICATIONNAME       ) );
    hb_clsAdd( uiClass, "APPLICATIONPID"       , HB_FUNCNAME( QCOREAPPLICATION_APPLICATIONPID        ) );
    hb_clsAdd( uiClass, "APPLICATIONVERSION"   , HB_FUNCNAME( QCOREAPPLICATION_APPLICATIONVERSION    ) );
    hb_clsAdd( uiClass, "ARGUMENTS"            , HB_FUNCNAME( QCOREAPPLICATION_ARGUMENTS             ) );
    hb_clsAdd( uiClass, "CLOSINGDOWN"          , HB_FUNCNAME( QCOREAPPLICATION_CLOSINGDOWN           ) );
    hb_clsAdd( uiClass, "EXEC"                 , HB_FUNCNAME( QCOREAPPLICATION_EXEC                  ) );
    hb_clsAdd( uiClass, "EXIT"                 , HB_FUNCNAME( QCOREAPPLICATION_EXIT                  ) );
    hb_clsAdd( uiClass, "FLUSH"                , HB_FUNCNAME( QCOREAPPLICATION_FLUSH                 ) );
    hb_clsAdd( uiClass, "HASPENDINGEVENTS"     , HB_FUNCNAME( QCOREAPPLICATION_HASPENDINGEVENTS      ) );
    hb_clsAdd( uiClass, "INSTALLTRANSLATOR"    , HB_FUNCNAME( QCOREAPPLICATION_INSTALLTRANSLATOR     ) );
    hb_clsAdd( uiClass, "INSTANCE"             , HB_FUNCNAME( QCOREAPPLICATION_INSTANCE              ) );
    hb_clsAdd( uiClass, "LIBRARYPATHS"         , HB_FUNCNAME( QCOREAPPLICATION_LIBRARYPATHS          ) );
    hb_clsAdd( uiClass, "ORGANIZATIONDOMAIN"   , HB_FUNCNAME( QCOREAPPLICATION_ORGANIZATIONDOMAIN    ) );
    hb_clsAdd( uiClass, "ORGANIZATIONNAME"     , HB_FUNCNAME( QCOREAPPLICATION_ORGANIZATIONNAME      ) );
    hb_clsAdd( uiClass, "POSTEVENT"            , HB_FUNCNAME( QCOREAPPLICATION_POSTEVENT             ) );
    hb_clsAdd( uiClass, "PROCESSEVENTS"        , HB_FUNCNAME( QCOREAPPLICATION_PROCESSEVENTS         ) );
    hb_clsAdd( uiClass, "REMOVELIBRARYPATH"    , HB_FUNCNAME( QCOREAPPLICATION_REMOVELIBRARYPATH     ) );
    hb_clsAdd( uiClass, "REMOVEPOSTEDEVENTS"   , HB_FUNCNAME( QCOREAPPLICATION_REMOVEPOSTEDEVENTS    ) );
    hb_clsAdd( uiClass, "REMOVETRANSLATOR"     , HB_FUNCNAME( QCOREAPPLICATION_REMOVETRANSLATOR      ) );
    hb_clsAdd( uiClass, "SENDEVENT"            , HB_FUNCNAME( QCOREAPPLICATION_SENDEVENT             ) );
    hb_clsAdd( uiClass, "SENDPOSTEDEVENTS"     , HB_FUNCNAME( QCOREAPPLICATION_SENDPOSTEDEVENTS      ) );
    hb_clsAdd( uiClass, "SETAPPLICATIONNAME"   , HB_FUNCNAME( QCOREAPPLICATION_SETAPPLICATIONNAME    ) );
    hb_clsAdd( uiClass, "SETAPPLICATIONVERSION", HB_FUNCNAME( QCOREAPPLICATION_SETAPPLICATIONVERSION ) );
    hb_clsAdd( uiClass, "SETATTRIBUTE"         , HB_FUNCNAME( QCOREAPPLICATION_SETATTRIBUTE          ) );
    hb_clsAdd( uiClass, "SETLIBRARYPATHS"      , HB_FUNCNAME( QCOREAPPLICATION_SETLIBRARYPATHS       ) );
    hb_clsAdd( uiClass, "SETORGANIZATIONDOMAIN", HB_FUNCNAME( QCOREAPPLICATION_SETORGANIZATIONDOMAIN ) );
    hb_clsAdd( uiClass, "SETORGANIZATIONNAME"  , HB_FUNCNAME( QCOREAPPLICATION_SETORGANIZATIONNAME   ) );
    hb_clsAdd( uiClass, "STARTINGUP"           , HB_FUNCNAME( QCOREAPPLICATION_STARTINGUP            ) );
    hb_clsAdd( uiClass, "TESTATTRIBUTE"        , HB_FUNCNAME( QCOREAPPLICATION_TESTATTRIBUTE         ) );
    hb_clsAdd( uiClass, "TRANSLATE"            , HB_FUNCNAME( QCOREAPPLICATION_TRANSLATE             ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */
