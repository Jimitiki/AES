#include <inttypes.h>
#include <stdio.h>

#include "ffmath.h"

byte M_X = 0x1B;

void ff_multiply_mat_vec(byte *vec, byte mat[][4], byte *result)
{
	result[0] = ff_multiply(vec[0], mat[0][0]) ^ ff_multiply(vec[1], mat[0][1]) ^ ff_multiply(vec[2], mat[0][2]) ^ ff_multiply(vec[3], mat[0][3]);
	result[1] = ff_multiply(vec[0], mat[1][0]) ^ ff_multiply(vec[1], mat[1][1]) ^ ff_multiply(vec[2], mat[1][2]) ^ ff_multiply(vec[3], mat[1][3]);
	result[2] = ff_multiply(vec[0], mat[2][0]) ^ ff_multiply(vec[1], mat[2][1]) ^ ff_multiply(vec[2], mat[2][2]) ^ ff_multiply(vec[3], mat[2][3]);
	result[3] = ff_multiply(vec[0], mat[3][0]) ^ ff_multiply(vec[1], mat[3][1]) ^ ff_multiply(vec[2], mat[3][2]) ^ ff_multiply(vec[3], mat[3][3]);
}

byte ff_multiply(byte a, byte b)
{
	if (a == 1)
	{
		return b;
	}
	else if (b == 1)
	{
		return a;
	}
	byte multiplier = b;
	byte result = 0;
	byte xtime_value = a;
	while (multiplier)
	{
		//For every 1 in the multiplier bits, xor the current total with the xtime of the previous xtime
		if (multiplier & 0x01)
		{
			if (result == 0)
			{
				result = xtime_value;
			}
			else
			{
				result = result ^ xtime_value;
			}
		}
		xtime_value = xtime(xtime_value);
		multiplier = multiplier >> 1;
	}
	return result;
}

byte xtime(byte a)
{
	byte result = a << 1;
	if (a & 0x80) 						//If the most significant bit is set
	{
		result = result ^ M_X;
	}
	return result;
}