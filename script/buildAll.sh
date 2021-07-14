#!/bin/bash

export CUR=$PWD
#
#
#
function fail()
{
echo "********* FAIL ***********"
echo "********* FAIL ***********"
exit 4
}
#
#
#
function buildAll()
{
echo "** STARTING ARCH ${ARCH}:${MCU}"
for i in `ls  ../demoProject/`;
#for i in adc;
do
    cd $CUR
    echo "___________________________________"
    echo "$ARCH:$MCU => $i"
    echo "___________________________________"
    cd ../demoProject/$i
    rm -f ${SDK}
    ln -s $PWD/../../../${SDK} .
    rm -Rf build${ARCH}_${MCU}
    mkdir build${ARCH}_${MCU}
    cd build${ARCH}_${MCU}
    cmake -DLN_ARCH="${ARCH}" -DLN_MCU="${MCU}" .. || fail cmake
    make -j 6  || fail make
    cd $CUR
done
echo "** DONE FOR ARCH ${ARCH}:${MCU}"
}
export SDK=Arduino_gd32_freeRTOS

export ARCH=RISCV
export MCU=VF103
buildAll
export ARCH=ARM
export MCU=M3
buildAll
export ARCH=ARM
export MCU=M4
buildAll
echo "*** ALL DONE  OK ***"
