cmake_minimum_required(VERSION 3.16)
project(DataStructures C)

set(CMAKE_C_STANDARD 99)

set(GFX_FLAGS "-lSDL -lSDL_gfx -lSDL_ttf")
set(OTIMIZATION_FLAGS "-O1")
set(COMPILE_FLAGS -Wall -Wextra -pedantic -std=c99 m)

add_executable(DataStructures src/main.c
        src/libs/gfx/gfx.c
        src/libs/gfx/gfx.h
        src/libs/List/List.c
        src/libs/List/List.h
        src/libs/Node/Node.c
        src/libs/Node/Node.h
        src/libs/Stack/Stack.c
        src/libs/Stack/Stack.h
        src/libs/Queue/Queue.c
        src/libs/Queue/Queue.h)

target_link_libraries(DataStructures ${GFX_FLAGS} ${OTIMIZATION_FLAGS} ${COMPILE_FLAGS})

