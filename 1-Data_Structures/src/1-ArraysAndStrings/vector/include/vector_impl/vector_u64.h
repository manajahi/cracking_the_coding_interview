/* vector_u64.h
 * Defines a C implementation of std::vector<uint64_t>
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U64_H
#define ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U64_H

#include "../c_types.h"
#include "common.h"

#define NO_ALIAS const __restrict

typedef struct
{
    size_t size;
    size_t capacity;
    __attribute__((aligned(16)))
    u64 * data;
} vector_u64;

// Constructor

vector_u64 * new_vector_u64();

// Element Access

u64 * vector_u64_at(vector_u64 * NO_ALIAS vector, size_t position);
u64 * vector_u64_front(vector_u64 * NO_ALIAS vector);
u64 * vector_u64_back(vector_u64 * NO_ALIAS vector);
u64 * vector_u64_data(vector_u64 * NO_ALIAS vector);

// Capacity

const bool vector_u64_empty(vector_u64 * NO_ALIAS vector);
const size_t vector_u64_size(vector_u64 * NO_ALIAS vector);
const size_t vector_u64_capacity(vector_u64 * NO_ALIAS vector);
const bool vector_u64_reserve(vector_u64 * NO_ALIAS vector, size_t size);
void vector_u64_shrink_to_fit(vector_u64 * NO_ALIAS vector);
void vector_u64_free(vector_u64 * NO_ALIAS vector);

// Modifiers

void vector_u64_clear(vector_u64 * NO_ALIAS vector);
u64 * vector_u64_insert(vector_u64 * NO_ALIAS vector, size_t position, u64 value);
u64 * vector_u64_push_back(vector_u64 * NO_ALIAS vector, u64 value);
void vector_u64_pop_back(vector_u64 * NO_ALIAS vector);
u64 * vector_u64_push_front(vector_u64 * NO_ALIAS vector, u64 value);
void vector_u64_pop_front(vector_u64 * NO_ALIAS vector);
u64 * vector_u64_resize(vector_u64 * NO_ALIAS vector, size_t size);
void vector_u64_swap(vector_u64 * NO_ALIAS vector1, vector_u64 * NO_ALIAS vector2);

// Comparitors
const bool vector_u64_equal(vector_u64 * NO_ALIAS vector1, vector_u64 * NO_ALIAS vector2);

#undef NO_ALIAS

#endif // !ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_U64_H
