/* LinkedList.hpp
 * Defines a templated implementation for a double linked-list
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
 * GNU General Public License for more deails.
 *
 * You should have received a copy of the GNU General Public License
 * along with LinkedList_test.  If not, see <http://www.gnu.org/licenses/>.
 * (C) 2016, E. Higham
 */

#ifndef DATA_STRUCTS_LINKEDLIST_HPP
#define DATA_STRUCTS_LINKEDLIST_HPP

namespace datastructs
{
    template<typename T>
    LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
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
    LinkedList<T>::~LinkedList()
    {
        clear();
    }

     // Modifiers
    template<typename T>
    void LinkedList<T>::push_back(T&& data)
    {
        Node * node = new Node(std::move(data), nullptr, _tail);
        reassign_tail(node);
        ++_elems;
    }
   
    template<typename T> 
    void LinkedList<T>::push_back(const T& data)
    {
       Node * node = new Node(data, nullptr, _tail);
       reassign_tail(node);
       ++_elems;
    }

    template<typename T>
    void LinkedList<T>::push_front(T&& data)
    {
        Node * node = new Node(std::move(data), _head, nullptr);
        reassign_head(node);
        ++_elems;
    }

    template<typename T>
    void LinkedList<T>::push_front(const T& data)
    {
        Node * node = new Node(data, _head, nullptr);
        reassign_head(node);
        ++_elems;
    }

    template<typename T> 
    void LinkedList<T>::pop_back()
    {   
        if (_tail != nullptr){
            Node * previous = _tail->_previous;
            delete _tail;
            reassign_tail(previous);
            --_elems;
        }
    }

    template<typename T>
    void LinkedList<T>::pop_front()
    {   
        if (_head != nullptr) {
            Node * next = _head->_next;
            delete _head;
            reassign_head(next);
            --_elems;
        }
    }

    template<typename T>
    void LinkedList<T>::swap(LinkedList<T>& x)
    {
        std::swap(_head, x._head);
        std::swap(_tail, x._tail);
        std::swap(_elems, x._elems);
    }
    
    template<typename T>
    void LinkedList<T>::clear()
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
    typename LinkedList<T>::const_iterator LinkedList<T>::cbegin() const
    {
        return const_iterator(_head);    
    }

    template<typename T>
    typename LinkedList<T>::iterator LinkedList<T>::begin() const
    {
        return iterator(_head);
    }

    template<typename T>
    typename LinkedList<T>::const_iterator LinkedList<T>::cend() const
    {
        return const_iterator(_tail->_next);
    }

    template<typename T>
    typename LinkedList<T>::iterator LinkedList<T>::end() const
    {
        return iterator(_tail->_next);
    }

    template<typename T>
    typename LinkedList<T>::const_reverse_iterator LinkedList<T>::crbegin() const
    {
        return const_reverse_iterator(_tail);
    }

    template<typename T>
    typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin() const
    {
        return reverse_iterator(_tail); 
    }

    template<typename T>
    typename LinkedList<T>::const_reverse_iterator LinkedList<T>::crend() const
    {
        return const_reverse_iterator(_head->_previous);
    }

    template<typename T>
    typename LinkedList<T>::reverse_iterator LinkedList<T>::rend() const
    {
        return reverse_iterator(_head->_previous);
    }

    // Capacity
    template<typename T>
    size_t LinkedList<T>::size() const
    {
        return _elems;
    }

    template<typename T>
    bool LinkedList<T>::empty() const
    {
        return _head == nullptr;
    }

    // Element Access
    template<typename T>
    T& LinkedList<T>::front() 
    {
        return _head->_data;
    }

    template<typename T>
    const T& LinkedList<T>::front() const
    {
        return _head->_data;    
    }

    template<typename T>
    T& LinkedList<T>::back() 
    {
        return _tail->_data;
    }

    template<typename T>
    const T& LinkedList<T>::back() const
    {
        return _tail->_data;
    }

    // Helper Functions
    template<typename T>
    void LinkedList<T>::reassign_tail(Node * const node)
    {
        if (_head == nullptr)
            _head = node;
        if (_tail != nullptr)
            _tail->_next = node;
        _tail = node;
    }

    template<typename T>
    void LinkedList<T>::reassign_head(Node * const node)
    {
        if (_tail == nullptr)
            _tail = node;
        if (_head != nullptr)
            _head->_previous = node;
        _head = node;
    }

} // end namespace datastructs

#endif //DATA_STRUCTS_LINKEDLIST_HPP

