#ifndef FFMATH_H_
#define FFMATH_H_

typedef unsigned char byte;

void ff_multiply_mat_vec(byte *vec, byte mat[][4], byte *result);
byte ff_multiply(byte a, byte b);
byte xtime(byte a);

#endif