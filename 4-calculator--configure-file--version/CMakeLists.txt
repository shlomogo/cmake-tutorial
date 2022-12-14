cmake_minimum_required(VERSION 3.15.0)
project(calculator)

# set calculator version
set(CALC_VERSION_MAJOR 2)
set(CALC_VERSION_MINOR 15)

# create the version header
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.h.in ${CMAKE_BINARY_DIR}/version.h)

# build the math library
add_subdirectory(math_lib)

# build the calculator
add_executable(calculator calculator.c)

# link the math library to the calculator
target_link_libraries(calculator math_lib)

# familiarize the calculator target with the version header
target_include_directories(calculator PRIVATE ${CMAKE_BINARY_DIR})
