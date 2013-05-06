/*
 * $Id: ppfuncs.prg 151 2012-12-20 21:53:28Z tfonrouge $
 */

#include "qtHarbour.ch"

/*
    __qth_MainWindow
    Teo. Mexico 2012
*/
FUNCTION __qth_MainWindow( fromClass, parent, flags, cTitle, posX, posY, width, height, codeBlock_closeEvent )
    LOCAL oWnd

    IF Empty( fromClass )

        oWnd := QTHMainWindow():New( parent, flags )

    ELSE

        oWnd := &( fromClass + "()" ):New( parent, flags )

        IF !oWnd:IsDerivedFrom( "QTHMainWindow" )
            oWnd:IsNotDerivedFrom_QTHMainWindow()
        ENDIF

    ENDIF

    IF cTitle != NIL
        oWnd:setWindowTitle( cTitle )
    ENDIF

    IF posX != NIL .AND. posY != NIL
        oWnd:move( posX, posY )
    ENDIF

    IF width != NIL .AND. height != NIL
        oWnd:resize( width, height )
    ENDIF

    IF codeBlock_closeEvent != NIL
        oWnd:codeBlock_closeEvent := codeBlock_closeEvent
    ENDIF

    //containerObj():AddToParentList( oWnd )

RETURN oWnd
