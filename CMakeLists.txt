cmake_minimum_required(VERSION 3.20)
project(learn_c C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        ChapterOne/*.h
        ChapterTwo/exercise*.h
        ChapterThree/*.h
        )

add_executable(learn_c empty.c ${SOURCES})
add_executable(symbol_constants ChapterOne/1_4.c)
add_executable(strlen_test ChapterTwo/strlen_test.c)
add_executable(atoi_test ChapterTwo/atoi_test.c)
add_executable(lower_test ChapterTwo/lower_test.c)
add_executable(rand_test ChapterTwo/rand_test.c)
add_executable(squeeze_test ChapterTwo/squeeze_test.c)
add_executable(strcat_test ChapterTwo/strcat_test.c)
add_executable(getbits_test ChapterTwo/getbits_test.c)