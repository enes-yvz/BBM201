#include "Node.h"
#include <iostream>
#include <string>

char data; 
struct Node* left; 
struct Node* right; 

Node::Node()
{
    left= NULL; 
    right = NULL ; 
    
}

Node::~Node()
{
}

