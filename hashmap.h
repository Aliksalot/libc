#include<stdlib.h>
#include<string.h>

#define HASHMAP_SIZE 100

typedef struct hashmap_node{
  char* key;
  void* value;
} hashmap_node_t;

typedef struct hashmap{
  size_t size;
  hashmap_node_t *nodes[HASHMAP_SIZE];
} hashmap_t;

//djb2 hashing function
unsigned long hash(char* str){
  unsigned long hash = 5381;
  int c;
  while((c = *str++)){
    hash = ((hash << 5) + hash) + c;
  }
  return hash % HASHMAP_SIZE;
}

hashmap_t hashmap_new(size_t size){
  return (hashmap_t){ .size=size };
}

void hashmap_set(hashmap_t *hashmap, char *key, void *val) {

  hashmap_node_t *new_node = (hashmap_node_t *)malloc(sizeof(hashmap_node_t));

  new_node->key = strdup(key);
  new_node->value = malloc(hashmap->size);
  memcpy(new_node->value, val, hashmap->size);

  hashmap->nodes[hash(key)] = new_node;
}

hashmap_node_t* hashmap_get(hashmap_t *hashmap, char* key) {
  return hashmap->nodes[hash(key)];
}

void hashmap_dump_ints(hashmap_t *hashmap) {
  printf("{\n");
  for(int i = 0; i < HASHMAP_SIZE; i ++){
    hashmap_node_t *node = hashmap->nodes[i];
    if(node){
      printf("  %10s: %d\n", node->key, *(int*)node->value);
    }
  }
  printf("}\n");
}

void hashmap_free(hashmap_t *hashmap){
  for(int i = 0; i < HASHMAP_SIZE; i ++){
    hashmap_node_t *node = hashmap->nodes[i];
    if(node){
      free(node->key);
      free(node->value);
      free(node);
    }
  }
}


