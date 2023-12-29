#include <stdio.h>
#include <string.h>

char planets[][10] = {
  "Mercury",
  "Venus",
  "Earth",
  "Mars",
  "Jupiter",
  "Sature",
  "Neptune",
  "Uranus"
};

void print_planets(char pl[][10], int n) {
  for (int i = 0; i < n; ++i) {
    puts(pl[i]); // puts 可以自动换行 // pl[i] 中 i 指的是 行（只有一个中括号时，指行）
  }
}

void sort_planets(char pl[][10], int n) {
  int i, j;
  char t[10];
  for (i = 0; i < n - 1; ++i) {
    for (j = 0; j < n - i - 1; ++j) {
      if (strcmp(pl[j], pl[j + 1]) > 0) {
        strcpy(t, pl[j]);
        strcpy(pl[j], pl[j + 1]);
        strcpy(pl[j + 1], t);
      }
    }
  }
}

int main() {
  print_planets(planets, 8);
  sort_planets(planets, 8);
  print_planets(planets, 8);

  return 0;
}