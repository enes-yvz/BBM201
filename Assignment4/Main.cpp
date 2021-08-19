#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Sorter.h"
#include "Node.h"
#include "Encoder.h"
#include "Decoder.h"
using namespace std;

vector <Node*> charArrayMain{};
                
vector <int> intArrayMain{};

Decoder decoder(charArrayMain,intArrayMain);

string code;

string forWrite;

int nodeCount =1;

void listTree(Node* node,int space) {
    
    if (node==NULL) {
        
        return;
    }
    
    space += nodeCount;
    
    listTree(node->left,space);
    
    cout << endl;
    
    for (int k= nodeCount;k<space;k++) {
        
        cout << " ";
    }
    
    cout << node ->data << endl ;
    
    listTree(node->right,space);
    
}

void display(Node* node,string addKey) {
    
    if (node==NULL) {
        
        return;
    }
    
    code.append(addKey);
    
    if (node->data!='#') {
        
        forWrite +=  node->data ;
        
        forWrite += code;
        
        forWrite += "\n";
        
    }
    
    display(node->left,"0");
    
    display(node->right,"1");
    
    code.pop_back();
    
    return;
    
}

struct Node* tableToTree() {
    
    ifstream secondFile;
                
    secondFile.open("encodeTable.txt");
    
    string finalString;
    
    string second;
    
    struct Node* root = new Node;
    
    root->data ='#';
    
    struct Node* tmp = root;
    
    while(getline(secondFile,second)) {
        
        for (int k=0;k<second.substr(2).size();k++) {
            
            if (second.substr(2)[k]=='0') {
                
               if (tmp->left!=NULL) {
                   
                   tmp->data ='#';
                   
                   tmp = tmp ->left;
               }
               
               else {
                   
                   struct Node* child = new Node;
                   
                   nodeCount ++;
                   
                   child->data ='#';
                   
                   tmp->left = child;
                   
                   tmp = tmp->left;
               }
                
            }
            
            else {
                
                if (tmp->right!=NULL) {
                    
                   tmp->data ='#';
                   
                   tmp = tmp->right;
                
                }
               
               else {
                   
                   struct Node* child = new Node;
                   
                   nodeCount ++;
                   
                   child->data ='#';
                   
                   tmp ->right = child;
                   
                   tmp = tmp->right;
               }
               
            }
            
        }
        
        tmp->data = second[0];
        
        
        
        tmp = root;
        
    }
    
    return root;
    
}

int main(int argc, char **argv) {
    
        ifstream inFile;
        
        string arg = argv[1];
        
        string item;
        
        inFile.open(argv[2]);
            
        getline(inFile,item);
        
        if (arg=="-i") {
            
            arg = argv[3];
            
            if (arg == "-encode") {
                
                for(int i =0;i< item.size();i++) {
            
                    item[i] = tolower(item[i]);
                    
                }

                string itemCopy = item;
                
                for (int i=0;i<item.size();i++) {
                    
                    int k = 1;
                    
                    for (int f = i+1;f<item.size();f++){
                
                        if (item[i]==item[f]) {
                            
                            item.erase(item.begin() + f);
                            
                            f--;
                            
                            k++;
                            
                            }
                            
                    }
                    
                    intArrayMain.push_back(k);
                    
                    struct Node* root = new Node;
                    
                    root->data = item[i];
                    
                    charArrayMain.push_back(root);
               }
               
               Sorter sorter(charArrayMain,intArrayMain);
               
               sorter.mySort();
               
               charArrayMain = sorter.getCharArray();
               
               intArrayMain = sorter.getIntArray();
               
                Encoder encoder(charArrayMain,intArrayMain);
                
                encoder.createTree();
                
                charArrayMain = encoder.getCharArrayEncoder();
        
                display(charArrayMain[0]," ");
                
                ofstream outFile("encodeTable.txt");
                
                outFile << forWrite;
        
                string encodedString = encoder.encode(itemCopy);
                
                cout << encodedString << endl;
                
            }
            
            else {
                
                Node* root = tableToTree();
                
                string decodedString = decoder.decode(item,root);
                
                cout << decodedString << endl;
            }
            
        }
        
        else if (arg=="-s") {
            
            Node* root = tableToTree();
            
            Encoder encoder(charArrayMain,intArrayMain);
            
            string encodedChar = encoder.findCharacter(argv[2][0],root);
            
            cout << encodedChar << endl;
            
        }
        
        else if (arg=="-l") {
            
            Node* root = tableToTree();
            
            listTree(root,0);
            
            
        }
        
    return 0;
}

