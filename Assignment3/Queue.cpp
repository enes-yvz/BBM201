#include <iostream>
#include "Queue.h"
#include "Package.h"

using namespace std;

template <typename T> Queue<T>::Queue()
{


}

template <typename T> Queue<T>::~Queue()
{
    
}

template <typename T> bool Queue<T>::isEmpty() const {
    
    if(_front == NULL && _lastNode == NULL){

            return true;
        }

        else {

            return false;

        }
}

template <typename T> int Queue<T>::size() const{
    
    return _size;
}

template <typename T> void Queue<T>::enqueue(const T& newItem) {
            
        QueueNode* node = new QueueNode;
        
        node->item = newItem;
        
        node->next = NULL;

        if(_lastNode == NULL){

            _front = node;
            
            _lastNode = _front;
        }

        else {
        
            _lastNode->next = node;
            
            _lastNode = node;
        }
        
        _size++;
    
    
}

template <typename T> void Queue<T>:: getFront(T& QueueTop) const{
    
    if (!isEmpty()) {
            
            QueueTop = _front->item;
            
        }
    
}


template <typename T> void Queue<T>::dequeue(){
    
    if (!isEmpty()) {
        
        if (_front == _lastNode){

            _lastNode = NULL;
        
        }

        _front = _front ->next;
            
    }
        
        _size--;
    
}

