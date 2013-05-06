/*
 * $Id: qthQSize.wip 126 2011-04-12 15:44:57Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <QSize>


/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QSIZE );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QTHBASE );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QSIZE )
{ "QSIZE", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QSIZE )}, NULL },
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
{ "(_INITSTATICS_1)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QSIZE )

HB_FUNC( QSIZE )
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
     * _public_functions_ : QSize ()
     */
    if( hb_pcount() == 0 )
    {
        qth_itemPushReturn( QtH::QSize, new QSize() );
        return;
    }
    /*
     * _public_functions_ : QSize ( int width, int height )
     */
    if( ( hb_pcount() == 2 ) && qth_Is( 1, HB_IT_INTEGER ) && qth_Is( 2, HB_IT_INTEGER ) )
    {
        qth_itemPushReturn( QtH::QSize, new QSize( hb_parni( 1 ), hb_parni( 2 ) ) );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( BOUNDEDTO )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : QSize  boundedTo ( const QSize & otherSize ) const
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QSize" ) )
        {
            const QSize & otherSize = * static_cast<QSize *>( qth_par_QthObject( 1 ) );
            qth_itemPushNewReturn( QtH::QSize, new QSize( p_size->boundedTo( otherSize ) ), "QSize" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( EXPANDEDTO )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : QSize  expandedTo ( const QSize & otherSize ) const
         */
        if( ( hb_pcount() == 1 ) && qth_IsObject( 1, "QSize" ) )
        {
            const QSize & otherSize = * static_cast<QSize *>( qth_par_QthObject( 1 ) );
            qth_itemPushNewReturn( QtH::QSize, new QSize( p_size->expandedTo( otherSize ) ), "QSize" );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( HEIGHT )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : int  height () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_size->height() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ISEMPTY )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : bool  isEmpty () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_size->isEmpty() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ISNULL )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : bool  isNull () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_size->isNull() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( ISVALID )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : bool  isValid () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retl( p_size->isValid() == true );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( RHEIGHT )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : int &  rheight ()
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_size->rheight() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( RWIDTH )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : int &  rwidth ()
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_size->rwidth() );
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SCALE )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : void  scale ( int width, int height, Qt::AspectRatioMode mode )
         */
        if( ( hb_pcount() == 3 ) && qth_Is( 1, HB_IT_INTEGER ) && qth_Is( 2, HB_IT_INTEGER ) && qth_IsIntType( 3, "Qt::AspectRatioMode" ) )
        {
            p_size->scale( hb_parni( 1 ), hb_parni( 2 ), (Qt::AspectRatioMode)  qth_par_IntType( 3 ) );
            hb_ret();
            return;
        }
        /*
         * _public_functions_ : void  scale ( const QSize & size, Qt::AspectRatioMode mode )
         */
        if( ( hb_pcount() == 2 ) && qth_IsObject( 1, "QSize" ) && qth_IsIntType( 2, "Qt::AspectRatioMode" ) )
        {
            const QSize & size = * static_cast<QSize *>( qth_par_QthObject( 1 ) );
            p_size->scale( size, (Qt::AspectRatioMode)  qth_par_IntType( 2 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETHEIGHT )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : void  setHeight ( int height )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_INTEGER ) )
        {
            p_size->setHeight( hb_parni( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( SETWIDTH )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : void  setWidth ( int width )
         */
        if( ( hb_pcount() == 1 ) && qth_Is( 1, HB_IT_INTEGER ) )
        {
            p_size->setWidth( hb_parni( 1 ) );
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( TRANSPOSE )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : void  transpose ()
         */
        if( hb_pcount() == 0 )
        {
            p_size->transpose();
            hb_ret();
            return;
        }
    }
    qth_errRT_PARAM();
}

HB_FUNC_STATIC( WIDTH )
{
    QSize* p_size = static_cast<QSize *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );

    if( p_size )
    {
        /*
         * _public_functions_ : int  width () const
         */
        if( hb_pcount() == 0 )
        {
            hb_retni( p_size->width() );
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

    hb_clsAdd( uiClass, "NEW"       , HB_FUNCNAME( NEW        ) );
    hb_clsAdd( uiClass, "BOUNDEDTO" , HB_FUNCNAME( BOUNDEDTO  ) );
    hb_clsAdd( uiClass, "EXPANDEDTO", HB_FUNCNAME( EXPANDEDTO ) );
    hb_clsAdd( uiClass, "HEIGHT"    , HB_FUNCNAME( HEIGHT     ) );
    hb_clsAdd( uiClass, "ISEMPTY"   , HB_FUNCNAME( ISEMPTY    ) );
    hb_clsAdd( uiClass, "ISNULL"    , HB_FUNCNAME( ISNULL     ) );
    hb_clsAdd( uiClass, "ISVALID"   , HB_FUNCNAME( ISVALID    ) );
    hb_clsAdd( uiClass, "RHEIGHT"   , HB_FUNCNAME( RHEIGHT    ) );
    hb_clsAdd( uiClass, "RWIDTH"    , HB_FUNCNAME( RWIDTH     ) );
    hb_clsAdd( uiClass, "SCALE"     , HB_FUNCNAME( SCALE      ) );
    hb_clsAdd( uiClass, "SETHEIGHT" , HB_FUNCNAME( SETHEIGHT  ) );
    hb_clsAdd( uiClass, "SETWIDTH"  , HB_FUNCNAME( SETWIDTH   ) );
    hb_clsAdd( uiClass, "TRANSPOSE" , HB_FUNCNAME( TRANSPOSE  ) );
    hb_clsAdd( uiClass, "WIDTH"     , HB_FUNCNAME( WIDTH      ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */
