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

namespace datastructs
{
    template<typename T>
    LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& rhs)
    {
        if (this != &rhs){
            clear();

            elems = rhs.elems;
            head = rhs.head;
            tail = rhs.tail;
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
    void LinkedList<T>::push_back(T&& item)
    {
        Node * mNode = new Node(std::move(item), nullptr, tail);
        reassign_tail(mNode);
        ++elems;
    }
   
    template<typename T> 
    void LinkedList<T>::push_back(const T& item)
    {
       Node * mNode = new Node(item, nullptr, tail);
       reassign_tail(mNode);
       ++elems;
    }

    template<typename T>
    void LinkedList<T>::push_front(T&& item)
    {
        Node * mNode = new Node(std::move(item), head, nullptr);
        reassign_head(mNode);
        ++elems;
    }

    template<typename T>
    void LinkedList<T>::push_front(const T& item)
    {
        Node * mNode = new Node(item, head, nullptr);
        reassign_head(mNode);
        ++elems;
    }

    template<typename T> 
    void LinkedList<T>::pop_back()
    {   
        if (tail != nullptr){
            Node * _previous = tail->previous;
            delete tail;
            reassign_tail(_previous);
            --elems;
        }
    }

    template<typename T>
    void LinkedList<T>::pop_front()
    {   
        if (head != nullptr) {
            Node * _next = head->next;
            delete head;
            reassign_head(_next);
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
        Node * mNode = head;
        while(mNode){
            Node * nextNode = mNode->next;
            delete mNode;
            mNode = nextNode;
        }
        elems = 0;
        tail = head = nullptr;
    }

    // Iterators
    template<typename T>    
    typename LinkedList<T>::const_iterator LinkedList<T>::cbegin() const
    {
        return const_iterator(*head);    
    }

    template<typename T>
    typename LinkedList<T>::iterator LinkedList<T>::begin() const
    {
        return iterator(*head);
    }

    template<typename T>
    typename LinkedList<T>::const_iterator LinkedList<T>::cend() const
    {
        return const_iterator(tail->next);
    }

    template<typename T>
    typename LinkedList<T>::iterator LinkedList<T>::end() const
    {
        return iterator(tail->end);
    }

    template<typename T>
    typename LinkedList<T>::const_reverse_iterator LinkedList<T>::crbegin() const
    {
        return const_reverse_iterator(*tail);
    }

    template<typename T>
    typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin() const
    {
        return reverse_iterator(*tail); 
    }

    template<typename T>
    typename LinkedList<T>::const_reverse_iterator LinkedList<T>::crend() const
    {
        return const_reverse_iterator(head->previous);
    }

    template<typename T>
    typename LinkedList<T>::reverse_iterator LinkedList<T>::rend() const
    {
        return reverse_iterator(head->previous);
    }

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
    T& LinkedList<T>::front() 
    {
        return head->item;
    }

    template<typename T>
    const T& LinkedList<T>::front() const
    {
        return head->item;    
    }

    template<typename T>
    T& LinkedList<T>::back() 
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
    void LinkedList<T>::reassign_tail(Node * const node)
    {
        if (head == nullptr)
            head = node;
        if (tail != nullptr)
            tail->next = node;
        tail = node;
    }

    template<typename T>
    void LinkedList<T>::reassign_head(Node * const node)
    {
        if (tail == nullptr)
            tail = node;
        if (head != nullptr)
            head->previous = node;
        head = node;
    }

} // end namespace datastructs

#endif //DATA_STRUCTS_LINKEDLIST_HPP

