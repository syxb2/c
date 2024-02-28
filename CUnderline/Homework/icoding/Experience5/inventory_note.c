// 维护一个部件数据库（数组版本）  

#include <stdio.h>  

// 定义一个宏，表示部件名字的最大长度  
#define NAME_LEN 25  
// 定义一个宏，表示最大部件数量  
#define MAX_PARTS 100  

// 定义一个结构体，表示一个部件，每个部件有一个编号、一个名字和一个库存量  
struct part {
    int number;      // 部件编号  
    char name[NAME_LEN + 1];  // 部件名字，最多能存25个字符（包括字符串结束符'\0'）  
    int on_hand;     // 库存量  
} inventory[MAX_PARTS];  // 定义一个部件数组，最多能存100个部件  

// 当前存储的部件数量，初始化为0  
int num_parts = 0;

// 定义一个函数，用于从输入中读取一行数据，去除前导空格，并把剩下的内容存储到给定的字符串中  
int read_line(char str[ ], int n);

// 定义一个函数，用于在部件数组中查找一个部件，返回其索引，否则返回-1  
int find_part(int number);

// 定义一个函数，用于插入一个新的部件到部件数组中  
void insert(void);

// 定义一个函数，用于在部件数组中查找一个部件并打印其信息  
void search(void);

// 定义一个函数，用于更新一个部件的库存量  
void update(void);

// 定义一个函数，用于打印部件数组中所有部件的信息  
void print(void);

// 主函数，接收用户输入的命令并调用相应的函数进行处理，当用户输入'q'时退出程序  
int main(void) {
    char code;  // 用于存储用户输入的命令代码  

    // 无限循环，直到用户输入'q'命令才退出循环  
    for (;;) {
        printf("Enter operation code: ");  // 提示用户输入操作代码  
        scanf(" %c", &code);  // 从用户输入中读取一个字符作为操作代码  
        while (getchar() != '\n')   // 读取掉用户输入的换行符，保证下次读取输入时从新的一行开始读取  
            ;
        switch (code) {  // 根据用户输入的操作代码选择对应的处理函数  
            case 'i': insert(); break;  // 如果用户输入'i'，调用insert函数处理  
            case 's': search(); break;  // 如果用户输入's'，调用search函数处理  
            case 'u': update(); break;  // 如果用户输入'u'，调用update函数处理  
            case 'p': print(); break;  // 如果用户输入'p'，调用print函数处理  
            case 'q': return 0; break;  // 如果用户输入'q'，退出循环并结束程序  
            default: printf("Illegal code\n"); break;  // 如果用户输入其他非法字符，打印错误信息并继续等待用户输入  
        }
        printf("\n");  // 每次执行完一个操作后打印一个换行符，以便于用户下一次输入操作代码时从新的一行开始读取  
    }
}

// 在部件数组中查找给定编号的部件，返回其索引；否则返回-1  
int find_part(int number) {
    int i;  // 循环计数器  

    // 遍历部件数组，查找给定编号的部件  
    for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) { // 如果找到匹配的部件，返回其索引  
            return i;
        }
    }
    return -1; // 如果未找到匹配的部件，返回-1     
}

// 这是一个函数，作用是插入新零件到库存中  
void insert(void) {
    int part_number;  // 定义一个整型变量，用来存储零件编号  

    if (num_parts == MAX_PARTS) {  // 如果库存已满，不能再添加零件  
        printf("Database is full; can't add more parts.\n");  // 打印提示信息  
        return;  // 结束函数  
    }

    printf("Enter part number: ");  // 提示用户输入零件编号  
    scanf("%d", &part_number);  // 从控制台读取用户输入的零件编号  
    if (find_part(part_number) >= 0) {  // 如果零件编号已存在  
        printf("Part already exists.\n");  // 打印提示信息  
        return;  // 结束函数  
    }

    inventory[num_parts].number = part_number;  // 将零件编号存储到库存中  
    printf("Enter part name: ");  // 提示用户输入零件名称  
    read_line(inventory[num_parts].name, NAME_LEN);  // 从控制台读取用户输入的零件名称  
    printf("Enter quantity on hand: ");  // 提示用户输入手头上的零件数量  
    scanf("%d", &inventory[num_parts].on_hand);  // 从控制台读取用户输入的零件数量，并将其存储到库存中  
    num_parts++;  // 库存中的零件数量加一  
}

// 这是一个函数，作用是在库存中搜索指定的零件  
void search(void) {
    int i, number;  // 定义两个整型变量，i用于循环，number用于存储用户输入的零件编号  

    printf("Enter part number: ");  // 提示用户输入零件编号  
    scanf("%d", &number);  // 从控制台读取用户输入的零件编号  
    i = find_part(number);  // 在库存中查找该零件编号，如果找到，返回其索引，否则返回-1  
    if (i >= 0) {  // 如果找到了该零件  
        printf("Part name: %s\n", inventory[i].name);  // 打印该零件的名称  
        printf("Quantity on hand: %d\n", inventory[i].on_hand);  // 打印该零件的手头数量  
    }
    else {  // 如果没找到该零件  
        printf("Part not found.\n");  // 打印提示信息  
    }
}

// 这是一个函数，作用是更新库存中指定零件的数量  
void update(void) {
    int i, number, change;  // 定义三个整型变量，i用于循环，number用于存储用户输入的零件编号，change用于存储更新的数量  

    printf("Enter part number: ");  // 提示用户输入零件编号  
    scanf("%d", &number);  // 从控制台读取用户输入的零件编号  
    i = find_part(number);  // 在库存中查找该零件编号，如果找到，返回其索引，否则返回-1  
    if (i >= 0) {  // 如果找到了该零件  
        printf("Enter change in quantity on hand: ");  // 提示用户输入要更新的数量变化值  
        scanf("%d", &change);  // 从控制台读取用户输入的数量变化值  
        inventory[i].on_hand += change;  // 更新库存中该零件的数量  
    }
    else {  // 如果没找到该零件  
        printf("Part not found.\n");  // 打印提示信息  
    }
}