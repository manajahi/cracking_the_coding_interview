#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

extern void *Mem_alloc  ( long nbytes,             const char *file, int line );
extern void *Mem_calloc ( long nbytes, long count, const char *file, int line );
extern void  Mem_free   ( void *ptr,               const char *file, int line );
extern void *Mem_resize ( void *ptr, long nbytes,  const char *file, int line );


#define ALLOC(nbytes)				\
  Mem_alloc ( ( nbytes ), __FILE__, __LINE__ )

#define CALLOC(count, nbytes)			\
  Mem_calloc ( ( nbytes ), ( count ),  __FILE__, __LINE__ )

#define FREE(ptr)							\
  ( (void) Mem_free ( ( ptr ), __FILE__, __LINE__ ), ( ptr ) = 0 )

#define RESIZE(ptr, nbytes)						\
  ( (ptr) = Mem_resize ( ( ptr ), ( nbytes ),  __FILE__, __LINE__ ) )

#define NEW(p) ( ( p ) = ALLOC ( sizeof *( p ) ) )

#define NEW0(p) ( ( p ) = CALLOC ( sizeof *( p ), 1 ) )

#endif //__MEMORY_H__
