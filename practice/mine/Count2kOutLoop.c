#include <stdio.h>

#define OUT   '#' // 这句话的意思就是 OUT 是一个宏，它的值是 '#'。也就是 OUT 就等价于 '#'。


int main() {
    char circle[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    int k = 0;
    scanf("%d", &k);

    int j = 0, count = 0, outnum = 0; // j 是循环总次数, count 是报数的总次数, outnum 是出去的人数  

    while (outnum < 26) { 
        for (int i = 0; i < k; ++i, ++j) { // for 循环每次执行 k 次
        // j 就相当于一个指针，在数组中循环移动，遇到 OUT 就跳过，直到找到一个没有被淘汰的人
            if (circle[j % 26] == OUT) continue;

            ++count;
            if (count % k == 0) {
                printf("%c", circle[j % 26]);
                circle[j % 26] = OUT;
                ++outnum;
            }
        }
    }
    printf("\n");

    return 0;
}
