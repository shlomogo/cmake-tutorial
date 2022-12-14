import argparse

def create_tester_autogen_file(test_list, filename):
    with open(filename, 'w') as file:
        # create the test function declarations
        for test in test_list:
            file.write(f'void {test}();\n')

        file.write('\n')

        # create the array of test functions
        file.write('typedef void (*test_func)();\n\n')
        file.write('const test_func test_list[] =\n{\n')

        for test in test_list:
            file.write(f'    {test},\n')

        file.write('};\n')

        # create the array size variable
        file.write(f'const int test_list_size = {len(test_list)};\n')

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--test-list', nargs='+', required=True, help='list of test names')
    parser.add_argument('--out', required=True, help='output filename')

    args = parser.parse_args()
    create_tester_autogen_file(args.test_list, args.out)


if __name__ == '__main__':
    main()
