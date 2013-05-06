
#include "qtHarbour.ch"

REQUEST QRect
REQUEST MyWidget_Ctor

Q_CLASS MyWidget FROM QWidget

PROTECTED:

    METHOD paintEvent( event ) EXPORTED

EXPORTED:

//    METHOD New //MESSAGE MyWidget_New
    METHOD Ctor

Q_ENDCLASS

//METHOD New CLASS MyWidget
//    AltD()
//    Super:New()
//RETURN Self

METHOD PROCEDURE paintEvent( event ) CLASS MyWidget
    LOCAL painter
    LOCAL i
    LOCAL r,g,b
    LOCAL w,h
    LOCAL step
    LOCAL x,y

    step := 10

    painter := QPainter():New( Self )
    painter:setRenderHint( QPainter():e_Antialiasing() )

    w := ::width()
    h := ::height()

    painter:translate( QPoint():New( Int(w/2), Int(h/2) ) )

    FOR i:=1 TO ( 360 / step )

        r := Int( HB_Random( 255 ) )
        g := Int( HB_Random( 255 ) )
        b := Int( HB_Random( 255 ) )

        painter:setPen( QColor():New( r, g, b ) )

        y := Min( w, h )

        x := Int( y / 2  - ( y / 8 ) )

        painter:drawEllipse( -x, -x, x, x )

        painter:rotate( step/1 )

    NEXT

    HB_SYMBOL_UNUSED( event )

RETURN

FUNCTION Main()
    LOCAL app
    LOCAL widget

    app := QApplication():New()

    widget := MyWidget():New()
    
    QPushButton():New( widget )

    widget:show()

RETURN app:exec()
