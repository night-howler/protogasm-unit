cmake_minimum_required(VERSION 3.13)
#project(Hello)
set(CMAKE_CXX_STANDARD 11)
file(GLOB AFSRC ~/src/ArduinoFake/src/*.cpp)
add_subdirectory(ArduinoFake)
add_executable(protogasm
    main.cpp
    test.cpp
    mocks/Mockmain.c
    ~/Arduino/libraries/RunningAverage/RunningAverage.cpp
    ArduinoFake/external/unity/unity-repo/src/unity.c
    ${AFSRC}
    ArduinoFake/src/arduino/IPAddress.cpp
    ArduinoFake/src/arduino/noniso.c
    ~/src/cmock/src/cmock.c
    ~/src/ArduinoFake/src/ArduinoFake.cpp

    )

target_include_directories(protogasm PRIVATE
    ArduinoFake/external/unity/unity-repo/src
    ArduinoFake/src
    ~/Arduino/libraries/Encoder
    ~/Arduino/libraries/FastLED/src
    ~/Arduino/libraries/RunningAverage
    ~/arduino-1.8.13/hardware/arduino/avr/libraries/EEPROM/src
    ~/arduino-1.8.13/hardware/arduino/avr/variants/standard
    #/home/user/arduino-1.8.13/hardware/tools/avr/avr/include
    .
    /home/user/src/cmock/src
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
