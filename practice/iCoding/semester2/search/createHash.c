#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HashTable* create_hash(int size) {
    // initialization
    HashTable* S = (HashTable*) malloc(sizeof(HashTable));
    if (S == NULL) return NULL;

    S->bucket = (HashEntry**) malloc(sizeof(HashEntry*) * size);
    if (S->bucket == NULL) {
        free(S); return NULL;
    }

    memset(S->bucket, 0, size * sizeof(HashEntry*));  // 初始化桶内存为零

    S->size = size;
    S->last_error = HASH_OK;

    return S;
}
