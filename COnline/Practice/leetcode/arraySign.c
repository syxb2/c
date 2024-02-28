#include <stdio.h>

/*
int arraySign(int* nums, int numsSize) {
  int n = 1;
  for (int i = 0; i < numsSize; ++i) {
    n *= *nums;
    ++nums;
  }
  if (n < 0) return -1;
  else if (n == 0) return 0;
  else return 1;
}
*/

int arraySign(int* nums, int numsSize) {
    int n = 1;
    for (int i = 0; i < numsSize; ++i) {
        if (*nums < 0) {
            n *= -1;
        }
        else if (*nums == 0) {
            return 0;
        }
        ++nums;
    }
    if (n < 0) return -1;
    else if (n == 0) return 0;
    else return 1;
}

int main() {
    int nums[13] = { 9, 72, 34, 29, -49, -22, -77, -17, -66, -75, -44, -30, -24 };
    printf("%d\n", arraySign(nums, 13));
    // printf("%d\n", -1 * 1);

    return 0;
}