cmake_minimum_required(VERSION 3.10)
project(ev_project_starter_v2 C)

set(CMAKE_C_STANDARD 99)

set(SOURCES
        main.c
        csv_loader.c
        json_loader.c
        events.c
        rules.c
        slist.c
        stack.c
        queue.c
        nary.c
        station_index.c
)

add_executable(ev_project_starter_v2 ${SOURCES})
