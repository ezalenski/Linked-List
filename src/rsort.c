#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

void lst_rsort_R(LIST **fromB, LIST **toB, int r, int d, int GOAL) {
  int i;
  int next = d*r;
  for(i = 0; i < r; i++) {
    LIST *l = fromB[i];
    while(!lst_is_empty(l)){
      int data = lst_pop_front(l);
      lst_push_back(toB[(data/d)%r], data);
    }
  }
  if( next <= GOAL )
    lst_rsort_R(toB, fromB, r, next, GOAL);
  else {
    int i;
    for(i = 1; i < r; i++) {
      lst_concat(toB[0], toB[i]);
    }
  }
}

void lst_rsort(LIST *l, int N){
  if(N <= 1)
    return;
  LIST *fromB[N];
  LIST *toB[N];
  int i;
  int max = 0;
  for(i = 0; i < N; i++){
    fromB[i] = lst_create();
    toB[i] = lst_create();
  }
  while(!lst_is_empty(l)){
    int data = lst_pop_front(l);
    lst_push_back(fromB[data%N], data);
    max = (data > max) ? data : max;
  }
  lst_rsort_R(fromB, toB, N, N, max);
  lst_concat(l, (lst_length(toB[0]) > lst_length(fromB[0])) ? toB[0] : fromB[0]);
  for(i = 0; i < N; i++){
    lst_free(fromB[i]);
    lst_free(toB[i]);
  }
}

int main(int argc, char *argv[]) {
  int val = 0;
  int n = 0;
  LIST *data = lst_create();

  printf("Please input integers to sort (any non-number to quit):\n");
  while(scanf("%i", &val) && val >= 0) { 
     lst_push_back(data, val); 
     n++; 
  } 
  lst_rsort(data, n);
  lst_print(data);
  lst_free(data);
  return 0;
}
