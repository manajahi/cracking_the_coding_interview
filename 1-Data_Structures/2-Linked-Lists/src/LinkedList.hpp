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
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LinkedList_test.  If not, see <http://www.gnu.org/licenses/>.
 * (C) 2016, E. Higham
 */

#ifndef DATA_STRUCTS_LINKEDLIST_HPP
#define DATA_STRUCTS_LINKEDLIST_HPP

#ifdef SUPPORTS_PRAGMA_ONCE
#pragma once
#endif

namespace datastructs
{
    template<typename T>
    LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& list)
    {
        
    }
   
    template<typename T> 
    LinkedList<T>::~LinkedList()
    {
        Node * mNode;
        while(head) {
            mNode = head;
            head = head->next;
            delete mNode;
        }
    }

     // Modifiers
    template<typename T>
    void LinkedList<T>::push_back(T&& item)
    {
        Node * mNode = new Node(std::move(item), nullptr, tail);
        reassign_LinkedList_hierarchy(mNode);
        ++elems;
    }
   
    template<typename T> 
    void LinkedList<T>::push_back(const T& item)
    {
       Node * mNode = new Node(item, nullptr, tail);
       reassign_LinkedList_tail(mNode);
       ++elems;
    }

    template<typename T>
    void LinkedList<T>::push_front(T&& item)
    {
        Node * mNode = new Node(std::move(item), head, nullptr);
        reassign_LinkedList_head(mNode);
        ++elems;
    }

    template<typename T>
    void LinkedList<T>::push_front(const T& item)
    {
        Node * mNode = new Node(item, head, nullptr);
        reassign_LinkedList_head(mNode);
        ++elems;
    }

    template<typename T> 
    void LinkedList<T>::pop_back()
    {   
        if (tail != nullptr){
            Node * _previous = tail->previous;
            delete tail;
            reassign_LinkedList_tail(_previous);
            --elems;
        }
    }

    template<typename T>
    void LinkedList<T>::pop_front()
    {   
        if (head != nullptr) {
            Node * _next = head->next;
            delete head;
            reassign_LinkedList_head(_next);
            --elems;
        }
    }

    template<typename T>
    void LinkedList<T>::swap(LinkedList<T>& x)
    {
        std::swap(head, x.head);
        std::swap(tail, x.tail);
        std::swap(elems, x.elems);
    }
    
    template<typename T>
    void LinkedList<T>::clear()
    {
    }

    // Iterators
    template<typename T>    
    const_iterator LinkedList<T>::cbegin() const;

    template<typename T>
    iterator LinkedList<T>::begin() const;

    template<typename T>
    const_iterator LinkedList<T>::cend() const;

    template<typename T>
    iterator LinkedList<T>::end() const;

    template<typename T>
    const_iterator LinkedList<T>::crbegin() const;

    template<typename T>
    iterator LinkedList<T>::rbegin() const;

    template<typename T>
    const_iterator LinkedList<T>::crend() const;

    template<typename T>
    iterator LinkedList<T>::rend() const;

    // Capacity
    template<typename T>
    size_t LinkedList<T>::size() const
    {
        return elems;
    }

    template<typename T>
    bool LinkedList<T>::empty() const
    {
        return head == nullptr;
    }

    // Element Access
    template<typename T>
    T& LinkedList<T>::front() const
    {
        return head->item;
    }

    template<typename T>
    const T& LinkedList<T>::front() const
    {
        return head->item;    
    }

    template<typename T>
    T& LinkedList<T>::back() const
    {
        return tail->item;
    }

    template<typename T>
    const T& LinkedList<T>::back() const
    {
        return tail->item;
    }

    // Helper Functions
    template<typename T>
    void LinkedList<T>::reassign_LinkedList_tail(const T * const node)
    {
        if (head == nullptr)
            head = node;
        if (tail != nullptr)
            tail.next = node;
        tail = node;
    }

    template<typename T>
    void LinkedList<T>::reassign_LinkedList_head(const T * const node)
    {
        if (tail == nullptr)
            tail = node;
        if (head != nullptr)
            head.previous = node;
        }
        head = node;
    }

} // end namespace datastructs

#endif //DATA_STRUCTS_LINKEDLIST_HPP

