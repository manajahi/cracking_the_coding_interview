#include "dynarray_i32.h"

#define T dynarray_i32

struct T {
  size_t size;
  size_t capacity;
  int32_t *data;
};


T Dynarray_i32_new( void ){
  T vector;
  NEW ( vector );
  vector -> size = 0;
  vector -> capacity = INITIAL_CAPACITY;
  vector -> data = CALLOC ( INITIAL_CAPACITY, sizeof ( *vector->data ) );
  return vector;
}

size_t Dynarray_get_size( T vector ){
  return vector -> size;
}

size_t Dynarray_get_capacity( T vector ){
  return vector -> capacity;
}

static void Dynarray_i32_expand ( T vector, size_t new_capacity ){
  assert ( new_capacity >= vector -> capacity );
  RESIZE(vector->data, new_capacity);
  vector -> capacity = new_capacity;
}

static void Dynarray_i32_expand_default ( T vector ){
  size_t new_capacity = vector->capacity * EXPANSION_FACTOR;
  Dynarray_i32_expand ( vector, new_capacity );
}

int32_t Dynarray_i32_get    ( T vector, size_t position ){
  assert ( position < vector -> size );
  return vector -> data [ position ];
}


void Dynarray_i32_set    ( T vector, int32_t elt, size_t position ){
  if ( position >= vector -> capacity )
    // TODO: correct next buggy line
    Dynarray_i32_expand ( vector,  position ); 
    

  vector -> data [ position ] = elt;

  if ( position >= vector -> size ){
    vector -> size = position + 1;
  }
}


void Dynarray_i32_push_back ( T vector, int32_t elt ){
  ++vector -> size;
  if ( vector -> size >= vector -> capacity )
    Dynarray_i32_expand_default ( vector );
  
  vector -> data [ vector -> size++ ] = elt; 
}

void Dynarray_i32_free( T *vector ){
  FREE ( ( *vector ) -> data );
  FREE ( *vector );
  *vector = NULL;
}


int main ()
{
  dynarray_i32 myd = Dynarray_i32_new();


  Dynarray_i32_free ( &myd );

  return 0;
}
