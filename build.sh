#!/bin/bash
#
# $Id: build.sh 142 2012-08-06 17:50:54Z tfonrouge $
#

platform="`uname`"
qthproject="qtHarbour.pro"
makefile="GNUmakefile.${platform}"
QMAKE=""
MAKE="`which make`"
cmdline="${MAKE} -f ${makefile} ${*}"

if [ -e "/usr/bin/qmake" ] ; then
  QMAKE="/usr/bin/qmake"
fi

if [[ -z "$QMAKE" && -e "/usr/bin/qmake-qt4" ]] ; then
  QMAKE="/usr/bin/qmake-qt4"
fi

if [ -z "$QMAKE" ] ; then
  QMAKE="`which qmake`"
fi

echo "Build utility for qtHarbour"
echo

echo "Platform: ${platform}"
echo "   QMake: ${QMAKE}"
echo "    make: ${MAKE}"
echo "    .pro: ${qthproject}"
echo "makefile: ${makefile}"
echo

build_mac()
{
  cmd="${QMAKE} -Wall -Wlogic -spec macx-g++ -o ${makefile} ${qthproject}"
  echo ${cmd}
  ${cmd}
}

build_linux()
{
  cmd="${QMAKE} -o ${makefile} ${qthproject}"
  echo ${cmd}
  ${cmd}
}


case ${platform} in
  Darwin)
    build_mac
    ;;
  Linux)
    build_linux
    ;;
  *)
    echo "Unable to build qtHarbour: Unknown platform..."
    exit
    ;;
esac

echo "building:"
echo

echo ${cmdline}

${cmdline}
