
#include "qtHarbour.ch"

FUNCTION Main()
    LOCAL app
    LOCAL widget

    app := QApplication():New()

    widget := QWidget():New()

    QBrush():New()
    QBrush():New( Qt():e_SolidPattern )
    QBrush():New( QColor():New() )
    QBrush():New( Qt():e_green )
    QBrush():New( QColor():New(), QPixmap():New() )
    QBrush():New( Qt():e_red, QPixmap():New() )
    QBrush():New( QPixmap():New() )
    QBrush():New( QImage():New() )
    QBrush():New( QBrush():New() )
    QBrush():New( QRadialGradient():New() )

    widget:show()

RETURN app:exec()
