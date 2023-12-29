#include <stdio.h>

int main(int argc, char *argv[]) { // argc等于命令行参数（包括本身）的个数（argc-1 是命令行参数的个数）；argv代表命令的文本）
  for (int i = 0; i < argc; ++i)
    puts(argv[i]);

  return 0;
}

// baijiale@Bais-Mac Practice % gcc cmdline.c -o cli

// baijiale@Bais-Mac Practice % ./cli p1 p2 p3
// ./cli
// p1
// p2
// p3