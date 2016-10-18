
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// very incomplete small test program...

int main() {
LIST *lst1;
LIST *lst2;
int i;
ElemType *arr1;

 arr1 = malloc(sizeof(ElemType) * 5);
  lst1 = lst_create();
  lst2 = lst_create();
  for(i=0; i<5; i++) {
     lst_push_front(lst1, i);
     arr1[i] = i;
  }
  for(i=0; i<5; i++) {
     lst_push_back(lst1, i);
  }

  printf("lst_length(lst1) : %i\n", lst_length(lst1));
  printf("lst1 contents: ");
  lst_print(lst1);


  lst_pop_front(lst1);
  lst_pop_front(lst1);
  printf("lst1 contents after two pops: ");
  lst_print(lst1);



  /** TODO:  test code here! **/


  /** test code for lst_count **/

  printf("number of 3's = %i\n", lst_count(lst1, 3));
  printf("number of 0's = %i\n", lst_count(lst1, 0));
  printf("number of 12's = %i\n", lst_count(lst1, 12));


  /** test code for lst_print_rev **/

  lst_print_rev(lst1);



  /** test code for lst_push_back **/
 
  /** test code fort lst_pop_back **/

  printf("lst1 contents: ");
  lst_print(lst1);


  lst_pop_back(lst1);
  lst_pop_back(lst1);
  printf("lst1 contents after two back pops: ");
  lst_print(lst1);


  /** test code for lst_reverse **/
  printf("Reversed list: ");
  lst_reverse(lst1);
  lst_print(lst1);

  /** test code for lst_is_sorted**/
  printf("List is sorted: %d\n", lst_is_sorted(lst1));
  
  lst_pop_front(lst1);
  lst_pop_front(lst1);
  lst_print(lst1);

  printf("List is sorted: %d\n", lst_is_sorted(lst1));

  lst_insert_sorted(lst1, 1);
  lst_insert_sorted(lst1, 4);
  lst_print(lst1); 

  printf("List is sorted: %d\n", lst_is_sorted(lst1));
 
  /** test code for lst_merge_sorted **/
  
  lst_insert_sorted(lst2, 1);
  lst_insert_sorted(lst2, 3);
  lst_insert_sorted(lst2, 5);
  lst_insert_sorted(lst2, 6);

  lst_merge_sorted(lst1, lst2);
  lst_print(lst1);
  
  /** test code for lst_clone **/

  LIST *copy = lst_clone(lst1);
  lst_print(copy);
  
  /** test code for lst_to_array and lst_from_array **/

  LIST *atol = lst_from_array(arr1, 5);
  lst_print(atol);
  ElemType *ltoa = lst_to_array(atol);
  printf("Array: [");
  for(i = 0; i<5; i++)
    printf(" %i ", ltoa[i]);
  printf("]\n");

  /** test code for concat **/

  lst_concat(lst1, lst1);
  lst_concat(lst1, atol);
  lst_print(lst1);

  /** test code for prefix **/

  lst2 = lst_prefix(lst1, 6);
  lst_print(lst1);
  lst_print(lst2);

  /** test code for filter **/
  printf("filter_leq\n");
  LIST *lst3 = lst_filter_leq(lst1, 3);
  lst_print(lst1);
  printf("List 1 length: %d", lst_length(lst1));
  lst_print(lst3);  
  printf("List 3 length: %d", lst_length(lst3));  


  /** sanity checks after all the manipulating **/
  lst_sanity1(lst1);
  lst_sanity2(lst1);
  lst_sanity3(lst1);
  
  lst_sanity1(lst2);
  lst_sanity2(lst2);
  lst_sanity3(lst2);
  
  
  lst_free(lst1);

}
  
