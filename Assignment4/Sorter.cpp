#include "Sorter.h"

using namespace std;

vector <Node*> charArray;
vector <int> intArray;

Sorter::Sorter(vector <Node*> charArray,vector <int> intArray)
{
    this->charArray = charArray;
    this->intArray = intArray;
    
}

Sorter::~Sorter()
{
}

void Sorter::mySort()
{
    
    for (int i =0 ; i < intArray.size();i++) {
            
            for (int f = i+1;f<intArray.size();f++){
                
                if (intArray[f]<intArray[i]) {
                    
                    int tmpFirst = intArray[i];
                    
                    intArray[i] = intArray[f];
                    
                    intArray[f] = tmpFirst;
                    
                    Node* tmpSecond = charArray[i];
                    
                    charArray[i] = charArray[f];
                    
                    charArray[f] = tmpSecond;
                }
            
            }
           
       }
    
}

vector <Node*> Sorter::getCharArray(){
    
    return charArray;
}

vector <int> Sorter::getIntArray(){
    
    return intArray;
}

void Sorter::setCharArray(vector <Node*> charArray){
    
    this->charArray = charArray;
}

void Sorter::setIntArray(vector <int> intArray){
    
    this->intArray = intArray;
}

