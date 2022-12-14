cmake_minimum_required(VERSION 3.15.0)
project(calculator)

# set the scripts dir
set(SCRIPTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/scripts)

# select the math library (int/float)
set(math_lib_type "int" CACHE STRING "Math library type")

# build the math libraries
add_subdirectory(math_lib_int)
add_subdirectory(math_lib_float)

# build the calculator
add_executable(calculator calculator.c)

# link the math library to the calculator
target_link_libraries(calculator math_lib_${math_lib_type})

# build the tester
add_subdirectory(tester)
