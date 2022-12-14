#include <stdio.h>
#include <stdint.h>
#include "math_lib/math_lib.h"

int main()
{
    int64_t res;
    int32_t a, b;
    char op;

    printf("Enter a math expression: ");
    scanf("%d %c %d", &a, &op, &b);

    switch (op)
    {
    case '+':
        res = math_lib_add(a, b);
        break;
    case '-':
        res = math_lib_sub(a, b);
        break;
    case '*':
        res = math_lib_mul(a, b);
        break;
    case '/':
        res = math_lib_div(a, b);
        break;
    }

    printf("%d %c %d = %ld\n", a, op, b, res);
    return 0;
}
