# build the math library
add_library(math_lib_int math_lib_int.c)

# expose the math library header directory to users
target_include_directories(math_lib_int INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# expose a special definition to users that marks the usage of this library
target_compile_definitions(math_lib_int INTERFACE MATH_LIB_INT)
