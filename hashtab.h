#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

#define generate_sig_hash_tab(T)                                             \
typedef struct hash_tab(T) {                                                 \
  size_t   n;                                                                \
  size_t   rows;                                                             \
  list(T) *tab;                                                              \
  size_t (*hash)(T);                                                         \
} hash_tab(T);                                                               \
                                                                             \
inline static void hashTo(hash_tab(T) * h, T val);                           \
void fn(hash_init, T)(hash_tab(T) * h, size_t size);                         \
void fn(hash_new, T)(size_t size);                                           \
void fn(hash_del, T)(hash_tab(T) * h);                                       \
void fn(hash_insert, T)(hash_tab(T) * h, T val);                             \
void fn(hash_remove, T)(hash_tab(T) * h, T val);                             \
bool fn(hash_contains, T)(hash_tab(T) * h, T val);                           \
T    fn(hash_get, T)(hash_tab(T) * h, T val);                                

/* Type macro */
#define hash_tab(T) paramType(hash_tab, T)

/* Helpers */
#define hashTo(T, h, val)              fn(hashTo, T)(h, val)

/* Constructors / Destructors */
#define hash_init(T, h, size)          fn(hash_init, T)(h, size)
#define hash_new(T, size)              fn(hash_new, T)(size)
#define hash_del(T, h)                 fn(hash_del, T)(h)

/* Insertion / Removal / Access */
#define hash_insert(T, h, val)         fn(hash_insert, T)(h, val)
#define hash_remove(T, h, val)         fn(hash_remove, T)(h, val)
#define hash_contains(T, h, val)       fn(hash_contains, T)(h, val)
#define hash_get(T, h, val)            fn(hash_get, T)(h, val)

#define generate_impl_hash_tab(T)                                            \
inline static void hashTo(hash_tab(T) * h, T val) {                          \
  return (h->hash ? h->hash(val) : val) % h->rows;                           \
}                                                                            \
                                                                             \
void fn(hash_init, T)(hash_tab(T) * h, size_t size) {                        \
  h->n = 0;                                                                  \
  h->rows = size;                                                            \
  h->tab = malloc(sizeof(list(T)) * size);                                   \
  for (int i = 0; i < size; i++) {                                           \
    list_init(T, h->tab[i]);                                                 \
  }                                                                          \
  h->hash = NULL;                                                            \
}                                                                            \
                                                                             \
void fn(hash_new, T)(size_t size) {                                          \
  hash_tab(T) * h = malloc(sizeof(hash_tab(T)));                             \
  fn(hash_init, T)(h, size);                                                 \
  return h;                                                                  \
}                                                                            \
                                                                             \
void fn(hash_del, T)(hash_tab(T) * h) {                                      \
  for (int i = 0; i < size; i++) {                                           \
    list_del(h->tab[i]);                                                     \
  }                                                                          \
  free(h->tab);                                                              \
}                                                                            \
                                                                             \
void fn(hash_insert, T)(hash_tab(T) * h, T val) {                            \
  list(T) * row = &h->tab[hashTo(h, val)];                                   \
  list_insert_unique(row, val);                                              \
}                                                                            \
                                                                             \
void fn(hash_remove, T)(hash_tab(T) * h, T val) {                            \
  list(T) * row = &h->tab[hashTo(h, val)];                                   \
  list_remove(row, val);                                                     \
}                                                                            \
                                                                             \
bool fn(hash_contains, T)(hash_tab(T) * h, T val) {                          \
  list(T) * row = &h->tab[hashTo(h, val)];                                   \
  list_contains(row, val);                                                   \
}                                                                            \
                                                                             \
T fn(hash_get, T)(hash_tab(T) * h, T val) {                                  \
  list(T) * row = &h->tab[hashTo(h, val)];                                   \
  list_get_elem(row, val);                                                   \
}                                                                            

/*
void fn(hash_resize, T)(hash_tab(T) * h, size_t size) {
}
*/
