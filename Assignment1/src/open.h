#ifndef OPEN_H
#define OPEN_H
#include <string>

using namespace std;

class Open
{   
    int i;
    string tableau[7][20];
    int tableau_control[7][20][1];
    
public:
    Open(string tableau[7][20],int tableau_control[7][20][1],int i);
    ~Open();

};

#endif // OPEN_H
