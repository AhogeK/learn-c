cmake_minimum_required(VERSION 3.20)
project(learn_c C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        ChapterOne/*.h
        ChapterOne/*.c
        ChapterTwo/exercise*.h
        ChapterTwo/exercise*.c
        ChapterThree/*.h
        ChapterThree/*.c
        )

add_executable(learn_c main.c ${SOURCES})
add_executable(strlen_test ChapterTwo/strlen_test.c)
add_executable(atoi_test ChapterTwo/atoi_test.c)
add_executable(lower_test ChapterTwo/lower_test.c)
add_executable(rand_test ChapterTwo/rand_test.c)
add_executable(squeeze_test ChapterTwo/squeeze_test.c)
