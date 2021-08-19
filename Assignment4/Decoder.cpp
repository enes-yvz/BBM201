#include "Decoder.h"

using namespace std;

vector <Node*> charArrayDecoder;
vector <int> intArrayDecoder;
string itemDecoder;

Decoder::Decoder(vector <Node*> charArrayDecoder,vector <int> intArrayDecoder)
{
    
    this->charArrayDecoder = charArrayDecoder;
    
    this->intArrayDecoder = intArrayDecoder;
}

Decoder::~Decoder()
{
}

string Decoder::decode(string itemDecoder,Node* node) {
    
    string finalString;
    
    Node* tmp = node; 
    
    for (char c: itemDecoder) {
        
        if(node->right==NULL && node->left==NULL) {
            
            finalString += node->data ;
            
            node = tmp;
            
        }
            
        if (c=='1') {
            
            node = node->right;
            
        }
        
        else {
            
            node = node->left;
            
        }
            
    }
    
    finalString += node->data ;
    
    return finalString;
        
}



