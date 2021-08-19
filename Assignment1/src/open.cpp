#include <iostream>
#include <fstream>
#include <string>
#include "open.h"

using namespace std;

int i;

Open::Open(string tableau[7][20],int tableau_control[7][20][1],int i)
{
    
    for(int i{0};i<7;i++)
        for(int k{0};k<20;k++)
            this->tableau[i][k] = tableau[i][k];
    
    for(int i{0};i<7;i++)
        for(int k{0};k<20;k++)
            for(int j{0};j<1;j++)
                this->tableau_control[i][j][k] = tableau_control[i][j][k];
                
    this->i=i;
                
    int k{19};
    
    while (tableau[i][k]=="   ") {
        
        k--;
    }
    
    tableau_control[i][k][0]=1;
    
}

Open::~Open()
{
}

