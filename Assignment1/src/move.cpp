#include <iostream>
#include <fstream>
#include <string>
#include "move.h"

using namespace std;

int pile_num;
int card_index;
int destination;
string move_resul{"   "};

Move::Move(string tableau[7][20],int tableau_control[7][20][1],string foundation_list[4][14],string waste[24],int pile_num,int card_index,int destination)
{
    
    for(int i{0};i<7;i++)
        for(int k{0};k<20;k++)
            this->tableau[i][k] = tableau[i][k];
    
    for(int i{0};i<7;i++)
        for(int k{0};k<20;k++)
            for(int j{0};j<1;j++)
                this->tableau_control[i][j][k] = tableau_control[i][j][k];
    
    for(int i{0};i<4;i++)
        for(int k{0};k<13;k++)
            this->foundation_list[i][k] = foundation_list[i][k];
    
    for(int i{0};i<24;i++)
        this->waste[i] = waste[i];
        
        this->pile_num = pile_num;
        
        this->card_index = card_index;
        
        this->destination = destination;
    
    int tmp{0};
        
    while(tableau[pile_num][tmp]!="   " && tmp<20) {
        
        tmp++;
        
    }
    
    int dest{0};
    
    while(tableau[destination][dest]!="   " && tmp<20) {
        
        dest++;
        
    }
    
    int num_first{};
        
    num_first = tableau[pile_num][tmp-1-card_index][2] - '0'; 
    
    if(tableau[pile_num][tmp-1-card_index][1]=='1') {
        
        num_first += 10;
        
    }
    
    int num_second{};
    
    if (dest!=0) {
        
        num_second = tableau[destination][dest-1][2]- '0'; 
        
        if(tableau[destination][dest-1][1]=='1') {
            
            num_second += 10;
            
        }
        
    }
    
    if(num_first==13 && dest==0) {
            
        for(int i{0};i<card_index+1;i++) {
            
            if(card_index>0) {
                
                num_first = tableau[pile_num][tmp-1-card_index][2] - '0'; 
                
                if(tableau[pile_num][tmp-1-card_index][1]=='1') {
                    
                    num_first += 10;
                    
                }
                
                int num_third{};
    
                num_third = tableau[pile_num][tmp-card_index][2]- '0'; 

                if(tableau[pile_num][tmp-card_index][1]=='1') {
                    
                    num_third += 10;
                    
                }
                
                if(!(((num_first=num_third+1) && (tableau[pile_num][tmp-1-card_index][0]=='S' || tableau[pile_num][tmp-1-card_index][0]=='C') && (tableau[pile_num][tmp-card_index][0]=='H' || tableau[pile_num][tmp-card_index][0]=='D')) || tableau[pile_num][tmp-card_index]!="    "))   {
                    this->move_resul += "Invalid Move!",
                    this->move_resul += "\n";
                    break;
                }
            }
        
            tableau[destination][dest]=tableau[pile_num][tmp-1-card_index];
    
            dest++;
    
            tableau[pile_num][tmp-1-card_index]="   ";
            
            tableau_control[pile_num][tmp-1-card_index][0]=1;
    
            tmp++; 
        
        }
        
    }
        
    else if((tableau[pile_num][tmp-1-card_index][0]=='H' || tableau[pile_num][tmp-1-card_index][0]=='D') && 
    (tableau[destination][dest-1][0]=='S' || tableau[destination][dest-1][0]=='C') && (num_second-1 == num_first) ) {
            
            for(int i{0};i<card_index+1;i++) {
                
                if(card_index>0) {
                    
                    num_first = tableau[pile_num][tmp-1-card_index][2] - '0'; 
                    
                    if(tableau[pile_num][tmp-1-card_index][1]=='1') {
                        
                        num_first += 10;
                        
                    }
                    
                    int num_third{};
        
                    num_third = tableau[pile_num][tmp-card_index][2]- '0'; 
    
                    if(tableau[pile_num][tmp-card_index][1]=='1') {
                        
                        num_third += 10;
                        
                    }
                    
                    if(!(((num_first=num_third+1) && (tableau[pile_num][tmp-1-card_index][0]=='S' || tableau[pile_num][tmp-1-card_index][0]=='C') && (tableau[pile_num][tmp-card_index][0]=='H' || tableau[pile_num][tmp-card_index][0]=='D')) || tableau[pile_num][tmp-card_index]!="    "))   {
                        this->move_resul += "Invalid Move!";
                        this->move_resul += "\n";
                        break;
                    }
                }
            
                tableau[destination][dest]=tableau[pile_num][tmp-1-card_index];
        
                dest++;
        
                tableau[pile_num][tmp-1-card_index]="   ";
                
                tableau_control[pile_num][tmp-1-card_index][0]=1;
        
                tmp++; 
            
            }
    }
    
    else if((tableau[pile_num][tmp-1-card_index][0]=='S' || tableau[pile_num][tmp-1-card_index][0]=='C') && 
    (tableau[destination][dest-1][0]=='H' || tableau[destination][dest-1][0]=='D') && (num_second-1 == num_first)) {
            
            for(int i{0};i<card_index+1;i++) {
                
                if(card_index>0) {
                    
                    num_first = tableau[pile_num][tmp-1-card_index][2] - '0'; 
                    
                    if(tableau[pile_num][tmp-1-card_index][1]=='1') {
                        
                        num_first += 10;
                        
                    }
                    
                    int num_third{};
        
                    num_third = tableau[pile_num][tmp-card_index][2]- '0'; 
    
                    if(tableau[pile_num][tmp-card_index][1]=='1') {
                        
                        num_third += 10;
                        
                    }
                    
                    if(!(((num_first=num_third+1) && (tableau[pile_num][tmp-1-card_index][0]=='S' || tableau[pile_num][tmp-1-card_index][0]=='C') && (tableau[pile_num][tmp-card_index][0]=='H' || tableau[pile_num][tmp-card_index][0]=='D')) || tableau[pile_num][tmp-card_index]!="    "))   {
                        this->move_resul += "Invalid Move!";
                        this->move_resul += "\n";
                        break;
                    }
                }
            
                tableau[destination][dest]=tableau[pile_num][tmp-1-card_index];
        
                dest++;
        
                tableau[pile_num][tmp-1-card_index]="   ";
                
                tableau_control[pile_num][tmp-1-card_index][0]=1;
        
                tmp++; 
            
            }
            
    }
    
    else {
            
            this->move_resul += "Invalid Move!";
            this->move_resul += "\n";
            
    }
    
}

Move::~Move()
{
}

string Move::get_move_resul(){
    
    return move_resul;
}

