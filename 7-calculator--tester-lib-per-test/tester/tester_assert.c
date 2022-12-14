#include <stdio.h>
#include <stdlib.h>
#include "tester_assert.h"

void _assert(int condition, char *filename, int line_number)
{
    if (!condition)
    {
        printf("Assertion failed at: %s:%d\n", filename, line_number);
        exit(1);
    }
}
