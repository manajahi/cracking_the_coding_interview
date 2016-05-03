/* List.hh
 * Defines the type definition of list and forward_list
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

#include "iterator.hh"
#include "traits/list_traits.hh"

#define SET_TAG(L) \
typename utils::conditional_t<is_doubly_linked<L>::value, \
                              std::bidirectional_iterator_tag, \
                              std::forward_iterator_tag>
namespace datastructs
{

    namespace linkedlists
    {
        template<typename T, LinkType L>
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

            List& operator = (const List&);

            ~List();

            // Modifiers
            void push_back(T&& data);
            void push_back(const T& data);
            void push_front(T&& data);
            void push_front(const T& data);
            void pop_back();
            void pop_front();
            void swap(List& x);
            void clear();

            // Iterators
            typedef iterators::iterator<Node, SET_TAG(L), direction::forward>       iterator;
            typedef iterators::iterator<const Node, SET_TAG(L), direction::forward> const_iterator;
            typedef iterators::iterator<Node, SET_TAG(L), direction::reverse>       reverse_iterator;
            typedef iterators::iterator<const Node, SET_TAG(L), direction::reverse> const_reverse_iterator;

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

    template<typename T>
    using forward_list = linkedlists::List<T, linkedlists::LinkType::singly>;

    template<typename T>
    using list = linkedlists::List<T, linkedlists::LinkType::doubly>;

} // !datastructs

#include "List.hpp"

#undef SET_TAG

#endif // DATA_STRUCTS_LINKEDLISTS_LIST_HH
