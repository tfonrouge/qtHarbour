@echo off
rem
rem Utility to build qtHarbour on Windows/MinGW
rem
rem $Id: build.bat 99 2011-03-23 22:48:37Z tfonrouge $
rem

qmake -o GNUmakefile.mingw

mingw32-make -f GNUmakefile.mingw %1
