#include "memory.h"

void *Mem_alloc  ( long nbytes, const char *file, int line ){
  void *ptr;
  assert ( nbytes > 0 );
  ptr = malloc ( nbytes );
  if ( !ptr ){
    fprintf ( stderr, "Allocation failed @%s:%d", file, line );
    exit ( EXIT_FAILURE );
  }
  return ptr;
}


void *Mem_calloc ( long count, long nbytes, const char *file, int line ){
  void *ptr;
  assert ( nbytes > 0 );
  ptr = calloc ( count, nbytes );
  if ( !ptr ){
    fprintf ( stderr, "Allocation failed @%s:%d", file, line );
    exit ( EXIT_FAILURE );
  }
  return ptr;
}

void Mem_free   ( void *ptr, const char *file, int line ){
  if ( ptr )
    free ( ptr );
}

void *Mem_resize ( void *ptr, long nbytes, const char *file, int line ){
  assert ( ptr );
  assert ( nbytes > 0 );
  ptr = realloc ( ptr, nbytes );
  if ( !ptr ){
    fprintf ( stderr, "Allocation failed @%s:%d", file, line );
    exit ( EXIT_FAILURE );
  }
  return ptr;
}
