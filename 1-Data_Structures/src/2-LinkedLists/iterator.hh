/* iterator.hh
 * Defines iterator data types in 2-LinkedLists
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

#ifndef DATA_STRUCTS_LINKEDLISTS_ITERATOR_HH
#define DATA_STRUCTS_LINKEDLISTS_ITERATOR_HH

#ifndef DATA_STRUCTS_LINKEDLISTS
#define DATA_STRUCTS_LINKEDLISTS
#endif

#include "traits/iterator_traits.hh"
#include <iterator>
#include "utils.hh"

#define CONST_IF_CONST(N, T) \
typename utils::conditional_t<utils::is_const<N>::value, const T, T>

namespace datastructs
{
    namespace linkedlists
    {
        namespace iterators
        {
            template<typename N,
                     typename TAG,
                     linkedlists::direction D
                    >
            class iterator : public std::iterator<TAG, N>
            {
                N * _node;
                public:
                iterator(N * node) : _node(node) {}
                iterator(const iterator& iter) : _node(iter._node) {}

                iterator& operator ++()
                {
                    _node = moveToNext<N,D>(_node);
                    return *this;
                }

                iterator operator ++(int)
                {
                    iterator iter(*this);
                    operator ++();
                    return iter;
                }

                iterator& operator --()
                {
                    _node = moveToPrevious<N,D>(_node);
                    return *this;
                }

                iterator operator --(int)
                {
                    iterator iter(*this);
                    operator --();
                    return iter;
                }

                bool operator == (const iterator& rhs) const
                {
                    return _node == rhs._node;
                }

                bool operator != (const iterator& rhs) const
                {
                    return _node != rhs._node;
                }
                
                
                CONST_IF_CONST(N, decltype(_node->_data))&
                operator *() const
                {
                    return _node->_data;
                }
            };

        } // !iterator
    } // !linkedlists
} // !datastructs

#undef CONST_IF_CONST

#endif // DATA_STRUCTS_LINKEDLISTS_COMMON_HH
