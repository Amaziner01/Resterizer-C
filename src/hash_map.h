#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>

struct bucket
{
    const char  *key;
    void        *value;
};

struct hash_map
{
    unsigned    size;
    struct      bucket *data;
};

typedef struct hash_map hash_map_t;

hash_map_t *hash_map_init();

void hash_map_insert(hash_map_t *hm, const char *key, void *ptr);

void *hash_map_get(hash_map_t *hm, const char *key);

void hash_map_terminate(hash_map_t *hm);

#endif
