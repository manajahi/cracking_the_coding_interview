/* vector_u8.h
 * Defines a C implementation of std::vector<uint8_t>
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U8_H
#define ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U8_H

#include "../c_types.h"
#include "common.h"

#define NO_ALIAS const __restrict

typedef struct
{
    size_t size;
    size_t capacity;
    __attribute__((aligned(16)))
    u8 * data;
} vector_u8;

// Constructor

vector_u8 * new_vector_u8();

// Element Access

u8 * vector_u8_at(vector_u8 * NO_ALIAS vector, size_t position);
u8 * vector_u8_front(vector_u8 * NO_ALIAS vector);
u8 * vector_u8_back(vector_u8 * NO_ALIAS vector);
u8 * vector_u8_data(vector_u8 * NO_ALIAS vector);

// Capacity

const bool vector_u8_empty(vector_u8 * NO_ALIAS vector);
const size_t vector_u8_size(vector_u8 * NO_ALIAS vector);
const size_t vector_u8_capacity(vector_u8 * NO_ALIAS vector);
const bool vector_u8_reserve(vector_u8 * NO_ALIAS vector, size_t size);
void vector_u8_shrink_to_fit(vector_u8 * NO_ALIAS vector);
void vector_u8_free(vector_u8 * NO_ALIAS vector);

// Modifiers

void vector_u8_clear(vector_u8 * NO_ALIAS vector);
u8 * vector_u8_insert(vector_u8 * NO_ALIAS vector, size_t position, u8 value);
u8 * vector_u8_push_back(vector_u8 * NO_ALIAS vector, u8 value);
void vector_u8_pop_back(vector_u8 * NO_ALIAS vector);
u8 * vector_u8_push_front(vector_u8 * NO_ALIAS vector, u8 value);
void vector_u8_pop_front(vector_u8 * NO_ALIAS vector);
u8 * vector_u8_resize(vector_u8 * NO_ALIAS vector, size_t size);
void vector_u8_swap(vector_u8 * NO_ALIAS vector1, vector_u8 * NO_ALIAS vector2);

// Comparitors
const bool vector_u8_equal(vector_u8 * NO_ALIAS vector1, vector_u8 * NO_ALIAS vector2);

#undef NO_ALIAS

#endif // !ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U8_H
