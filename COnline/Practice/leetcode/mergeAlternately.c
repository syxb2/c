#include <stdio.h>

char q[256];

char * mergeAlternately(char * word1, char * word2) {
  int t = 0;
  for (int i = 0; i < 256; ++i) {
    if (*word1 == '\0' && *word2 == '\0') {
      q[i] = '\0';
      break;
    }
    else if ((t == 0 && *word1 != '\0') || (*word2 == '\0')) {
      q[i] = *word1;
      ++word1;
      t = 1;
    }
    else if ((t == 1 && *word2 != '\0') || (*word1 == '\0')) {
      q[i] = *word2;
      ++word2;
      t = 0;
    }
  }

  return q;
}

int main() {
  char a[128] = "asdasd";
  char b[128];
  // scanf("%s", sa);
  scanf("%s", b);

  printf("%s\n", mergeAlternately(a, b));

  return 0;
}