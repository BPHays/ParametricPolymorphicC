#include <stdlib.h>

#include "containers.h"

/* Generic header for vector of type T */
#define generate_sig_vector(T)                                               \
typedef struct vector(T) {                                                   \
  size_t n;                                                                  \
  size_t size;                                                               \
  T * array;                                                                 \
  struct interface( vector, T ) * methods;                                   \
} vector(T);                                                                 \
                                                                             \
struct interface( vector, T ) {                                              \
  void   (* del)     (vector(T) *);                                          \
  void   (* push)    (vector(T) *, T);                                       \
  T      (* pop)     (vector(T) *);                                          \
  T      (* at)      (vector(T) *, size_t);                                  \
  void   (* set)     (vector(T) *, size_t, T);                               \
  size_t (* size)    (vector(T) *);                                          \
  size_t (* max_size)(vector(T) *);                                          \
  void   (* clear)   (vector(T) *);                                          \
  T *    (* data)    (vector(T) *);                                          \
};                                                                           \
                                                                             \
static void fn(vector_resize, T)(vector(T) * v, size_t newSize);             \
void fn(vector_init, T)(vector(T) * v, size_t size);                         \
vector(T) * fn(vector_new, T)(size_t size);                                  \
void fn(vector_del, T)(vector(T) * v);                                       \
void fn(vector_push, T)(vector(T) * v, T elem);                              \
T fn(vector_pop, T)(vector(T) * v);                                          \
T fn(vector_at, T)(vector(T) * v, size_t i);                                 \
void fn(vector_set, T)(vector(T) * v, size_t i, T elem);                     \
size_t fn(vector_size, T)(vector(T) * v);                                    \
size_t fn(vector_max_size, T)(vector(T) * v);                                \
void fn(vector_clear, T)(vector(T) * v);                                     \
T * fn(vector_data, T)(vector(T) * v);                                      

#define vector(T) paramType(vector, T)

/* Helpers */
#define vector_resize(T, v, size) fn(vector_resize,  T)(v, size)

/* Constructors / Destructors */
#define vector_init(T, v, size)   fn(vector_init, T)(v , size)
#define vector_new(T, size)       fn(vector_new,  T)(size)
#define vector_del(T, v)          fn(vector_del,  T)(v)

/* Insertion / Removal */
#define vector_push(T, v, elem)   fn(vector_push, T)(v, elem) 
#define vector_pop(T, v)          fn(vector_pop,  T)(v)
#define vector_at(T, v, i)        fn(vector_at,   T)(v, i)
#define vector_set(T, v, i, elem) fn(vector_set,  T)(v, i, elem)

/* Field access */
#define vector_size(T, v)         fn(vector_size,     T)(v)
#define vector_max_size(T, v)     fn(vector_max_size, T)(v)
#define vector_clear(T, v)        fn(vector_clear,    T)(v)
#define vector_data(T, v)         fn(vector_data,     T)(v)

/* Generic implementation for vector of type T */
#define generate_impl_vector(T)                                              \
                                                                             \
/* Assign interface struct */                                                \
struct interface( vector, T ) interface( vector, T ) = {                     \
  .del      = fn(vector_del, T),                                             \
  .push     = fn(vector_push, T),                                            \
  .pop      = fn(vector_pop, T),                                             \
  .at       = fn(vector_at, T),                                              \
  .set      = fn(vector_set, T),                                             \
  .size     = fn(vector_size, T),                                            \
  .max_size = fn(vector_max_size, T),                                        \
  .clear    = fn(vector_clear, T),                                           \
  .data     = fn(vector_data, T)                                             \
};                                                                           \
                                                                             \
/* Function impelementations */                                              \
static void fn(vector_resize, T)(vector(T) * v, size_t newSize) {            \
  v->size  = newSize;                                                        \
  v->array = realloc(v->array, v->size);                                     \
}                                                                            \
                                                                             \
void fn(vector_init, T)(vector(T) * v, size_t size) {                        \
  v->n = 0;                                                                  \
  v->size = size;                                                            \
  v->array = malloc(size);                                                   \
  v->methods = &interface(vector, T);                                        \
}                                                                            \
                                                                             \
vector(T) * fn(vector_new, T)(size_t size) {                                 \
  vector(T) * v = malloc(sizeof(vector(T)));                                 \
  fn(vector_init, T)(v, size);                                               \
  return v;                                                                  \
}                                                                            \
                                                                             \
void fn(vector_del, T)(vector(T) * v) {                                      \
  free(v->array);                                                            \
}                                                                            \
                                                                             \
void fn(vector_push, T)(vector(T) * v, T elem) {                             \
  if(v->n >= v->size) {                                                      \
    vector_resize(T, v, v->size * 2);                                        \
  }                                                                          \
  v->array[v->n++] = elem;                                                   \
}                                                                            \
                                                                             \
T fn(vector_pop, T)(vector(T) * v) {                                         \
  return v->array[--v->n];                                                   \
}                                                                            \
                                                                             \
T fn(vector_at, T)(vector(T) * v, size_t i) {                                \
  return v->array[i];                                                        \
}                                                                            \
                                                                             \
void fn(vector_set, T)(vector(T) * v, size_t i, T elem) {                    \
  if (i > v->size) {                                                         \
    /* TODO                                                                  \
     * Maybe update size to nearest power of 2?                              \
     */                                                                      \
    vector_resize(T, v, i + 1);                                              \
    v->n = i;                                                                \
  }                                                                          \
  v->array[i] = elem;                                                        \
}                                                                            \
                                                                             \
size_t fn(vector_size, T)(vector(T) * v) {                                   \
  return v->n;                                                               \
}                                                                            \
                                                                             \
size_t fn(vector_max_size, T)(vector(T) * v) {                               \
  return v->size;                                                            \
}                                                                            \
                                                                             \
void fn(vector_clear, T)(vector(T) * v) {                                    \
  v->n = 0;                                                                  \
}                                                                            \
                                                                             \
T * fn(vector_data, T)(vector(T) * v) {                                      \
  return v->array;                                                           \
}                                                                            \
