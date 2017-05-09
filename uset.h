#include "hashtab.h"

/* Wrapper around the hash table to make an unordered set */

/* Type macro */
#define uset(T) hash_tab(T)

/* Constructors / Destructors */
#define uset_init(T, h, size)            hash_init(T, h, size)
#define uset_new(T, size)                hash_new(T, size)
#define uset_del(T, h)                   hash_del(T, h)

/* Insertion / Removal / Access */
#define uset_insert(T, h, val)           hash_insert(T, h, val)
#define uset_remove(T, h, val)           hash_remove(T, h, val)
#define uset_contains(T, h, val)         hash_contains(T, h, val)
#define uset_get(T, h, val)              hash_get(T, h, val)
