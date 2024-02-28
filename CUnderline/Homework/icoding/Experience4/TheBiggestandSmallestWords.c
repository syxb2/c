#include <stdio.h>
#include <string.h>

int main() {
    char arr[20] = { '\0' }, max[20] = { 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', '\0' }, min[20] = { '\0' }, temp[20] = { '\0' };
    int i = 0;
    do {
        for (int j = 0; j < 20; ++j) {
            arr[j] = '\0';
        };
        while ((arr[i] = getchar()) != '\n') {
            ++i;
        }
        strcpy(temp, arr);
        if (strcmp(arr, max) < 0) {
            strcpy(max, arr);
        }
        if (strcmp(arr, min) > 0) {
            strcpy(min, arr);
        }
        i = 0;
    } while (strlen(arr) != 5);

    int m = 0, n = 0;
    printf("Smallest word:");
    while (max[m] != '\n') {
        printf("%c", max[m]);
        ++m;
    }
    printf("\n");

    printf("Largest word:");
    while (min[n] != '\n') {
        printf("%c", min[n]);
        ++n;
    }
    printf("\n");

    return 0;
}