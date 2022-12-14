#include <tester_assert.h>
#include <math_lib_int.h>

void test_mul()
{
    ASSERT(math_lib_int_mul(1, 2) == 2);
    ASSERT(math_lib_int_mul(-1, -2) == 2);
    ASSERT(math_lib_int_mul(10, -10) == -100);
    ASSERT(math_lib_int_mul(0, 0) == 0);
}
