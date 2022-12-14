function(add_math_test name)
    # create the test library
    add_library(${name} ${ARGN})

    # familiarize the test library with the tester_assert header
    target_include_directories(${name} PRIVATE ${TESTER_DIR})

    # link the math library to the test library
    target_link_libraries(${name} math_lib_int)

    # add the test name to the tester's test-list property
    set_property(TARGET tester APPEND PROPERTY test_list ${name})
endfunction()
