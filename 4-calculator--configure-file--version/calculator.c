#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <version.h>
#include <math_lib.h>

int main(int argc, char *argv[])
{
    int64_t res;
    int32_t a, b;
    char op;

    if (argc == 2)
    {
        if (strcmp(argv[1], "--version") == 0)
        {
            printf("Version %d.%d\n", CALC_VERSION_MAJOR, CALC_VERSION_MINOR);
            exit(0);
        }
    }

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
