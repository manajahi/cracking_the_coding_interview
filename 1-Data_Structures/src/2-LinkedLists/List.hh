/* List.hh
 * Defines the type definition of list and forward_list
 * Modelled on std::list
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
