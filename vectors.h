#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"./memory.h"

#define VECTOR_STEP 100

struct vec{
  void* st;
  size_t sizeoft;
  size_t count;
};

struct vec vector_new(size_t vec_size){
  return(struct vec) { .st = 0, .count = 0, .sizeoft = vec_size };
}

void vector_push(struct vec* vec, void* el){
  if(vec->count % VECTOR_STEP == 0){
    vec->st = realloc(vec->st, vec->sizeoft * (vec->count + VECTOR_STEP));
  }
  vec->count ++;
  memcpy(vec->st + vec->sizeoft * (vec->count - 1), el, vec->sizeoft);
}

void* vector_get(struct vec* vec, size_t index){
  return vec->st + index * vec->sizeoft;
}

void vector_pop(struct vec* vec, void* dest){
  vec->count --;
  memcpy(dest, vec->st + vec->count * vec->sizeoft, vec->sizeoft);
  if(vec->count % VECTOR_STEP == 0){
    vec->st = realloc(vec->st, vec->sizeoft * vec->count);
  }
}

bool vector_is_empty(struct vec* vec){
  return vec->count <= 0;
}

void vector_free(struct vec* vec){
  free(vec->st);
}
void vector_sort_selection(struct vec* vec, bool (*cond_func)(void*, void*)){
  //bubble sort
  size_t curr = 0;
  for(size_t i = 0; i < vec->count - 1; i ++){
    size_t max_ind = i;
    for(size_t j = i + 1; j < vec->count; j ++){
      if(cond_func(vec->st + vec->sizeoft * j, vec->st + vec->sizeoft * i)){
        memswp(vec->st + vec->sizeoft * j, vec->st + vec->sizeoft * i, vec->sizeoft);
      }
    }
  }
}
