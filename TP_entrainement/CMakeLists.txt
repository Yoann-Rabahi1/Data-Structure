cmake_minimum_required(VERSION 4.0)
project(V1 C)

set(CMAKE_C_STANDARD 11)

add_executable(V1 main.c
        slist.c
        slist.h)
