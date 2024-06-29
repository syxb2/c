#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


long hash_string(const char *str) {
    long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    if (hash < 0)
        hash *= -1;
    return hash;
}

HASH_RESULT hash_add_int(HashTable *table, const char *key, int value) {

}
