#include "dynarray_i32.h"

#define NEW(var)                             \
do {                                       \
     var = malloc ( sizeof(*var) );          \
     if ( !var )                             \
       fprintf (stderr, "Error allocating memory\n"); \
  } while ( 0 )

#define FREE(var)                             \
do {                                       \
     free ( var );          \
  } while ( 0 )

#define T dynarray_i32

struct T {
  size_t size;
  size_t capacity;
  int32_t * data;
};

T Dynarray_i32_new( void ){
  T dyna;
  NEW ( dyna );
  dyna -> size = 0;
  dyna -> capacity = 0;
  dyna -> data = NULL;
  return dyna;
}


int32_t* Dynarray_i32_at    (T vector, size_t position);
int32_t* Dynarray_i32_front (T vector);
int32_t* Dynarray_i32_back  (T vector);
int32_t* Dynarray_i32_data  (T vector);

void Dynarray_i32_free( T* dyna ){
  FREE ( ( *dyna ) -> data );
  FREE ( ( *dyna ));
  *dyna = NULL;
}


int main ()
{
  dynarray_i32 myd = Dynarray_i32_new();


  Dynarray_i32_free ( &myd );

  return 0;
}
