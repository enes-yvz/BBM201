#include <iostream>
#include <fstream>
#include <string>
#include "stock.h"

using namespace std;

string stock_list[24];
string stock_resul{"   "};

Stock::Stock(string stock_list[24],string waste[24],string display_waste[3])
{
    
     for(int i{0};i<24;i++)
        this->waste[i] = waste[i];
        
     for(int i{0};i<24;i++)
        this->stock_list[i] = stock_list[i];
        
     int l{23};
            
     while(waste[l]=="   " && l>-1){
    
         l--;

     }
     
     int k{23};
            
     while(stock_list[k]=="   " && k>0){
    
        k--;

     }
     
     if(k>=2){
         
        display_waste[0] =stock_list[k];
        
        display_waste[1]= stock_list[k-1];
        
        display_waste[2]= stock_list[k-2];
         
        waste[l+1]=stock_list[k];
        
        waste[l+2]=stock_list[k-1];
        
        waste[l+3]=stock_list[k-2];
         
        stock_list[k]="   ";

        stock_list[k-1]="   ";
        
        stock_list[k-2]="   ";
         
     }
     
     else if (k>=1) {
         
        display_waste[0] =stock_list[k];
        
        display_waste[1]= stock_list[k-1];
        
        display_waste[2]="   ";
         
        waste[l+1]=stock_list[k];
        
        waste[l+2]=stock_list[k-1]; 
        
        stock_list[k]="   ";
        
        stock_list[k-1]="   ";
         
     }
     
     else if (k==0 && stock_list[k]!="   ") {
         
         display_waste[0] =stock_list[k];
         
         display_waste[1]="   ";
         
         display_waste[2]="   ";
         
         waste[l+1]=stock_list[k];
         
         stock_list[k]="   ";
         
     }
     
     else if (k==0 && stock_list[k]=="   ") {
         
         display_waste[0]="   ";
         
         display_waste[1]="   ";
         
         display_waste[2]="   ";
         
         int w{0};
         
         while (waste[w]!="   ") {
             
             w++;
             
         }
         
         int b{0};
         
         while (w>0) {
             
            stock_list[b] = waste[w-1];
            
            waste[w-1]="   ";
            
            w--;
            
            b++;
         }
     }
     
    else {
        
        this->stock_resul += "Invalid Move!";
        this->stock_resul += "\n";
    }
     
}

Stock::~Stock()
{
}

string Stock::get_stock_resul(){
    
    return stock_resul;
}

