/*
 * $Id: qtHarbour_global.h 131 2011-04-20 15:56:14Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#ifndef QTHARBOUR_GLOBAL_H
#define QTHARBOUR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTHARBOUR_LIBRARY)
#  define QTHARBOURSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTHARBOURSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTHARBOUR_GLOBAL_H
