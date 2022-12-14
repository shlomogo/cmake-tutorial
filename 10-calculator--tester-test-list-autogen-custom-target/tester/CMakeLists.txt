set(TESTER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# include tester cmake utils
include(tester.cmake)

# set the tester autogen filenames and mark the c file as auto-generated
set(TESTER_AUTOGEN_CODE ${CMAKE_BINARY_DIR}/tester_autogen.c)
set(TESTER_AUTOGEN_HEADER ${CMAKE_BINARY_DIR}/test_ids.h)
set_source_files_properties(${TESTER_AUTOGEN_CODE} PROPERTIES GENERATED TRUE)

# build the tester
add_executable(tester tester.c tester_assert.c ${TESTER_AUTOGEN_CODE})

# familiarize the tester with the test_ids header
target_include_directories(tester PRIVATE ${CMAKE_BINARY_DIR})

# build the tests
add_subdirectory(tests)

# create autogen files
create_autogen_files(${TESTER_AUTOGEN_CODE} ${TESTER_AUTOGEN_HEADER})
