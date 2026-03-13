#ifndef BASE64_H
#define BASE64_H

/*************************** HEADER FILES ***************************/
#include <stddef.h>

/**************************** DATA TYPES ****************************/
typedef unsigned char BYTE;             // 8-bit byte

/*********************** FUNCTION DECLARATIONS **********************/
// Returns the size of the output. If called with out = NULL, will just return
// the size of what the output would have been (without a terminating NULL).
size_t base64_encode(const BYTE in[], BYTE out[], size_t len, int newline_flag);

// Returns the size of the output. If called with out = NULL, will just return
// the size of what the output would have been (without a terminating NULL).
size_t base64_decode(const BYTE in[], BYTE out[], size_t len);

#endif   // BASE64_H
