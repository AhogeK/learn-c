cmake_minimum_required(VERSION 3.20)
project(learn_c C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(1_2_1 ChapterOne/1_2_1.c)
add_executable(1_2_2 ChapterOne/1_2_2.c)
add_executable(1_3_1 ChapterOne/1_3_1.c)
add_executable(1_4_1 ChapterOne/1_4_1.c)
add_executable(1_5_1 ChapterOne/1_5_1.c)
add_executable(1_5_2 ChapterOne/1_5_2.c)
add_executable(1_5_3 ChapterOne/1_5_3.c)
add_executable(1_5_4 ChapterOne/1_5_4.c)
add_executable(1_5_5 ChapterOne/1_5_5.c)
add_executable(1_5_6 ChapterOne/1_5_6.c)

add_executable(2_3 ChapterTwo/2_3.c)
add_executable(strlen_test ChapterTwo/strlen_test.c)
add_executable(atoi_test ChapterTwo/atoi_test.c)
add_executable(lower_test ChapterTwo/lower_test.c)
add_executable(rand_set ChapterTwo/rand_test.c)
add_executable(squeeze_test ChapterTwo/squeeze_test.c)
add_executable(strcat_test ChapterTwo/strcat_test.c)
add_executable(getbits_test ChapterTwo/getbits_test.c)
add_executable(bitcount_test ChapterTwo/bitcount_test.c)

add_executable(exercise_2_1 ChapterTwo/exercise_2_1.c)
add_executable(exercise_2_3 ChapterTwo/exercise_2_3.c)
add_executable(exercise_2_4 ChapterTwo/exercise_2_4.c)
add_executable(exercise_2_5 ChapterTwo/exercise_2_5.c)

add_executable(atoi_demo ChapterThree/atoi_demo.c)

add_executable(extern_demo.c ChapterFour/extern_demo.c)

target_link_libraries(exercise_2_3 m)