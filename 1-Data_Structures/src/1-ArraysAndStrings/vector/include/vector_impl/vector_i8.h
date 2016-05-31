/* vector_i8.h
 * Defines a C implementation of std::vector<int8_t>
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I8_H
#define ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I8_H

#include "../c_types.h"
#include "common.h"

#define NO_ALIAS const __restrict

typedef struct
{
    size_t size;
    size_t capacity;
    __attribute__((aligned(16)))
    i8 * data;
} vector_i8;

// Constructor
vector_i8 * new_vector_i8();

// Element Access

i8 * vector_i8_at(vector_i8 * NO_ALIAS vector, size_t position);
i8 * vector_i8_front(vector_i8 * NO_ALIAS vector);
i8 * vector_i8_back(vector_i8 * NO_ALIAS vector);
i8 * vector_i8_data(vector_i8 * NO_ALIAS vector);

// Capacity

const bool vector_i8_empty(vector_i8 * NO_ALIAS vector);
const size_t vector_i8_size(vector_i8 * NO_ALIAS vector);
const size_t vector_i8_capacity(vector_i8 * NO_ALIAS vector);
const bool vector_i8_reserve(vector_i8 * NO_ALIAS vector, size_t size);
void vector_i8_shrink_to_fit(vector_i8 * NO_ALIAS vector);
void vector_i8_free(vector_i8 * NO_ALIAS vector);

// Modifiers

void vector_i8_clear(vector_i8 * NO_ALIAS vector);
i8 * vector_i8_insert(vector_i8 * NO_ALIAS vector, size_t position, i8 value);
i8 * vector_i8_push_back(vector_i8 * NO_ALIAS vector, i8 value);
void vector_i8_pop_back(vector_i8 * NO_ALIAS vector);
i8 * vector_i8_push_front(vector_i8 * NO_ALIAS vector, i8 value);
void vector_i8_pop_front(vector_i8 * NO_ALIAS vector);
i8 * vector_i8_resize(vector_i8 * NO_ALIAS vector, size_t size);
void vector_i8_swap(vector_i8 * NO_ALIAS vector1, vector_i8 * NO_ALIAS vector2);

// Comparitors
const bool vector_i8_equal(vector_i8 * NO_ALIAS vector1, vector_i8 * NO_ALIAS vector2);

#undef NO_ALIAS

#endif // !ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I8_H
