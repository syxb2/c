#include <stdio.h>

bool isMonotonic(int* nums, int numsSize) {
    int i = 0;
    while (i < numsSize - 1) {
        if (i < numsSize - 1 && nums[i] == nums[i + 1]) {
            ++i;
        }
        else if (nums[i] < nums[i + 1]) {
            while (i < numsSize - 1 && nums[i] <= nums[i + 1]) {
                ++i;
            }
            if (i == numsSize - 1) return 1;
            else return 0;
        }
        else if (nums[i] > nums[i + 1]) {
            while (i < numsSize - 1 && nums[i] >= nums[i + 1]) {
                ++i;
            }
            if (i == numsSize - 1) return 1;
            else return 0;
        }
    }
    if (i == numsSize - 1) return 1;
    else return 0;
}

int main() {
    int nums[5] = { 0, 0, 0, 0, 1 };
    printf("%d\n", isMonotonic(nums, 5) ? 1 : 0);

    return 0;
}