#ifndef SORTER_H
#define SORTER_H
#include <vector>
#include "Node.h"

using namespace std;

class Sorter
{
    vector <Node*> charArray;
    vector <int> intArray;

public:
    Sorter(vector <Node*> charArray,vector <int> intArray);
    ~Sorter();
    void mySort();
    vector <Node*> getCharArray();
    vector <int> getIntArray();
    void setCharArray(vector <Node*> charArray);
    void setIntArray(vector <int> intArray);
    
};

#endif // SORTER_H
