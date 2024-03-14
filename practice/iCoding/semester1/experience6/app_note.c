#include <stdio.h>  
#include <stdlib.h>  
// 包含lab52.h头文件，请不要删除本行头文件，否则检查不通过  
// #include "lab52.h"   

// 商品信息文件名  
#define GOODS_FILE_NAME "goodsinfo.txt"  
// 最大商品ID长度  
#define MAX_ID_LEN 30  
// 最大商品名称长度  
#define MAX_NAME_LEN 30  
// 最大商品价格长度  
#define MAX_PRICE_LEN 30  
// 最大商品折扣长度  
#define MAX_DISCOUNT_LEN 30  

// 商品信息结构体定义  
typedef struct {
  // 商品ID  
    char goods_id[MAX_ID_LEN];
    // 商品名称  
    char goods_name[MAX_NAME_LEN];
    // 商品价格  
    int goods_price;
    // 商品折扣  
    char goods_discount[MAX_DISCOUNT_LEN];
    // 商品数量  
    int goods_amount;
    // 商品剩余数量  
    int goods_remain;
} GoodsInfo;

// 商品列表结构体定义  
typedef struct node {
  // 商品信息  
    GoodsInfo data;
    // 下一个节点指针  
    struct node *next;
} GoodsList;

// 读取商品信息的函数声明  
GoodsInfo read_goods_info();
// 初始化商品列表的函数声明  
void init_list(GoodsList **pL);
// 销毁商品列表的函数声明  
void destory_list(GoodsList **pL);
// 销毁商品列表并文件的函数声明  
void destory_list_and_file(GoodsList **pL);
// 将商品列表保存到文件的函数声明  
int save_to_file(GoodsList *L);
// 输出单个商品的函数声明  
void output_one_item(GoodsList *L);
// 输出所有商品的函数声明  
void output_all_items(GoodsList *L);
// 在列表中插入商品的函数声明（带选择项）  
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
// 根据商品ID从列表中删除商品的函数声明  
bool delete_item(GoodsList *L, char* goods_id);
// 根据商品ID在列表中查找商品的函数声明  
GoodsList* search_item(GoodsList *L, char* goods_id);
// 根据商品ID和新的商品信息修改列表中商品的函数声明  
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
// 对商品列表进行冒泡排序的函数声明  
void bubble_sort(GoodsList *L);
// 从控制台读取一行字符串的函数声明，最大长度为n-1，并返回读取的字符数（不包括结束符'\0'）  
int read_line(char str[ ], int n);

// 主函数入口  
int main() {
    int x, y; // 用于用户输入的变量  
    char goods_id[MAX_ID_LEN]; // 用于存储商品ID的变量  
    GoodsList temp;
    GoodsList* p = &temp; // 商品列表指针  
    GoodsInfo h1, h2; // 用于存储商品信息的变量  
    init_list(&p); // 初始化商品列表  
    printf("1.显示所有商品的信息\n"); // 打印选项1：显示所有商品信息  
    printf("2.修改某个商品的信息\n"); // 打印选项2：修改某个商品信息  
    printf("3.插入某个商品的信息\n"); // 打印选项3：插入某个商品信息  
    printf("4.删除某个商品的信息\n"); // 打印选项4：删除某个商品信息  
    printf("5.查找某个商品的信息\n"); // 打印选项5：查找某个商品信息  
    printf("6.商品存盘并退出系统\n"); // 打印选项6：存盘并退出系统  
    printf("7.对商品价格进行排序\n"); // 打印选项7：对商品价格进行排序  
    printf("8.(慎用)删除所有内容\n"); // 打印选项8：(慎用)删除所有内容  
    printf("存盘并退出系统\n"); // 打印提示：存盘并退出系统  

    while (1) { // 无限循环，直到用户手动终止程序  
        printf("please enter a number:"); // 提示用户输入操作编号  
        scanf("%d", &x); // 从控制台读取用户输入的操作编号并存储到变量x中  
        switch (x) { // 根据用户输入的操作编号执行相应的操作  
            case 1: // 如果用户输入的操作编号是1，则执行以下代码块，显示所有商品信息  
                output_all_items(p); // 调用output_all_items函数，输出所有商品信息到控制台  
                break; // 中断switch语句，跳出当前case代码块，准备执行下一个case代码块或结束while循环  
            case 2: // 如果用户输入的操作编号是2，则执行以下代码块，修改某个商品信息  
                read_line(goods_id, MAX_ID_LEN); // 从控制台读取用户输入的商品ID并存储到变量goods_id中，最大长度为MAX_ID_LEN  
                h1 = read_goods_info(); // 从控制台读取用户输入的新的商品信息并存储到变量h1中，
                // 调用read_goods_info函数读取新的商品信息并返回结果存储到变量h1中作为修改后的数据源。同时将修改后的数据存储到结构体变量data中作为节点数据。
                change_item(p, goods_id, h1);
                // 如果修改成功，打印“修改成功”  
                if (change_item(p, goods_id, h1))
                    printf("修改成功\n");
                break;
            case 3:
              // 读取商品信息  
                h2 = read_goods_info();
                printf("请输入您的选择:\n");
                // 从用户输入中读取一个整数  
                scanf("%d", &y);
                // 插入商品信息  
                insert_item(p, h2, y);
                // 如果插入成功，打印“插入成功”  
                if (insert_item(p, h2, y))
                    printf("插入成功\n");
                break;
            case 4:
              // 读取商品ID，最大长度为MAX_ID_LEN  
                read_line(goods_id, MAX_ID_LEN);
                // 删除商品信息  
                delete_item(p, goods_id);
                // 如果删除成功，打印“删除成功”  
                if (delete_item(p, goods_id))
                    printf("删除成功\n");
                break;
            case 5:
              // 读取商品ID，最大长度为MAX_ID_LEN  
                read_line(goods_id, MAX_ID_LEN);
                // 搜索商品信息  
                search_item(p, goods_id);
                break;
            case 6:
              // 保存数据到文件并退出程序  
                save_to_file(p);
                exit(0);
                break;
            case 7:
              // 对列表进行冒泡排序  
                bubble_sort(p);
                break;
            case 8:
              // 销毁链表和文件  
                destory_list_and_file(&p);
                break;
            default:
              // 如果不是以上选项，销毁链表并退出程序  
                destory_list(&p);
                exit(0);
        }
    }

    return 0; // 返回0表示程序正常结束
}