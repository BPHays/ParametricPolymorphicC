#include "containers.h"

#define generate_sig_pair(T1, T2)                                            \
typedef struct pair(T1, T2) {                                                \
  T1 fst;                                                                    \
  T2 snd;                                                                    \
} pair(T1, T2);                                                              \
                                                                             \
T1   fn2(pair_fst, T1, T2)(pair(T1, T2) * p);                                \
T2   fn2(pair_snd, T1, T2)(pair(T1, T2) * p);                                \
void fn2(pair_set, T1, T2)(pair(T1, T2) * p, T1 fst, T2 snd);                \
void fn2(pair_set_fst, T1, T2)(pair(T1, T2) * p, T1 fst);                    \
void fn2(pair_set_snd, T1, T2)(pair(T1, T2) * p, T2 snd);                    \

/* Type macro */
#define pair(T1, T2) paramType2(pair, T1, T2)

/* Access */
#define pair_fst(T1, T2, p)           fn2(pair_fst, T1, T2)(p)
#define pair_snd(T1, T2, p)           fn2(pair_snd, T1, T2)(p)
#define pair_set(T1, T2, p, fst, snd) fn2(pair_set, T1, T2)(p, fst, snd)
#define pair_set_fst(T1, T2, p, fst)  fn2(pair_fst, T1, T2)(p, fst)
#define pair_set_snd(T1, T2, p, snd)  fn2(pair_fst, T1, T2)(p, snd)

#define generate_impl_pair(T1, T2)                                            \
T1 fn2(pair_fst, T1, T2)(pair(T1, T2) * p) {                                  \
  return p->fst;                                                              \
}                                                                             \
                                                                              \
T2 fn2(pair_snd, T1, T2)(pair(T1, T2) * p) {                                  \
  return p->snd;                                                              \
}                                                                             \
                                                                              \
void fn2(pair_set, T1, T2)(pair(T1, T2) * p, T1 fst, T2 snd) {                \
  p->fst = fst;                                                               \
  p->snd = snd;                                                               \
}                                                                             \
                                                                              \
void fn2(pair_set_fst, T1, T2)(pair(T1, T2) * p, T1 fst) {                    \
  p->fst = fst;                                                               \
}                                                                             \
                                                                              \
void fn2(pair_set_snd, T1, T2)(pair(T1, T2) * p, T2 snd) {                    \
  p->snd = snd;                                                               \
}                                                                             
