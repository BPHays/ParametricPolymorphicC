#include <stdbool.h>
#include <stdlib.h>

#include "containers.h"

/* Generic header for vector of type T */
#define generate_sig_list(T)                                                 \
typedef struct listNode(T) {                                                 \
  T val;                                                                     \
  struct listNode(T) * next;                                                 \
  struct listNode(T) * prev;                                                 \
} listNode(T);                                                               \
                                                                             \
typedef struct list(T) {                                                     \
  size_t size;                                                               \
  listNode(T) sentinel;                                                      \
  int (*cmpFunc)(T, T);                                                      \
} list(T);                                                                   \
                                                                             \
static void fn(insert_between, T)(listNode(T) *, listNode(T) *,              \
                                  listNode(T) *);                            \
static void fn(remove_node, T)(listNode(T) * node);                          \
void      fn(list_init, T)(list(T) * l);                                     \
list(T) * fn(list_new, T)();                                                 \
void      fn(list_del, T)(list(T) * l);                                      \
void      fn(list_insert_front, T)(list(T) * l, T val);                      \
void      fn(list_insert_back, T)(list(T) * l, T val);                       \
void      fn(list_remove_front, T)(list(T) * l);                             \
void      fn(list_remove_back, T)(list(T) * l);                              \
bool      fn(list_remove, T)(list(T) * l, T val);                            \
bool      fn(list_contains, T)(list(T) * l, T val);                          \
T         fn(list_get, T)(list(T) * l, size_t i);                            \
T         fn(list_get_elem, T)(list(T) * l, T val);                          \
void      fn(list_set_compare, T)(list(T) * l, int(*cmpFunc)(T, T));         \
size_t    fn(list_size, T)(list(T) * l);                                     

/* Type macro */
#define list(T)     paramType(list, T)
#define listNode(T) paramType(listNode, T)

/* Helpers */
#define insert_between(T, before, node, after)                               \
          fn(insert_between, T)(before, node, after)
#define remove_node(T, node) fn(remove_node, T)(node)

/* Constructors / Destructors */
#define list_init(T, l)                fn(list_init, T)(l)
#define list_new(T)                    fn(list_new, T)()
#define list_del(T, l)                 fn(list_del, T)(l)

/* Insertion / Removal */
#define list_insert_front(T, l, val)   fn(list_insert_front, T)(l, val)
#define list_insert_back(T, l, val)    fn(list_insert_back, T)(l, val)
#define list_remove_front(T, l)        fn(list_remove_front, T)(l)
#define list_remove_back(T, l)         fn(list_remove_back, T)(l)
#define list_remove(T, l, val)         fn(list_remove, T)(l, val)

/* Field access */
#define list_size(T, l)                fn(list_size, T)(l)

/* Misc. */
#define list_contains(T, l, val)       fn(list_contains, T)(l, val)
#define list_get(T, l, i)              fn(list_get, T)(l, i)
#define list_get_elem(T, l, val)       fn(list_get, T)(l, val)
#define list_set_compare(T, l, cmp)    fn(list_set_compare, T)(l, cmp)

/* Generic implementation for vector of type T */
#define generate_impl_list(T)                                                \
static void fn(insert_between, T)(listNode(T) * before,                      \
                                  listNode(T) * node,                        \
                                  listNode(T) * after) {                     \
  before->next = node;                                                       \
  after->prev = node;                                                        \
  node->next = after;                                                        \
  node->prev = before;                                                       \
}                                                                            \
                                                                             \
static void fn(remove_node, T)(listNode(T) * node) {                         \
  node->next->prev = node->prev;                                             \
  node->prev->next = node->next;                                             \
  free(node);                                                                \
}                                                                            \
                                                                             \
void fn(list_init, T)(list(T) * l) {                                         \
  l->cmpFunc = NULL;                                                         \
  l->size = 0;                                                               \
  l->sentinel.next = &l->sentinel;                                           \
  l->sentinel.prev = &l->sentinel;                                           \
}                                                                            \
                                                                             \
list(T) * fn(list_new, T)() {                                                \
  list(T) * l = malloc(sizeof(list(T)));                                     \
  fn(list_init, T)(l);                                                       \
  return l;                                                                  \
}                                                                            \
                                                                             \
void fn(list_del, T)(list(T) * l) {                                          \
  listNode(T) * node = l->sentinel.next;                                     \
  listNode(T) * next = NULL;                                                 \
  while(node != &l->sentinel) {                                              \
    next = node->next;                                                       \
    free(node);                                                              \
    node = next;                                                             \
  }                                                                          \
  free(l);                                                                   \
}                                                                            \
                                                                             \
void fn(list_insert_front, T)(list(T) * l, T val) {                          \
  listNode(T) * node = malloc(sizeof(listNode(T)));                          \
  node->val = val;                                                           \
  fn(insert_between, T)(&l->sentinel, node, l->sentinel.next);               \
  l->size++;                                                                 \
}                                                                            \
                                                                             \
void fn(list_insert_back, T)(list(T) * l, T val) {                           \
  listNode(T) * node = malloc(sizeof(listNode(T)));                          \
  node->val = val;                                                           \
  fn(insert_between, T)(l->sentinel.prev, node, &l->sentinel);               \
  l->size++;                                                                 \
}                                                                            \
                                                                             \
void fn(list_insert_unique, T)(list(T) * l, T val) {                         \
  if (!fn(list_contains, T)(l, val)) {                                       \
    fn(list_insert_front, T)(l, val);                                        \
  }                                                                          \
}                                                                            \
                                                                             \
void fn(list_remove_front, T)(list(T) * l) {                                 \
  listNode(T) * toRemove;                                                    \
  if (l->size > 0) {                                                         \
    fn(remove_node, T)(l->sentinel.next);                                    \
    l->size--;                                                               \
  }                                                                          \
}                                                                            \
                                                                             \
void fn(list_remove_back, T)(list(T) * l) {                                  \
  listNode(T) * toRemove;                                                    \
  if (l->size > 0) {                                                         \
    fn(remove_node, T)(l->sentinel.prev);                                    \
    l->size--;                                                               \
  }                                                                          \
}                                                                            \
                                                                             \
bool fn(list_remove, T)(list(T) * l, T val) {                                \
  listNode(T) * node;                                                        \
  for (node = l->sentinel.next; node != &l->sentinel; node = node->next) {   \
    if ((l->cmpFunc && !l->cmpFunc(node->val, val)) || node->val == val) {   \
      fn(remove_node, T)(node);                                              \
      l->size--;                                                             \
      return true;                                                           \
    }                                                                        \
  }                                                                          \
  return false;                                                              \
}                                                                            \
                                                                             \
bool fn(list_contains, T)(list(T) * l, T val) {                              \
  listNode(T) * node;                                                        \
  for (node = l->sentinel.next; node != &l->sentinel; node = node->next) {   \
    if ((l->cmpFunc && !l->cmpFunc(node->val, val)) || node->val == val) {   \
      return true;                                                           \
    }                                                                        \
  }                                                                          \
  return false;                                                              \
}                                                                            \
                                                                             \
void fn(list_set_compare, T)(list(T) * l, int(*cmpFunc)(T, T)) {             \
  l->cmpFunc = cmpFunc;                                                      \
}                                                                            \
                                                                             \
T fn(list_get, T)(list(T) * l, size_t i) {                                   \
  listNode(T) * node;                                                        \
  size_t count;                                                              \
  for (node = l->sentinel.next, count = 0;                                   \
       node != &l->sentinel && count < i;                                    \
       node = node->next, count++);                                          \
  return node->val;                                                          \
}                                                                            \
                                                                             \
T fn(list_get_elem, T)(list(T) * l, T val) {                                 \
  listNode(T) * node;                                                        \
  for (node = l->sentinel.next; node != &l->sentinel; node = node->next) {   \
    if ((l->cmpFunc && !l->cmpFunc(node->val, val)) || node->val == val) {   \
      return node->val;                                                      \
    }                                                                        \
  }                                                                          \
  return 0;                                                                  \
}                                                                            \
                                                                             \
size_t fn(list_size, T)(list(T) * l) {                                       \
  return l->size;                                                            \
}                                                                            
