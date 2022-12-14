set(TESTER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# include tester cmake utils
include(tester.cmake)

# build the tester
add_executable(tester tester.c tester_assert.c)

# build the tests
add_subdirectory(tests)

# get the final test list
get_target_property(test_list tester test_list)

# link the list of tests to the tester
target_link_libraries(tester ${test_list})
