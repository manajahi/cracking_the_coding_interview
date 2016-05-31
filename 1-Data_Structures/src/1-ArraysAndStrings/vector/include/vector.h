/* vector.h
 * Defines a C implementation of std::vector
 * 
 * Copyright 2016 Edmund Highan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ARRAYS_AND_STRINGS_VECTOR_H
#define ARRAYS_AND_STRINGS_VECTOR_H

#include "vector_impl/vector_i32.h"
#include "vector_impl/vector_i64.h"
#include "vector_impl/vector_u32.h"
#include "vector_impl/vector_u64.h"

#define vector_at(X,Y) _Generic((X),\
         vector_i8*:  vector_i8_at, \
        vector_i16*: vector_i16_at, \
        vector_i32*: vector_i32_at, \
        vector_i64*: vector_i64_at, \
         vector_u8*:  vector_u8_at, \
        vector_u16*: vector_u16_at, \
        vector_u32*: vector_u32_at, \
        vector_u64*: vector_u64_at, \
        vector_f32*: vector_f32_at, \
        vector_f64*: vector_f64_at  \
)(X,Y)

#define vector_front(X) _Generic((X),\
       vector_i8*:  vector_i8_front, \
      vector_i16*: vector_i16_front, \
      vector_i32*: vector_i32_front, \
      vector_i64*: vector_i64_front, \
       vector_u8*:  vector_u8_front, \
      vector_u16*: vector_u16_front, \
      vector_u32*: vector_u32_front, \
      vector_u64*: vector_u64_front, \
      vector_f32*: vector_f32_front, \
      vector_f64*: vector_f64_front  \
)(X)

#define vector_back(X) _Generic((X),\
       vector_i8*:  vector_i8_back, \
      vector_i16*: vector_i16_back, \
      vector_i32*: vector_i32_back, \
      vector_i64*: vector_i64_back, \
       vector_u8*:  vector_u8_back, \
      vector_u16*: vector_u16_back, \
      vector_u32*: vector_u32_back, \
      vector_u64*: vector_u64_back, \
      vector_f32*: vector_f32_back, \
      vector_f64*: vector_f64_back  \
)(X)

#define vector_data(X) _Generic((X),\
       vector_i8*:  vector_i8_data, \
      vector_i16*: vector_i16_data, \
      vector_i32*: vector_i32_data, \
      vector_i64*: vector_i64_data, \
       vector_u8*:  vector_u8_data, \
      vector_u16*: vector_u16_data, \
      vector_u32*: vector_u32_data, \
      vector_u64*: vector_u64_data, \
      vector_f32*: vector_f32_data, \
      vector_f64*: vector_f64_data  \
)(X)

#define vector_empty(X) _Generic((X),\
       vector_i8*:  vector_i8_empty, \
      vector_i16*: vector_i16_empty, \
      vector_i32*: vector_i32_empty, \
      vector_i64*: vector_i64_empty, \
       vector_u8*:  vector_u8_empty, \
      vector_u16*: vector_u16_empty, \
      vector_u32*: vector_u32_empty, \
      vector_u64*: vector_u64_empty, \
      vector_f32*: vector_f32_empty, \
      vector_f64*: vector_f64_empty  \
)(X)

#define vector_size(X) _Generic((X),\
       vector_i8*:  vector_i8_size, \
      vector_i16*: vector_i16_size, \
      vector_i32*: vector_i32_size, \
      vector_i64*: vector_i64_size, \
       vector_u8*:  vector_u8_size, \
      vector_u16*: vector_u16_size, \
      vector_u32*: vector_u32_size, \
      vector_u64*: vector_u64_size, \
      vector_f32*: vector_f32_size, \
      vector_f64*: vector_f64_size  \
)(X)

#define vector_capacity(X) _Generic((X),\
       vector_i8*:  vector_i8_capacity, \
      vector_i16*: vector_i16_capacity, \
      vector_i32*: vector_i32_capacity, \
      vector_i64*: vector_i64_capacity, \
       vector_u8*:  vector_u8_capacity, \
      vector_u16*: vector_u16_capacity, \
      vector_u32*: vector_u32_capacity, \
      vector_u64*: vector_u64_capacity, \
      vector_f32*: vector_f32_capacity, \
      vector_f64*: vector_f64_capacity  \
)(X)

#define vector_reserve(X,Y) _Generic((X),\
         vector_i8*:  vector_i8_reserve, \
        vector_i16*: vector_i16_reserve, \
        vector_i32*: vector_i32_reserve, \
        vector_i64*: vector_i64_reserve, \
         vector_u8*:  vector_u8_reserve, \
        vector_u16*: vector_u16_reserve, \
        vector_u32*: vector_u32_reserve, \
        vector_u64*: vector_u64_reserve, \
        vector_f32*: vector_f32_reserve, \
        vector_f64*: vector_f64_reserve  \
)(X,Y)

#define vector_shrink_to_fit(X) _Generic((X),\
       vector_i8*:  vector_i8_shrink_to_fit, \
      vector_i16*: vector_i16_shrink_to_fit, \
      vector_i32*: vector_i32_shrink_to_fit, \
      vector_i64*: vector_i64_shrink_to_fit, \
       vector_u8*:  vector_u8_shrink_to_fit, \
      vector_u16*: vector_u16_shrink_to_fit, \
      vector_u32*: vector_u32_shrink_to_fit, \
      vector_u64*: vector_u64_shrink_to_fit, \
      vector_f32*: vector_f32_shrink_to_fit, \
      vector_f64*: vector_f64_shrink_to_fit  \
)(X)

#define vector_clear(X) _Generic((X),\
       vector_i8*:  vector_i8_clear, \
      vector_i16*: vector_i16_clear, \
      vector_i32*: vector_i32_clear, \
      vector_i64*: vector_i64_clear, \
       vector_u8*:  vector_u8_clear, \
      vector_u16*: vector_u16_clear, \
      vector_u32*: vector_u32_clear, \
      vector_u64*: vector_u64_clear, \
      vector_f32*: vector_f32_clear, \
      vector_f64*: vector_f64_clear  \
)(X)

#define vector_insert(X,Y,Z) _Generic((X),\
           vector_i8*:  vector_i8_insert, \
          vector_i16*: vector_i16_insert, \
          vector_i32*: vector_i32_insert, \
          vector_i64*: vector_i64_insert, \
           vector_u8*:  vector_u8_insert, \
          vector_u16*: vector_u16_insert, \
          vector_u32*: vector_u32_insert, \
          vector_u64*: vector_u64_insert, \
          vector_f32*: vector_f32_insert, \
          vector_f64*: vector_f64_insert  \
)(X,Y,Z)

#define vector_push_back(X,Z) _Generic((X),\
         vector_i8*:  vector_i8_push_back, \
        vector_i16*: vector_i16_push_back, \
        vector_i32*: vector_i32_push_back, \
        vector_i64*: vector_i64_push_back, \
         vector_u8*:  vector_u8_push_back, \
        vector_u16*: vector_u16_push_back, \
        vector_u32*: vector_u32_push_back, \
        vector_u64*: vector_u64_push_back, \
        vector_f32*: vector_f32_push_back, \
        vector_f64*: vector_f64_push_back  \
)(X,Z)

#define vector_pop_back(X) _Generic((X),\
       vector_i8*:  vector_i8_pop_back, \
      vector_i16*: vector_i16_pop_back, \
      vector_i32*: vector_i32_pop_back, \
      vector_i64*: vector_i64_pop_back, \
       vector_u8*:  vector_u8_pop_back, \
      vector_u16*: vector_u16_pop_back, \
      vector_u32*: vector_u32_pop_back, \
      vector_u64*: vector_u64_pop_back, \
      vector_f32*: vector_f32_pop_back, \
      vector_f64*: vector_f64_pop_back  \
)(X)

#define vector_push_front(X,Z) _Generic((X),\
         vector_i8*:  vector_i8_push_front, \
        vector_i16*: vector_i16_push_front, \
        vector_i32*: vector_i32_push_front, \
        vector_i64*: vector_i64_push_front, \
         vector_u8*:  vector_u8_push_front, \
        vector_u16*: vector_u16_push_front, \
        vector_u32*: vector_u32_push_front, \
        vector_u64*: vector_u64_push_front, \
        vector_f32*: vector_f32_push_front, \
        vector_f64*: vector_f64_push_front  \
)(X,Z)

#define vector_pop_front(X) _Generic((X),\
       vector_i8*:  vector_i8_pop_front, \
      vector_i16*: vector_i16_pop_front, \
      vector_i32*: vector_i32_pop_front, \
      vector_i64*: vector_i64_pop_front, \
       vector_u8*:  vector_u8_pop_front, \
      vector_u16*: vector_u16_pop_front, \
      vector_u32*: vector_u32_pop_front, \
      vector_u64*: vector_u64_pop_front, \
      vector_f32*: vector_f32_pop_front, \
      vector_f64*: vector_f64_pop_front  \
)(X)

#define vector_resize(X,Y) _Generic((X),\
         vector_i8*:  vector_i8_resize, \
        vector_i16*: vector_i16_resize, \
        vector_i32*: vector_i32_resize, \
        vector_i64*: vector_i64_resize, \
         vector_u8*:  vector_u8_resize, \
        vector_u16*: vector_u16_resize, \
        vector_u32*: vector_u32_resize, \
        vector_u64*: vector_u64_resize, \
        vector_f32*: vector_f32_resize, \
        vector_f64*: vector_f64_resize  \
)(X,Y)

#define vector_swap(X,Y) _Generic((X),\
         vector_i8*:  vector_i8_swap, \
        vector_i16*: vector_i16_swap, \
        vector_i32*: vector_i32_swap, \
        vector_i64*: vector_i64_swap, \
         vector_u8*:  vector_u8_swap, \
        vector_u16*: vector_u16_swap, \
        vector_u32*: vector_u32_swap, \
        vector_u64*: vector_u64_swap, \
        vector_f32*: vector_f32_swap, \
        vector_f64*: vector_f64_swap  \
)(X,Y)

#define vector_equal(X,Y) _Generic((X),\
         vector_i8*:  vector_i8_equal, \
        vector_i16*: vector_i16_equal, \
        vector_i32*: vector_i32_equal, \
        vector_i64*: vector_i64_equal, \
         vector_u8*:  vector_u8_equal, \
        vector_u16*: vector_u16_equal, \
        vector_u32*: vector_u32_equal, \
        vector_u64*: vector_u64_equal, \
        vector_f32*: vector_f32_equal, \
        vector_f64*: vector_f64_equal  \
)(X,Y)

#endif // !ARRAYS_AND_STRINGS_VECTOR_H
