#include <tester_assert.h>
#include <math_lib_int.h>

void test_div()
{
    ASSERT(math_lib_int_div(1, 2) == 0);
    ASSERT(math_lib_int_div(-1, -2) == 0);
    ASSERT(math_lib_int_div(10, -10) == -1);
    ASSERT(math_lib_int_div(3, 2) == 1);
}
