#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX    4294967295U


/**
 * @brief get the moved number 
 * 
 * @param value 
 * @param shift 
 * @return unsigned int 
 */
unsigned int decode(unsigned int value, int shift) {
    return value << (32 - shift);
}

/**
 * @brief if the number can be encoded
 * 
 * @param num 
 * @return bool 
 */
bool can_be_encoded(unsigned int num) {
    for (int i = 0; i <= 0xFF; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (decode(i, j * 2) == num) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    unsigned int K, m = 0, n = MAX;
    scanf("%u", &K);

    // if find the number K, return -1
    if (can_be_encoded(K)) {
        printf("-1\n");
        return 0;
    }

    // if not find the number K, find the number m and n
    // find the number m
    for (unsigned int i = K - 1; i > 0; --i) {
        if (can_be_encoded(i) && can_be_encoded(K - i)) {
            m = i;
            break;
        }
    }

    // find the number n
    for (unsigned int i = K + 1; i < MAX; ++i) {
        if (can_be_encoded(i) && can_be_encoded(i - K)) {
            n = i;
            break;
        }
    }

    if (m == 0 && n == MAX) {
        printf("-2\n");
        return 0;
    }
    printf("%u,%u,%u\n", K, m, n);


    return 0;
}