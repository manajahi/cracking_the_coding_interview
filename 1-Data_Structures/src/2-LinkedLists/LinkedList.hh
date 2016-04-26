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

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

#include<iterator>

namespace datastructs
{

    template<typename T>
    class LinkedList
    {
      private:

        struct Node
        {
            T data;
            Node<T> * next, * previous;

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
        Node<T> * head, * tail;

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
        class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
            T * data;
          public:
            iterator(const T * data) : data(data) {}
            iterator(const iterator& iter) : data(iter.data) {}
            
            iterator& operator ++()
            {
                this = this->next;
                return *this;
            }

            iterator operator ++(T)
            {
                iterator _iter(*this);
                operator ++();
                return _iter;
            }

            iterator& operator --()
            {
                this = this->previous;
                return *this;
            }

            iterator operator --(T)
            {
                iterator _iter(*this);
                this = this->previous;
                return _iter;
            }

            iterator operator == (const iterator& rhs)
            {
                return data == rhs.data
            }

            iterator operator != (const iterator& rhs)
            {
                return data != rhs.data;
            }

            T& operator *()
            {
                return *data;
            }
            
        };

        class reverse_iterator : public std::iterator<std::forward_iterator_tag, T>
        {

        };

        const_iterator cbegin() const;
        iterator begin() const;

        const_iterator cend() const;
        iterator end() const;

        const_iterator crbegin() const;
        iterator rbegin() const;

        const_iterator crend() const;
        iterator rend() const;

        // Capacity
        size_t size() const;
        bool empty const;

        // Element Access
        T& front() const;
        const T& front() const;
        T& back() const;
        const T& back() const;
        

    };
`

} // end namespace datastructs

#include "LinkedList.hpp"

#endif // DATA_STRUCTS_LINKEDLIST_HH
