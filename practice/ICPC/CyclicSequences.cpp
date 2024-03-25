#include <stdio.h>
#include <iostream>
using namespace std;

char c[100000002];

int main() {
    int n, w;
    unsigned long long ti = 0;
    cin >> n >> w;
    int t = 8 * n / w, l = w / 8;
    for (int i = 0; i < l; i++) c[i] = 'a';
    for (int i = 0; ; i++) {
        for (int j = 0; j < l; j++) {
            if (c[j] > 'z') {
                c[j] = 'a';
                c[j + 1] += 1;
            }
            cout << c[j];
            ti++;
            if (ti == n) break;
        }
        if (ti == n) break;
        c[0]++;
    }
    return 0;
}