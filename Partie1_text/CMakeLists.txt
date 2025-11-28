cmake_minimum_required(VERSION 4.0)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

add_executable(data_structure main.c
        slist.c
        slist.h
        btree.c
        btree.h)
