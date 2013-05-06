/*
 * $Id: qtharbour.h 148 2012-09-23 07:29:41Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#ifndef QTHARBOUR_H
#define QTHARBOUR_H

#include "qtHarbour_global.h"

#include <QtGui>
#include <QHash>
#include <vector>

using namespace std;

class QTHARBOURSHARED_EXPORT QtHarbour 
{
public:
    QtHarbour();
};

#include "hbvmint.h"

#include "hbapi.h"
#include "hbapiitm.h"
#include "hbinit.h"
#include "hbapicls.h"
#include "hbvm.h"
#include "hbstack.h"
#include "hbapierr.h"

#include "hbchksum.h"

typedef void CPP_OBJECT;
typedef CPP_OBJECT* PCPP_OBJECT;

#define WXH_ERRBASE     8000
#define qthEventType QEvent

#define QTH_DEFAULT     (unsigned int) 0x00001
#define QTH_BYREF       (unsigned int) 0x00002
#define QTH_SINGLECHAR  (unsigned int) 0x00004

class QTH_ITEM;

typedef QTH_ITEM* PQTH_ITEM;

#define MAP_PHB_BASEARRAY   QHash<PHB_BASEARRAY, PQTH_ITEM>
#define MAP_QTHOBJECT       QHash<PCPP_OBJECT, PQTH_ITEM>
#define MAP_CRC32           QHash<long, PQTH_ITEM>
#define MAP_PHB_ITEM        QHash<PHB_ITEM, bool>

enum QTHI_FLAG {
    QTHI_NONE,
    QTHI_TRANSFER,
    QTHI_TRANSFERBACK
};

namespace QtH
{
    enum clsTypes
    {
#include "../.tmp/qth_clsTypes.inc"
    };
}

#include "qth_classes.h"

bool        qth_derivedConstructor();
void        qth_errRT_PARAM();
void        qth_errRT_UNKNOWNOBJ( const char* szFuncName, const char* szErrorMsg );
bool        qth_ObjIsDerivedFrom( PHB_ITEM pSelf, const char* szClsName );

bool        qth_IsArray( const int iParam );
bool        qth_IsIntType( const int iParam, const char* szIntType, const uint uiFlags = 0 );
bool        qth_IsObject( const int iParam, const char* szClsName = 0 );
bool        qth_IsString( const int iParam, const uint uiFlags = 0 );
bool        qth_IsVariant( const int iParam );
QString     qth_par_QString( const int iParam );
bool        qth_Is( const int iParam, const char* szClsName, const uint uiFlags = 0 );
bool        qth_Is( const int iParam, const long lhbType, const uint uiFlags = 0 );
int         qth_par_IntType( const int iParam, int iDefaultValue = 0 );
PHB_ITEM    qth_par_ObjDerivedFrom( const int iParam, const char* szClsName );
char        qth_par_SingleChar( const int iParam );
PQTH_ITEM   qth_par_QthItem( const int iParam );
QVariant    qth_par_QVariant( const int iParam );
void        qth_stor_QString( const QString& string, const int iParam );

void        qth_registerClassEnum( PHB_ITEM pSelf, const char* szEnumType, const char* szEnumName, const int iEnumValue );

void        qth_set_param_QthItemFlag( PQTH_ITEM qthItem, QTHI_FLAG qthiFlag );

const char* qth_symName( PHB_SYMB symbol );

void        qthClassObjCreator( PHB_SYMB symbols, const int iNumParentCls );
void        qthInitStatics( PHB_SYMB symbols, const int iNumParentCls );

template <class Q>
Q* qth_new( QtH::clsTypes clsType, Q* obj )
{
    return obj;
}

template <class Q>
Q& qth_par( const int iParam )
{
    Q& obj = *(Q*) qth_par_QthObject( iParam );
    return obj;
}

template <class Q>
Q* qth_parPtr( const int iParam, QTHI_FLAG qthiFlag = QTHI_NONE )
{
    return (Q*) qth_par_QthObject( iParam, qthiFlag );
}

template <class Q>
const Q* qth_parConstPtr( const int iParam )
{   
    const Q* obj = (Q*) qth_par_QthObject( iParam );
    return obj; 
}

template <class Q>
Q& qth_parRef( const int iParam )
{
    Q& obj = *(Q*) qth_par_QthObject( iParam );
    return obj;
}

template <class Q>
const Q& qth_parConstRef( const int iParam )
{
    const Q& obj = * static_cast<Q*> ( qth_par_QthObject( iParam ) );
    return obj;
}

const QStringList& qth_parConstRef_QStringList( const int iParam );

template <class Q>
QList<Q*> qth_par_QListPtr( const int iParam )
{
    QList<Q*> * list = (QList<Q*> *) ( iParam );
    return *list;
}

template <class Q>
QList<Q> qth_par_QList( const int iParam )
{
    QList<Q> * list = (QList<Q> *) qth_par_QthObject( iParam );
    return *list;
}

template <class Q>
QVector<Q*> qth_par_QVectorPtr( const int iParam )
{
    QVector<Q*> * vector = (QVector<Q*> *) qth_par_QthObject( iParam );
    return *vector;
}

template <class Q>
QVector<Q> qth_par_QVector( const int iParam )
{
    QVector<Q> * vector = (QVector<Q> *) qth_par_QthObject( iParam );
    return *vector;
}

template <class Q>
void qth_retPtr( Q* obj, const char* szClsName, QTHI_FLAG qthiFlag = QTHI_NONE )
{
    qth_itemReturn( (Q *) obj, szClsName, qthiFlag );
}

/*
 * this solves when functions returns a copy of the object in the stack
 * e.g.: QSize frameSize()
 */
template <class Q>
void qth_ret( Q* obj, const char* szClsName = NULL )
{
    qth_itemReturn( (Q *) obj, szClsName );
}

template <class Q>
void qth_retConstPtr( const Q* obj )
{
    qth_itemReturn( (Q *) obj );
}

template <class Q>
void qth_retRef( const Q& obj, const char* szClsName = 0, QTHI_FLAG qthiFlag = QTHI_NONE )
{
    qth_itemReturn( (Q *) &obj, szClsName, qthiFlag );
}

template <class Q>
void qth_ret_QList( QList<Q *> obj )
{
    qth_itemReturn( (Q *) &obj );
}

template <class Q>
void qth_ret_QList( QList<Q> obj )
{
    qth_itemReturn( (Q *) &obj );
}

template <class Q>
void qth_ret_QSet( QSet<Q *> obj )
{
    qth_itemReturn( (Q *) &obj );
}

template <class Q>
void qth_ret_QVector( QVector<Q *> obj )
{
    qth_itemReturn( (Q *) &obj );
}

template <class Q>
void qth_ret_QVector( QVector<Q> obj )
{
    qth_itemReturn( (Q *) &obj );
}

void qth_ret_QString( const QString& string );
void qth_ret_SingleChar( const char c );
void qth_ret_WId( WId id );
WId qth_par_WId( const int iParam );

#endif // QTHARBOUR_H
