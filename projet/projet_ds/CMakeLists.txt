cmake_minimum_required(VERSION 3.13)

project(projet_ds C)   # préciser que c'est un projet en C

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        main.c
        csv_loader.c
        Events.c
        nary.c
        Queue.c
        rules.c
        SList.c
        Stack.c
        station_index.c
)

add_executable(projet_ds ${SOURCE_FILES})


# Add executable target with source files listed in SOURCE_FILES variable
add_executable(projet_ds ${SOURCE_FILES})