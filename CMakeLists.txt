cmake_minimum_required(VERSION 3.10)
project(Embedded_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Embedded_1
        STD_TYPES.h
        BIT_MATH.h
        MemScanner.h
        MemScanner.c
        Message.h
        Message.c
        main.c)
