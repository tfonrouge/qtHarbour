/*
 * $Id:$
 *
 * Simple app with one Window
 */

#include "qtHarbour.ch"

FUNCTION Main()
  LOCAL app
  LOCAL wnd

  app := QApplication():New()

  CREATE MAINWINDOW wnd ;
    WIDTH 800 HEIGHT 600 ;
    TITLE "window01.prg" ;
    ON CLOSE {|| .T. }

  SHOW WINDOW wnd

  app:exec()

RETURN NIL
