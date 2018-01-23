#ifndef AES_H_
#define AES_H_

#include <string.h>
#include <stdlib.h>

#include "ffmath.h"

void cipher(byte *input, byte *output, byte *key, int n_k);
void inverse_cipher(byte *input, byte *output, byte *key, int n_k);

#endif