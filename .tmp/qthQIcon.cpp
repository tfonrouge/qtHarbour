/*
 * $Id: qthQIcon.wip 126 2011-04-12 15:44:57Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QIcon>

#define Mode                                    QIcon::Mode
#define Normal                                  QIcon::Normal
#define Disabled                                QIcon::Disabled
#define Active                                  QIcon::Active
#define Selected                                QIcon::Selected
#define State                                   QIcon::State
#define Off                                     QIcon::Off
#define On                                      QIcon::On

/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QICON );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QTHBASE );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();
HB_FUNC_EXTERN( QPIXMAP ); // REQUEST'ed Class
HB_FUNC_EXTERN( QSIZE ); // REQUEST'ed Class

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QICON )
{ "QICON", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QICON )}, NULL },
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
{ "QPIXMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( QPIXMAP )}, NULL }, // REQUEST'ed Class
{ "QSIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( QSIZE )}, NULL }  // REQUEST'ed Class
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QICON )

HB_FUNC( QICON )
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
     * _public_functions_ : QIcon ()
     */
    if( hb_pcount() == 0 )
    {
        qth_itemPushReturn( QtH::QIcon, new QIcon() );
        return;
    }
    /*
     * _public_functions_ : QIcon ( const QPixmap & pixmap )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QPixmap" ) )
    {
        const QPixmap & pixmap = * static_cast<QPixmap *>( qth_par_QthObject( 1 ) );
        qth_itemPushReturn( QtH::QIcon, new QIcon( pixmap ) );
        return;
    }
    /*
     * _public_functions_ : QIcon ( const QIcon & other )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QIcon" ) )
    {
        const QIcon & other = * static_cast<QIcon *>( qth_par_QthObject( 1 ) );
        qth_itemPushReturn( QtH::QIcon, new QIcon( other ) );
        return;
    }
    /*
     * _public_functions_ : QIcon ( const QString & fileName )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString fileName =  qth_par_QString( 1 );
        qth_itemPushReturn( QtH::QIcon, new QIcon( fileName ) );
        return;
    }
    /*
     * _public_functions_ : QIcon ( QIconEngine * engine )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QIconEngine" ) )
    {
        qth_itemPushReturn( QtH::QIcon, new QIcon( static_cast<QIconEngine *>( qth_par_QthObject( 1 ) ) ) );
        return;
    }
    /*
     * _public_functions_ : QIcon ( QIconEngineV2 * engine )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QIconEngineV2" ) )
    {
        qth_itemPushReturn( QtH::QIcon, new QIcon( static_cast<QIconEngineV2 *>( qth_par_QthObject( 1 ) ) ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ACTUALSIZE )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
        /*
         * _public_functions_ : QSize  actualSize ( const QSize & size, Mode mode = Normal, State state = Off ) const
         */
        if( ( hb_pcount() <= 3 ) && qth_IsObject( 1, "QSize" ) && qth_IsIntType( 2, "Mode", QTH_DEFAULT ) && qth_IsIntType( 3, "State", QTH_DEFAULT ) )
        {
            const QSize & size = * static_cast<QSize *>( qth_par_QthObject( 1 ) );
            qth_itemPushNewReturn( QtH::QSize, new QSize( p_icon->actualSize( size, (Mode) qth_par_IntType( 2, Normal ), (State) qth_par_IntType( 3, Off ) ) ), "QSize" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ADDFILE )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
        /*
         * _public_functions_ : void  addFile ( const QString & fileName, const QSize & size = QSize(), Mode mode = Normal, State state = Off )
         */
        if( ( hb_pcount() <= 4 ) && qth_IsString( 1 ) && qth_Is( 2, "QSize", QTH_DEFAULT ) && qth_IsIntType( 3, "Mode", QTH_DEFAULT ) && qth_IsIntType( 4, "State", QTH_DEFAULT ) )
        {
            QString fileName =  qth_par_QString( 1 );
            const QSize& size = hb_param( 2, HB_IT_OBJECT ) ? qth_parConstRef<QSize>( 2 ) : QSize();
            p_icon->addFile( fileName, size, (Mode) qth_par_IntType( 3, Normal ), (State) qth_par_IntType( 4, Off ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ADDPIXMAP )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
        /*
         * _public_functions_ : void  addPixmap ( const QPixmap & pixmap, Mode mode = Normal, State state = Off )
         */
        if( ( hb_pcount() <= 3 ) && qth_IsObject( 1, "QPixmap" ) && qth_IsIntType( 2, "Mode", QTH_DEFAULT ) && qth_IsIntType( 3, "State", QTH_DEFAULT ) )
        {
            const QPixmap & pixmap = * static_cast<QPixmap *>( qth_par_QthObject( 1 ) );
            p_icon->addPixmap( pixmap, (Mode) qth_par_IntType( 2, Normal ), (State) qth_par_IntType( 3, Off ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( AVAILABLESIZES )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
        /*
         * _public_functions_ : QList<QSize>  availableSizes ( Mode mode = Normal, State state = Off ) const
         */
        if( ( hb_pcount() <= 2 ) && qth_IsIntType( 1, "Mode", QTH_DEFAULT ) && qth_IsIntType( 2, "State", QTH_DEFAULT ) )
        {
            // ! Don't know how to return type 'QList'
            // qth_itemPushNewReturn( QtH::QList, new QList<QSize>( p_icon->availableSizes( (Mode) qth_par_IntType( 1, Normal ), (State) qth_par_IntType( 2, Off ) ) ), "QList<QSize>" );
            qth_errRT_UNKNOWNOBJ( "QIcon::availableSizes", "Don't know how to return type 'QList'" ) ;
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( CACHEKEY )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
        /*
         * _public_functions_ : qint64  cacheKey () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retnll( p_icon->cacheKey() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ISNULL )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
        /*
         * _public_functions_ : bool  isNull () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_icon->isNull() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( NAME )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
#if QT_VERSION >= 0x040700
        /*
         * _public_functions_ : QString  name () const
         */
        if( hb_pcount() == 0 )
        {
            qth_ret_QString( p_icon->name() );
            return;
        }
#endif  /* QT_VERSION >= 0x040700 */
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( PAINT )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
        /*
         * _public_functions_ : void  paint ( QPainter * painter, const QRect & rect, Qt::Alignment alignment = Qt::AlignCenter, Mode mode = Normal, State state = Off ) const
         */
        if( ( hb_pcount() <= 5 ) && qth_IsObject( 1, "QPainter" ) && qth_IsObject( 2, "QRect" ) && qth_IsIntType( 3, "Qt::Alignment", QTH_DEFAULT ) && qth_IsIntType( 4, "Mode", QTH_DEFAULT ) && qth_IsIntType( 5, "State", QTH_DEFAULT ) )
        {
            const QRect & rect = * static_cast<QRect *>( qth_par_QthObject( 2 ) );
            p_icon->paint( static_cast<QPainter *>( qth_par_QthObject( 1 ) ), rect, (Qt::Alignment) qth_par_IntType( 3, Qt::AlignCenter ), (Mode) qth_par_IntType( 4, Normal ), (State) qth_par_IntType( 5, Off ) );
            hb_ret();
            return;
        }
        /*
         * _public_functions_ : void  paint ( QPainter * painter, int x, int y, int w, int h, Qt::Alignment alignment = Qt::AlignCenter, Mode mode = Normal, State state = Off ) const
         */
        if( ( hb_pcount() <= 8 ) && qth_IsObject( 1, "QPainter" ) && qth_Is( 2, HB_IT_INTEGER ) && qth_Is( 3, HB_IT_INTEGER ) && qth_Is( 4, HB_IT_INTEGER ) && qth_Is( 5, HB_IT_INTEGER ) && qth_IsIntType( 6, "Qt::Alignment", QTH_DEFAULT ) && qth_IsIntType( 7, "Mode", QTH_DEFAULT ) && qth_IsIntType( 8, "State", QTH_DEFAULT ) )
        {
            p_icon->paint( static_cast<QPainter *>( qth_par_QthObject( 1 ) ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ), (Qt::Alignment) qth_par_IntType( 6, Qt::AlignCenter ), (Mode) qth_par_IntType( 7, Normal ), (State) qth_par_IntType( 8, Off ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( PIXMAP )
{
    QIcon* p_icon = static_cast<QIcon *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_icon )
    {
        /*
         * _public_functions_ : QPixmap  pixmap ( const QSize & size, Mode mode = Normal, State state = Off ) const
         */
        if( ( hb_pcount() <= 3 ) && qth_IsObject( 1, "QSize" ) && qth_IsIntType( 2, "Mode", QTH_DEFAULT ) && qth_IsIntType( 3, "State", QTH_DEFAULT ) )
        {
            const QSize & size = * static_cast<QSize *>( qth_par_QthObject( 1 ) );
            qth_itemPushNewReturn( QtH::QPixmap, new QPixmap( p_icon->pixmap( size, (Mode) qth_par_IntType( 2, Normal ), (State) qth_par_IntType( 3, Off ) ) ), "QPixmap" );
            return;
        }
        /*
         * _public_functions_ : QPixmap  pixmap ( int w, int h, Mode mode = Normal, State state = Off ) const
         */
        if( ( hb_pcount() <= 4 ) && qth_Is( 1, HB_IT_INTEGER ) && qth_Is( 2, HB_IT_INTEGER ) && qth_IsIntType( 3, "Mode", QTH_DEFAULT ) && qth_IsIntType( 4, "State", QTH_DEFAULT ) )
        {
            qth_itemPushNewReturn( QtH::QPixmap, new QPixmap( p_icon->pixmap( hb_parni( 1 ), hb_parni( 2 ), (Mode) qth_par_IntType( 3, Normal ), (State) qth_par_IntType( 4, Off ) ) ), "QPixmap" );
            return;
        }
        /*
         * _public_functions_ : QPixmap  pixmap ( int extent, Mode mode = Normal, State state = Off ) const
         */
        if( ( hb_pcount() <= 3 ) && qth_Is( 1, HB_IT_INTEGER ) && qth_IsIntType( 2, "Mode", QTH_DEFAULT ) && qth_IsIntType( 3, "State", QTH_DEFAULT ) )
        {
            qth_itemPushNewReturn( QtH::QPixmap, new QPixmap( p_icon->pixmap( hb_parni( 1 ), (Mode) qth_par_IntType( 2, Normal ), (State) qth_par_IntType( 3, Off ) ) ), "QPixmap" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_FROMTHEME )
{
    /*
     * _static_public_members_ : QIcon  fromTheme ( const QString & name, const QIcon & fallback = QIcon() )
     */
    if( ( hb_pcount() <= 2 ) && qth_IsString( 1 ) && qth_Is( 2, "QIcon", QTH_DEFAULT ) )
    {
        QString name =  qth_par_QString( 1 );
        const QIcon& fallback = hb_param( 2, HB_IT_OBJECT ) ? qth_parConstRef<QIcon>( 2 ) : QIcon();
        qth_itemPushNewReturn( QtH::QIcon, new QIcon( QIcon::fromTheme( name, fallback ) ), "QIcon" );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_HASTHEMEICON )
{
    /*
     * _static_public_members_ : bool  hasThemeIcon ( const QString & name )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString name =  qth_par_QString( 1 );
        hb_retl( QIcon::hasThemeIcon( name ) == true );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_SETTHEMENAME )
{
    /*
     * _static_public_members_ : void  setThemeName ( const QString & name )
     */
    if( ( hb_pcount() == 1 ) && qth_IsString( 1 ) )
    {
        QString name =  qth_par_QString( 1 );
        QIcon::setThemeName( name );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_SETTHEMESEARCHPATHS )
{
    /*
     * _static_public_members_ : void  setThemeSearchPaths ( const QStringList & paths )
     */
    if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QStringList" ) )
    {
        const QStringList & paths = * static_cast<QStringList *>( qth_par_QthObject( 1 ) );
        QIcon::setThemeSearchPaths( paths );
        hb_ret();
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_THEMENAME )
{
    /*
     * _static_public_members_ : QString  themeName ()
     */
    if( hb_pcount() == 0 )
    {
        qth_ret_QString( QIcon::themeName() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_THEMESEARCHPATHS )
{
    /*
     * _static_public_members_ : QStringList  themeSearchPaths ()
     */
    if( hb_pcount() == 0 )
    {
        // ! Don't know how to return type 'QStringList'
        // qth_itemPushNewReturn( QtH::QStringList, new QStringList( QIcon::themeSearchPaths() ), "QStringList" );
        qth_errRT_UNKNOWNOBJ( "QIcon::themeSearchPaths", "Don't know how to return type 'QStringList'" ) ;
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_E_NORMAL )
{
    /*
     * _static_public_members_ : Normal
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QIcon::Mode", "Normal", Normal );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_E_DISABLED )
{
    /*
     * _static_public_members_ : Disabled
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QIcon::Mode", "Disabled", Disabled );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_E_ACTIVE )
{
    /*
     * _static_public_members_ : Active
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QIcon::Mode", "Active", Active );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_E_SELECTED )
{
    /*
     * _static_public_members_ : Selected
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QIcon::Mode", "Selected", Selected );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_E_OFF )
{
    /*
     * _static_public_members_ : Off
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QIcon::State", "Off", Off );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QICON_E_ON )
{
    /*
     * _static_public_members_ : On
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "QIcon::State", "On", On );
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

    hb_clsAdd( uiClass, "NEW"                , HB_FUNCNAME( NEW                       ) );
    hb_clsAdd( uiClass, "ACTUALSIZE"         , HB_FUNCNAME( ACTUALSIZE                ) );
    hb_clsAdd( uiClass, "ADDFILE"            , HB_FUNCNAME( ADDFILE                   ) );
    hb_clsAdd( uiClass, "ADDPIXMAP"          , HB_FUNCNAME( ADDPIXMAP                 ) );
    hb_clsAdd( uiClass, "AVAILABLESIZES"     , HB_FUNCNAME( AVAILABLESIZES            ) );
    hb_clsAdd( uiClass, "CACHEKEY"           , HB_FUNCNAME( CACHEKEY                  ) );
    hb_clsAdd( uiClass, "ISNULL"             , HB_FUNCNAME( ISNULL                    ) );
    hb_clsAdd( uiClass, "NAME"               , HB_FUNCNAME( NAME                      ) );
    hb_clsAdd( uiClass, "PAINT"              , HB_FUNCNAME( PAINT                     ) );
    hb_clsAdd( uiClass, "PIXMAP"             , HB_FUNCNAME( PIXMAP                    ) );
    hb_clsAdd( uiClass, "FROMTHEME"          , HB_FUNCNAME( QICON_FROMTHEME           ) );
    hb_clsAdd( uiClass, "HASTHEMEICON"       , HB_FUNCNAME( QICON_HASTHEMEICON        ) );
    hb_clsAdd( uiClass, "SETTHEMENAME"       , HB_FUNCNAME( QICON_SETTHEMENAME        ) );
    hb_clsAdd( uiClass, "SETTHEMESEARCHPATHS", HB_FUNCNAME( QICON_SETTHEMESEARCHPATHS ) );
    hb_clsAdd( uiClass, "THEMENAME"          , HB_FUNCNAME( QICON_THEMENAME           ) );
    hb_clsAdd( uiClass, "THEMESEARCHPATHS"   , HB_FUNCNAME( QICON_THEMESEARCHPATHS    ) );
    hb_clsAdd( uiClass, "E_NORMAL"           , HB_FUNCNAME( QICON_E_NORMAL            ) );
    hb_clsAdd( uiClass, "E_DISABLED"         , HB_FUNCNAME( QICON_E_DISABLED          ) );
    hb_clsAdd( uiClass, "E_ACTIVE"           , HB_FUNCNAME( QICON_E_ACTIVE            ) );
    hb_clsAdd( uiClass, "E_SELECTED"         , HB_FUNCNAME( QICON_E_SELECTED          ) );
    hb_clsAdd( uiClass, "E_OFF"              , HB_FUNCNAME( QICON_E_OFF               ) );
    hb_clsAdd( uiClass, "E_ON"               , HB_FUNCNAME( QICON_E_ON                ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */
