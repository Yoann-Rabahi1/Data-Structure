cmake_minimum_required(VERSION 4.0)
project(TD1_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(TD1_1 main.c
        SList.h
        SList.c
        tree.h
        tree.c
        queue.c
        queue.h
)
