#include <stdio.h>
#include "list.h"

void lst_qsort(LIST *l) {
  if(lst_length(l) <= 1)
    return;
  int pivot = lst_pop_front(l);
  LIST *left = lst_filter_leq(l, pivot);
  lst_qsort(left);
  lst_qsort(l);
  lst_push_front(l, pivot);
  lst_concat(left, l);
  lst_concat(l, left);
}

int main(int argc, char *argv[]) {
  int val = 0;
  LIST *data = lst_create();
  
  //printf("Please input integers to sort (any non-number to quit):\n");
  while(scanf("%i", &val)) {
    lst_push_back(data, val);
  }
  lst_qsort(data);
  lst_print(data);
  lst_free(data);
  return 0;
}
