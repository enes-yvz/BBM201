#include <iostream>
#include <fstream>
#include <string>
#include "moving.h"

using namespace std;

int destination_pile;
string moving_resul{"   "};

Moving::Moving(string tableau[7][20],int tableau_control[7][20][1],string foundation_list[4][14],string waste[24],int destination_pile,string display_waste[3])
{
    
    for(int i{0};i<7;i++)
        for(int k{0};k<13;k++)
            this->tableau[i][k] = tableau[i][k];
    
    for(int i{0};i<7;i++)
        for(int k{0};k<13;k++)
            for(int j{0};j<1;j++)
                this->tableau_control[i][j][k] = tableau_control[i][j][k];
    
    for(int i{0};i<4;i++)
        for(int k{0};k<14;k++)
            this->foundation_list[i][k] = foundation_list[i][k];
    
    for(int i{0};i<24;i++)
        this->waste[i] = waste[i];
        
    this->destination_pile = destination_pile;
    
    int tmp{23};
        
    while(waste[tmp]=="   " && tmp >0) {
            
        tmp--;
        
    }
    
    int f{2};
            
    while(display_waste[f]=="   "&& f>0){
    
        f--;

    }
    
    if (waste[0]=="   ") {
        
        tmp=0;
    }
    
    int dest{0};
    
    while(tableau[destination_pile][dest]!="   " && dest<20) {
            
        dest++;
        
    }
    
    int num_first{waste[tmp][2] - '0'};
    
    if(waste[tmp][1]=='1') {
        
        num_first += 10;
        
    }
    
    int num_second{};
    
    if (dest!=0) { 
        
        num_second = tableau[destination_pile][dest-1][2]- '0'; 
        
        if(tableau[destination_pile][dest-1][1]=='1') {
            
            num_second += 10;
            
        }
    
    }
    
    if((num_first==13) && (dest== 0)) {
        
        tableau[destination_pile][dest]=waste[tmp];
        
        waste[tmp]="   ";
        
        display_waste[f]="   ";
        
    }
    
    else if((waste[tmp][0]=='H' || waste[tmp][0]=='D') && (tableau[destination_pile][dest-1][0]=='S' || tableau[destination_pile][dest-1][0]=='C') && (num_second-1 == num_first)) {
            
            tableau[destination_pile][dest]=waste[tmp];
    
            waste[tmp]="   ";
            
            display_waste[f]="   ";
        
    }
    
    else if ((waste[tmp][0]=='S' || waste[tmp][0]=='C') && (tableau[destination_pile][dest-1][0]=='H' || tableau[destination_pile][dest-1][0]=='D') && (num_second-1 == num_first)) {
            
            tableau[destination_pile][dest]=waste[tmp];
    
            waste[tmp]="   ";
            
            display_waste[f]="   ";
    
    }
    
    else {
            
            moving_resul += "Invalid Move!";
            moving_resul += "\n";
    }
}

Moving::~Moving()
{
}

string Moving::get_moving_resul(){
    
    return moving_resul;
}

