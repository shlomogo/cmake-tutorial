set(TESTER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# include tester cmake utils
include(tester.cmake)

# set the tester autogen filename
set(TESTER_AUTOGEN_FILENAME ${CMAKE_BINARY_DIR}/tester_autogen.c)

# build the tester
add_executable(tester tester.c tester_assert.c ${TESTER_AUTOGEN_FILENAME})

# build the tests
add_subdirectory(tests)

# create autogen files
create_autogen_files(${TESTER_AUTOGEN_FILENAME})
