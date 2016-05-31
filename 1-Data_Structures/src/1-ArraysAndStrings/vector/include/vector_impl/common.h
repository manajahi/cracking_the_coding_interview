/* common.h
 * Defines common traits and utils for vector implementations
 * defined within vector
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_COMMON_H
#define ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_COMMON_H

#define VECTOR_START_CAPACITY 32
#define VECTOR_CAPACITY_GROWTH_RATE 2

size_t vector_grow_capacity(size_t capacity);
size_t vector_shrink_capacity(size_t capacity);

#endif // !ARRAYS_AND_STRINGS_INCLUDE_VECTOR_IMPL_COMMON_H
