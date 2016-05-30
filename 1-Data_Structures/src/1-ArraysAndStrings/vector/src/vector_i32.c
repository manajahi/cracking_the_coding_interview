/* vector_i32.c
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

#include "../include/vector_impl/vector_i32.h"
#include <string.h>
#include <stdlib.h>

#define NO_ALIAS const __restrict

// Element Access

i32 * vector_i32_at(vector_i32 * NO_ALIAS vector, size_t position)
{
    return &vector->data[position];
}

i32 * vector_i32_front(vector_i32 * NO_ALIAS vector)
{
    return &vector->data[0];
}

i32 * vector_i32_back(vector_i32 * NO_ALIAS vector)
{
    return &vector->data[vector->size-1];
}

i32 * vector_i32_data(vector_i32 * NO_ALIAS vector)
{
    return vector->data;
}

// Capacity

const bool vector_i32_empty(vector_i32 * NO_ALIAS vector)
{
    return (vector->size == 0);
}

const size_t vector_i32_size(vector_i32 * NO_ALIAS vector)
{
    return vector->size;
}

const size_t vector_i32_capacity(vector_i32 * NO_ALIAS vector)
{
    return vector->capacity;
}

const bool vector_i32_reserve(vector_i32 * NO_ALIAS vector, size_t size)
{
    if (size > vector->capacity) {
        i32 * new_data = malloc(size * sizeof(i32));
        if (new_data == NULL) {
            return true;
        }
        else {
            memcpy(new_data, vector->data, vector->size * sizeof(i32));
            free(vector->data);
            vector->data = new_data;
        }
    }
    return false;
}

void vector_i32_shrink_to_fit(vector_i32 * NO_ALIAS vector)
{
    i32 * new_data = realloc(vector->data, vector->size * sizeof(i32));
    if (new_data != NULL){
        vector->data = new_data;
        vector->capacity = vector->size;
    }
}

void vector_i32_free(vector_i32 * NO_ALIAS vector)
{
    free(vector->data);
}

// Modifiers

void vector_i32_clear(vector_i32 * NO_ALIAS vector)
{
    memset(vector->data, 0, vector->size * sizeof(i32));
}

i32 * vector_i32_insert(vector_i32 * NO_ALIAS vector, size_t position, i32 value)
{
    if (position > vector->size){
        return NULL;
    } else {
        size_t n_elems_to_mv = vector->size - position; 
        if (vector->size + 1 > vector->capacity)
            vector_i32_resize(vector, vector->capacity * 2);
        
        memmove(vector->data + position + 1,
                vector->data + position,
                n_elems_to_mv * sizeof(i32));
        vector->data[position] = value;
        ++(vector->size);
    }
    return &vector->data[position];
}

i32 * vector_i32_push_back(vector_i32 * NO_ALIAS vector, i32 value);

i32 * vector_i32_pop_back(vector_i32 * NO_ALIAS vector)
{
    --(vector->size);
    return vector->data;
}

i32 * vector_i32_push_front(vector_i32 * NO_ALIAS vector, i32 value);
i32 * vector_i32_pop_front(vector_i32 * NO_ALIAS vector);
i32 * vector_i32_resize(vector_i32 * NO_ALIAS vector, size_t size);
i32 * vector_i32_swap(vector_i32 * NO_ALIAS vector1, vector_i32 * NO_ALIAS vector2);

// Comparitors
const bool vector_i32_equal(vector_i32 * NO_ALIAS vector1, vector_i32 * NO_ALIAS vector2);

#undef NO_ALIAS
