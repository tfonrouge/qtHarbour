/*
 * $Id:$
 */

#include "qtHarbour.ch"

FUNCTION Main()
  LOCAL qtApp
  LOCAL widget

  qtApp := QApplication():New()

  BuildWidgets( @widget )

  qtApp:exec()

RETURN NIL

PROCEDURE BuildWidgets( tableWidget )
  LOCAL tableWidgetItem
  LOCAL i,n

  n := 10

  tableWidget := QTableWidget():New( n, 2 )

  FOR i:=0 TO n-1
    tableWidgetItem := QTableWidgetItem():New( "Hello " + LTrim( Str( i ) ), 0 )
    tableWidget:setItem( i, 0, tableWidgetItem )
  NEXT

  tableWidget:show()

  ? "item(): ", tableWidget:item( 0, 0 ):text

  ? "moving items..."

  FOR i:=0 TO n-1
    IF (i % 2) = 0
      tableWidgetItem := tableWidget:takeItem( i, 0 )
      tableWidget:setItem( i, 1, tableWidgetItem )
    ENDIF
  NEXT

RETURN
