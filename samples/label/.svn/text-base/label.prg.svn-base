
//#include "qtHarbour.ch"

FUNCTION Main()
  LOCAL app
  LOCAL mainWindow
  LOCAL boxLayout
  LOCAL label
  LOCAL n

  app := QApplication():New()

  mainWindow := QWidget():New()

  boxLayout := QVBoxLayout():New()

  boxLayout:addWidget( QLabel():New( "Text label...", mainWindow ) )

  label := QLabel():New( mainWindow )
  boxLayout:addWidget( label )
  label:setNum( 10 )

  label := QLabel():New( mainWindow )
  boxLayout:addWidget( label )
  label:setNum( 3.14 )

  n := 1*(10^6)
  label := QLabel():New( mainWindow )
  boxLayout:addWidget( label )
  label:setNum( n )
  ? "n = ", n
  //label:setNum( 1e50 )

  mainWindow:setLayout( boxLayout )

  mainWindow:show()

  app:exec()

RETURN NIL
