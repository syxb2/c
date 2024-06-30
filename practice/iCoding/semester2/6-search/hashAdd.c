#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/**
 * 哈希表相关说明：
 * HASH_RESULT 类型为相关函数的返回类型
 * HashEntry 为哈希表所保存元素（即键值对 《key, value》）类型
 * HashTable 为哈希表，其中 bucket 指向大小为size的、元素类型为 HashEntry*的指针数组
 * 哈希表采用链地址法处理冲突
 * 请实现 hash_add_int 函数，向哈希表中添加元素，其中键类型为char*， 元素类型为int。在添加过程中，如果要添加的键值key已在哈希表中，且对应的值value也已存在，则函数返回 HASH_ALREADY_ADDED；如果要添加的键值key已在哈希表中，但对应的值value不同，则函数将value值更新到哈希表中，之后返回 HASH_REPLACED_VALUE；如果要添加的键值key不在哈希表中，则函数创建 HashEntry 类型，并将其加入到哈希表中，且函数返回 HASH_ADDED。本题所用的哈希函数如下：
 *
 * @param table
 * @param key
 * @param value
 * @return HASH_RESULT
 */
HASH_RESULT hash_add_int(HashTable *table, const char *key, int value) {
    // 计算键值对在哈希表中的索引
    long hash_value = hash_string(key);
    int i = hash_value % table->size;

    // p 记录 Hash 表中索引位置的值
    HashEntry* p = table->bucket[i];

    // 如果 Hash 表中存在这个键
    while (p != NULL) {
        if (strcmp(key, p->key.str_value) == 0) { 
            if (value == p->value.int_value) return HASH_ALREADY_ADDED;
            else if (value != p->value.int_value) {
                p->value.int_value = value;
                return HASH_REPLACED_VALUE;
            }
        }
        else {
            p = p->next;
        }
    }

    // 如果不存在这个键，即函数没有在 while 循环中返回。则创建新的元素 S，并将其插入哈希表
    HashEntry* S = (HashEntry*) malloc(sizeof(HashEntry));
    if (S == NULL) return HASH_ERROR;

    // 为 S 赋值
    S->value.int_value = value;
    S->key.str_value = (char *) malloc(sizeof(char) * strlen(key) + 1); // "+1" 是为了容纳 "\0"
    if (S->key.str_value == NULL) return HASH_ERROR;
    strcpy(S->key.str_value, key);

    // 将 S 插入 Hash 表：头插法
    S->next = table->bucket[i];
    table->bucket[i] = S;

    return HASH_ADDED;
}
