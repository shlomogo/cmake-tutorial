function(add_math_test name)
    # create the test library
    add_library(${name} ${ARGN})

    # familiarize the test library with the tester_assert header
    target_include_directories(${name} PRIVATE ${TESTER_DIR})

    # link the math library to the test library
    target_link_libraries(${name} math_lib_int)

    # link the test to the tester
    target_link_libraries(tester ${name})

    # add the test name to the tester's test-list property
    set_property(TARGET tester APPEND PROPERTY test_list ${name})
endfunction()

function(create_autogen_files filename)
    # get the list of test names
    get_target_property(test_list tester test_list)

    # add command to generate the files
    add_custom_command(
        OUTPUT ${filename}
        COMMAND python3 ${SCRIPTS_DIR}/tester_autogen.py
            --test-list ${test_list}
            --out       ${filename}
    )
endfunction()
