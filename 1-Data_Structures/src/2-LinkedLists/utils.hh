/* utils.hh
 * Defines template utilities for types in 2-LinkedLists
 * 
 * This file is a part of 1-Data_Structures.
 *
 * 1-Data_Structures is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * 1-Data_Structures is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 1-Data_Structures.  If not, see <http://www.gnu.org/licenses/>.
 *
 * (C) 2016, E. Higham
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
