/* NodeTraits.hh
 * Defines traits for double linked-list iterators
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

#ifdef DATA_STRUCTS_LINKEDLIST_ITERATORTRAITS_HH
#define DATA_STRUCTS_LINKEDLIST_ITERATORTRAITS_HH

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

namespace datastructs
{
    enum class direction {FORWARD, REVERSE};

    template<enum class E>
    struct direction_selector
    {
        template<typename N>
        static N * moveToNext(N * _node)
        {
            return _node->next;
        }

        template<typename N>
        static N * moveToPrevious(N * _node)
        {
            return _node->previous;
        }

    };

    template<>
    struct direction_selector<direction::REVERSE>
    {
        template<typename N>
        static N * moveToNext(N * _node)
        {
            return _node->previous;
        }

        template<typename N>
        static N * moveToPrevious(N * _node)
        {
            return _node->next;
        }
    };

    template<typename N, enum class E>
    N * _moveToNext(N * _node) const
    {
        return direction_selector<E::value>::moveToNext(_node);
    }

    template<typename N, enum class E>
    N * _moveToPrevious(N * _node) const
    {                                                             
        return direction_selector<E::value>::moveToPrevious(_node);
    }

} // namespace datastructs

#endif // DATA_STRUCTS_LINKEDLIST_NODETRAITS_HH
