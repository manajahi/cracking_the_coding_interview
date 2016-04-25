/* LinkedList.hh
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

namespace DataStructs
{
    template<typename T>
    LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& list)
    {
        
    }
    
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
    void LinkedList<T>::push_back(T&& item)
    {
        Node * mNode = new Node(std::move(item), nullptr, tail);
        reassign_LinkedList_hierarchy(mNode);
    }
    
    void LinkedList<T>::push_back(const T& item)
    {
       Node * mNode = new Node(item,nullptr, tail);
       reassign_LinkedList_hierarchy(mNode);
    }

    void LinkedList<T>::push_front(T&& item)
    {
    }

    void LinkedList<T>::push_front(const T& item)
    {
    }

    void LinkedList<T>::pop_back()
    {
    }

    void LinkedList<T>::pop_front()
    {
    }

    void LinkedList<T>::swap(LinkedList<T>& x)
    {
    }

    void LinkedList<T>::clear()
    {
    }

    // Iterators
        
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
    const T& back() const()

    // Helper Functions
    
    void LinkedList<T>::reassign_LinkedList_hierarchy(const T * const node)
    {
        if (head == nullptr)
            head = node;
        if (tail != nullptr)
            tail.next = node;
        tail = node;
        ++elems;
    }
} // end namespace DataStructs

