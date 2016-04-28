/* List.hh
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
 *
 * (C) 2016, E. Higham
 */

#ifndef DATA_STRUCTS_LINKEDLISTS_LIST_HH
#define DATA_STRUCTS_LINKEDLISTS_LIST_HH

#ifndef DATA_STRUCTS_LINKEDLISTS
#define DATA_STRUCTS_LINKEDLISTS
#endif

#include "common.hh"
#include "traits/list_traits.hh"

namespace datastructs
{
    namespace linkedlists
    {
        template<typename T, linkdirection L>
        class List
        {
            private:

                struct Node
                {
                    T _data;
                    Node * _next, * _previous;

                    Node(const T& data, Node * next, Node * previous)
                    : _data(data)
                      , _next(next)
                      , _previous(previous) {}

                    Node(T&& data, Node * next, Node * previous)
                    : _data(std::move(data))
                      , _next(next)
                      , _previous(previous) {}
                };

                size_t _elems = 0;
                Node * _head, * _tail;

            public:

                List<T>& operator = (const List<T>&);

                ~List();

                // Modifiers
                void push_back(T&& data);
                void push_back(const T& data);
                void push_front(T&& data);
                void push_front(const T& data);
                void pop_back();
                void pop_front();
                void swap(List<T>& x);
                void clear();

                // Iterators
                typedef common::iterator<Node, direction::forward>       iterator;
                typedef common::iterator<const Node, direction::forward> const_iterator;
                typedef common::iterator<Node, direction::reverse>       reverse_iterator;
                typedef common::iterator<const Node, direction::reverse> const_reverse_iterator;

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
                void reassign_head(Node * const node);
                void reassign_tail(Node * const node);
        };

    } // !linkedlists
} // !datastructs

#include "List.hpp"

#endif // DATA_STRUCTS_LINKEDLISTS_LIST_HH
