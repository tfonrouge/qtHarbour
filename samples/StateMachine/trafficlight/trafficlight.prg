
#include "qtHarbour.ch"

REQUEST QSignalTransition

CLASS LightWidget FROM QWidget
    //Q_OBJECT
HIDDEN:
    DATA color
    DATA m_on
EXPORTED:
    METHOD setOn( on )
    METHOD turnOn INLINE ::setOn( .T. )
    METHOD turnOff INLINE ::setOn( .F. )
    CONSTRUCTOR New
ENDCLASS

METHOD New( color, parent ) CLASS LightWidget
    Super:New( parent )
    ::color := QColor():New( color )
RETURN Self

METHOD PROCEDURE setOn( on ) CLASS LightWidget
//    LOCAL painter
//
//    painter := QPainter():New( Self )
//    
//    painter:setRenderHint( QPainter():e_Antialiasing )
//    //painter:setRenderHint( 1 )
//    painter:setPen( ::color )
//    painter:drawEllipse( 0, 0, ::width(), ::height() )
//
//    ? painter

    ? on, ::color:name
    ::setBackgroundRole( 7 )
    ::setForegroundRole( 2 )
    ::m_on := on

RETURN

STATIC FUNCTION createLightState( light, duration, parent )
    LOCAL lightState
    LOCAL timer
    LOCAL timing
    LOCAL done

    lightState := QState():New( parent )
    timer := QTimer():New( lightState )
    timer:setInterval( duration )
    timer:setSingleShot( .T. )
    timing := QState():New( lightState )
//    QObject():connect( timing, SIGNAL(entered()), light, SLOT(turnOn()) )
//    QObject():connect( timing, SIGNAL(entered()), timer, SLOT(start()) )
//    QObject():connect( timing, SIGNAL(exited()), light, SLOT(turnOff()) )
    timing:hbConnect( SIGNAL(entered()), {|| light:turnOn } )
    timing:hbConnect( SIGNAL(entered()), {|| timer:start } )
    timing:hbConnect( SIGNAL(exited()), {|| light:turnOff } )
    done := QFinalState():New( lightState )
    timing:addTransition( timer, SIGNAL(timeout()), done )
    lightState:setInitialState( timing )

RETURN lightState

CLASS TrafficLightWidget FROM QWidget
HIDDEN:
    DATA m_red, m_yellow, m_green
EXPORTED:
    METHOD redLight INLINE ::m_red
    METHOD yellowLight INLINE ::m_yellow
    METHOD greenLight INLINE ::m_green
    CONSTRUCTOR New
ENDCLASS

METHOD New( parent ) CLASS TrafficLightWidget
    LOCAL vbox
    LOCAL pal

    Super:New( parent )

    vbox := QVBoxLayout():New( Self )
    ::m_red := LightWidget():New( Qt():e_red )
    vbox:addWidget( ::m_red )
    ::m_yellow := LightWidget():New( Qt():e_yellow )
    vbox:addWidget( ::m_yellow )
    ::m_green := LightWidget():New( Qt():e_green )
    vbox:addWidget( ::m_green )
    pal := ::palette()
    AltD()
    pal:setColor( QPalette():e_Background, QColor():New("black") )
    AltD()
    //pal:setColor( QPalette():e_Background, QColor():New( "black" ) )
    ::setPalette( pal )
    ::setAutoFillBackground( .T. )

RETURN Self

CLASS TrafficLight FROM QWidget
    CONSTRUCTOR New
ENDCLASS

METHOD New( parent ) CLASS TrafficLight
    LOCAL vbox
    LOCAL widget
    LOCAL machine
    LOCAL redGoingYellow
    LOCAL yellowGoingGreen
    LOCAL greenGoingYellow
    LOCAL yellowGoingRed

    Super:New( parent )

    vbox := QVBoxLayout():New( Self )
    widget := TrafficLightWidget():New()
    vbox:addWidget( widget )
    vbox:setMargin( 0 )

    machine := QStateMachine():New( Self )
    redGoingYellow := createLightState( widget:redLight(), 3000 )
    redGoingYellow:setObjectName( "redGoingYellow" )
    yellowGoingGreen := createLightState( widget:yellowLight(), 1000 )
    yellowGoingGreen:setObjectName( "yellowGoingGreen" )
    redGoingYellow:addTransition( redGoingYellow, SIGNAL(finished()), yellowGoingGreen )
    greenGoingYellow := createLightState( widget:greenLight(), 3000 )
    greenGoingYellow:setObjectName( "greenGoingYellow" )
    yellowGoingGreen:addTransition( yellowGoingGreen, SIGNAL(finished()), greenGoingYellow )
    yellowGoingRed := createLightState( widget:yellowLight(), 1000 )
    yellowGoingRed:setObjectName( "yellowGoingRed" )
    greenGoingYellow:addTransition( greenGoingYellow, SIGNAL(finished()), yellowGoingRed )
    yellowGoingRed:addTransition( yellowGoingRed, SIGNAL(finished()), redGoingYellow )

    machine:addState( redGoingYellow )
    machine:addState( yellowGoingGreen )
    machine:addState( greenGoingYellow )
    machine:addState( yellowGoingRed )
    machine:setInitialState( redGoingYellow )
    machine:start()

RETURN Self

FUNCTION Main()
    LOCAL app
    LOCAL widget

    app := QApplication():New()

    widget := TrafficLight():New()
    widget:resize( 110, 300 )
    widget:show()

RETURN app:exec()


/*
 #include <QtGui>

 class LightWidget : public QWidget
 {
     Q_OBJECT
     Q_PROPERTY(bool on READ isOn WRITE setOn)
 public:
     LightWidget(const QColor &color, QWidget *parent = 0)
         : QWidget(parent), m_color(color), m_on(false) {}

     bool isOn() const
         { return m_on; }
     void setOn(bool on)
     {
         if (on == m_on)
             return;
         m_on = on;
         update();
     }

 public slots:
     void turnOff() { setOn(false); }
     void turnOn() { setOn(true); }

 protected:
     virtual void paintEvent(QPaintEvent *)
     {
         if (!m_on)
             return;
         QPainter painter(this);
         painter.setRenderHint(QPainter::Antialiasing);
         painter.setBrush(m_color);
         painter.drawEllipse(0, 0, width(), height());
     }

 private:
     QColor m_color;
     bool m_on;
 };

 class TrafficLightWidget : public QWidget
 {
 public:
     TrafficLightWidget(QWidget *parent = 0)
         : QWidget(parent)
     {
         QVBoxLayout *vbox = new QVBoxLayout(this);
         m_red = new LightWidget(Qt::red);
         vbox->addWidget(m_red);
         m_yellow = new LightWidget(Qt::yellow);
         vbox->addWidget(m_yellow);
         m_green = new LightWidget(Qt::green);
         vbox->addWidget(m_green);
         QPalette pal = palette();
         pal.setColor(QPalette::Background, Qt::black);
         setPalette(pal);
         setAutoFillBackground(true);
     }

     LightWidget *redLight() const
         { return m_red; }
     LightWidget *yellowLight() const
         { return m_yellow; }
     LightWidget *greenLight() const
         { return m_green; }

 private:
     LightWidget *m_red;
     LightWidget *m_yellow;
     LightWidget *m_green;
 };

 QState *createLightState(LightWidget *light, int duration, QState *parent = 0)
 {
     QState *lightState = new QState(parent);
     QTimer *timer = new QTimer(lightState);
     timer->setInterval(duration);
     timer->setSingleShot(true);
     QState *timing = new QState(lightState);
     QObject::connect(timing, SIGNAL(entered()), light, SLOT(turnOn()));
     QObject::connect(timing, SIGNAL(entered()), timer, SLOT(start()));
     QObject::connect(timing, SIGNAL(exited()), light, SLOT(turnOff()));
     QFinalState *done = new QFinalState(lightState);
     timing->addTransition(timer, SIGNAL(timeout()), done);
     lightState->setInitialState(timing);
     return lightState;
 }

 class TrafficLight : public QWidget
 {
 public:
     TrafficLight(QWidget *parent = 0)
         : QWidget(parent)
     {
         QVBoxLayout *vbox = new QVBoxLayout(this);
         TrafficLightWidget *widget = new TrafficLightWidget();
         vbox->addWidget(widget);
         vbox->setMargin(0);

         QStateMachine *machine = new QStateMachine(this);
         QState *redGoingYellow = createLightState(widget->redLight(), 3000);
         redGoingYellow->setObjectName("redGoingYellow");
         QState *yellowGoingGreen = createLightState(widget->yellowLight(), 1000);
         yellowGoingGreen->setObjectName("yellowGoingGreen");
         redGoingYellow->addTransition(redGoingYellow, SIGNAL(finished()), yellowGoingGreen);
         QState *greenGoingYellow = createLightState(widget->greenLight(), 3000);
         greenGoingYellow->setObjectName("greenGoingYellow");
         yellowGoingGreen->addTransition(yellowGoingGreen, SIGNAL(finished()), greenGoingYellow);
         QState *yellowGoingRed = createLightState(widget->yellowLight(), 1000);
         yellowGoingRed->setObjectName("yellowGoingRed");
         greenGoingYellow->addTransition(greenGoingYellow, SIGNAL(finished()), yellowGoingRed);
         yellowGoingRed->addTransition(yellowGoingRed, SIGNAL(finished()), redGoingYellow);

         machine->addState(redGoingYellow);
         machine->addState(yellowGoingGreen);
         machine->addState(greenGoingYellow);
         machine->addState(yellowGoingRed);
         machine->setInitialState(redGoingYellow);
         machine->start();
     }
 };

 int main(int argc, char **argv)
 {
     QApplication app(argc, argv);

     TrafficLight widget;
     widget.resize(110, 300);
     widget.show();

     return app.exec();
 }

 #include "main.moc"
*/
