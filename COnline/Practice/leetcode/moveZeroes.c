#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int *front = nums + 1;
    int *p = nums;
    int *q = front;
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = 0; j < numsSize - 1; ++j) {
            if (*front != 0 && *nums == 0) {
                int t = *front;
                *front = *nums;
                *nums = t;
            }
            ++nums, ++front;
        }
        nums = p;
        front = q;
    }
}

int main() {
    const int n = 5;
    int arr[n] = { 0, 1, 0, 3, 12 };
    moveZeroes(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}