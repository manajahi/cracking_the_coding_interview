/* LinkedList.hh
 * Defines a template for a double linked-list
 * Modelled on std::list
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
    }

     // Modifiers
    void LinkedList<T>::push_back(T&& item)
    {
    }
    
    void LinkedList<T>::push_back(const T& item)
    {
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

} // end namespace DataStructs

