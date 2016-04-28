/* List.hpp
 * Defines a templated implementation for a linked-list
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

#ifndef DATA_STRUCTS_LINKEDLISTS_LINKEDLIST_HPP
#define DATA_STRUCTS_LINKEDLISTS_LINKEDLIST_HPP

namespace datastructs
{
    namespace linkedlists
    {
        template<typename T>
        List<T>& List<T>::operator = (const List<T>& rhs)
        {
            if (this != &rhs){
                clear();

                _elems = rhs._elems;
                _head = rhs._head;
                _tail = rhs._tail;
            }
            return *this;
        }

        template<typename T> 
        List<T>::~List()
        {
            clear();
        }

        // Modifiers
        template<typename T>
        void List<T>::push_back(T&& data)
        {
            Node * node = new Node(std::move(data), nullptr, _tail);
            reassign_tail(node);
            ++_elems;
        }

        template<typename T> 
        void List<T>::push_back(const T& data)
        {
            Node * node = new Node(data, nullptr, _tail);
            reassign_tail(node);
            ++_elems;
        }

        template<typename T>
        void List<T>::push_front(T&& data)
        {
            Node * node = new Node(std::move(data), _head, nullptr);
            reassign_head(node);
            ++_elems;
        }

        template<typename T>
        void List<T>::push_front(const T& data)
        {
            Node * node = new Node(data, _head, nullptr);
            reassign_head(node);
            ++_elems;
        }

        template<typename T> 
        void List<T>::pop_back()
        {   
            if (_tail != nullptr){
                Node * previous = _tail->_previous;
                delete _tail;
                reassign_tail(previous);
                --_elems;
            }
        }

        template<typename T>
        void List<T>::pop_front()
        {   
            if (_head != nullptr) {
                Node * next = _head->_next;
                delete _head;
                reassign_head(next);
                --_elems;
            }
        }

        template<typename T>
        void List<T>::swap(List<T>& x)
        {
            std::swap(_head, x._head);
            std::swap(_tail, x._tail);
            std::swap(_elems, x._elems);
        }

        template<typename T>
        void List<T>::clear()
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
        template<typename T>    
        typename List<T>::const_iterator List<T>::cbegin() const
        {
            return const_iterator(_head);    
        }

        template<typename T>
        typename List<T>::iterator List<T>::begin() const
        {
            return iterator(_head);
        }

        template<typename T>
        typename List<T>::const_iterator List<T>::cend() const
        {
            return const_iterator(_tail->_next);
        }

        template<typename T>
        typename List<T>::iterator List<T>::end() const
        {
            return iterator(_tail->_next);
        }

        template<typename T>
        typename List<T>::const_reverse_iterator List<T>::crbegin() const
        {
            return const_reverse_iterator(_tail);
        }

        template<typename T>
        typename List<T>::reverse_iterator List<T>::rbegin() const
        {
            return reverse_iterator(_tail); 
        }

        template<typename T>
        typename List<T>::const_reverse_iterator List<T>::crend() const
        {
            return const_reverse_iterator(_head->_previous);
        }

        template<typename T>
        typename List<T>::reverse_iterator List<T>::rend() const
        {
            return reverse_iterator(_head->_previous);
        }

        // Capacity
        template<typename T>
        size_t List<T>::size() const
        {
            return _elems;
        }

        template<typename T>
        bool List<T>::empty() const
        {
            return _head == nullptr;
        }

        // Element Access
        template<typename T>
        T& List<T>::front() 
        {
            return _head->_data;
        }

        template<typename T>
        const T& List<T>::front() const
        {
            return _head->_data;    
        }

        template<typename T>
        T& List<T>::back() 
        {
            return _tail->_data;
        }

        template<typename T>
        const T& List<T>::back() const
        {
            return _tail->_data;
        }

        // Helper Functions
        template<typename T>
        void List<T>::reassign_tail(Node * const node)
        {
            if (_head == nullptr)
                _head = node;
            if (_tail != nullptr)
                _tail->_next = node;
            _tail = node;
        }

        template<typename T>
        void List<T>::reassign_head(Node * const node)
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

