
#include "qtHarbour.ch"

CLASS MyApplication FROM QApplication
ENDCLASS

FUNCTION Main()
  LOCAL qtApp
  LOCAL widget
  LOCAL x,y,xLen,yLen:=0

  qtApp := MyApplication():New()

  ? "qApp:", qApp():ClassName

  widget := QWidget():New()
  widget:show()

  widget:setWindowTitle( "Hello world..." )

  ? widget:x, widget:y

  ? widget:getContentsMargins( @x, @y, @xLen, yLen )

  ? x, y, xLen, yLen

  qtApp:exec()

  ? "Finished..."

RETURN NIL
