#!/usr/bin/qmake -Wall
#
# $Id: qtHarbour.pro 151 2012-12-20 21:53:28Z tfonrouge $
#
#-------------------------------------------------
# (C) Teo Fonrouge. WindTelSoft 2010
#-------------------------------------------------
# *
# * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
# * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
# *
#

include(qtHarbour.qmk)

QT += network webkit xml xmlpatterns

TARGET = qtHarbour
TEMPLATE = lib

CONFIG += staticlib

DEFINES += QTHARBOUR_LIBRARY

HBSOURCES = src/base/*.prg \
            src/hb/*.prg

WIPSOURCES += wip/*.wip

QTHSOURCES = src/hb/*.qth

SOURCES = src/base/*.cpp

HEADERS += include/*.h \
	   include/*.ch
