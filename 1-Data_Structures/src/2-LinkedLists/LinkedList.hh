/* LinkedList.hh
 * Defines a template for a double linked-list
 * Modelled on std::list
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

#ifndef DATA_STRUCTS_LINKEDLIST_HH
#define DATA_STRUCTS_LINKEDLIST_HH

#include<iterator>
#include "iterator_traits.hh"

namespace datastructs
{

    template<typename T>
    class LinkedList
    {
      private:

        struct Node
        {
            T data;
            Node * next, * previous;

            Node(const T& data, Node * next, Node * previous)
                : data(data)
                , next(next)
                , previous(previous) {}
                
            Node(T&& data, Node * next, Node * previous)
                : data(std::move(data))
                , next(next)
                , previous(previous) {}
        };

        size_t elems = 0;
        Node * head, * tail;

      public:

        LinkedList<T>& operator = (const LinkedList<T>&);

        ~LinkedList();

        // Modifiers
        void push_back(T&& data);
        void push_back(const T& data);
        void push_front(T&& data);
        void push_front(const T& data);
        void pop_back();
        void pop_front();
        void swap(LinkedList<T>& x);
        void clear();

        // Iterators
        template<typename N, typename E>
        class iterator : public std::iterator<std::bidirectional_iterator_tag, N>
        {
            N * _node;
          public:
            iterator(const N * _node) : _node(_node) {}
            iterator(const iterator& iter) : _node(iter._node) {}
            
            iterator& operator ++()
            {
                _node = _moveToNext<E>(_node);
                return _node->data;
            }


            iterator operator ++(N)
            {
                iterator _iter(*this);
                operator ++();
                return *_iter;
            }

            iterator& operator --()
            {
                _node = _moveToPrevious<E>(_node);
                return _node->data;
            }

            iterator operator --(N)
            {
                iterator _iter(*this);
                operator --();
                return _iter;
            }

            iterator operator == (const iterator& rhs)
            {
                return data == rhs.data;
            }

            iterator operator != (const iterator& rhs)
            {
                return data != rhs.data;
            }

            T& operator *() 
            {
                return _node->data;
            }
        };

        typedef iterator<Node, direction::forward> iterator;
        typedef iterator<const Node, direction::forward> const_iterator;

        typedef iterator<Node, direction::reverse> reverse_iterator;
        typedef iterator<const Node, direction::reverse> reverse_const_iterator;

        const_iterator cbegin() const;
        iterator begin() const;

        const_iterator cend() const;
        iterator end() const;

        const_reverse_iterator crbegin() const;
        reverse_iterator rbegin() const;

        const_reverse_iterator crend() const;
        reverse_iterator rend() const;

        // Capacity
        size_t size() const;
        bool empty const;

        // Element Access
        T& front() const;
        const T& front() const;
        T& back() const;
        const T& back() const;
        

    };


} // end namespace datastructs

#include "LinkedList.hpp"

#endif // DATA_STRUCTS_LINKEDLIST_HH
