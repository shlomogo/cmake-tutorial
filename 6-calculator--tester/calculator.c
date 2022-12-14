#include <stdio.h>
#include <stdint.h>
#include "math.h"

int main(int argc, char *argv[])
{
    double res;
    float a, b;
    char op;

    printf("Enter a math expression: ");
    scanf("%f %c %f", &a, &op, &b);

    switch (op)
    {
    case '+':
        res = MATH_ADD(a, b);
        break;
    case '-':
        res = MATH_SUB(a, b);
        break;
    case '*':
        res = MATH_MUL(a, b);
        break;
    case '/':
        res = MATH_DIV(a, b);
        break;
    }

    printf("%.02f %c %.02f = %.02lf\n", a, op, b, res);
    return 0;
}
