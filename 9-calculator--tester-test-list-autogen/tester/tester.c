#include <stdio.h>
#include <stdlib.h>

typedef void (*test_func)();

extern const test_func test_list[];
extern const int test_list_size;

int main()
{
    for (int i = 0; i < test_list_size; i++)
    {
        test_list[i]();
    }

    printf("Tests passed successfully!\n");
    return 0;
}
