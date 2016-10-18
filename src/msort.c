#include <stdio.h>
#include "list.h"

void lst_msort(LIST *l) {
  //base case
  if(lst_length(l) <= 1)
    return;

  //divide list in 2
  LIST *split = lst_prefix(l, (lst_length(l)/2));
  //sort each list
  lst_msort(split);
  lst_msort(l);

  //merge the two lists 
  lst_merge_sorted(l, split);
  lst_free(split);
}

int main(int argc, char *argv[]) {
  int val = 0;
  LIST *data = lst_create();
  
  //printf("Please input integers to sort (any non-number to quit):\n");
  while(scanf("%i", &val)) {
    lst_push_back(data, val);
  }
  lst_msort(data);
  lst_print(data);
  lst_free(data);
  return 0;
}
