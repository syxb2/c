// #include <stdio.h>
// int main() {
//   float a, d;
//   char ch;
//   printf("Enter an expression: ");
//   scanf("%lf", &a);
//   while ((ch = getchar()) != '\n') {
//     scanf("%lf", &d);
//     switch (ch) {
//       case '+':
//         a = a + d;
//         break;
//       case '-':
//         a = a - d;
//         break;
//       case '*':
//         a = a * d;
//         break;
//       case '/':
//         a = a / d;
//         break;
//     }
//   }
//   printf("Value of expression: %f", a);
// }

#include <stdio.h>

int main() {
    float a = 0, b = 0;
    char sign;
    scanf("%lf", &b);
    while ((sign = getchar()) != '\n') {
        scanf("%lf", &a);
        switch (sign) {
            case '+':
                b = b + a;
                break;
            case '-':
                b = b - a;
                break;
            case '*':
                b = b * a;
                break;
            case '/':
                b = b / a;
                break;
        }
        a = b;
    }
    printf("%lf\n", a);

    return 0;
}