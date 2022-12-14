# build the tester
add_executable(tester tester.c tester_assert.c)

# link the tested library to the tester
target_link_libraries(tester math_lib_int)
