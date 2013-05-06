
#include "qtharbour.h"

#include <QMainWindow>

void MyMainWindow::doSomething()
{
    PHB_ITEM pSelf = qth_itemListGet_HB( this );

    if( pSelf )
    {
	hb_objSendMsg( pSelf, "doSomething", 0 );
    }
}
