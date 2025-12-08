cmake_minimum_required(VERSION 3.20)


project(Training C)

include_directories(.)

add_library(Training STATIC SList.c SList.h Queue.c Queue.h
        tree.c
        tree.h
)

add_executable(Runner main_slist.c main_btree.c)

# Nouveau (Pour tester les arbres) :
target_link_libraries(Runner PRIVATE Training)