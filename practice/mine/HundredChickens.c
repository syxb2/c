# include <stdio.h>

int main() {
    int x, y, z; //设 x为公鸡，y为母鸡，z为小鸡
    for (x = 0; x < 100; x++)
        for (y = 0; y < 100; y++)
            for (z = 0; z < 100; z += 3) {
                if (x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100) {
                    printf("公鸡：%d只  母鸡：%d只  小鸡：%d只\n", x, y, z);
                }
            }


    return 0;
}
