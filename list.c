#include <stdio.h>
#include "list.h"

generate_sig_list(int)

generate_impl_list(int)

int main() {
  list(int) l;
  list(int) *lptr = &l;
  list_init(int, lptr);
  list_insert_front(int, lptr, 1);
  list_insert_front(int, lptr, 2);
  list_insert_front(int, lptr, 3);
  list_insert_front(int, lptr, 4);
  list_insert_front(int, lptr, 5);
  list_insert_front(int, lptr, 6);
  for (int i = 0; i < list_size(int, lptr); i++) {
    printf("%d\n", list_get(int, lptr, i));
  }
}
