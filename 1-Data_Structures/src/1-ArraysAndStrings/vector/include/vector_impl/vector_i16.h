/* vector_i16.h
 * Defines a C implementation of std::vector<int16_t>
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I16_H
#define ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I16_H

#include "../c_types.h"
#include "common.h"

#define NO_ALIAS const __restrict

typedef struct
{
    size_t size;
    size_t capacity;
    __attribute__((aligned(16)))
    i16 * data;
} vector_i16;

// Constructor
vector_i16 * new_vector_i16();

// Element Access

i16 * vector_i16_at(vector_i16 * NO_ALIAS vector, size_t position);
i16 * vector_i16_front(vector_i16 * NO_ALIAS vector);
i16 * vector_i16_back(vector_i16 * NO_ALIAS vector);
i16 * vector_i16_data(vector_i16 * NO_ALIAS vector);

// Capacity

const bool vector_i16_empty(vector_i16 * NO_ALIAS vector);
const size_t vector_i16_size(vector_i16 * NO_ALIAS vector);
const size_t vector_i16_capacity(vector_i16 * NO_ALIAS vector);
const bool vector_i16_reserve(vector_i16 * NO_ALIAS vector, size_t size);
void vector_i16_shrink_to_fit(vector_i16 * NO_ALIAS vector);
void vector_i16_free(vector_i16 * NO_ALIAS vector);

// Modifiers

void vector_i16_clear(vector_i16 * NO_ALIAS vector);
i16 * vector_i16_insert(vector_i16 * NO_ALIAS vector, size_t position, i16 value);
i16 * vector_i16_push_back(vector_i16 * NO_ALIAS vector, i16 value);
void vector_i16_pop_back(vector_i16 * NO_ALIAS vector);
i16 * vector_i16_push_front(vector_i16 * NO_ALIAS vector, i16 value);
void vector_i16_pop_front(vector_i16 * NO_ALIAS vector);
i16 * vector_i16_resize(vector_i16 * NO_ALIAS vector, size_t size);
void vector_i16_swap(vector_i16 * NO_ALIAS vector1, vector_i16 * NO_ALIAS vector2);

// Comparitors
const bool vector_i16_equal(vector_i16 * NO_ALIAS vector1, vector_i16 * NO_ALIAS vector2);

#undef NO_ALIAS

#endif // !ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I16_H
