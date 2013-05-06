/*
 * $Id: qth_classes.h 148 2012-09-23 07:29:41Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

void        qth_itemListDel_CPP( PCPP_OBJECT cppObj, bool bDeleteWxObj = false );
PQTH_ITEM   qth_itemListGet_PQTH_ITEM( PCPP_OBJECT cppObj );
PQTH_ITEM   qth_itemListGet_PQTH_ITEM( PHB_ITEM pSelf );
PHB_ITEM    qth_itemListGet_HB( PCPP_OBJECT cppObj );
PCPP_OBJECT qth_itemListGet_CPP( PHB_ITEM pSelf, const char* inheritFrom = NULL );
void        qth_itemListReleaseAll();
void        qth_itemReturn( PCPP_OBJECT cppObj, const char* szClsName = NULL, QTHI_FLAG qthiFlag = QTHI_NONE );
void        qth_par_arrayInt( int param, int* arrayInt, const size_t len );
PCPP_OBJECT qth_par_QthObject( int param, QTHI_FLAG qthiFlag = QTHI_NONE );
void        qth_itemPushNewReturn( QtH::clsTypes clsId, PCPP_OBJECT cppObj, const char* szClsName );
PQTH_ITEM   qth_itemPushReturn( QtH::clsTypes clsId, PCPP_OBJECT cppObj );

/* generic qoutf for debug output */
void qoutf( const char* format, ... );
void qqoutf( const char* format, ... );

typedef struct _CONN_PARAMS
{
    bool force;
    int id;
    int lastId;
    qthEventType eventType;
    PHB_ITEM pItmActionBlock;
} CONN_PARAMS, *PCONN_PARAMS;

class DynObject;

/*
 QTH_ITEM class : Holds PHB_ITEM's and the eXtended Harbour Object associated
 Teo. Mexico 2011
 */
class QTH_ITEM
{
protected:
    void            deleteRawObject();
    bool            isQObject;
    bool            isQWidget;
    bool            isRawObject;
    PHB_ITEM        pSelf;
    bool            refCount;      // holds logical value for HB Object stored in pSelf counts for GC
public:
    QtH::clsTypes   clsId;
    bool            deleteCppObj;
    PCPP_OBJECT     cppObjectPtr;
    PHB_BASEARRAY   hbObjectArrayId;
    vector<PCONN_PARAMS> evtList;
    HB_USHORT       uiClass;
    DynObject*      dynObject;

    QTH_ITEM( PCPP_OBJECT cppObj, PHB_ITEM p, bool refCount );
    
    PHB_ITEM get_HBObject();
    void     hbo_SetRefCount( const bool refCount );

    ~QTH_ITEM();

};
