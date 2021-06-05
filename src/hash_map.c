#include "hash_map.h"
#include <string.h>

unsigned hash(const char *key)
{
    unsigned hash = 0;
    char c;
    for (char *p = (char*)key; (c = *p) != 0; p++)
        hash += c;
    
    hash ^= 7521453792 * c;

    return hash;
}

hash_map_t *hash_map_init()
{
    hash_map_t *hm = (hash_map_t*)malloc(sizeof(hash_map_t));
    hm->size = 10;
    hm->data = (struct bucket*)calloc(10, sizeof(struct bucket));

    return hm;
}

void hash_map_insert(hash_map_t *hm, const char *key, void *ptr)
{
    unsigned index = hash(key) % hm->size;
    struct bucket *bucket = &hm->data[index];

    if (!bucket->key) goto write;
    
    if (!strcmp(bucket->key, key))
    {
        bucket->value = ptr;
        return;
    }

    while (hm->data[index].key)
    {
        unsigned new_size = hm->size * 2;
        struct bucket *new_data = calloc(new_size, sizeof(struct bucket));
        for (int i = 0; i < hm->size; i++)
        {
            if(hm->data[i].key)
            {
                struct bucket new_bucket = { hm->data[i].key, hm->data[i].value };
                new_data[hash(hm->data[i].key) % new_size] = new_bucket;
            }
        }
        
        free(hm->data);
        hm->data = new_data;
        hm->size = new_size;
        index = hash(key) % new_size;
        bucket = &hm->data[index];
    }

write:

    bucket->value = ptr;
    bucket->key = key;

}

void *hash_map_get(hash_map_t *hm, const char *key)
{
    unsigned index = hash(key) % hm->size;
    struct bucket *bucket = &hm->data[index];

    if (bucket->key) return bucket->value;
    return NULL;
}

void hash_map_terminate(hash_map_t *hm)
{
    free(hm->data);
    free(hm);
    hm = NULL;
}
