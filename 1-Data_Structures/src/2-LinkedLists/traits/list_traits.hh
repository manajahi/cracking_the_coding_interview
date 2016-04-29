/* list_traits.hh
 * Defines traits for LinkedList list types
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
 * (C) 2016, E. Higham
 */

#ifndef DATA_STRUCTS_LINKEDLISTS_TRAITS_LIST_HH
#define DATA_STRUCTS_LINKEDLISTS_TRAITS_LIST_HH

#ifdef DATA_STRUCTS_LINKEDLISTS

namespace datastructs
{
    namespace linkedlists
    {
        enum class LiaisonType
        {
            singly,
            doubly
        };

        template<LiaisonType L>
        struct is_doubly_linked
        {
            static const bool value = false;
        };

        template<>
        struct is_doubly_linked<LiaisonType::doubly>
        {
            static const bool value = true;
        };

    } // !linkedlists
} // !datastructs

#endif // DATA_STRUCTS_LINKEDLISTS
#endif // DATA_STRUCTS_LINKEDLISTS_TRAITS_LIST_HH
