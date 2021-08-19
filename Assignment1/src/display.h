#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>

using namespace std;

class Display
{
    string tableau[7][20];
    int tableau_control[7][20][1];
    string foundation_list[4][14];
    string waste[24];
    string stock_list[24];
    string display_waste[3];
    string display_resul;
    
public:
    Display(string tableau[7][20],int tableau_control[7][20][1],string foundation_list[4][14],string waste[24],string stock_list[24],string display_waste[3]);
    ~Display();
    string get_display_resul();

};

#endif // DISPLAY_H
