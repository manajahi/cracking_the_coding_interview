#ifndef __DYNARRAY__I32_H__
#define __DYNARRAY__I32_H__

#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>


#define T dynarray_i32
typedef struct T* T;

T Dynarray_i32_new();
int32_t* Dynarray_i32_at    ( T vector, size_t position );
int32_t* Dynarray_i32_front ( T vector );
int32_t* Dynarray_i32_back  ( T vector );
int32_t* Dynarray_i32_data  ( T vector );
void Dynarray_i32_free      ( T* );

#endif //__DYNARRAY__I32_H__
