cmake_minimum_required(VERSION 3.15.0)
project(cmake_language)

function(barrier title)
    message("======== ${title} ========")
endfunction()

###############
#  variables  #
###############

# simple reference
barrier("simple reference")

set(var1 "var1_value")
message(${var1})

# nested reference
barrier("nested reference")

set(var_first "this is me, the FIRST variable")
set(var_second "this is me, the SECOND variable")

set(var_selector "first")
message("var selector: ${var_selector}")
message(${var_${var_selector}})

set(var_selector "second")
message("var selector: ${var_selector}")
message(${var_${var_selector}})

# scope
barrier("scope")

set(directory_var "directory-variable")
set(persistent_cache_var "persistent-cache-variable" CACHE STRING "variable description for gui users")
function(variable_scope_weak_demo)
    set(function_var "function-variable")
    message(${function_var})
    message(${directory_var})
    message(${persistent_cache_var})
endfunction()
variable_scope_weak_demo()

# lists
barrier("lists")

set(list_var a)
set(list_var ${list_var} b)
set(list_var ${list_var} c)
list(APPEND list_var d e f)
message("${list_var}")

list(FIND list_var "d" index)
list(GET list_var ${index} found_value)
message(${found_value})

list(JOIN list_var "," comma_separated_list)
message(${comma_separated_list})

list(LENGTH list_var list_length)
message(${list_length})

list(REVERSE list_var)
message("${list_var}")

list(SORT list_var)
message("${list_var}")

########################
#  control structures  #
########################

# conditional blocks
barrier("conditional blocks")

set(control_flow "1")
if(${control_flow} STREQUAL "1")
    message("entered if")
elseif(${control_flow} STREQUAL "2")
    message("entered 1st elseif")
elseif(${control_flow} STREQUAL "3")
    message("entered 2nd elseif")
else()
    message("entered else")
endif()

if(1)   # ON, YES, TRUE, Y, <non-zero number>
    message("entered the if statement, constant evaluates to true")
endif()

if("ON")
    message("ON - evaluate to true")
endif()

if("string with non-true constant value")
    message(FATAL_ERROR "oops, we should not have entered here")
else()
    message("\"string with non-true constant value\" - evaluates to false")
endif()

if(NOT FALSE)
    message("NOT FALSE - evaluates to true")
endif()

if(FALSE OR TRUE)
    message("FALSE OR TRUE - evaluates to true")
endif()

if(ON AND (NO OR YES))
    message("ON AND (NO OR YES) - evaluates to true")
endif()

set(list1 "item1;item2;item3")
if("item3" IN_LIST list1)
    message([["item3" IN_LIST list1 - evaluates to true]])
endif()

# loops
barrier("loops")

foreach(item a b c)
    message(${item})
endforeach()
message("")

foreach(item a;b;c;)
    message(${item})
endforeach()

set(list1 item1;item2;item3)
set(list2 item4 item5)
foreach(item IN LISTS list1 list2)
    message(${item})
endforeach()

set(list1 1;2;3;4;5;6;7;8;9;10)
foreach(x IN LISTS list1)
    if(${x} STREQUAL "7")
        continue()
    endif()
    if(${x} STREQUAL "10")
        break()
    endif()
    message(${x})
endforeach()

# functions
barrier("functions")

function(func_with_no_args)
    message("func_with_no_args()")
endfunction()
func_with_no_args()

function(func_with_one_required_arg arg1)
    message("func_with_one_required_arg() - arg1=${arg1}")
endfunction()
func_with_one_required_arg("1st-argument")
# func_with_one_required_arg() --> Error

function(func_with_optional_args)
    message("func_with_optional_args() - args-count: ${ARGC}")
    message("func_with_optional_args() - ${ARGV}")
endfunction()
func_with_optional_args()
func_with_optional_args(1)
func_with_optional_args(1 2)    # no commas

set(args_list 1;2;3)
func_with_optional_args("${args_list}")
func_with_optional_args(${args_list})

function(func_with_required_and_optional_args arg1 arg2)
    message("func_with_required_and_optional_args() - ${arg1} ${arg2}")
    message("func_with_required_and_optional_args() - ${ARGN}")
endfunction()
func_with_required_and_optional_args("a" "b")
func_with_required_and_optional_args("a" "b" "c")

barrier("end of demo")
