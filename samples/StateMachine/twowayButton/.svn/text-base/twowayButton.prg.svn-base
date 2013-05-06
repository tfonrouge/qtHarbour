
REQUEST QSignalTransition

#include "qtHarbour.ch"

FUNCTION Main()
    LOCAL app
    LOCAL button
    LOCAL machine
    LOCAL off
    LOCAL on

    app := QApplication():New()

    button := QPushButton():New()
    machine := QStateMachine():New()

    off := QState():New()
    off:assignProperty( button, "text", "Off" )
    off:setObjectName( "off" )

    on := QState():New()
    on:setObjectName( "on" )
    on:assignProperty( button, "text", "On" )

    off:addTransition( button, SIGNAL(clicked()), on )
    on:addTransition( button, SIGNAL(clicked()), off )

    machine:addState( off )
    machine:addState( on )

    machine:setInitialState( off )
    machine:start()

    button:resize( 100, 50 )
    button:show()

RETURN app:exec()

/*
 int main(int argc, char **argv)
 {
     QApplication app(argc, argv);
     QPushButton button;
     QStateMachine machine;

     QState *off = new QState();
     off->assignProperty(&button, "text", "Off");
     off->setObjectName("off");

     QState *on = new QState();
     on->setObjectName("on");
     on->assignProperty(&button, "text", "On");

     off->addTransition(&button, SIGNAL(clicked()), on);
     on->addTransition(&button, SIGNAL(clicked()), off);

     machine.addState(off);
     machine.addState(on);

     machine.setInitialState(off);
     machine.start();

     button.resize(100, 50);
     button.show();
     return app.exec();
 }
*/
