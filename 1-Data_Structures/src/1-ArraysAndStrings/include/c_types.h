/* c_types.h
 * Defines helper typedefs from stdint.h
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

#ifndef ARRAYS_AND_STRINGS_INCLUDE_C_TYPES_H
#define ARRAYS_AND_STRINGS_INCLUDE_C_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// Signed integer types
typedef  int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// Unsigned integer types
typedef  uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// Floating point

typedef  float f32;
typedef double f64;

#define typename(X) _Generic((X), \
    i8: "char",            i8*: "char *",     \
   i16: "int16_t",        i16*: "int16_t *",  \
   i32: "int32_t",        i32*: "int32_t *",  \
   i64: "int64_t",        i64*: "int64_t *",  \
    u8: "unsigned char",   u8*: "char *",     \
   u16: "uint16_t",       u16*: "uint16_t *", \
   u32: "uint32_t",       u32*: "uint32_t *", \
   u64: "uint64_t",       u64*: "uint64_t *", \
   f32: "float",          f32*: "float *",    \
   f64: "double",         f64*: "double *",   \
   default: "other")

#endif // !ARRAYS_AND_STRINGS_INCLUDE_C_TYPES_H
