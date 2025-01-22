#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"../hashmap.h"

#define get hashmap_get
#define HASHMAP_SIZE 100

int main(void){

  printf("Running test on [hashmap.h]...\n");

  hashmap_t map = hashmap_new(sizeof(char*));

  printf("[hashmap.h] hashmap_new OK\n");

  for(int i = 1; i < 200; i ++){
    char *key = (char*)malloc(4 * sizeof(char));
    int cp = i;
    for(int j = 0; j < 3; j ++){
      key[2 - j] = (cp % 10) + (int)'0';
      cp /= 10;
    }
    key[3] = '\0';
    hashmap_set(&map, key, &i);
    free(key);
  }

  printf("[hashmap.h] pushing 200 numbers OK\n");

  //hashmap_dump_ints(&map);

  bool ok = true;
  for(int i = 1; i < 200; i ++){
    char *key = (char*)malloc(4 * sizeof(char));
    int cp = i;
    for(int j = 0; j < 3; j ++){
      key[2 - j] = (cp % 10) + (int)'0';
      cp /= 10;
    }
    key[3] = '\0';
    hashmap_node_t *node = hashmap_get(&map, key);
    if(*(int*)node->value != i){
      ok = false;
      printf("[hashmap.h] FAIL:\n");
      printf("            expected { %s: %d };\n", key, i);
      printf("            but got { %s: %d };\n", node->key, *(int*)node->value);
    }
    free(key);
  }

  if(ok) {
    printf("[hashmap.h] Value fetching and accuracy OK\n");
  }

  printf("[hashmap.h] free OK\n");
  hashmap_free(&map);
  printf("[hashmap.h] ALL OK\n");
  printf("continuing...\n");
  return 0;
}

