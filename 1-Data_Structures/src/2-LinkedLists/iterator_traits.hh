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

#ifndef DATA_STRUCTS_LINKEDLIST_ITERATORTRAITS_HH
#define DATA_STRUCTS_LINKEDLIST_ITERATORTRAITS_HH

namespace datastructs
{
    enum class direction {forward, reverse};

    template<direction D>
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
    struct direction_selector<direction::reverse>
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

    template<typename N, direction D>
    N * _moveToNext(N * _node)
    {
        return direction_selector<D>::moveToNext(_node);
    }

    template<typename N, direction D>
    N * _moveToPrevious(N * _node)
    {                                                             
        return direction_selector<D>::moveToPrevious(_node);
    }

} // namespace datastructs

#endif // DATA_STRUCTS_LINKEDLIST_ITERATORTRAITS_HH
