set(TESTER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# include tester cmake utils
include(tester.cmake)

# build the tester
add_executable(tester tester.c tester_assert.c)

# build the tests
add_subdirectory(tests)

# link the tests to the tester
target_link_libraries(tester test_add test_sub test_mul test_div)
