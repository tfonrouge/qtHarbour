/*
 * $Id: alarm.prg 150 2012-10-20 22:33:26Z tfonrouge $
 *
 * Generates C++ sources from SIGNALS/SLOTS methods in Harbour prgs
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Francisco Perillo
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtHarbour.ch"

CLASS MyApp FROM QApplication
    DATA oSys
    DATA setting
    DATA text
    DATA oWnd
ENDCLASS

PROCEDURE Main()
    LOCAL app
    LOCAL clock, text2, btsyst
    LOCAL oMenuSys, oActShow, oActHide, oActHide1

    app := MyApp():New()

    qApp():oWnd := QMainWindow():New()
    qApp():oWnd:setWindowTitle( "Send to systray and alert..." )
    qApp():oWnd:resize( 250, 150 )

    qApp():text := Qlabel():New( qApp():oWnd )
    qApp():text:setText( "clocking..." )
    qApp():text:move( 100, 100 )

    qApp():setting := QTimeEdit():New( qApp():oWnd )
    qApp():setting:move( 100, 50 )

    text2:=Qlabel():New( qApp():oWnd )
    text2:setText( "Alarm at" )
    text2:move( 40, 50 )

    clock := QTimer():New()
    clock:hbConnect( SIGNAL( timeout() ), { || tick() } )
    clock:start( 1000 )

    btsyst := QPushButton():New( qApp():oWnd )
    btsyst:setText( "Hide to systray..." )
    btsyst:resize( 150, 25 )
    btsyst:move( 50, 25 )
    btsyst:Connect( btsyst, SIGNAL( clicked() ), qApp():oWnd, SLOT( hide() ) )

    oMenuSys := QMenu():New( qApp():oWnd )
    oMenuSys:setTitle( "Alert clock" )

    oActShow := oMenuSys:addAction( QIcon():New( hb_dirBase() + "Alarme.png" ), "&Show" )
    oActShow:Connect( oActShow, SIGNAL( triggered(bool) ), qApp():oWnd, SLOT( show() ) )

    oMenuSys:addSeparator()

    oActHide := oMenuSys:addAction( QIcon():New( hb_dirBase() + "Reduced Size.png" ), "&Hide" )
    oActHide:Connect( oActHide, SIGNAL( triggered(bool) ), qApp():oWnd, SLOT( hide() ) )

    oActHide1 := oMenuSys:addAction( QIcon():New( hb_dirBase() + "Standby.png" ), "&Quit" )
    oActHide1:Connect( oActHide1, SIGNAL( triggered(bool) ), qApp(), SLOT( quit() ) )

    qApp():oSys := QSystemTrayIcon():New( qApp():oWnd )
    qApp():oSys:setIcon( QIcon():New( hb_dirBase() + "Clock.png" ) )
    qApp():oSys:setContextMenu( oMenuSys )
    qApp():oSys:show() // show the systray icon and menu
    qApp():oSys:showMessage( "Harbour-QT", "This is Harbour-QT System Tray", 2, 10000 )

    app:exec()

    clock:stop()

RETURN

STATIC PROCEDURE tick()
    LOCAL set_time,set_hou,set_min,set_sec
    LOCAL cur_time,cur_hou,cur_min,cur_sec
    LOCAL oBox

    qApp():text:setText( time() )

    set_time = qApp():setting:time()
    set_hou = set_time:hour()
    set_min  = set_time:minute()
    set_sec  = set_time:second()

    cur_time = time()
    cur_hou = val( left(cur_time,2) )
    cur_min  = val( substr(cur_time,4,2) )
    cur_sec  = val( right(cur_time,2) )

    IF set_hou=cur_hou .AND. set_min=cur_min .AND. set_sec=cur_sec
        qApp():oSys:setIcon( QIcon():New( hb_dirBase() + "clock_green.png" ) )
        qApp():oSys:showmessage( "It's time to go", "run run run",  2, 50000 )

        oBox:= QMessageBox():New()
        oBox:setWindowTitle( "Alarm" )
        oBox:setInformativeText( "It's " + cur_time + " o'clock")
        oBox:exec()
    ENDIF
RETURN
