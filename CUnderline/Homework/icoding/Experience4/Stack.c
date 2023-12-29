#include <stdbool.h>   /* C99 only */ // 引入stdbool.h，这是C99标准中才有的  
#include <stdio.h>      // 引入标准输入输出头文件  
#include <stdlib.h>     // 引入标准库头文件  

#define STACK_SIZE 100   // 定义栈的大小为100  

/* external variables */ // 定义外部变量  
char contents[STACK_SIZE]; // 存储栈内容的字符数组  
int top = 0; // 栈顶指针，初始化为0  
int bottom = 0;

// 定义函数stack_overflow()，当栈溢出时调用该函数  
void stack_overflow(void) {
  printf("Stack overflow\n"); // 打印栈溢出的提示信息  
  exit(EXIT_FAILURE); // 结束程序运行，返回失败状态  
}

// 定义函数stack_underflow()，当栈下溢时调用该函数  
void stack_underflow(void) {
  printf("Stack underflow\n"); // 打印栈下溢的提示信息  
  exit(EXIT_FAILURE); // 结束程序运行，返回失败状态  
}

// 定义函数make_empty()，用于清空栈  
void make_empty(void) {
  top = 0; // 将栈顶指针重置为0，表示栈为空  
}

// 定义函数is_empty()，判断栈是否为空  
bool is_empty(void) {
  return top == 0; // 如果栈顶指针为0，则栈为空，返回true；否则返回false  
}

// 定义函数is_full()，判断栈是否已满  
bool is_full(void) {
  return top == STACK_SIZE; // 如果栈顶指针等于栈的大小，则栈已满，返回true；否则返回false  
}

// 定义函数push()，用于将字符压入栈中  
void push(char ch) {
  if (is_full()) // 如果栈已满，调用stack_overflow()函数处理溢出情况  
    stack_overflow();
  else
    contents[top++] = ch; // 将字符压入栈中，并将栈顶指针加1  
}

// 定义函数pop()，用于从栈中取出字符  
char pop(void) {
  if (is_empty()) // 如果栈为空，调用stack_underflow()函数处理下溢情况  
    stack_underflow();
  else
    return contents[--top]; // 从栈中取出字符，并将栈顶指针减1，返回取出的字符  

  return '\0'; // 如果调用stack_underflow()函数，则返回空字符，防止编译器警告（stack_underflow()调用后未返回任何值）
}

// 主函数main()，程序的入口点
int main() {
  char arr[128];
  scanf("%s", arr);
  int j = 0;
  // while (arr[i] != '\0' && (arr[i] == '(' || arr[i] == '{')) {
  //   push(arr[i]);
  //   ++i;
  // }
  while (arr[j] != '\0') {
    if (arr[j] == '(' || arr[j] == '{') {
      push(arr[j]);
      ++j;
    }
    else if (arr[j] == ')') {
      if (is_empty()) {
        printf("Parentheses/braces are NOT nested properly\n");
        return 0;
      }
      else {
        if (pop() != '(') {
          printf("Parentheses/braces are NOT nested properly\n");
          return 0;
        }
      }
      ++j;
    }
    else if (arr[j] == '}') {
      if (is_empty()) {
        printf("Parentheses/braces are NOT nested properly\n");
        return 0;
      }
      else {
        if (pop() != '{') {
          printf("Parentheses/braces are NOT nested properly\n");
          return 0;
        }
      }
      ++j;
    }
  }
  if (is_empty()) {
    printf("Parentheses/braces are nested properly\n");
  }
  else {
    printf("Parentheses/braces are NOT nested properly\n");
  }



  // while (top != bottom) {
  //   printf("%c", contents[top - 1]);
  //   top--;
  // }
// printf("Parentheses/braces are nested properly\n");
  return 0; // 主函数返回0，表示程序正常结束（实际上这里没有进行任何操作）  
}