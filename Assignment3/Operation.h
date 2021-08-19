#ifndef OPERATION_H
#define OPERATION_H
#include <string>
#include "Queue.cpp"
#include "Stack.cpp"
//#include "Package.h"
//#include "Truck.h"
#include "Package.cpp"
#include "Truck.cpp"

using namespace std;


class Operation
{
    struct Node* start = NULL;
    
public:
    Operation();
    ~Operation();
    void operation(char *argvFirst,char *argvSecond,char *argvThird,char *argvFourth,char *argvFifth);
    int findIndex(vector <string> dests,string searchItem);
    int strToInt(string str);
    bool foundItem(Package item);
    void addItem(Package item);
    Package deleteItem(Package item);

};

#endif // OPERATION_H
