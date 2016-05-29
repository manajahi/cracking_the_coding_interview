/* List.hpp
 * Defines a templated implementation for a linked-list
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

#ifndef DATA_STRUCTS_LINKEDLISTS_LINKEDLIST_HPP
#define DATA_STRUCTS_LINKEDLISTS_LINKEDLIST_HPP

namespace datastructs
{
    namespace linkedlists
    {
        template<typename T, LinkType L>
        List<T, L>& List<T, L>::operator = (const List<T, L>& rhs)
        {
            if (this != &rhs){
                clear();

                _elems = rhs._elems;
                _head = rhs._head;
                _tail = rhs._tail;
            }
            return *this;
        }

        template<typename T, LinkType L>
        List<T, L>::~List()
        {
            clear();
        }

        // Modifiers
        template<typename T, LinkType L>
        void List<T, L>::push_back(T&& data)
        {
            Node * node = new Node(std::move(data), nullptr, _tail);
            reassign_tail(node);
            ++_elems;
        }

        template<typename T, LinkType L>
        void List<T, L>::push_back(const T& data)
        {
            Node * node = new Node(data, nullptr, _tail);
            reassign_tail(node);
            ++_elems;
        }

        template<typename T, LinkType L>
        void List<T, L>::push_front(T&& data)
        {
            Node * node = new Node(std::move(data), _head, nullptr);
            reassign_head(node);
            ++_elems;
        }

        template<typename T, LinkType L>
        void List<T, L>::push_front(const T& data)
        {
            Node * node = new Node(data, _head, nullptr);
            reassign_head(node);
            ++_elems;
        }

        template<typename T, LinkType L>
        void List<T, L>::pop_back()
        {   
            if (_tail != nullptr){
                Node * previous = _tail->_previous;
                delete _tail;
                reassign_tail(previous);
                --_elems;
            }
        }

        template<typename T, LinkType L>
        void List<T, L>::pop_front()
        {   
            if (_head != nullptr) {
                Node * next = _head->_next;
                delete _head;
                reassign_head(next);
                --_elems;
            }
        }

        template<typename T, LinkType L>
        void List<T, L>::swap(List<T, L>& x)
        {
            std::swap(_head, x._head);
            std::swap(_tail, x._tail);
            std::swap(_elems, x._elems);
        }

        template<typename T, LinkType L>
        void List<T, L>::clear()
        {
            Node * node = _head;
            while(node){
                Node * _nextNode = node->_next;
                delete node;
                node = _nextNode;
            }
            _elems = 0;
            _tail = _head = nullptr;
        }

        // Iterators
        template<typename T, LinkType L>
        typename List<T, L>::const_iterator List<T, L>::cbegin() const
        {
            return const_iterator(_head);    
        }

        template<typename T, LinkType L>
        typename List<T, L>::iterator List<T, L>::begin() const
        {
            return iterator(_head);
        }

        template<typename T, LinkType L>
        typename List<T, L>::const_iterator List<T, L>::cend() const
        {
            return const_iterator(_tail->_next);
        }

        template<typename T, LinkType L>
        typename List<T, L>::iterator List<T, L>::end() const
        {
            return iterator(_tail->_next);
        }

        template<typename T, LinkType L>
        typename List<T, L>::const_reverse_iterator List<T, L>::crbegin() const
        {
            return const_reverse_iterator(_tail);
        }

        template<typename T, LinkType L>
        typename List<T, L>::reverse_iterator List<T, L>::rbegin() const
        {
            return reverse_iterator(_tail); 
        }

        template<typename T, LinkType L>
        typename List<T, L>::const_reverse_iterator List<T, L>::crend() const
        {
            return const_reverse_iterator(_head->_previous);
        }

        template<typename T, LinkType L>
        typename List<T, L>::reverse_iterator List<T, L>::rend() const
        {
            return reverse_iterator(_head->_previous);
        }

        // Capacity
        template<typename T, LinkType L>
        size_t List<T, L>::size() const
        {
            return _elems;
        }

        template<typename T, LinkType L>
        bool List<T, L>::empty() const
        {
            return _head == nullptr;
        }

        // Element Access
        template<typename T, LinkType L>
        T& List<T, L>::front() 
        {
            return _head->_data;
        }

        template<typename T, LinkType L>
        const T& List<T, L>::front() const
        {
            return _head->_data;    
        }

        template<typename T, LinkType L>
        T& List<T, L>::back() 
        {
            return _tail->_data;
        }

        template<typename T, LinkType L>
        const T& List<T, L>::back() const
        {
            return _tail->_data;
        }

        // Helper Functions
        template<typename T, LinkType L>
        void List<T, L>::reassign_tail(Node * const node)
        {
            if (_head == nullptr)
                _head = node;
            if (_tail != nullptr)
                _tail->_next = node;
            _tail = node;
        }

        template<typename T, LinkType L>
        void List<T, L>::reassign_head(Node * const node)
        {
            if (_tail == nullptr)
                _tail = node;
            if (_head != nullptr)
                _head->_previous = node;
            _head = node;
        }

    } // !linkedlists
} // !datastructs

#endif // DATA_STRUCTS_LINKEDLISTS_LINKEDLIST_HPP

