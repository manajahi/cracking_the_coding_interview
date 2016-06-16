#ifndef __DYNARRAY__I32_H__
#define __DYNARRAY__I32_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"


#define T dynarray_i32
#define INITIAL_CAPACITY 64
#define EXPANSION_FACTOR 2

typedef struct T *T;

T Dynarray_i32_new();

size_t   Dynarray_get_size     ( T vector );
size_t   Dynarray_get_capacity ( T vector );
int32_t *Dynarray_i32_at       ( T vector, size_t position );
int32_t *Dynarray_i32_front    ( T vector );
int32_t *Dynarray_i32_back     ( T vector );
int32_t *Dynarray_i32_data     ( T vector );

void Dynarray_i32_free         ( T * );

#endif //__DYNARRAY__I32_H__
