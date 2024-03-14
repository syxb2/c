#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int arr1[10] = { 0 };
        int arr2[10] = { 0 };
        char input1[101], input2[101];
        char *str1 = input1, *str2 = input2;
        scanf("%s", input1);
        scanf("%s", input2);

        for (; *str1 != '\0';) {
            int num = *str1 - '0';
            ++str1;
            ++arr1[num];
        }
        for (; *str2 != '\0';) {
            int num = *str2 - '0';
            ++str2;
            ++arr2[num];
        }

        int i = 1;
        while (i < 10) {
            if (arr1[i] == arr2[i]) {
                ++i;
            }
            else {
                break;
            }
        }
        if (i == 10) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}