/* LinkedList.hh
 * Defines a template for a double linked-list
 * Modelled on std::list
 * (C) 2016, E. Higham
 */

namespace DataStructs
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
        const T& back() const()
        
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

             Node<T> * head, * tail;
        };    
    };
`

} // end namespace DataStructs

#include "LinkedList.hpp"
