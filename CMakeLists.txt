cmake_minimum_required(VERSION 3.18.4)
project(gpioDriver C)

set(CMAKE_C_STANDARD 99)


#add_executable(gpioDriver main.c core/Driver.h core/src/Driver.c)
add_library(gpioDriver SHARED core/Driver.h core/src/Driver.c)

