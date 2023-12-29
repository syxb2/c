#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GOODS_FILE_NAME "goodsinfo.txt"
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30

typedef struct {
  char goods_id[MAX_ID_LEN];
  char goods_name[MAX_NAME_LEN];
  int goods_price;
  char goods_discount[MAX_DISCOUNT_LEN];
  int goods_amount;
  int goods_remain;
} GoodsInfo;

typedef struct node {
  GoodsInfo data;
  struct node *next;
} GoodsList;

int CurrentCnt = 0; // CurrentCnt是节点数量

/*
void init_list(GoodsList **L) {
  FILE *fp = fopen("/Users/baijiale/Documents/VisualStudioCode/c/CUnderline/Homework/ICODING/Experience6/goodsinfo.txt", "r");
  *L = (GoodsList*) malloc(sizeof(GoodsList));
  (*L)->next = NULL;
  GoodsList *temp = (GoodsList*) malloc(sizeof(GoodsList));
  while (fscanf(fp, "%s %s %d %s %d %d\n", temp->data.goods_id, temp->data.goods_name, &temp->data.goods_price, temp->data.goods_discount, &temp->data.goods_amount, &temp->data.goods_remain) != EOF) {
    if (!((*L)->next == NULL)) {
      temp->next = (*L)->next;
    }
    else {
      temp->next = NULL;
    }
    // *L = (GoodsList*) malloc(sizeof(GoodsList));
    (*L)->data = temp->data;
    (*L)->next = temp;
    temp = (GoodsList*) malloc(sizeof(GoodsList));
  }
  temp->next = (*L)->next;
  (*L) = temp;
}
*/

void init_list(GoodsList** L) {
  FILE *fp = fopen("/Users/baijiale/Documents/VisualStudioCode/c/CUnderline/Homework/icoding/Experience6/goodsinfo.txt", "r");
  GoodsList *pre = (GoodsList*) malloc(sizeof(GoodsList));
  GoodsList *temp = pre;
  ++CurrentCnt;
  pre->next = NULL;
  if (fp == NULL) {
    perror("fopen()");
    return;
  }
  do {
    *L = (GoodsList*) malloc(sizeof(GoodsList));
    if ((fscanf(fp, "%s %s %d %s %d %d\n", (*L)->data.goods_id, (*L)->data.goods_name, &(*L)->data.goods_price, (*L)->data.goods_discount, &(*L)->data.goods_amount, &(*L)->data.goods_remain) == EOF)) {
      break;
    }
    ++CurrentCnt;
    // fscanf(fp, "%s %s %d %s %d %d\n", (*L)->data.goods_id, (*L)->data.goods_name, &(*L)->data.goods_price, (*L)->data.goods_discount, &(*L)->data.goods_amount, &(*L)->data.goods_remain);
    (*L)->next = pre->next;
    pre->next = *L;
    pre = *L;
  } while (1);
  *L = temp;
  --CurrentCnt;

  printf("目前有%d个商品信息\n", CurrentCnt);
  return;
}

bool insert_item(GoodsList *L, GoodsInfo goodsInfo, int choice) {
  if (L == NULL) {
    return 0;
  }
  GoodsList *temp = (GoodsList*) malloc(sizeof(GoodsList));
  switch (choice) {
    case 0:
      while (L->next != NULL) {
        L = L->next;
      }
      temp->next = NULL;
      L->next = temp;
      temp->data = goodsInfo;
      ++CurrentCnt;
      return 1;
      break;
    case 1:
      temp->next = L->next;
      L->next = temp;
      temp->data = goodsInfo;
      ++CurrentCnt;
      return 1;
      break;
    default:
      for (int i = 0; i < choice - 1; ++i) {
        L = L->next;
      }
      temp->next = L->next;
      L->next = temp;
      temp->data = goodsInfo;
      ++CurrentCnt;
      return 1;
      break;
  }
  return 0;
}

bool delete_item(GoodsList *L, char *goods_id) {
  GoodsList* t = L->next;
  while (strcmp(goods_id, t->data.goods_id) != 0) {
    t = t->next;
    L = L->next;
    if (t->next == NULL) {
      if (strcmp(goods_id, t->data.goods_id) == 0) {
        free(t);
        L->next = NULL;
        --CurrentCnt;
        return 1;
      }
      printf("err\n");
      return 0;
    }
  }
  L->next = t->next;
  free(t);
  --CurrentCnt;
  return 1;
}

GoodsList* search_item(GoodsList *L, char* goods_id) {
  while (strcmp(goods_id, L->data.goods_id) != 0) {
    if (L->next != NULL) {
      L = L->next;
    }
    else if (L->next == NULL) {
      return NULL;
    }
  }
  return L;
}

bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info) {
  if (search_item(L, goods_id) != NULL) {
    GoodsList *t = search_item(L, goods_id);
    t->data = new_info;
    return 1;
  }
  else {
    return 0;
  }
}

void output_one_item(GoodsList *p) {
  printf("%s %s %d %s %d %d\n", p->data.goods_id, p->data.goods_name, p->data.goods_price, p->data.goods_discount, p->data.goods_amount, p->data.goods_remain);
  return;
}

void output_all_items(GoodsList *L) {
  L = L->next;
  while (L != NULL) {
    output_one_item(L);
    L = L->next;
  }
  return;
}

void destory_list(GoodsList **L) {
  GoodsList *p = *L;
  while (*L != NULL) {
    *L = (*L)->next;
    free(p);
    p = *L;
  }
  *L = NULL;
  CurrentCnt = 0;
  return;
}

void destory_list_and_file(GoodsList **L) {
  destory_list(L);
  remove("/Users/baijiale/Documents/VisualStudioCode/c/CUnderline/Homework/icoding/Experience6/goodsinfo.txt");
  return;
}

int save_to_file(GoodsList *L) {
  int a = 0;
  FILE *fp = fopen("/Users/baijiale/Documents/VisualStudioCode/c/CUnderline/Homework/icoding/Experience6/goodsinfo copy.txt", "w");
  L = L->next;
  while (L != NULL) {
    fprintf(fp, "%s %s %d %s %d %d\n", L->data.goods_id, L->data.goods_name, L->data.goods_price, L->data.goods_discount, L->data.goods_amount, L->data.goods_remain);
    ++a;
    L = L->next;
  }
  fclose(fp);

  return a;
}

void bubble_sort(GoodsList *L) {
  for (int i = 0; i < CurrentCnt; ++i) {
    GoodsList *ppre = L, *pre = L->next, *p = L->next->next;
    while (p != NULL) {
      if (pre->data.goods_price > p->data.goods_price) {
        ppre->next = pre->next;
        pre->next = p->next;
        p->next = pre;

        ppre = ppre->next;
        p = pre->next;
      }
      else {
        ppre = ppre->next;
        pre = pre->next;
        p = p->next;
      }
    }
  }
}

/*
GoodsInfo read_goods_info() {
  GoodsInfo t;
  printf("商品ID:");
  read_line(t.goods_id, MAX_ID_LEN);
  printf("商品名称：");
  read_line(t.goods_name, MAX_NAME_LEN);
  printf("商品价格：");
  scanf("%d", &t.goods_price);
  printf("商品折扣：");
  read_line(t.goods_discount, MAX_DISCOUNT_LEN);
  printf("商品数量：");
  scanf("%d", &t.goods_amount);
  printf("商品剩余数量:");
  scanf("%d", &t.goods_remain);
  return t;
}
*/