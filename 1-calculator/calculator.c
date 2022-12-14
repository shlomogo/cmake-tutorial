#include <stdio.h>
#include <stdint.h>

int64_t
add(int32_t a, int32_t b)
{
    return a + b;
}

int64_t
sub(int32_t a, int32_t b)
{
    return a - b;
}

int64_t
mul(int32_t a, int32_t b)
{
    return a * b;
}

int64_t
div(int32_t a, int32_t b)
{
    return a / b;
}

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
        res = add(a, b);
        break;
    case '-':
        res = sub(a, b);
        break;
    case '*':
        res = mul(a, b);
        break;
    case '/':
        res = div(a, b);
        break;
    }

    printf("%d %c %d = %ld\n", a, op, b, res);
    return 0;
}
