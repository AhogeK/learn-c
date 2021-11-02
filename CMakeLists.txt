cmake_minimum_required(VERSION 3.20)
project(learn_c C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        ChapterOne/*.h
        ChapterOne/*.c
        ChapterTwo/*.h
        ChapterTwo/*.c
        ChapterThree/*.h
        ChapterThree/*.c
        )

add_executable(learn_c main.c ${SOURCES})
