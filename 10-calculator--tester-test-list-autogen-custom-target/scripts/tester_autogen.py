import argparse
from pathlib import Path

def create_tester_autogen_header(test_list, filename):
    with open(filename, 'w') as file:
        # create include guards
        guard = Path(filename).stem.upper()
        file.write(f'#ifndef _{guard}_H_\n')
        file.write(f'#define _{guard}_H_\n\n')

        # create test_id enum
        file.write('typedef enum _test_id\n{\n')

        for i, test in enumerate(test_list, start=1):
            file.write(f'    TEST_ID_{test.upper()} = {i},\n')

        file.write('} test_id;\n\n')

        # create test_func definition
        file.write('typedef void (*test_func)();\n\n')

        # create test struct definition
        file.write(
            'typedef struct _test\n'
            '{\n'
            '    test_id id;\n'
            '    test_func test;\n'
            '} test;\n\n'
        )

        # close include guards
        file.write('#endif\n')

def create_tester_autogen_code(test_list, filename):
    with open(filename, 'w') as file:
        # include test_ids.h
        file.write('#include "test_ids.h"\n\n')

        # create the test function declarations
        for test in test_list:
            file.write(f'void {test}();\n')

        file.write('\n')

        # create the array of test functions
        file.write('const test test_list[] =\n{\n')

        for test in test_list:
            file.write(f'    {{ .id = TEST_ID_{test.upper()}, .test = {test} }},\n')

        file.write('};\n')

        # create the array size variable
        file.write(f'const int test_list_size = {len(test_list)};\n')

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--test-list', nargs='+', required=True, help='list of test names')
    parser.add_argument('--code', required=True, help='c file output name')
    parser.add_argument('--header', required=True, help='h file output name')

    args = parser.parse_args()
    create_tester_autogen_header(args.test_list, args.header)
    create_tester_autogen_code(args.test_list, args.code)


if __name__ == '__main__':
    main()
