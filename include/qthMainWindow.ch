/*
 * $Id: qthMainWindow.ch 151 2012-12-20 21:53:28Z tfonrouge $
 */

#ifndef _QTHMAINWINDOW_H_
#define _QTHMAINWINDOW_H_

/*
 * QMainWindow
 */
#xcommand CREATE MAINWINDOW <wnd> ;
                    [ CLASS <fromClass> ] ;
                    [ PARENT <parent> ] ;
                    [ FLAGS <flags> ] ;
                    [ TITLE <cTitle> ] ;
                    [ FROM <posX>, <posY> ] [ WIDTH <width> ] [ HEIGHT <height> ] ;
                    [ STYLE <nStyle> ] ;
                    [ NAME <cName> ] ;
                    [ ON CLOSE <onClose> ] ;
                    => ;
                    <wnd> := __qth_MainWindow( [<fromClass>], [<parent>], [<flags>], [<cTitle>], [<posX>], [<posY>], [<width>], [<height>], [<{onClose}>] )

#endif
