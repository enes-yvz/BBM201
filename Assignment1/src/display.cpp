#include <iostream>
#include <fstream>
#include <string>
#include "display.h"

using namespace std;

string display_resul{"   "};

Display::Display(string tableau[7][20],int tableau_control[7][20][1],string foundation_list[4][14],string waste[24],string stock_list[24],string display_waste[3])
{
    
    for(int i{0};i<24;i++)
        this->stock_list[i] = stock_list[i];
    
    for(int i{0};i<7;i++)
        for(int k{0};k<20;k++)
            this->tableau[i][k] = tableau[i][k];
    
    for(int i{0};i<7;i++)
        for(int k{0};k<20;k++)
            for(int j{0};j<1;j++)
                this->tableau_control[i][j][k] = tableau_control[i][j][k];
    
    for(int i{0};i<4;i++)
        for(int k{0};k<14;k++)
            this->foundation_list[i][k] = foundation_list[i][k];
    
    for(int i{0};i<24;i++)
        this->waste[i] = waste[i];
    
    this->display_resul+= "\n";
    
    if (stock_list[0]!="   ")
        this->display_resul += "@@@ ";
        
    else 
        this->display_resul += "___ ";
        
    if (display_waste[0]=="   " && waste[0]=="   ") {
        
        this->display_resul += "___ ";
        
        this->display_resul += "___ ";
   
        this->display_resul += "___ ";
    }
        
    else if (display_waste[0]=="   " && waste[0]!="   ") {
        
        int p{23};
        
        while (waste[p]!="    " && p>0) {
            
            p--;
        }
        
        display_waste[0]=waste[p];
        
        this->display_resul += "___ ";
   
        this->display_resul += "___ ";
        
        
    }
    
    else {
        
        if(display_waste[1]=="    ") {
            
            this->display_resul += display_waste[0];
            
            this->display_resul += " ";
            
            this->display_resul += "___ ";
   
            this->display_resul += "___ ";
            
        }
        
        else if(display_waste[2]=="   ") {
            
            this->display_resul += display_waste[0];
            
            this->display_resul += " ";
            
            this->display_resul += display_waste[1];
            
            this->display_resul += " ";
   
            this->display_resul += "___ ";
            
            
        }
        
        else {
            
            this->display_resul += display_waste[0];
            
            this->display_resul += " ";
            
            this->display_resul += display_waste[1];
            
            this->display_resul += " ";
            
            this->display_resul += display_waste[2];
            
            this->display_resul += " ";
            
        }
    }
   
    this->display_resul += "        ";
    
    int a{0};
    
    while (foundation_list[0][a]!="   " && a<20) {
        
        a++;
    }
    
    int b{0};
    
    while (foundation_list[1][b]!="   " && b<20) {
        
        b++;
    }
    
    int c{0};
    
    while (foundation_list[2][c]!="   " && c<20) {
        
        c++;
    }
    
    int d{0};
    
    while (foundation_list[3][d]!="   " && d<20) {
        
        d++;
    }
    
    a--;
    
    b--;
    
    c--;
    
    d--;
    
    if(a==-1)
        this->display_resul += "___ ";
        
    else
        this->display_resul += foundation_list[0][a] + " ";
   
    if(b==-1)
        this->display_resul += "___ ";
        
    else
        this->display_resul += foundation_list[1][b] + " ";
   
    if(c==-1)
        this->display_resul += "___ ";
        
    else
        this->display_resul += foundation_list[2][c] + " ";
   
    if(d==-1)
        this->display_resul += "___ ";
        
    else
        this->display_resul += foundation_list[3][d] + " ";
   
    this->display_resul += "\n";
    
    this->display_resul += "\n";
   
    for(int i{0};i<20;i++) {
       
       for(int f{0};f<7;f++) {
           
           if (tableau_control[f][i][0]==1) {
               
               this->display_resul += tableau[f][i];
               
           }
           
           else {
               
               this->display_resul += "@@@";
           }
           
           if(f!=6) {
               
               this->display_resul += "   ";
           }
       }
       
       this->display_resul += "\n";
   }
   
   this->display_resul.erase(display_resul.find_last_not_of(" \n\r\t")+1);
   
   this->display_resul += "\n";
    
}

Display::~Display()
{
}

string Display::get_display_resul(){
    
    return display_resul;
}
