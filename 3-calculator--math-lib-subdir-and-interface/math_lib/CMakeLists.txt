# build the math library
add_library(math_lib math_lib.c)

# expose the math library header directory to users
target_include_directories(math_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
