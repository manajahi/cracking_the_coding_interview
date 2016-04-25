/* LinkedList.hh
 * Defines a template for a double linked-list
 * Modelled on std::list
 * 
 * This file is a part of LinkedList_test.
 *
 * LinkedList_test is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LinkedList_test is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LinkedList_test.  If not, see <http://www.gnu.org/licenses/>.
 * (C) 2016, E. Higham
 */

#ifndef DATA_STRUCTS_LINKEDLIST_HH
#define DATA_STRUCTS_LINKEDLIST_HH

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

namespace datastructs
{

    template<typename T>
    class LinkedList
    {
        LinkedList<T>& operator = (const LinkedList<T>&);
        ~LinkedList();

        // Modifiers
        void push_back(T&& item);
        void push_back(const T& item);
        void push_front(T&& item);
        void push_front(const T& item);
        void pop_back();
        void pop_front();
        void swap(LinkedList<T>& x);
        void clear();

        // Iterators
        typedef T * iterator;
        typedef const T * const_iterator;
        
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
        
      private:
        struct Node
        {
            T item;
            Node<T> * next, * previous;

            Node(const T& item, Node * next, Node * previous)
                : item(item)
                , next(next)
                , previous(previous) {}
                
            Node(T&& item, Node * next, Node * previous)
                : item(std::move(item))
                , next(next)
                , previous(previous) {}
        };

        size_t elems = 0;
        Node<T> * head, * tail;
    };
`

} // end namespace datastructs

#include "LinkedList.hpp"

#endif // DATA_STRUCTS_LINKEDLIST_HH
