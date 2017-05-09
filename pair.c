#include <stdio.h>
#include <stdbool.h>

#include "pair.h"

generate_sig_pair(int, float)

generate_impl_pair(int, float)

#define runtest(test)                    \
          if (test()) {                  \
            printf("%s passed\n", #test);  \
          } else {                       \
            printf("%s failed\n", #test);  \
          }                              

int main() {
  pair(int, float) p;
  pair_set(int, float, &p, 1337, 3.14);
  printf("%d x %f\n", pair_fst(int, float, &p), pair_snd(int, float, &p));
}
