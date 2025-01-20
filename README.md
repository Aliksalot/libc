# libc
C utils

## Vectors

### ```struct vec```

#### ```void* st```

- points to start of vector.

#### ```size_t sizeoft```

- size of each element in vector.

#### ```size_t count```

- count of elements present in vector

### ```struct vec vector_new(size_t vec_size)```

#### usage

Creates a new vector with elements of size ```size_t vec_size```

##### params
```size_t vec_size``` - sizeof type of elements

#### returns
```vec struct``` with ```void* st``` set to ```NULL```

### ```void* vector_get(struct vec* vec, size_t index)```

#### usage

Returns element at index in vector

##### params

```struct vec* vec``` - the vector to perform operation on
```size_t index``` - the index of the element to retrieve

##### returns
```void*``` to the element inside the vector

### ```void vector_push(struct vec* vec, void* el)```

#### usage

- Pushes element at the end of vector.
- If not enough space allocated allocates ```VECTOR_STEP * vec->sizeoft``` more bits using ```realloc()```.
  
##### params
```struct vec* vec``` - the vector to perform operation on
```void* el``` - pointer to an element to be pushed at the end of vector

### ```void vector_pop(struct vec* vec, void* dest)

#### usage

- Copies element at end of vector into ```void* dest```.
- Deallocates memory in steps of ```VECTOR_STEP``` elements.

##### params

```struct vec* vec``` - the vector to perform operation on
```void* dest``` - location in which to copy the result of the pop

### ```void vector_free(struct vec* vec)```

#### usage

- Frees allocated memory at ```vec->st```

##### params

```struct vec* vec``` - the vector to perform operation on

### ```bool vector_is_empty(struct vec* vec)```

#### usage

- Check if vector is empty

#### params

```struct vec* vec``` - the vector to perform operation on

#### returns

```bool``` - Whether ot not the vector has any elements in it





