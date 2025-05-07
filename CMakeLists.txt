cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_SYSTEM_NAME Generic)

project(XMemCeckAVR)

set(CMAKE_C_FLAGS "-mmcu=at90can128") 
set(CMAKE_CXX_FLAGS "-mmcu=at90can128") 

add_definitions(-DF_CPU=16000000UL -DBAUD=115200)

add_executable(XMemCheckAVR src/main.cpp src/com/usart.cpp src/util/xmem.cpp)
