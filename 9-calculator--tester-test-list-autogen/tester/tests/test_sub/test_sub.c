#include <tester_assert.h>
#include <math_lib_int.h>

void test_sub()
{
    ASSERT(math_lib_int_sub(1, 2) == -1);
    ASSERT(math_lib_int_sub(-1, -2) == 1);
    ASSERT(math_lib_int_sub(10, -10) == 20);
    ASSERT(math_lib_int_sub(0, 0) == 0);
}
