cmake_minimum_required(VERSION 3.15.0)
project(calculator)

# build the math library
add_library(math_lib math_lib/math_lib.c)

# build the calculator
add_executable(calculator calculator.c)

# link the math library to the calculator
target_link_libraries(calculator math_lib)
