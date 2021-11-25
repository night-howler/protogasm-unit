cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(ArduinoFake)
add_executable(protogasm
    main.cpp
    test.cpp
    RunningAverage/RunningAverage.cpp
    ArduinoFake/external/unity/unity-repo/src/unity.c
    cmock/src/cmock.c
    mocks/Mockmain.c
    )

target_include_directories(protogasm PRIVATE
    ArduinoFake/external/unity/unity-repo/src
    ArduinoFake/src
    Encoder
    FastLED/src
    RunningAverage
    arduino-1.8.13/hardware/arduino/avr/libraries/EEPROM/src
    arduino-1.8.13/hardware/arduino/avr/variants/standard
    #arduino-1.8.13/hardware/tools/avr/avr/include
    .
    cmock/src
    )
target_compile_definitions(protogasm PRIVATE
    ARDUINO=10813
    ARDUINO_ARCH_AVR
    ARDUINO_AVR_UNO
    F_CPU=16000000L
    __AVR_ATmega328P__
    __AVR__
    )
target_compile_options(protogasm PRIVATE -w -g)
target_link_libraries(protogasm PUBLIC ArduinoFake)
