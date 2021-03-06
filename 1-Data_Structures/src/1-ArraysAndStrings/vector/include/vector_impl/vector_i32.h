/* vector_i32.h
 * Defines a C implementation of std::vector<int32_t>
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I32_H
#define ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I32_H

#include "../c_types.h"
#include "common.h"

#define NO_ALIAS const __restrict

typedef struct
{
    size_t size;
    size_t capacity;
    __attribute__((aligned(16)))
    i32 * data;
} vector_i32;

// Constructor
vector_i32 * new_vector_i32();

// Element Access

i32 * vector_i32_at(vector_i32 * NO_ALIAS vector, size_t position);
i32 * vector_i32_front(vector_i32 * NO_ALIAS vector);
i32 * vector_i32_back(vector_i32 * NO_ALIAS vector);
i32 * vector_i32_data(vector_i32 * NO_ALIAS vector);

// Capacity

const bool vector_i32_empty(vector_i32 * NO_ALIAS vector);
const size_t vector_i32_size(vector_i32 * NO_ALIAS vector);
const size_t vector_i32_capacity(vector_i32 * NO_ALIAS vector);
const bool vector_i32_reserve(vector_i32 * NO_ALIAS vector, size_t size);
void vector_i32_shrink_to_fit(vector_i32 * NO_ALIAS vector);
void vector_i32_free(vector_i32 * NO_ALIAS vector);

// Modifiers

void vector_i32_clear(vector_i32 * NO_ALIAS vector);
i32 * vector_i32_insert(vector_i32 * NO_ALIAS vector, size_t position, i32 value);
i32 * vector_i32_push_back(vector_i32 * NO_ALIAS vector, i32 value);
void vector_i32_pop_back(vector_i32 * NO_ALIAS vector);
i32 * vector_i32_push_front(vector_i32 * NO_ALIAS vector, i32 value);
void vector_i32_pop_front(vector_i32 * NO_ALIAS vector);
i32 * vector_i32_resize(vector_i32 * NO_ALIAS vector, size_t size);
void vector_i32_swap(vector_i32 * NO_ALIAS vector1, vector_i32 * NO_ALIAS vector2);

// Comparitors
const bool vector_i32_equal(vector_i32 * NO_ALIAS vector1, vector_i32 * NO_ALIAS vector2);

#undef NO_ALIAS

#endif // !ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I32_H
