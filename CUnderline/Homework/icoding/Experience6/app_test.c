#include <stdio.h>
#include <stdlib.h>
#include "lab52.h"
#include <string.h>

extern int CurrentCnt;

int main() {
  GoodsList* p;
  init_list(&p);

  // delete_item(p, "23");

  // output_all_items(p);

  // printf("%s\n", search_item(p, "22")->data.goods_id);
  bubble_sort(p);

  printf("%d\n", save_to_file(p));

  return 0;
}