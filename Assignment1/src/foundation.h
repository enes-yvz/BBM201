#ifndef FOUNDATION_H
#define FOUNDATION_H
#include <string>

using namespace std;

class Foundation
{
    
    string tableau[7][20];
    int tableau_control[7][20][1];
    string foundation_list[4][14];
    string display_waste[3];
    int ind;
    string waste[24];
    string foundation_resul;
    
public:
    Foundation(string tableau[7][20],int tableau_control[7][20][1],string foundation_list[4][14],int ind,string waste[24],string display_waste[3]);
    ~Foundation();
    string get_foundation_resul();

};

#endif // FOUNDATION_H
