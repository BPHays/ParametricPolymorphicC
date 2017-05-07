#include <stdio.h>
#include "vector.h"

generate_sig_vector(int);
generate_impl_vector(int);

/*
typedef float f;
generate_vector_sig(f);
generate_vector(f);

int main() {
  int_vector v;
  int_vector *vptr = &v;
  int_vector_init(10, vptr);
  int_vector_push_back(vptr, 5);
  int_vector_push_back(vptr, 6);
  int_vector_push_back(vptr, 7);
  int_vector_push_back(vptr, 8);
  for (int i = 0; i < 4; i++) {
    printf("%d\n", int_vector_at(vptr, i));
  }

  f_vector v2;
  f_vector *v2ptr = &v2;
  f_vector_init(5, v2ptr);
  f_vector_push_back(v2ptr, 3.14);
  printf("%f\n", f_vector_at(v2ptr, 0));
}
*/
