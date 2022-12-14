#ifndef _MATH_H_
#define _MATH_H_

#if defined(MATH_LIB_FLOAT)
#include <math_lib_float.h>
#define MATH_ADD math_lib_float_add
#define MATH_SUB math_lib_float_sub
#define MATH_MUL math_lib_float_mul
#define MATH_DIV math_lib_float_div
#elif defined(MATH_LIB_INT)
#include <math_lib_int.h>
#define MATH_ADD math_lib_int_add
#define MATH_SUB math_lib_int_sub
#define MATH_MUL math_lib_int_mul
#define MATH_DIV math_lib_int_div
#else
#error "Missing a math library"
#endif

#endif
