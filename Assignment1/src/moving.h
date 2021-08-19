#ifndef MOVING_H
#define MOVING_H
#include <string>

using namespace std;

class Moving
{
    string tableau[7][20];
    int tableau_control[7][20][1];
    string foundation_list[4][14];
    string waste[24];
    int destination_pile;
    string display_waste[3];
    string moving_resul;
    
public:
    Moving(string tableau[7][20],int tableau_control[7][20][1],string foundation_list[4][14],string waste[24],int destination_pile,string display_waste[3]);
    ~Moving();
    string get_moving_resul();

};

#endif // MOVING_H
