
#include "qtHarbour.ch"

FUNCTION Main()
    LOCAL app
    LOCAL widget
    LOCAL dial
    LOCAL label
    LOCAL vbox

    app := QApplication():New()

    widget := QWidget():New()

    vbox := QVBoxLayout():New()

    dial := QDial():New( widget )
    dial:setNotchesVisible( .T. )

    label := QLabel():New( "Hello" )

    vbox:addWidget( dial )
    vbox:addWidget( label )

    widget:setLayout( vbox )

    dial:hbConnect( SIGNAL(valueChanged(int)), {|| label:setText( Str( dial:value ) )  } )

    widget:show()

    app:exec()

RETURN NIL
