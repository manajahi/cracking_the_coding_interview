/* vector_u8.c
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

#include "../include/vector_impl/vector_u8.h"
#include <string.h>
#include <stdlib.h>

#define NO_ALIAS const __restrict

// Constructor

vector_u8 * new_vector_u8()
{
    vector_u8 * vector = malloc(sizeof(vector_u8));
    vector->capacity = VECTOR_START_CAPACITY;
    vector->size = 0;
    vector->data = malloc(vector->capacity * sizeof(u8));
    return vector;
}

// Element Access

u8 * vector_u8_at(vector_u8 * NO_ALIAS vector, size_t position)
{
    return &vector->data[position];
}

u8 * vector_u8_front(vector_u8 * NO_ALIAS vector)
{
    return vector->data;
}

u8 * vector_u8_back(vector_u8 * NO_ALIAS vector)
{
    u8 * back;
    if (vector->size > 0)
        back = (vector->data + vector->size - 1);
    else
        back = vector->data;
    return back;
}

u8 * vector_u8_data(vector_u8 * NO_ALIAS vector)
{
    return vector->data;
}

// Capacity

const bool vector_u8_empty(vector_u8 * NO_ALIAS vector)
{
    return (vector->size == 0);
}

const size_t vector_u8_size(vector_u8 * NO_ALIAS vector)
{
    return vector->size;
}

const size_t vector_u8_capacity(vector_u8 * NO_ALIAS vector)
{
    return vector->capacity;
}

const bool vector_u8_reserve(vector_u8 * NO_ALIAS vector, size_t size)
{
    if (size > vector->capacity) {
        u8 * new_data = malloc(size * sizeof(u8));
        if (new_data == NULL) {
            return true;
        }
        else {
            memcpy(new_data, vector->data, vector->size * sizeof(u8));
            free(vector->data);
            vector->data = new_data;
        }
    }
    return false;
}

void vector_u8_shrink_to_fit(vector_u8 * NO_ALIAS vector)
{
    u8 * new_data = realloc(vector->data, vector->size * sizeof(u8));
    if (new_data != NULL){
        vector->data = new_data;
        vector->capacity = vector->size;
    }
}

void vector_u8_free(vector_u8 * NO_ALIAS vector)
{
    free(vector->data);
}

// Modifiers

void vector_u8_clear(vector_u8 * NO_ALIAS vector)
{
    memset(vector->data, 0, vector->size * sizeof(u8));
    vector->size = 0;
}

u8 * vector_u8_insert(vector_u8 * NO_ALIAS vector, size_t position, u8 value)
{
    if (position > vector->size){
        return NULL;
    } else {
        size_t n_elems_to_mv = vector->size - position; 
        if (vector->size + 1 > vector->capacity){
            if (!vector_u8_resize(vector, vector_grow_capacity(vector->capacity)))
                return NULL;
        }
        memmove(vector->data + position + 1,
                vector->data + position,
                n_elems_to_mv * sizeof(u8));
        vector->data[position] = value;
        ++(vector->size);
    }
    return &vector->data[position];
}

u8 * vector_u8_push_back(vector_u8 * NO_ALIAS vector, u8 value)
{
    u8 * last_elem;
    if (vector->capacity < (vector->size + 1)){
        if (!vector_u8_resize(vector, vector_grow_capacity(vector->capacity)))
            return NULL;
    }

    last_elem = &vector->data[vector->size];
    *last_elem = value;
    ++(vector->size);

    return last_elem;
}

void vector_u8_pop_back(vector_u8 * NO_ALIAS vector)
{
    if (vector->size > 0){
        --(vector->size);

        if (vector->capacity > 2*vector->size)
            vector_u8_resize(vector, vector_shrink_capacity(vector->capacity));
    }
}

u8 * vector_u8_push_front(vector_u8 * NO_ALIAS vector, u8 value)
{
    if (vector->size > 0){

        if (vector->capacity < (vector->size + 1)) {
            if (vector_u8_resize(vector, vector_grow_capacity(vector->capacity)))
                return NULL;
        }
        memmove(vector->data + 1, vector->data, vector->size);
    }

    *(vector->data) = value;
    ++(vector->size);
    return (vector->data);
}

void vector_u8_pop_front(vector_u8 * NO_ALIAS vector)
{
    if (vector->size > 0){
        if (vector->capacity > 2*vector->size)
            vector_u8_resize(vector, vector_shrink_capacity(vector->capacity));
        memmove(vector->data, vector->data-1, vector->size);
        --(vector->size);
    }
}

u8 * vector_u8_resize(vector_u8 * NO_ALIAS vector, size_t size)
{
    if(realloc(vector->data, size * sizeof(u8)) != NULL) {
        return NULL;
    } else {
        vector->capacity = size;
        if ((vector->size) > size) vector->size = size;
    }
    return vector->data;
}

void vector_u8_swap(vector_u8 * NO_ALIAS vector1, vector_u8 * NO_ALIAS vector2)
{
    u8 * tmp;
    // swap size
    vector1->size ^= vector2->size;
    vector2->size ^= vector1->size;
    vector1->size ^= vector2->size;
    
    // swap capacity
    vector1->capacity ^= vector2->capacity;
    vector2->capacity ^= vector1->capacity;
    vector1->capacity ^= vector2->capacity;

    // swap pointers
    tmp = vector1->data;
    vector1->data = vector2->data;
    vector2->data = tmp;
}

// Comparitors
const bool vector_u8_equal(vector_u8 * NO_ALIAS vector1, vector_u8 * NO_ALIAS vector2)
{
    if (vector1->size != vector2->size) return false;
    
    for (size_t i = 0; i < vector1->size; ++i) {
        if (vector1->data[i] != vector2->data[i]) return false;
    }
    
    return true;
}

#undef NO_ALIAS
