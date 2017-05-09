#include <stdio.h>
#include "hashtab.h"

generate_sig_hash_tab(int)

generate_impl_hash_tab(int)

int main() {
  hash_tab(int) h;
  hash_init(int, &h, 32);
  hash_insert(int, &h, 12);
  printf("contains %d\n", hash_contains(int, &h, 12));
  printf("contains %d\n", hash_contains(int, &h, 18));
}
