#!/bin/bash
set -ex

if [ $# -eq 1 ]; then
    g++ -c -g \
        -I ~/src/ArduinoFake/src \
        -I ~/src/cmock/src \
        -I /home/user/src/cmock/vendor/unity/src \
        -I . \
        mocks/*.c \
        ~/Arduino/libraries/RunningAverage/RunningAverage.cpp \
        ~/src/ArduinoFake/external/unity/unity-repo/src/unity.c \
        ~/src/ArduinoFake/src/*.cpp \
        ~/src/ArduinoFake/src/arduino/IPAddress.cpp \
        ~/src/ArduinoFake/src/arduino/noniso.c \
        ~/src/cmock/src/cmock.c
fi

g++ \
    -fdiagnostics-color=always \
    -DARDUINO=10813 \
    -DARDUINO_ARCH_AVR \
    -DARDUINO_AVR_UNO \
    -DF_CPU=16000000L \
    -D__AVR_ATmega328P__ \
    -D__AVR__ \
    -c -g -Os -w -std=gnu++11 \
    -Wno-error=narrowing -MMD -flto \
    -I ~/src/ArduinoFake/external/unity/unity-repo/src \
    -I ~/src/ArduinoFake/src \
    -I ~/Arduino/libraries/Encoder \
    -I ~/Arduino/libraries/FastLED/src \
    -I ~/Arduino/libraries/RunningAverage \
    -I ~/arduino-1.8.13/hardware/arduino/avr/libraries/EEPROM/src/ \
    -I ~/arduino-1.8.13/hardware/arduino/avr/variants/standard/ \
    -I . \
    -c main.cpp test.cpp

g++ -g *.o
