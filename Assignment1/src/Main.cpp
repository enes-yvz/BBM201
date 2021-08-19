#include <iostream>
#include <fstream>
#include <string>
#include "foundation.h"
#include "display.h"
#include "stock.h"
#include "move.h"
#include "moving.h"
#include "open.h"

using namespace std;

int main(int argc, char **argv) {
    
    string resul{"   "};
    
    ifstream in_file_first;
    
    in_file_first.open(argv[1]);
    
    string stock_list[24]{"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "};
    
    if(!in_file_first) {
        
        return 0;
    }
    
    string waste[24]{"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "};
    
    string display_waste[3]{"   "};
    
    string foundation_list[4][14]{{"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                                  {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                                  {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                                  {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "}};
    
    string tableau[7][20]{{"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                          {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                          {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                          {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                          {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                          {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "},
                          {"   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","   "}};
    
    int tableau_control[7][20][1]{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    
    for(int i{0};i<24;i++) {
        
        in_file_first >> stock_list[i]; 
        
    }
    
    int j{6};
    
    while(j>=0) {
        
        int k{6};
        
        while (k>=j) {
            
            in_file_first >> tableau[k][j];
            
            if (k!=j) {
                
               tableau_control[k][j][0]=0;
            }
            
            k--;
            
        }
        
        j--;
        
   }
    
   in_file_first.close();
   
   ifstream in_file_second;
   
   string line{};
   
   in_file_second.open(argv[2]);
   
   Display display(tableau,tableau_control,foundation_list,waste,stock_list,display_waste);
   
   resul += display.get_display_resul();
   
   while (getline(in_file_second,line)) {
       
       resul += "\n";
       
       resul += line;
       
       resul += "\n";
       
       if(line.find("stock")!=string::npos) {
           
           Stock stock(stock_list,waste,display_waste);
           
           resul += stock.get_stock_resul();
           
       }
       
       else if(line.find("foundation pile")!=string::npos) {
           
            int tmp = line[24] - '0';
               
            Foundation foundation(tableau,tableau_control,foundation_list,tmp,waste,display_waste);
       }
       
       else if(line.find("foundation waste")!=string::npos) {
           
            int ind {7};
           
            Foundation foundation(tableau,tableau_control,foundation_list,ind,waste,display_waste);
            
            resul += foundation.get_foundation_resul();
       }
       
       else if (line.find("move pile")!=string::npos) {
           
           int pile_num{};
           
           int card_index{};
           
           int destination{};
           
           if(line[13]==' '){
                
                pile_num = line[10] - '0';
            
                card_index = line[12] - '0';
            
                destination = line[14] - '0';
                
            }
            
            else {
                
                pile_num = line[10] - '0';
                
                int first = line[12] - '0';
                
                int second = line[13] - '0';
        
                card_index = second; 
                
                card_index += first * 10;
                
                destination = line[15] - '0';
                
            }
            
            Move move(tableau,tableau_control,foundation_list,waste,pile_num,card_index,destination);
            
            resul += move.get_move_resul();
           
       }
       
       else if (line.find("move waste")!=string::npos) {
           
           int destination_pile = line[11] - '0';
           
           Moving moving(tableau,tableau_control,foundation_list,waste,destination_pile,display_waste);
           
           resul += moving.get_moving_resul();
           
       }
       
       else if(line.find("open")!=string::npos) {
           
           int i = line[5] - '0';
           
           Open open(tableau,tableau_control,i);
           
       }
       
       else if(line.find("exit")!=string::npos) {
       
           resul += "****************************************";
           
           resul += "\n";
           
           resul += "\n";

           resul += "Game Over!"; 
       
           return 0;
       }
       
       resul += "\n";
       
       resul += "****************************************";
       
       resul += "\n";
       
       Display display(tableau,tableau_control,foundation_list,waste,stock_list,display_waste);
       
       resul += display.get_display_resul();
       
   }
    
    ofstream out_file{argv[3]};
    
    if(!out_file) {
        
        return 0;
    }
    
    out_file << resul << endl;
   
    out_file.close();
    
    return 0;
}
