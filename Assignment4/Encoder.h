#ifndef ENCODER_H
#define ENCODER_H
#include <vector>
#include <string>
#include "Node.h"
#include "Sorter.h"

using namespace std;

class Encoder
{
    vector <Node*> charArrayEncoder;
    vector <int> intArrayEncoder;
    string myResult;
    string myString;
    
public:
    Encoder(vector <Node*> charArrayEncoder,vector <int> intArrayEncoder);
    ~Encoder();
    void createTree();
    vector <int> getIntArrayEncoder();
    vector <Node*> getCharArrayEncoder();
    string encode(string itemEncoder);
    void findNode(Node* node,char key,string addKey);
    string findCharacter(char c,Node* node);

};

#endif // ENCODER_H
