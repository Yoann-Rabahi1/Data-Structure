cmake_minimum_required(VERSION 4.0)
project(stack C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(stack
        main.c
        stack.c
        stack.h)
