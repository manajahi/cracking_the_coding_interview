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

#ifndef DATA_STRUCTS_LIST_ITERATORS_HH
#define DATA_STRUCTS_LIST_ITERATORS_HH

#ifdef DATA_STRUCTS_LINKEDLIST_HH

#include <iterator>

namespace datastructs
{
    namespace listtraits
    {
        enum class direction {forward, reverse};

        template<direction D>
        struct direction_selector
        {
            template<typename N>
            static N * moveToNext(N * node)
            {
                return node->_next;
            }

            template<typename N>
            static N * moveToPrevious(N * node)
            {
                return node->_previous;
            } 
        };
        
        template<>
        struct direction_selector<direction::reverse>
        {
            template<typename N>
            static N * moveToNext(N * node)
            {
                return node->_previous;
            }
    
            template<typename N>
            static N * moveToPrevious(N * node)
            {
                return node->_next;
            }
        };
        
        template<typename N, direction D>
        N * moveToNext(N * node)
        {
            return direction_selector<D>::moveToNext(node);
        }
        
        template<typename N, direction D>
        N * moveToPrevious(N * node)
        {                                                             
            return direction_selector<D>::moveToPrevious(node);
        }
    } // namespace listtraits

    namespace listiterators
    {

        template<typename N, listtraits::direction D>
        struct iterator : public std::iterator<std::bidirectional_iterator_tag, N>
        {
            N * _node;
          public:
            iterator(N * node) : _node(node) {}
            iterator(const iterator& iter) : _node(iter._node) {}
            
            iterator& operator ++()
            {
                _node = listtraits::moveToNext<N,D>(_node);
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
                _node = listtraits::moveToPrevious<N,D>(_node);
                return *this;
            }

            iterator operator --(int)
            {
                iterator iter(*this);
                operator --();
                return iter;
            }

            bool operator == (const iterator& rhs)
            {
                return _node == rhs._node;
            }

            bool operator != (const iterator& rhs)
            {
                return _node != rhs._node;
            }

            decltype(_node->_data)& operator *() 
            {
                return _node->_data;
            }
        };

    } //namespace listiterators
} // namespace datastructs

#endif // DATA_STRUCTS_LINKEDLIST_HH
#endif // DATA_STRUCTS_LIST_ITERATORS_HH
