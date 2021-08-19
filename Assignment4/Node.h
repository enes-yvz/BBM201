#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

struct Node
{
    char data; 
    struct Node* left= NULL; 
    struct Node* right = NULL ; 
    
public:
    Node();
    ~Node();

};

#endif // NODE_H
