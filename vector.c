#include <stdio.h>
#include "vector.h"

generate_sig_vector(int)

generate_impl_vector(int)

int main() {
  vector(int) v;
  vector(int) *vptr = &v;
  vector_init(int, vptr, 10);
  vector_push(int, vptr, 5);
  vector_push(int, vptr, 6);
  vector_push(int, vptr, 7);
  vector_push(int, vptr, 8);
  vector_push(int, vptr, 8);
  vector_push(int, vptr, 8);
  vector_push(int, vptr, 8);
  for (int i = 0; i < vector_size(int, vptr); i++) {
    printf("%d\n", vector_at(int, vptr, i));
  }
}
