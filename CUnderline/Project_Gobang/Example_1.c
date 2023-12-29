#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
// #include"game.h"
#define A 20//设置默认棋盘规模行
#define B 20//设置默认棋盘规模列
int h = 0, l = 0;
int H = 0, L = 0;
int d = 0;
int o = 0;
char qipan[200][200];
int Color = 1;//棋子颜色
int k;
int m = 5;//总优先级
int MM = 5;//小范围的优先级
int I = 0, J = 0;//光标位置
int key, ch, get;
int zuo1 = 0, you1 = 0, shang1 = 0, xia1 = 0;
int zuo2 = 0, you2 = 0, shang2 = 0, xia2 = 0;
int zuoshang1 = 0, zuoshang2 = 0, youxia1 = 0, youxia2 = 0;
int youshang1 = 0, youshang2 = 0, zuoxia1 = 0, zuoxia2 = 0;
int hang[1000], lie[1000];//悔棋函数记录的步骤
int g = 0, e = 0, j = 0;//悔棋函数记录
int b = 0;
int X = 0;
int  youxi = 0;//游戏模式记录
char a1[] = "######      *AI  GObang*      ######";//菜单打印
char a2[] = "####################################";//菜单打印
char a3[] = "   ####################################";//菜单打印
void menu() {
  int right = strlen(a2) - 1;
  int left = 0;
  int i = 0;
  while (left + 5 <= right - 5) {
    a2[right - 5] = a1[right - 5];
    a2[left + 5] = a1[left + 5];
    left++;
    right--;
    printf("\n\n\n\n\n\n\n");
    printf("%s\n", a3);
    printf("   ");
    printf("%s\n", a2);
    printf("   ######                        ######\n");
    printf("   ######      1.人机对战        ######\n");
    printf("   ######      2.双人对弈        ######\n");
    printf("   ######      3.游戏设置        ######\n");
    printf("   ######      0.退出游戏        ######\n");
    printf("%s\n", a3);
    printf("%s\n", a3);
    printf("   ################# MADE BY ##########\n");
    printf("   #########################  高三金 ##\n");
    printf("%s\n\n\n", a3);
    printf("   ***PS：本程序所有指令皆按回车键确认***\n");
    printf("   *********制作时间：2021.3.10**********\n\n");
    Sleep(100);
    i++;
    if (i < 13) {
      system("cls");
    }
  }
  printf("快选择呀：");
  menu_choice();
}
/*
    ####################################
  #####       *AIbang*         #######
    #####                        #######
  #####      1.人机对战        #######
  #####      2.双人对弈        #######
  #####      3.游戏设置        #######
    #####      0.退出游戏        #######
    ####################################
  ####################################
  ################# MADE BY ##########
  #########################  高三金 ##
  ####################################*/



void menu_choice() {
  int x = 0;
  scanf("%d", &x);
  switch (x) {
    case 1:
      Board_initialize();
      AIgame(); break;
    case 2:
      getchar();
      Board_initialize();
      game(); break;
    case 3:
      setting(); break;
    case 0:
      system("exit"); break;
    default:
      printf("摇摇脑袋，有没有听见大海的声音？有这个选项吗？\n");
      printf("请重新输入：");
      menu_choice();
      break;
  }
}
void Board_initialize() {
  Color = 1;
  for (h = 0; h < H; h++)
    for (l = 0; l < L; l++)
      qipan[h][l] = 2;
}
void color() {
  char a[11] = "\"color 02\"";
  a[7] = a[7] + d;
  a[8] = a[8] + o;
  if (a[7] > 57) {
    a[7] = a[7] + 7;
  }
  if (a[7] > 70) {
    a[7] = a[7] - 23;
    d = 0;
  }
  if (a[8] > 57) {
    a[8] = a[8] + 7;
  }
  if (a[8] > 70) {
    a[8] = a[8] - 23;
    o = 0;
  }
  //printf("%s\n", a);  检查输出颜色字号
  system(a);
  printf("\n颜色已更改为色号%s\n  继续游戏请按回车键\n", a);
  o++;
  d++;
}
void setting() {
  int y = 0;
  printf("1.更改颜色  2.棋盘规模(默认20*20）  3.返回主菜单\n");
  scanf("%d", &y);
  switch (y) {
    case 1:
      color();
      while (1) {
        if (getchar() == '\n') {
          setting();
          break;
        }
      }
      break;
    case 2:
      Board_setting();
      while (1) {
        if (getchar() == '\n') {
          setting();
          break;
        }
      }
      break;
    case 3:
      system("cls");
      menu();
      break;
    default:
      printf("逗我玩呢？有这个选项吗？\n请重新选择\n");
      setting();
      break;
  }
}
void Board_setting() {
  printf("请输入棋盘规格（默认20*20）:");
  scanf("%d*%d", &H, &L);
  for (h = 0; h < H; h++)
    for (l = 0; l < L; l++)
      qipan[h][l] = 2;
  printf("\n已将棋盘规格修改为%d*%d\n  继续游戏请按回车键\n", H, L);
  getchar();
}
void huiqi() {
  if ((hang[g] == 0 && lie[e] == 0) || (g != 0 && e != 0)) {
    g--, e--;
  }
  h = hang[g];
  l = lie[e];
  if (g == 1 && e == 1) {
    b = 0;
  }

  //printf("%d,%d",h,l);
  //getchar();

  qipan[h][l] = 2;


  //printf("%d",Color);
  /*printf("%d,%d",h,l);*/
  if (j != 0) {
    Color = (Color + 1) % 2;
    j--;
  }
  //printf("%d",Color);
  //getchar();
}
void setPos(int x, int y) {
  HANDLE a;//句柄HANDLE 
  COORD c;//COORD是个结构体 ，有两个成员int X与int Y 
  c.X = x;
  c.Y = y;
  a = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(a, c);
}
void getKey() {
  while (1) {
    key = getch();
    if (key == 13 || key == 32) {
      break;
    }
    switch (key) {
    //↑
      case 72:
      case 87:
        J--;
        setPos(I, J);
        break;

    // ↓
      case 80:
      case 83:
        J++;
        setPos(I, J);
        break;

    // ←
      case 75:
      case 65:
        I -= 2;
        setPos(I, J);
        break;

    // →
      case 77:
      case 68:
        I += 2;
        setPos(I, J);
        break;
    //返回菜单Backspace
      case 8:
        menu();
        break;
      //退出游戏Q	
      case 81:
        system("exit");
        break;
      //重开游戏R
      case 82:
        if (youxi == 1) {
          Board_initialize();
          game();
        }
        else if (youxi == 2) {
          Board_initialize();
          player_first();
        }
        else if (youxi == 3) {
          Board_initialize();
          robot_first();
        }
        break;
      //悔棋T
      case 84:
        huiqi();
        if (youxi == 1) {
          game();
        }
        else if (youxi == 2) {
          player_first();
        }
        else if (youxi == 3) {
          robot_first();
        }
        break;
      //定位V
      case 86:
        if (youxi == 1) {
          game();
        }
        else if (youxi == 2) {
          player_first();
        }
        else if (youxi == 3) {
          robot_first();
        }
        break;
    }
  }
}
void judge_shangxia()    //统计上下棋子数
{
  /*printf("%d,%d,%d",qipan[h-1][l],qipan[h+1][l],Color);*/
  if (qipan[h - 1][l] == Color && qipan[h + 1][l] == Color && h != 0 && h != (H - 1)) {
    int i = 0;
    int j = 0;
    shang1 = 0, shang2 = 0, xia1 = 0, xia2 = 0;
    while (qipan[h - 1][l] == Color && h != 0) {
      if (Color == 1) {
        shang1++;
      }
      else {
        shang2++;
      }
      i++;
      h--;
    }
    h = h + i;



    while (qipan[h + 1][l] == Color && h != (H - 1)) {
      if (Color == 1) {
        xia1++;
      }
      else {
        xia2++;
      }
      j++;
      h++;
    }
    h = h - j;
  }
    //printf("%d,%d,%d,%d,%d,%d,%d,%d",shang1,shang2,xia1,xia2,zuo1,zuo2,you1,you2);
    //getchar();
  if ((shang1 + xia1) >= 4) {
    m = 1;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((shang2 + xia2) >= 4) {
    m = 2;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((shang1 + xia1) == 3) {
    m = 3;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((shang2 + xia2) == 3) {
    m = 3;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((shang1 + xia1) == 2) {
    m = 4;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((shang2 + xia2) == 2) {
    m = 4;
    if (MM >= m) {
      MM = m;
    }
  }
  m = MM;
}

void judge_zuoyou()  //统计左右棋子数
{
  if (qipan[h][l - 1] == Color && qipan[h][l + 1] == Color && l != 0 && l != (L - 1)) {
    int i = 0;
    int j = 0;
    zuo1 = 0, zuo2 = 0, you1 = 0, you2 = 0;
    while (qipan[h][l - 1] == Color && l != 0) {
      if (Color == 1) {
        zuo1++;
      }
      else {
        zuo2++;
      }
      i++;
      l--;
    }
    l = l + i;



    while (qipan[h][l + 1] == Color && l != (L - 1)) {
      if (Color == 1) {
        you1++;
      }
      else {
        you2++;
      }
      j++;
      l++;
    }
    l = l - j;
  }

  if ((zuo1 + you1) >= 4) {
    m = 1;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuo2 + you2) >= 4) {
    m = 2;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuo1 + you1) == 3) {
    m = 3;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuo2 + you2) == 3) {
    m = 3;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuo1 + you1) == 2) {
    m = 4;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuo2 + you2) == 2) {
    m = 4;
    if (MM >= m) {
      MM = m;
    }
  }

}

void judge_zuoshangyouxia()  //统计从左上到右下棋子数
{
  if (qipan[h - 1][l - 1] == Color && qipan[h + 1][l + 1] == Color && l != 0 && h != 0 && l != (L - 1) && h != (H - 1)) {
    int i = 0;
    int j = 0;
    zuoshang1 = 0, zuoshang2 = 0, youxia1 = 0, youxia2 = 0;
    while (qipan[h - 1][l - 1] == Color && l != 0 && h != 0) {
      if (Color == 1) {
        zuoshang1++;
      }
      else {
        zuoshang2++;
      }
      i++;
      h--;
      l--;
    }
    h = h + i;
    l = l + i;



    while (qipan[h + 1][l + 1] == Color && l != (L - 1) && h != (H - 1)) {
      if (Color == 1) {
        youxia1++;
      }
      else {
        youxia2++;
      }
      j++;
      h++;
      l++;
    }
    h = h - j;
    l = l - j;
  }

  if ((zuoshang1 + youxia1) >= 4) {
    m = 1;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuoshang2 + youxia2) >= 4) {
    m = 2;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuoshang1 + youxia1) == 3) {
    m = 3;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuoshang2 + youxia2) == 3) {
    m = 3;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuoshang1 + youxia1) == 2) {
    m = 4;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((zuoshang2 + youxia2) == 2) {
    m = 4;
    if (MM >= m) {
      MM = m;
    }
  }
}




void judge_youshangzuoxia()  //统计从右上到左下棋子数
{
  if (qipan[h - 1][l + 1] == Color && qipan[h + 1][l - 1] == Color && h != 0 && l != (L - 1) && h != (H - 1) && l != 0) {
    int i = 0;
    int j = 0;
    youshang1 = 0, youshang2 = 0, zuoxia1 = 0, zuoxia2 = 0;
    while (qipan[h - 1][l + 1] == Color && h != 0 && l != (L - 1)) {
      if (Color == 1) {
        youshang1++;
      }
      else {
        youshang2++;
      }
      i++;
      h--;
      l++;
    }
    h = h + i;
    l = l - i;



    while (qipan[h + 1][l - 1] == Color && h != (H - 1) && l != 0) {
      if (Color == 1) {
        zuoxia1++;
      }
      else {
        zuoxia2++;
      }
      j++;
      h++;
      l--;
    }
    h = h - j;
    l = l + j;
  }

  if ((youshang1 + zuoxia1) >= 4) {
    m = 1;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((youshang2 + zuoxia2) >= 4) {
    m = 2;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((youshang1 + zuoxia1) == 3) {
    m = 3;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((youshang2 + zuoxia2) == 3) {
    m = 3;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((youshang1 + zuoxia1) == 2) {
    m = 4;
    if (MM >= m) {
      MM = m;
    }
  }
  if ((youshang2 + zuoxia2) == 2) {
    m = 4;
    if (MM >= m) {
      MM = m;
    }
  }
}

void judge() {
  shang1 = 0, shang2 = 0, xia1 = 0, xia2 = 0, zuo1 = 0, zuo2 = 0, you1 = 0, you2 = 0, MM = 5;
  zuoshang1 = 0, zuoshang2 = 0, youxia1 = 0, youxia2 = 0, youshang1 = 0, youshang2 = 0, zuoxia1 = 0, zuoxia2 = 0;
  judge_shangxia();
  if (qipan[h - 1][l] == Color && h != 0) {
    h--;
    if (h == 0) {
      if (Color == 1) {
        shang1++;
      }
      else if (Color == 0) {
        shang2++;
      }
    }
    judge_shangxia();
    h++;
  }
  if (qipan[h + 1][l] == Color && h != (H - 1)) {
    h++;
    if (h == (H - 1)) {
      if (Color == 1) {
        xia1++;
      }
      else {
        xia2++;
      }
    }
    judge_shangxia();
    h--;
  }



  judge_zuoyou();
  if (qipan[h][l - 1] == Color && l != 0) {
    l--;
    if (l == 0) {
      if (Color == 1) {
        zuo1++;
      }
      else if (Color == 0) {
        zuo2++;
      }
    }
    judge_zuoyou();
    l++;
  }
  if (qipan[h][l + 1] == Color && l != (L - 1)) {
    l++;
    if (l == (L - 1)) {
      if (Color == 1) {
        you1++;
      }
      else {
        you2++;
      }
    }
    judge_zuoyou();
    l--;
  }


  judge_zuoshangyouxia();
  if (qipan[h - 1][l - 1] == Color && h != 0 && l != 0) {
    h--;
    l--;
    if (h == 0 || l == 0) {
      if (Color == 1) {
        zuoshang1++;
      }
      else if (Color == 0) {
        zuoshang2++;
      }
    }
    judge_zuoshangyouxia();
    h++;
    l++;
  }
  if (qipan[h + 1][l + 1] == Color && h != (H - 1) && l != (L - 1)) {
    h++;
    l++;
    if (h == (H - 1) || l == (L - 1)) {
      if (Color == 1) {
        youxia1++;
      }
      else {
        youxia2++;
      }
    }
    judge_zuoshangyouxia();
    h--;
    l--;
  }




  judge_youshangzuoxia();
  if (qipan[h - 1][l + 1] == Color && h != 0 && l != (L - 1)) {
    h--;
    l++;
    if (h == 0 || l == (L - 1)) {
      if (Color == 1) {
        youshang1++;
      }
      else if (Color == 0) {
        youshang2++;
      }
    }
    judge_youshangzuoxia();
    h++;
    l--;
  }
  if (qipan[h + 1][l - 1] == Color && h != (H - 1) && l != 0) {
    h++;
    l--;
    if (h == (H - 1) || l == 0) {
      if (Color == 1) {
        zuoxia1++;
      }
      else {
        zuoxia2++;
      }
    }
    judge_youshangzuoxia();
    h--;
    l++;
  }
  m = MM;
}




void game() {
  youxi = 1;
  system("cls");
  Board_print();
  //h=J;
  //l=I/2;

  //printf("%d,%d",h,l);
  /*getchar();*/
  Player();
  I = L - 2; J = (H / 2 - 1);
  while (1) {
    //I=0;J=(H/2);
    setPos(I, J);
    getKey();
    h = J;
    l = I / 2;
    if (qipan[h][l] != 2) {
      //setPos(0,0);
      system("cls");
      Board_print();
      Player();
      h = J;
      l = I / 2;
      //printf("%d,%d\n",h,l);检查输出坐标位置	

      if (h < 0 || h >= H || l < 0 || l >= L) {
        I = L - 2; J = (H / 2 - 1);
        for (k = 0; k <= L / 4; k++) {
          printf(" ");
        }
        printf("******超出了棋盘的范围，请重新输入！******\n");
      }
      else {
        for (k = 0; k <= L / 3; k++) {
          printf(" ");
        }
        printf("******此处已有棋子，不能覆盖哦！******\n");
      }
      continue;
    }

    system("cls");
    qipan[h][l] = Color;
    /*printf("%d",qipan[h-1][l]);*/
    judge();

    //printf("%d",m);
    //getchar();


    Board_print();
    h = J;
    l = I / 2;
    //printf("%d,%d",h,l);
    //getchar();
    hang[g] = h;
    lie[e] = l;
    g++, e++, j++;

    //printf("%d",m);
    //getchar();
    if (m == 1) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，●赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
    again1:
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          game();
          break;
        case 89:
          color();
          Board_initialize();
          game();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          game();
          break;
        case 81:
          system("exit");
          break;
        default:
          goto again1;
          break;
      }
      break;
    }

    if (m == 2) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，○赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          game();
          break;
        case 89:
          color();
          Board_initialize();
          game();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          game();
          break;
        case 81:
          system("exit");
          break;
        default:
          goto again1;
          break;
      }
      break;
    }
    Color = (Color + 1) % 2;
    Player();

  }

}

void Player() {
  if (Color == 1) {
    for (k = 0; k <= L / 3; k++) {
      printf(" ");
    }
    printf("******请●玩家下棋******\n");
  }
  if (Color == 0) {
    for (k = 0; k <= L / 3; k++) {
      printf(" ");
    }
    printf("******请○玩家下棋******\n");
  }
}

void Board_print() {
  int jiluhang = h, jilulei = l;
  for (h = 1; h <= H; h++) {
    if (h == 1) //第1行
    {

        //第1行，第1列
      if (qipan[h - 1][0] == 1)
        printf("● ");
      if (qipan[h - 1][0] == 0)
        printf("○ ");
      if (qipan[h - 1][0] == 2)
        printf("┌ ");
//第1行，第2-(L-1)列
      for (l = 2; l <= (L - 1); l++) {
/*qipan[h-1][3]=0;*/
        if (qipan[h - 1][l - 1] == 1)
          printf("● ");
        if (qipan[h - 1][l - 1] == 0)
          printf("○ ");
        if (qipan[h - 1][l - 1] == 2)
          printf("┬ ");
      }
//出内循环 第1行，最后一个
      if (qipan[h - 1][l - 1] == 1)
        printf("● ");
      if (qipan[h - 1][l - 1] == 0)
        printf("○ ");
      if (qipan[h - 1][l - 1] == 2)
        printf("┐ ");
      printf("\n");
    }
    if (h <= (H - 1) && h >= 2)//第2-(H-1)行
    {
        //第2-(H-1)行，第1列
      if (qipan[h - 1][0] == 1)
        printf("● ");
      if (qipan[h - 1][0] == 0)
        printf("○ ");
      if (qipan[h - 1][0] == 2)
        printf("├ ");
//第2-(H-1)行，第2-(L-1)列
      for (l = 2; l <= (L - 1); l++) {
        if (qipan[h - 1][l - 1] == 1)
          printf("● ");
        if (qipan[h - 1][l - 1] == 0)
          printf("○ ");
        if (qipan[h - 1][l - 1] == 2)
          printf("┼ ");
      }
//出内循环 第2-(H-1)行，最后一个
      if (qipan[h - 1][l - 1] == 1)
        printf("● ");
      if (qipan[h - 1][l - 1] == 0)
        printf("○ ");
      if (qipan[h - 1][l - 1] == 2)
        printf("┤ ");
      printf("\n");
    }
    if (h == H)//最后一行
    {
      if (qipan[h - 1][0] == 1)
        printf("● ");
      if (qipan[h - 1][0] == 0)
        printf("○ ");
      if (qipan[h - 1][0] == 2)
        printf("└ ");
    //最后一行，第2-(L-1)个
      for (l = 2; l <= (L - 1); l++) {
        if (qipan[h - 1][l - 1] == 1)
          printf("● ");
        if (qipan[h - 1][l - 1] == 0)
          printf("○ ");
        if (qipan[h - 1][l - 1] == 2)
          printf("┴ ");
      }
      //出内循环 最后一行，最后一个
      if (qipan[h - 1][l - 1] == 1)
        printf("● ");
      if (qipan[h - 1][l - 1] == 0)
        printf("○ ");
      if (qipan[h - 1][l - 1] == 2)
        printf("┘ ");
      printf("\n");
    }
  }
  h = jiluhang;
  l = jilulei;
}

void robot() {
  int M = 5, c = 0, MD = 5, u = 0;
  int jiluh, jilul, jiluc, jiluhh, jilull;
  jiluc = Color;
  //if(m<=4)  加上if语句限定，人机难度降低，但计算量大大减小
  //{
  Color = (Color + 1) % 2;
  m = 5;
  for (h = 0; h <= (H - 1); h++) {
    for (l = 0; l <= (L - 1); l++) {
      if (Color == qipan[h - 1][l] || Color == qipan[h + 1][l] || Color == qipan[h][l + 1] || Color == qipan[h][l - 1] || Color == qipan[h - 1][l - 1] || Color == qipan[h + 1][l + 1] || Color == qipan[h - 1][l + 1] || Color == qipan[h + 1][l - 1]) {
        if (2 == qipan[h][l]) {
          if ((h - 1) >= 0 && (h + 1) <= (H - 1) && (l - 1) >= 0 && (l + 1) <= (L - 1)) {
            qipan[h][l] = Color;
            judge();
            //printf("%d,%d,%d,%d\n",h,l,m,MD);
            //getchar();
            qipan[h][l] = 2;
            if (MD >= m) {
              MD = m;
              jiluhh = h;
              jilull = l;
              u = 1;
            }
          }
        }
      }
    }
  }
//}
  m = 5;
  Color = (Color + 1) % 2;
  for (h = 0; h <= (H - 1); h++) {
    for (l = 0; l <= (L - 1); l++) {
      if (Color == qipan[h - 1][l] || Color == qipan[h + 1][l] || Color == qipan[h][l + 1] || Color == qipan[h][l - 1] || Color == qipan[h - 1][l - 1] || Color == qipan[h + 1][l + 1] || Color == qipan[h - 1][l + 1] || Color == qipan[h + 1][l - 1]) {
        if (2 == qipan[h][l]) {
          if ((h - 1) >= 0 && (h + 1) <= (H - 1) && (l - 1) >= 0 && (l + 1) <= (L - 1)) {
            qipan[h][l] = Color;
            judge();
            qipan[h][l] = 2;
            if (M >= m) {
              M = m;
              jiluh = h;
              jilul = l;
            }
          }
        }
      }
    }
  }
  //printf("%d,%d,%d,%d,%d,%d,%d,%d",MD,M,m,X,jiluh,jilul,jiluhh,jilull);
  //getchar();
  //getchar();
  if (MD < M) {
    m = MD;
    h = jiluhh;
    l = jilull;
    Color = jiluc;
  }
  else if (MD > M) {
    m = M;
    h = jiluh;
    l = jilul;
    Color = jiluc;
  }
  else if (MD == M) {

    if (X == 1) {
      m = M;
      h = jiluh;
      l = jilul;
      Color = jiluc;
    }
    else if (X == 0) {
      if (u == 0) {
        m = M;
        h = jiluh;
        l = jilul;
        Color = jiluc;
      }
      else if (u == 1) {
        m = MD;
        h = jiluhh;
        l = jilull;
        Color = jiluc;
      }
    }
  }
  //printf("%d,%d",h,l);
  //getchar();
}
void robot_first() {
  youxi = 3;
  system("cls");
  I = L - 2; J = (H / 2 - 1);
  h = J;
  l = I / 2;
  Board_print();
  Player();
  while (1) {
    while (1) {
      //I=0;J=(H/2);
      setPos(I, J);
      getKey();
      h = J;
      l = I / 2;
      if (qipan[h][l] != 2) {
        //setPos(0,0);
        system("cls");
        Board_print();
        Player();
        h = J;
        l = I / 2;
        //printf("%d,%d\n",h,l);检查输出坐标位置	

        if (h < 0 || h >= H || l < 0 || l >= L) {
          I = L - 2; J = (H / 2 - 1);
          for (k = 0; k <= L / 4; k++) {
            printf(" ");
          }
          printf("******超出了棋盘的范围，请重新输入！******\n");
        }
        else {
          for (k = 0; k <= L / 3; k++) {
            printf(" ");
          }
          printf("******此处已有棋子，不能覆盖哦！******\n");
        }
        continue;
      }
      break;
    }
    system("cls");
    qipan[h][l] = Color;
    /*printf("%d",qipan[h-1][l]);*/
    judge();
    Board_print();//打印玩家局势
    h = J;
    l = I / 2;
    //printf("%d",m);
    //getchar();
    hang[g] = h;
    lie[e] = l;
    g++, e++, j++;
    Color = (Color + 1) % 2;

    if (m == 1) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，●赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          AIgame();
          break;
        case 89:
          color();
          Board_initialize();
          AIgame();
          break;
        case 70:
          Board_setting();
          AIgame();
          break;
        case 81:
          system("exit");
          break;
      }
      break;
    }

    if (m == 2) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，○赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          AIgame();
          break;
        case 89:
          color();
          Board_initialize();
          AIgame();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          AIgame();
          break;
        case 81:
          system("exit");
          break;
      }
      break;
    }


    robot();
    qipan[h][l] = Color;
    hang[g] = h;
    lie[e] = l;
    g++, e++, j++;
    system("cls");
    Board_print();//打印总局势
    //printf("%d,%d,%d",m,h,l);
    //getchar();
    judge();
    //printf("%d,%d,%d",m,h,l);
    //getchar();
    if (m == 1) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，●赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          AIgame();
          break;
        case 89:
          color();
          Board_initialize();
          AIgame();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          AIgame();
          break;
        case 81:
          system("exit");
          break;
      }
      break;
    }

    if (m == 2) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，○赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          AIgame();
          break;
        case 89:
          color();
          Board_initialize();
          AIgame();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          AIgame();
          break;
        case 81:
          system("exit");
          break;
      }
      break;
    }
    Color = (Color + 1) % 2;
    Player();

  }
}
void player_first() {
  youxi = 2;
  system("cls");
  I = L - 2; J = (H / 2 - 1);
  h = J;
  l = I / 2;
  Board_print();
  Player();
  while (1) {
    while (1) {
      //I=0;J=(H/2);
      setPos(I, J);
      getKey();
      h = J;
      l = I / 2;
      if (qipan[h][l] != 2) {
        //setPos(0,0);
        system("cls");
        Board_print();
        Player();
        h = J;
        l = I / 2;
        //printf("%d,%d\n",h,l);检查输出坐标位置	

        if (h < 0 || h >= H || l < 0 || l >= L) {
          I = L - 2; J = (H / 2 - 1);
          for (k = 0; k <= L / 4; k++) {
            printf(" ");
          }
          printf("******超出了棋盘的范围，请重新输入！******\n");
        }
        else {
          for (k = 0; k <= L / 3; k++) {
            printf(" ");
          }
          printf("******此处已有棋子，不能覆盖哦！******\n");
        }
        continue;
      }
      break;
    }
    system("cls");
    qipan[h][l] = Color;
    /*printf("%d",qipan[h-1][l]);*/
    judge();
    Board_print();//打印玩家局势
    h = J;
    l = I / 2;
    //printf("%d,%d",h,l);
    //getchar();
    hang[g] = h;
    lie[e] = l;
    g++, e++, j++;
    Color = (Color + 1) % 2;

    if (m == 1) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，●赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
    again:
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          AIgame();
          break;
        case 89:
          color();
          Board_initialize();
          AIgame();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          AIgame();
          break;
        case 81:
          system("exit");
          break;
        default:
          goto again;
          break;
      }
      break;
    }

    if (m == 2) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，○赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          AIgame();
          break;
        case 89:
          color();
          Board_initialize();
          AIgame();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          AIgame();
          break;
        case 81:
          system("exit");
          break;
        default:
          goto again;
          break;
      }
      break;
    }

    if (b == 0) {
      h = h + 1;
      l = l - 1;
      b++;
    }
    else if (b > 0) {
      robot();
      b = 1;
    }
    //printf("%d,%d,%d,%d",m,h,l,Color);
    //getchar();
    qipan[h][l] = Color;
    hang[g] = h;
    lie[e] = l;
    g++, e++, j++;
    system("cls");
    Board_print();//打印总局势
    judge();
    //printf("%d,%d,%d,%d",m,h,l,Color);
    //getchar();
    if (m == 1) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，●赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          AIgame();
          break;
        case 89:
          color();
          Board_initialize();
          AIgame();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          AIgame();
          break;
        case 81:
          system("exit");
          break;
        default:
          goto again;
          break;
      }
      break;
    }

    if (m == 2) {
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("******恭喜，○赢了******\n");
      for (k = 0; k <= L / 3; k++) {
        printf(" ");
      }
      printf("重新游戏请按R  游戏设置(更改颜色请按Y，棋盘规模请按F） 退出游戏请按Q \n");
      ch = getch();
      switch (ch) {
        case 82:
          Board_initialize();
          AIgame();
          break;
        case 89:
          color();
          Board_initialize();
          AIgame();
          break;
        case 70:
          Board_setting();
          Board_initialize();
          AIgame();
          break;
        case 81:
          system("exit");
          break;
        default:
          goto again;
          break;
      }
      break;
    }
    Color = (Color + 1) % 2;
    Player();
  }
}
void AIgame() {
  system("cls");
  printf("您是否要当先手?  Y.那必须  N.算了,你先\n");
AI:
  get = getch();
  switch (get) {
    case 89:
      X = 0;
      b = 0;
      player_first();
      break;
    case 78:
      X = 1;
      system("cls");
      I = L - 2; J = (H / 2 - 1);
      h = J;
      l = I / 2;
      qipan[h][l] = Color;
      Color = (Color + 1) % 2;
      robot_first();
      break;
    case 8:
      menu();
      break;
    default:
      goto AI;
      break;
  }

}



int main() {
  H = A, L = B;
  system("color 06");
  Board_initialize();
  menu();
  return 0;
}