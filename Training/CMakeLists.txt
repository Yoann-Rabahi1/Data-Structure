cmake_minimum_required(VERSION 3.20)


project(Training C)

include_directories(.)

add_library(Training STATIC SList.c SList.h
        tree.c
        tree.h
        main_btree.c)

add_executable(Runner main_slist.c
        tree.c
        tree.h
        main_btree.c
        Queue.c
        Queue.h)

target_link_libraries(Runner PRIVATE Training)