#include <tester_assert.h>
#include <math_lib_int.h>

void test_add()
{
    ASSERT(math_lib_int_add(1, 2) == 3);
    ASSERT(math_lib_int_add(-1, -2) == -3);
    ASSERT(math_lib_int_add(10, -10) == 0);
    ASSERT(math_lib_int_add(0, 0) == 0);
}
