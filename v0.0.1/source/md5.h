#ifndef MD5_H
#define MD5_H

/*************************** HEADER FILES ***************************/
#include <stddef.h>

/****************************** MACROS ******************************/
#define MD5_BLOCK_SIZE 16               // MD5 outputs a 16 byte digest

/**************************** DATA TYPES ****************************/
typedef unsigned char BYTE;             // 8-bit byte
typedef unsigned int  WORD;             // 32-bit word, change to "long" for 16-bit machines

typedef struct {
   BYTE data[64];
   WORD datalen;
   unsigned long long bitlen;
   WORD state[4];
} MD5_CTX;

/*********************** FUNCTION DECLARATIONS **********************/
void md5_init(MD5_CTX *ctx);
void md5_update(MD5_CTX *ctx, const BYTE data[], size_t len);
void md5_final(MD5_CTX *ctx, BYTE hash[]);

void* gc_alloc(int bytes);
void* md5_context_allocate() {
   return gc_alloc(sizeof(MD5_CTX));
}

void md5_init_binded(void* ctx) {
   md5_init((MD5_CTX*)ctx);
}

void md5_update_binded(void *ctx, const BYTE data[], size_t len) {
   md5_update((MD5_CTX*)ctx, data, len);
}

void md5_final_binded(void *ctx, BYTE hash[]) {
   md5_final((MD5_CTX*)ctx, hash);
}

#endif   // MD5_H
