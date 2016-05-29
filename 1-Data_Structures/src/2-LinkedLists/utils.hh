/* utils.hh
 * Defines template utilities for types in 2-LinkedLists
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

#ifndef DATA_STRUCTS_LINKEDLISTS_UTILS_HH
#define DATA_STRUCTS_LINKEDLISTS_UTILS_HH

namespace datastructs
{
    namespace linkedlists
    {
        namespace utils
        {
            
            template<bool B, typename T = void>
            struct enable_if {};

            template<typename T>
            struct enable_if<true, T>
            {
                typedef T type;
            };

            template<bool B, typename T, typename F>
            struct conditional
            {
                typedef T type;
            };

            template<typename T, typename F>
            struct conditional<false, T, F>
            {
                typedef F type;
            };

            template<typename T>
            struct is_const
            {
                static const bool value = false;
            };

            template<typename T>
            struct is_const<const T>
            {
                static const bool value = true;
            };

            template<bool B, typename T>
            using enable_if_t = typename enable_if<B, T>::type;

            template<bool B, typename T, typename F>
            using conditional_t = typename conditional<B, T, F>::type;

        } // !utils

    } // !linkedlists
} // !datastructs

#endif // DATA_STRUCTS_LINKEDLISTS_UTILS_HH
