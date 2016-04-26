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
        template<typename N, datastructs::direction D>
        class ListIterator : public std::iterator<std::bidirectional_iterator_tag, N>
        {
            N * _node;
          public:
            ListIterator(const N * _node) : _node(_node) {}
            ListIterator(const ListIterator& iter) : _node(iter._node) {}
            
            ListIterator& operator ++()
            {
                _node = _moveToNext<D>(_node);
                return _node->data;
            }


            ListIterator operator ++(N)
            {
                ListIterator _iter(*this);
                operator ++();
                return *_iter;
            }

            ListIterator& operator --()
            {
                _node = _moveToPrevious<D>(_node);
                return _node->data;
            }

            ListIterator operator --(N)
            {
                ListIterator _iter(*this);
                operator --();
                return _iter;
            }

            ListIterator operator == (const ListIterator& rhs)
            {
                return _node->data == rhs.data;
            }

            ListIterator operator != (const ListIterator& rhs)
            {
                return _node->data != rhs.data;
            }

            T& operator *() 
            {
                return _node->data;
            }
        };

        typedef ListIterator<Node, direction::forward> iterator;
        typedef ListIterator<const Node, direction::forward> const_iterator;
        typedef ListIterator<Node, direction::reverse> reverse_iterator;
        typedef ListIterator<const Node, direction::reverse> const_reverse_iterator;

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
        bool empty() const;

        // Element Access
        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

      private:
        void reassign_head(const T * const node);
        void reassign_tail(const T * const node);
    };


} // end namespace datastructs

#include "LinkedList.hpp"

#endif // DATA_STRUCTS_LINKEDLIST_HH
