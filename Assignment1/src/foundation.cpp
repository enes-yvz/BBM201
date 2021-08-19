#include <iostream>
#include <fstream>
#include <string>
#include "foundation.h"

using namespace std;

string tableau[7][20];
int tableau_control[7][20][1];
string foundation_list[4][14];
string display_waste[3];
string waste[24];
int ind;
string foundation_resul{"   "};

Foundation::Foundation(string tableau[7][20],int tableau_control[7][20][1],string foundation_list[4][14],int ind,string waste[24],string display_waste[3])
{
    
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
    
    this->ind = ind;
    
    for(int i{0};i<24;i++)
        this->waste[i] = waste[i];
    
    int i{19};
    
    if (ind !=7) {
        
        while(tableau[ind][i]=="   " && i>0){
            
            i--;
        
        }
        
        if (tableau[ind][0]=="   ") {
            
            i=0;
        }
        
        int num{-1000};
            
        num = tableau[ind][i][2] - '0'; 
    
        if(tableau[ind][i][1]!='0') {
            
            num += 10;
            
        }
        
        if (tableau[ind][i][0]=='H') {
            
            int k{13};
            
            while(foundation_list[0][k]=="   " && k>0){
            
            k--;
        
            }
            
            k++;
            
            if(foundation_list[0][0]== "   ") {
                    
                k=0;
                
            }
            
            if(num==1 && k==0) {
                
                foundation_list[0][0]=tableau[ind][i];
                
                tableau[ind][i]="   ";
                
                
            }
            
            else if(num-1==k) {
                
                foundation_list[0][k]=tableau[ind][i];
                
                tableau[ind][i]="   ";
                
            }
            
            else {
                
                this->foundation_resul += "Invalid Move!";
                this->foundation_resul += "\n";
            }
            
        }
        
        else if (tableau[ind][i][0]=='D') {
            
            int k{13};
            
            while(foundation_list[1][k]=="   " && k>0){
            
            k--;
        
            }
            
            k++;
            
            if(foundation_list[1][0]== "   ") {
                    
                k=0;
                
            }
            
            if(num==1 && k==0) {
                
                foundation_list[1][0]=tableau[ind][i];
                
                tableau[ind][i]="   ";
                
                
            }
            
            else if(num-1==k) {
                
                foundation_list[1][k]=tableau[ind][i];
                
                tableau[ind][i]="   ";
                
            }
            
            else {
                
                this->foundation_resul += "Invalid Move!";
                this->foundation_resul += "\n";
            }
            
        }
        
        else if (tableau[ind][i][0]=='S') {
            
            int k{13};
            
            while(foundation_list[2][k]=="   " && k>0){
            
            k--;
        
            }
            
            k++;
            
            if(foundation_list[2][0]== "   ") {
                    
                k=0;
                
            }
            
            if(num==1 && k==0) {
                
                foundation_list[2][0]=tableau[ind][i];
                
                tableau[ind][i]="   ";
                
                
            }
            
            else if(num-1==k) {
                
                foundation_list[2][k]=tableau[ind][i];
                
                tableau[ind][i]="   ";
                
            }
            
            else {
                
                this->foundation_resul += "Invalid Move!";
                this->foundation_resul += "\n";
            }
            
        }
        
        else if (tableau[ind][i][0]=='C') {
            
            int k{13};
            
            while(foundation_list[3][k]=="   " && k>0){
            
            k--;
        
            }
            
            k++;
            
            if(foundation_list[3][0]== "   ") {
                    
                k=0;
                
            }
            
            if(num==1 && k==0) {
                
                foundation_list[3][0]=tableau[ind][i];
                
                tableau[ind][i]="   ";
                
                
            }
            
            else if(num-1==k) {
                
                foundation_list[3][k]=tableau[ind][i];
                
                tableau[ind][i]="   ";
                
            }
            
            else {
                
                this->foundation_resul += "Invalid Move!";
                this->foundation_resul += "\n";
            }
        } 
        
    }
    
    else {
        
        if (waste[0]=="   ") {
            
            this->foundation_resul += "Invalid Move!";
            this->foundation_resul += "\n";
        }
        
        else {
            
            int l{23};
            
            while(waste[l]=="   "&& l>0){
            
                l--;
        
            }
            
            int f{2};
            
            while(display_waste[f]=="   "&& f>0){
            
                f--;
        
            }
            
            int num{};
            
            num = waste[l][2] - '0';
        
            if(waste[l][1]!='0') {
            
                num += 10;
                
            }
            
            if (waste[l][0]=='H') {
            
                int k{12};
                
                while(foundation_list[0][k]=="   " && k>0){
                
                k--;
            
                }
                
                k++;
                
                if(foundation_list[0][0]== "   ") {
                    
                    k=0;
                
                }
                
                if(num-1==k) {
                    
                    foundation_list[0][k]=waste[l];
                    
                    waste[l] = "   ";
                    
                    display_waste[f] = "   ";
                    
                }
                
                else {
                    
                    this->foundation_resul += "Invalid Move!";
                    this->foundation_resul += "\n";
                }
                
            }
            
            else if (waste[l][0]=='D') {
                
                int k{12};
                
                while(foundation_list[1][k]=="   " && k>0){
                
                k--;
            
                }
                
                k++;
                
                if(foundation_list[1][0]== "   ") {
                    
                    k=0;
                
                }
                
                if(num-1==k) {
                    
                    foundation_list[1][k]=waste[l];
                    
                    waste[l] = "   ";
                    
                    display_waste[f] = "   ";
                    
                }
                
                else {
                    
                    this->foundation_resul += "Invalid Move!";
                    this->foundation_resul += "\n";
                }
                
            }
            
            else if (waste[l][0]=='S') {
                
                int k{12};
                
                while(foundation_list[2][k]=="   " && k>0){
                
                k--;
            
                }
                
                k++;
                
                if(foundation_list[2][0]== "   ") {
                    
                    k=0;
                
                }
                
                if(num-1==k) {
                    
                    foundation_list[2][k]=waste[l];
                    
                    waste[l] = "   ";
                    
                    display_waste[f] = "   ";
                    
                }
                
                else {
                    
                    this->foundation_resul += "Invalid Move!";
                    this->foundation_resul += "\n";
                }
                
            }
            
            else if (waste[l][0]=='C') {
                
                int k{12};
                
                while(foundation_list[3][k]=="   " && k>0){
                
                k--;
            
                }
                
                k++;
                
                if(foundation_list[3][0]== "   ") {
                    
                    k=0;
                
                }
                
                if(num-1==k) {
                    
                    foundation_list[3][k]=waste[l];
                    
                    waste[l] = "   ";
                    
                    display_waste[f] = "   ";
                    
                }
                
                else {
                    
                    this->foundation_resul += "Invalid Move!";
                    this->foundation_resul += "\n";
                }
            }
        }
        
    }
    
}

Foundation::~Foundation()
{
}

string Foundation::get_foundation_resul(){
    
    return foundation_resul;
}



