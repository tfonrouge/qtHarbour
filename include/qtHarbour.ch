/*
 * $Id: qtHarbour.ch 151 2012-12-20 21:53:28Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#ifndef _QTHARBOUR_H_
#define _QTHARBOUR_H_

#xtranslate SIGNAL( <cSignal> ) => "2"+<"cSignal">
#xtranslate SLOT( <cSlot> ) => "1"+<"cSlot">

#include "hbclass.ch"
#include "property.ch"

#include "qthMainWindow.ch"

#xcommand SHOW WINDOW <wnd> => <wnd>:show()

#define Q_CLASS CLASS
#define Q_ENDCLASS ENDCLASS

#endif
