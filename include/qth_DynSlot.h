/*
 * $Id: qth_DynSlot.h 131 2011-04-20 15:56:14Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#ifndef __QTH_DYNSLOT_H__
#define __QTH_DYNSLOT_H__

#include <QHash>
#include <QList>
#include <QObject>

#include "qtharbour.h"

class DynSlot
{

public:
    virtual void call(  QObject* sender, void** arguments ) = 0;
};


class DynObject: public QObject
{

public:
    DynObject( QObject* parent = 0 ) : QObject( parent ) {}

    virtual int qt_metacall( QMetaObject::Call _c, int _id, void** _a );

    bool connectDynSlot_Block( QObject *obj, const char* signal, PHB_ITEM pBlock, Qt::ConnectionType type );
    bool connectDynSlot_Method( QObject *obj, const char* signal, PHB_ITEM receiver, const char* method, Qt::ConnectionType type );

private:
    QHash<void*, int> slotBlockIdx;
    QHash<QByteArray, int> slotMthdIdx;
    QList<DynSlot *> slotList;
    QHash<QByteArray, int> signalIdx;
};

enum SlotType 
{
    byBlock,
    byMethod
};

class Slot : public DynSlot
{

public:
    Slot( PHB_ITEM pBlock );
    Slot( PHB_ITEM pReceiver, const char* methodName );
    ~Slot();
    
    void call( QObject* sender, void** arguments );

    SlotType slotType;
    
    PHB_ITEM pBlock;
    PHB_ITEM pReceiver;
    QByteArray methodName;
};

#endif
