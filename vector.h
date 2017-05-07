
#define vector(T) vector__ ## T ## __

#define fn(name, T) name ## __ ## T ## __

/* Generic header for vector of type T */
#define generate_sig_vector(T)                                               \
struct {                                                                     \
  size_t n;                                                                  \
  size_t size;                                                               \
  T * array;                                                                 \
} vector(T);                                                                 \
static void vector_resize(vector(T) * v, size_t newSize);                    \
void fn(vector_init, T)(vector(T) * v, size_t size);                         \
void fn(vector_new, T)(size_t size);                                         \
void fn(vector_del, T)(vector(T) * v);                                       \
void fn(vector_push, T)(vector(T) * v, T elem);                              \
T fn(vector_pop, T)(vector(T) * v);                                          \
T fn(vector_at, T)(vector(T) * v, size_t i);                                 \
void fn(vector_set, T)(vector(T) * v, size_t i, T elem);                     

/* Helpers */
#define vector_resize(T, vector(T) *, size) fn(vector_set,  T)(vector(T) *, size)

/* Constructors / Destructors */
#define vector_init(T, size)                fn(vector_init, T)(size, vector(T) *)
#define vector_new(T, size)                 fn(vector_new,  T)(size)
#define vector_del(T, vector(T) *)          fn(vector_del,  T)(vector(T) *)

/* Insertion / Removal */
#define vector_push(T, vector(T) *, elem)   fn(vector_push, T)(vector(T) *, elem) 
#define vector_pop(T, vector(T) *)          fn(vector_pop,  T)(vector(T) *)
#define vector_at(T, vector(T) *, i)        fn(vector_at,   T)(vector(T) *, i)
#define vector_set(T, vector(T) *, i, elem) fn(vector_set,  T)(vector(T) *, i, elem)

/* Generic implementation for vector of type T */
#define generate_impl_vector(T)                                              \
static void vector_resize(vector(T) * v, size_t newSize) {                   \
  v->size  = newSize;                                                        \
  v->array = realloc(v->array, v->size);                                     \
}                                                                            \
                                                                             \
void fn(vector_init, T)(vector(T) * v, size_t size) {                        \
  v->n = 0;                                                                  \
  v->size = size;                                                            \
  v->array = malloc(size);                                                   \
}                                                                            \
                                                                             \
void fn(vector_new, T)(size_t size) {                                        \
  vector(T) * v = malloc(sizeof(vector(T)));                                 \
  vector_init(v, size);                                                      \
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
}                                                                            
