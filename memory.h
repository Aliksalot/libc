void memswp(void* ptr1, void*ptr2, size_t size){
  void* buf = malloc(size);
  memcpy(buf, ptr1, size);
  memcpy(ptr1, ptr2, size);
  memcpy(ptr2, buf, size); 
  free(buf);
}
