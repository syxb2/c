// #include <stdio.h>

// double ave_f(double *p, int a, int ave) {
//   for (int i = 0; i < a; i++) {
//     ave += *p;
//     ++p;
//   }
//   ave = ave / a;

//   return ave;
// }

// int mount_f(int a, double *p, int mount, int ave) {
//   for (int i = 0; i < a; i++) {
//     if (*p < ave) {
//       mount += 1;
//       p++;
//     }
//   }

//   return mount;
// }

// int main() {
//   // int n, peoamount = 0, i = 0;
//   // double average = 0.0;
//   int n = 0, i = 0;

//   scanf("%d", &n);
//   double arr[n];
//   // scanf("%ld", );

//   for (i = 0; i < n; i++) {
//     scanf("%lf", &arr[i]);
//   }

//   /*求平均*/

//   // average_f (arr, n);
//   // for (i = 0; i < n; i++) {
//   //   average += arr[i];
//   // }
//   // average = average / n;

//   /*把上一板块写成函数*/
//   // average = ave_f(arr, n, 0);

//   /*求低于平均分的人数*/

//   // for (i = 0; i < n; i++) {
//   //   if (arr[i] < average)
//   //     peoamount += 1;
//   // }

//   /*把上一板块写成函数*/
//   // peoamount = mount_f(n, arr, 0, average);

//   printf("%.1lf\n%d\n", ave_f(arr, n, 0), mount_f(n, arr, 0, ave_f(arr, n, 0)));


//   return 0;
// }

#include <stdio.h>

double ave_f(double *p, int a, double ave) {
  for (int i = 0; i < a; i++) {
    ave += *p;
    ++p;
  }
  ave = ave / a;

  return ave;
}

int mount_f(int a, double *p, int mount, int ave) {
  for (int i = 0; i < a; i++) {
    if (*p < ave) {
      mount += 1;
    }
    ++p;
  }

  return mount;
}

int main() {
  int n = 0, i = 0;  scanf("%d", &n);
  double arr[n];
  for (i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }

  printf("%.1lf\n%d\n", ave_f(arr, n, 0.0), mount_f(n, arr, 0, ave_f(arr, n, 0)));

  return 0;
}