cmake_minimum_required(VERSION 3.20)
project(learn_c C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(make_test_file make_test_file.c)

add_executable(1_2_1 chapter_one/1_2_1.c)
add_executable(1_2_2 chapter_one/1_2_2.c)
add_executable(1_3_1 chapter_one/1_3_1.c)
add_executable(1_4_1 chapter_one/1_4_1.c)
add_executable(1_5_1 chapter_one/1_5_1.c)
add_executable(1_5_2 chapter_one/1_5_2.c)
add_executable(1_5_3 chapter_one/1_5_3.c)
add_executable(1_5_4 chapter_one/1_5_4.c)
add_executable(1_5_5 chapter_one/1_5_5.c)
add_executable(1_5_6 chapter_one/1_5_6.c)
add_executable(1_6_1 chapter_one/1_6_1.c)
add_executable(1_7_1 chapter_one/1_7_1.c)
add_executable(1_9_1 chapter_one/1_9_1.c)
add_executable(exercise_1_3 chapter_one/exercise_1_3.c)
add_executable(exercise_1_4 chapter_one/exercise_1_4.c)
add_executable(exercise_1_5 chapter_one/exercise_1_5.c)
add_executable(exercise_1_6 chapter_one/exercise_1_6.c)
add_executable(exercise_1_7 chapter_one/exercise_1_7.c)
add_executable(exercise_1_8 chapter_one/exercise_1_8.c)
add_executable(exercise_1_9 chapter_one/exercise_1_9.c)
add_executable(exercise_1_10 chapter_one/exercise_1_10.c)
add_executable(exercise_1_12 chapter_one/exercise_1_12.c)
add_executable(exercise_1_13 chapter_one/exercise_1_13.c)
add_executable(exercise_1_14 chapter_one/exercise_1_14.c)
add_executable(exercise_1_15 chapter_one/exercise_1_15.c)
add_executable(exercise_1_16 chapter_one/exercise_1_16.c)
add_executable(exercise_1_17 chapter_one/exercise_1_17.c)

add_executable(2_3 chapter_two/2_3.c)
add_executable(strlen_test chapter_two/strlen_test.c)
add_executable(atoi_test chapter_two/atoi_test.c)
add_executable(lower_test chapter_two/lower_test.c)
add_executable(rand_set chapter_two/rand_test.c)
add_executable(squeeze_test chapter_two/squeeze_test.c)
add_executable(strcat_test chapter_two/strcat_test.c)
add_executable(getbits_test chapter_two/getbits_test.c)
add_executable(bitcount_test chapter_two/bitcount_test.c)

add_executable(exercise_2_1 chapter_two/exercise_2_1.c)
add_executable(exercise_2_3 chapter_two/exercise_2_3.c)
add_executable(exercise_2_4 chapter_two/exercise_2_4.c)
add_executable(exercise_2_5 chapter_two/exercise_2_5.c)

add_executable(atoi_demo chapter_three/atoi_demo.c)

add_executable(chapter_four_demo chapter_four/chapter_four_demo.c)
add_executable(extern_demo chapter_four/extern_demo.c)
add_executable(static_inside_demo chapter_four/static_inside_demo.c)
add_executable(static_outside_demo chapter_four/static_outside_demo.c chapter_four/static_function.c)
add_executable(register_demo chapter_four/register_demo.c)

add_executable(chapter_five_demo chapter_five/chapter_five_demo.c)

target_link_libraries(exercise_2_3 m)