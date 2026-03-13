#ifndef MD2_H
#define MD2_H

/*************************** HEADER FILES ***************************/
#include <stddef.h>

/****************************** MACROS ******************************/
#define MD2_BLOCK_SIZE 16

/**************************** DATA TYPES ****************************/
typedef unsigned char BYTE;             // 8-bit byte

typedef struct {
   BYTE data[16];
   BYTE state[48];
   BYTE checksum[16];
   int len;
} MD2_CTX;

/*********************** FUNCTION DECLARATIONS **********************/
void md2_init(MD2_CTX *ctx);
void md2_update(MD2_CTX *ctx, const BYTE data[], size_t len);
void md2_final(MD2_CTX *ctx, BYTE hash[]);   // size of hash must be MD2_BLOCK_SIZE

void* gc_alloc(int bytes);
void* md2_context_allocate() {
   return gc_alloc(sizeof(MD2_CTX));
}

void md2_init_binded(void* ctx) {
   md2_init((MD2_CTX*)ctx);
}

void md2_update_binded(void *ctx, const BYTE data[], size_t len) {
   md2_update((MD2_CTX*)ctx, data, len);
}

void md2_final_binded(void *ctx, BYTE hash[]) {
   md2_final((MD2_CTX*)ctx, hash);
}

#endif   // MD2_H
