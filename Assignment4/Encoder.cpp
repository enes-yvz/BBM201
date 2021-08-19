#include "Encoder.h"

using namespace std;

vector <Node*> charArrayEncoder;
vector <int> intArrayEncoder;
string myResult;
string myString;

Encoder::Encoder(vector <Node*> charArrayEncoder,vector <int> intArrayEncoder)
{
    this->charArrayEncoder = charArrayEncoder;
    
    this->intArrayEncoder = intArrayEncoder;
    
}

Encoder::~Encoder()
{
}

void Encoder::createTree(){
    
    while (intArrayEncoder.size()>1) {
       
       struct Node* root = new Node;
   
       struct Node* right = new Node;
       
       struct Node* left = new Node;
       
       root->data ='#';
       
       left =charArrayEncoder[0];
       
       right =charArrayEncoder[1];
       
       root->left = left;
       
       root->right = right;
       
       charArrayEncoder.push_back(root);
       
       charArrayEncoder.erase(charArrayEncoder.begin());
       
       charArrayEncoder.erase(charArrayEncoder.begin());
       
       int sum =0;
       
       sum += intArrayEncoder[0];
       
       intArrayEncoder.erase(intArrayEncoder.begin());
       
       sum += intArrayEncoder[0];
       
       intArrayEncoder.erase(intArrayEncoder.begin());
       
       intArrayEncoder.push_back(sum);
       
       sum = 0;
       
       Sorter sorter(charArrayEncoder,intArrayEncoder);

       sorter.mySort();
       
       intArrayEncoder = sorter.getIntArray();
       
       charArrayEncoder = sorter.getCharArray();
       
   }
    
}

string Encoder::encode(string itemEncoder) {
    
    string finalString;
    
    for (char c: itemEncoder) {
    
        Node* node = charArrayEncoder[0];
    
        findNode(node,c," ");
        
        size_t n = myString.find_first_not_of(" ");
        
        myString = myString.substr(n,myString.size());
        
        finalString.append(myString);
        
    }
    
    return finalString;
}



vector <Node*> Encoder::getCharArrayEncoder(){
    
    return charArrayEncoder;
}

vector <int> Encoder::getIntArrayEncoder(){
    
    return intArrayEncoder;
}

void Encoder::findNode(Node* node,char key,string addKey) {
    
    if (node==NULL) {
        
        return;
    }
    
    myResult.append(addKey);
    
    if (node->data==key) {
        
        this ->myString = myResult;
        
        return;
    }
    
    findNode(node->left,key,"0");
    
    findNode(node->right,key,"1");
    
    myResult.pop_back();
    
    return;
    
}

string Encoder::findCharacter(char c,Node* node) {
    
    string finalString;

    findNode(node,c," ");
    
    string newMyString = myString+"*";
    
    size_t n = newMyString.find_first_not_of(" ");
    
    newMyString = newMyString.substr(n,myString.size()-1);
    
    if (newMyString== "*") {
        
        newMyString = "There isn't such a character";
    }
    
    finalString.append(newMyString);
    
    return finalString;
}

