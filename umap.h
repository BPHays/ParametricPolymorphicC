#include "hashtab.h"
#include "pair.h"

/* Wrapper around the hash table to make an unordered map */

/* Type macro */
#define umap(K, V) hash_tab(pair(K, V))

/* Constructors / Destructors */
#define uset_init(K, V, h, size)            hash_init(pair(K, V), h, size)
#define uset_new(K, V, size)                hash_new(pair(K, V), size)
#define uset_del(K, V, h)                   hash_del(pair(K, V), h)

/* Insertion / Removal / Access */
#define uset_insert(K, V, h, val)           hash_insert(pair(K, V), h, val)
#define uset_remove(K, V, h, val)           hash_remove(pair(K, V), h, val)
#define uset_contains(K, V, h, val)         hash_contains(pair(K, V), h, val)
#define uset_get(K, V, h, val)              hash_get(pair(K, V), h, val)

/* Hash function to hash keys */

/* Compare function to compare keys */
