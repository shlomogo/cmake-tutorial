#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <test_ids.h>

extern const test test_list[];
extern const int test_list_size;

void run_test_by_id(test_id id)
{
    for (int i = 0; i < test_list_size; i++)
    {
        if (id == test_list[i].id)
        {
            test_list[i].test();
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        if (strcmp(argv[1], "-t") != 0)
        {
            printf("Unexpected argument: %s\n", argv[1]);
            exit(1);
        }

        int id = atoi(argv[2]);
        if (id == 0 || id > test_list_size)
        {
            printf("Invalid test id: %s\n", argv[2]);
            exit(1);
        }

        run_test_by_id((test_id)id);
    }
    else
    {
        for (int i = 0; i < test_list_size; i++)
        {
            test_list[i].test();
        }
    }

    printf("Tests passed successfully!\n");
    return 0;
}
