#ifndef _TESTER_ASSERT_H_
#define _TESTER_ASSERT_H_

void _assert(int condition, char *filename, int line_number);
#define ASSERT(x) _assert((x), __FILE__, __LINE__)

#endif