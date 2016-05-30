/* vector_i64.h
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I64_H
#define ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I64_H

#include "../c_types.h"

#define NO_ALIAS const __restrict

typedef struct
{
    size_t size;
    size_t capacity;
    __attribute__((aligned(16)))
    i64 * data;
} vector_i64;

// Element Access

i64 * vector_i64_at(vector_i64 * NO_ALIAS vector, size_t position);
i64 * vector_i64_front(vector_i64 * NO_ALIAS vector);
i64 * vector_i64_back(vector_i64 * NO_ALIAS vector);
i64 * vector_i64_data(vector_i64 * NO_ALIAS vector);

// Capacity

const bool vector_i64_empty(vector_i64 * NO_ALIAS vector);
const size_t vector_i64_size(vector_i64 * NO_ALIAS vector);
const size_t vector_i64_capacity(vector_i64 * NO_ALIAS vector);
void vector_i64_reserve(vector_i64 * NO_ALIAS vector, size_t size);
void vector_i64_shrink_to_fit(vector_i64 * NO_ALIAS vector);
void vector_i64_free(vector_i64 * NO_ALIAS vector);

// Modifiers

void vector_i64_clear(vector_i64 * NO_ALIAS vector);
i64 * vector_i64_insert(vector_i64 * NO_ALIAS vector, size_t position, i64 value);
i64 * vector_i64_push_back(vector_i64 * NO_ALIAS vector, i64 value);
i64 * vector_i64_pop_back(vector_i64 * NO_ALIAS vector);
i64 * vector_i64_push_front(vector_i64 * NO_ALIAS vector, i64 value);
i64 * vector_i64_pop_front(vector_i64 * NO_ALIAS vector);
i64 * vector_i64_resize(vector_i64 * NO_ALIAS vector, size_t size);
i64 * vector_i64_swap(vector_i64 * NO_ALIAS vector1, vector_i64 * NO_ALIAS vector2);

// Comparitors
const bool vector_i64_equal(vector_i64 * NO_ALIAS vector1, vector_i64 * NO_ALIAS vector2);

#undef NO_ALIAS

#endif // !ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_VECTOR_I64_H
