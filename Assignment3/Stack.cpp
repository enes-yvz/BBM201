#include <iostream>
#include "Stack.h"
#include "Package.h"

template <typename T> Stack<T>::Stack()
{

}

template <typename T> Stack<T>::~Stack()
{
    
}

template <typename T> bool Stack<T>::isEmpty() const {
    
        if (_head==NULL) {

            return true;
        }

        else {

            return false;
        
        }
    
    
}

template <typename T> int Stack<T>::size() const{
    
    return _size;
    
}

template <typename T> void Stack<T>::push(const T& newItem) {
    
        ListNode* node = new ListNode;
        
        node->item = newItem;
        
        node->next = NULL;
        
        if (_head == NULL) {
            
            _head = node;
            
            node->next = NULL;
        }   
        
        else { 
        
            ListNode* temp = _head; 
            _head = node;
            node->next = temp;
        }
        
        _size++;
    
}

template <typename T> void Stack<T>::getTop(T& stackTop) const{
    
    if (!isEmpty()) {
           
            stackTop = _head ->item ;
            
        }
    
}


template <typename T> void Stack<T>::pop() {
    
    if (!isEmpty()) {
            
        _head = _head->next;
    
    }
    
    _size--;
    
}




