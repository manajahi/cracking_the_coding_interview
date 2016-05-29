/* iterator.hh
 * Defines iterator data types in 2-LinkedLists
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

#ifndef DATA_STRUCTS_LINKEDLISTS_ITERATOR_HH
#define DATA_STRUCTS_LINKEDLISTS_ITERATOR_HH

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
