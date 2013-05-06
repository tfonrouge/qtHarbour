
#include "qtHarbour.ch"

CLASS MyApp FROM QApplication
    DATA button
    DATA label
    DATA mainWindow
    DATA spinBox
ENDCLASS 

FUNCTION Main()
    LOCAL app
    LOCAL layout

    app := MyApp():New()

    layout := QVBoxLayout():New()

    qApp():mainWindow := QWidget():New()

    qApp():spinBox := QSpinBox():New()
    qApp():spinBox:setPrefix( "milliseconds: " )
    qApp():spinBox:setSingleStep( 100 )
    qApp():spinBox:setMaximum( 60000 )

    qApp():label := QLabel():New()

    qApp():button := QPushButton():New()
    qApp():button:setText( "Start Timer..." )

    qApp():label:setText( "Nothing happens..." )

    layout:addWidget( qApp():spinBox )
    layout:addWidget( qApp():label )
    layout:addWidget( qApp():button )

    qApp():mainWindow:setLayout( layout )

    qApp():button:hbConnect( SIGNAL(clicked()), {|| StartTimer() } )

    qApp():mainWindow:show()

    app:exec()

RETURN NIL

STATIC PROCEDURE StartTimer()
    LOCAL ms

    ms := qApp():spinBox:value

    IF ms > 0

        /* using protected public member (no C++ object is instanced here) */
        //QTimer():singleShot( ms, qApp(), SLOT(quit()) )
        /* this is also supported */
        QTimer_singleShot( ms, qApp(), SLOT(quit()) )

        qApp():label:setText( "Tic tac..." )
        qApp():button:setText( "Timer started..." )
        qApp():button:setEnabled( .F. )
        qApp():spinBox:setEnabled( .F. )
    ELSE
        QMessageBox():warning( qApp():mainWindow, "!", "SpinBox value must be > 0" )
    ENDIF

RETURN
