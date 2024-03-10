#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp, *out; // 生成文件指针

  fp = fopen("/Users/baijiale/Documents/VisualStudioCode/c/CProject/data.txt", "rt"); // rt代表用读模式打开文件
  if (!fp) { // fp若为空指针，则fp这个条件表达式为0
    fprintf(stderr, "cannot open file\n"); // 向文件打印
    exit(1);
  }

  out = fopen("/Users/baijiale/Documents/VisualStudioCode/c/CProject/rev-data.txt", "wt");

  int a, b, c;

  while (!feof(fp)) {
    fscanf(fp, "%d\t%d\t%d\n", &a, &b, &c); // 语法与scanf完全一样，只是不是从键盘读，而是从文件读
    fprintf(stdout, "%d\t%d\t%d\n", a, b, c); // stdout是标准输出文件；stdin是标准输入文件；stderr是标准出错文件
    fprintf(out, "%d\t%d\t%d\n", c, b, a);
  }

  fclose(fp);
  fclose(out); // 一定要关闭被写的文件，否则写入的内容可能丢失

  return 0;
}
