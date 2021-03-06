/* vector_u32.h
 * Defines a C implementation of std::vector<uint32_t>
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U32_H
#define ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U32_H

#include "../c_types.h"
#include "common.h"

#define NO_ALIAS const __restrict

typedef struct
{
    size_t size;
    size_t capacity;
    __attribute__((aligned(16)))
    u32 * data;
} vector_u32;

// Constructor

vector_u32 * new_vector_u32();

// Element Access

u32 * vector_u32_at(vector_u32 * NO_ALIAS vector, size_t position);
u32 * vector_u32_front(vector_u32 * NO_ALIAS vector);
u32 * vector_u32_back(vector_u32 * NO_ALIAS vector);
u32 * vector_u32_data(vector_u32 * NO_ALIAS vector);

// Capacity

const bool vector_u32_empty(vector_u32 * NO_ALIAS vector);
const size_t vector_u32_size(vector_u32 * NO_ALIAS vector);
const size_t vector_u32_capacity(vector_u32 * NO_ALIAS vector);
const bool vector_u32_reserve(vector_u32 * NO_ALIAS vector, size_t size);
void vector_u32_shrink_to_fit(vector_u32 * NO_ALIAS vector);
void vector_u32_free(vector_u32 * NO_ALIAS vector);

// Modifiers

void vector_u32_clear(vector_u32 * NO_ALIAS vector);
u32 * vector_u32_insert(vector_u32 * NO_ALIAS vector, size_t position, u32 value);
u32 * vector_u32_push_back(vector_u32 * NO_ALIAS vector, u32 value);
void vector_u32_pop_back(vector_u32 * NO_ALIAS vector);
u32 * vector_u32_push_front(vector_u32 * NO_ALIAS vector, u32 value);
void vector_u32_pop_front(vector_u32 * NO_ALIAS vector);
u32 * vector_u32_resize(vector_u32 * NO_ALIAS vector, size_t size);
void vector_u32_swap(vector_u32 * NO_ALIAS vector1, vector_u32 * NO_ALIAS vector2);

// Comparitors
const bool vector_u32_equal(vector_u32 * NO_ALIAS vector1, vector_u32 * NO_ALIAS vector2);

#undef NO_ALIAS

#endif // !ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U32_H
