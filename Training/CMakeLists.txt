cmake_minimum_required(VERSION 3.20)


project(Training C)

include_directories(.)

add_library(Training STATIC SList.c SList.h )

add_executable(Runner main_slist.c)

target_link_libraries(Runner PRIVATE Training)