#include <stdio.h>
#include <stdlib.h>
#include <math_lib_int.h>
#include "tester_assert.h"

/* tests for ADD */
static void test_add()
{
    ASSERT(math_lib_int_add(1, 2) == 3);
    ASSERT(math_lib_int_add(-1, -2) == -3);
    ASSERT(math_lib_int_add(10, -10) == 0);
    ASSERT(math_lib_int_add(0, 0) == 0);
}

/* tests for SUB */
static void test_sub()
{
    ASSERT(math_lib_int_sub(1, 2) == -1);
    ASSERT(math_lib_int_sub(-1, -2) == 1);
    ASSERT(math_lib_int_sub(10, -10) == 20);
    ASSERT(math_lib_int_sub(0, 0) == 0);
}

/* tests for MUL */
static void test_mul()
{
    ASSERT(math_lib_int_mul(1, 2) == 2);
    ASSERT(math_lib_int_mul(-1, -2) == 2);
    ASSERT(math_lib_int_mul(10, -10) == -100);
    ASSERT(math_lib_int_mul(0, 0) == 0);
}

/* tests for DIV */
static void test_div()
{
    ASSERT(math_lib_int_div(1, 2) == 0);
    ASSERT(math_lib_int_div(-1, -2) == 0);
    ASSERT(math_lib_int_div(10, -10) == -1);
    ASSERT(math_lib_int_div(3, 2) == 1);
}

int main()
{
    test_add();
    test_sub();
    test_mul();
    test_div();

    printf("Tests passed successfully!\n");
    return 0;
}
