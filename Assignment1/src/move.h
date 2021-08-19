#ifndef MOVE_H
#define MOVE_H
#include <string>

using namespace std;

class Move
{
    string tableau[7][20];
    int tableau_control[7][20][1];
    string foundation_list[4][14];
    string waste[24];
    int pile_num;
    int card_index;
    int destination;
    string move_resul;
    
public:
    Move(string tableau[7][20],int tableau_control[7][20][1],string foundation_list[4][14],string waste[24],int pile_num,int card_index,int destination);
    ~Move();
    string get_move_resul();

};

#endif // MOVE_H
