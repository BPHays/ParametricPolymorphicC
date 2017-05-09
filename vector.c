#include <stdio.h>
#include <stdbool.h>

#include "vector.h"

generate_sig_vector(int)

generate_impl_vector(int)

#define runtest(test)                    \
          if (test()) {                  \
            printf("%s passed\n", #test);  \
          } else {                       \
            printf("%s failed\n", #test);  \
          }                              

bool push_test() {
  vector(int) v;
  vector(int) *vptr = &v;
  int array [] = {5, 6, 7, 8};
  vector_init(int, vptr, 10);
  for (int i = 0; i < sizeof(array)/sizeof(*array); i++) {
    //vector_push(int, vptr, array[i]);
    vptr->m(push)(vptr, array[i]);
  }
  for (int i = 0; i < vector_size(int, vptr); i++) {
    if(array[i] != vector_at(int, vptr, i))
      return false;
  }
  return true;
}

bool pop_test() {
  vector(int) v;
  vector(int) *vptr = &v;
  int array [] = {5, 6, 7, 8};
  vector_init(int, vptr, 10);
  for (int i = 0; i < sizeof(array)/sizeof(*array); i++) {
    vector_push(int, vptr, array[i]);
  }
  int n = vector_size(int, vptr);
  vector_pop(int, vptr);
  return vector_size(int, vptr) != n;
}

int main() {
  runtest(push_test);
  runtest(pop_test);
}
