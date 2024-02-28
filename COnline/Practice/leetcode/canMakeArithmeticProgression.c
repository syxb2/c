#include <stdio.h>

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    for (int i = 0; i < arrSize - 1; ++i) {
        for (int j = 0; j < arrSize - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int c = arr[1] - arr[0];
    for (int i = 0; i < arrSize - 1; ++i) {
        if (arr[i + 1] - arr[i] == c) {
            ;
        }
        else return 0;
    }
    return 1;
}

int main() {
    int arr[5] = { 2, 3, 4, 5, 6 };
    int arrSize = 5;
    canMakeArithmeticProgression(arr, arrSize);

    // for (int i = 0; i < arrSize; ++i) {
      // printf("%d", arr[i]);
    // }
    // printf("%d\n", cd);

    return 0;
}
