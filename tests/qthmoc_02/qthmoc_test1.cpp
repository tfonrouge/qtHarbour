
#include "qtharbour.h"

class MyWidget : public QWidget
{
    Q_OBJECT

protected:

    virtual void paintEvent( QPaintEvent* event );

public:

};

void MyWidget::paintEvent( QPaintEvent* event )
{
    PHB_ITEM pSelf = qth_itemListGet_HB( this );

    if( pSelf )
    {
        PHB_ITEM pEvent = hb_itemNew( NULL );

        hb_objSendMsg( pSelf, "paintEvent", 1, pEvent );
        
        hb_itemRelease( pEvent );

        hb_ret();
        hb_gcCollectAll( true );
    }
    return;
}

HB_FUNC( MYWIDGET_CTOR )
{
    MyWidget* myWidget = new MyWidget;
    qth_itemPushReturn( QtH::QWidget, myWidget );
}

#include "qthmoc_test1.moc"
