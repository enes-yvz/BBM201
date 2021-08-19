#include "Operation.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node* start = NULL;

struct Node
{ 
    Package item;
    
    struct Node *next; 
    struct Node *prev; 
};

Operation::Operation()
{
}

Operation::~Operation()
{
}

void Operation::operation(char *argvFirst,char *argvSecond,char *argvThird,char *argvFourth,char *argvFifth) {
    
    freopen(argvFifth, "w", stdout);
    
    vector <string> dests;
    
    ifstream inFile;
    
    inFile.open(argvFirst);
    
    
    string lineFirst;
    
    while (inFile >> lineFirst) {
        
        dests.push_back(lineFirst);
        
    }
    
    inFile.close();
    
    inFile.open(argvSecond);
    
    string lineSecond;
    
    Queue<Package> destsQueue [dests.size()];
    
    Stack<Package> destsStack [dests.size()] ;
    
    while (inFile >> lineFirst) {
        
        inFile >> lineSecond;
        
        int index = findIndex(dests,lineSecond);
        
        Package package (0,Operation::strToInt(lineFirst));
        
        destsStack[index].push(package);
        
    }
    
    inFile.close();
    
    inFile.open(argvThird);
    
    string lineThird;
    
    while (inFile >> lineFirst) {
        
        inFile >> lineSecond;
        
        inFile >> lineThird;
        
        int index = findIndex(dests,lineSecond);
        
        Package package (Operation::strToInt(lineFirst),0);
        
        destsQueue[index].enqueue(package); 
        
    }
    
    inFile.close();
  
    inFile.open(argvFourth);
    
    string text;
    
    vector <string> mission;
    
    vector <int> index;

    while (inFile >> text) {
        
        size_t pos = 0;
        
        while ((pos = text.find("-")) != string::npos) {
            
            string token = text.substr(0, pos);
            
            mission.push_back(token);
            
            text.erase(0, pos+1);
            
        }
        
        mission.push_back(text);
        
        string first = mission[0];
        
        string second = mission[1];
        
        string third = mission[2];
        
        int numFirst = Operation::strToInt(mission[3]);
        
        int numSecond = Operation::strToInt(mission[4]);
        
        pos = 0;
        
        text = mission[5];
        
        while ((pos = text.find(",")) != string::npos) {
            
            string token = text.substr(0, pos);
            
            index.push_back(Operation::strToInt(token));
            
            text.erase(0, pos+1);
            
        }
        
        index.push_back(Operation::strToInt(text));
        
        Package package(-1,-1);
        
        int indexOfDest = findIndex(dests,first);
        
        destsQueue[indexOfDest].getFront(package);
        
        destsQueue[indexOfDest].dequeue();
        
        addItem(package);
        
        for (int i{};i<numFirst;i++) {
            
            destsStack[indexOfDest].getTop(package);
            
            destsStack[indexOfDest].pop();
            
            addItem(package);
        }
        
        indexOfDest = findIndex(dests,second);
        
        for (int i{};i<numSecond;i++) {
            
            destsStack[indexOfDest].getTop(package);
            
            destsStack[indexOfDest].pop();
            
            addItem(package);
            
        }
        
        int f{};
        
        for (int i{0};i<index.size();i++) {
            
            struct Node* tp = start;
        
            tp = tp->next;
            
            for (int k{};k<index[i]-f;k++) {
                
                tp = tp->next;
            
            }
            
            f++;
            
            Package package(-1,-1);
            
            package = deleteItem(tp->item);
            
            if (package.packageNum!=-10 && package.truckNum!=-10) {
                
                destsStack[indexOfDest].push(package);
                
            }
            
        }
        
        indexOfDest = findIndex(dests,third);
        
        struct Node* temp = start->next;
        
        while (temp!=start)  {
            
            package = deleteItem(temp->item);
            
            destsStack[indexOfDest].push(package);
            
            temp = temp->next;
        }
        
        package = deleteItem(temp->item);
        
        destsQueue[indexOfDest].enqueue(package);
        
        mission.clear();
        
        index.clear();
        
        start = NULL;
    
    }
    
    int n = 0;
    
    for (string dest: dests) {
        
        cout << dest << endl;
        
        cout << "Packages:" << endl;
        
        while (!destsStack[n].isEmpty()) {
               
                Package pac(-1,-1);
            
                destsStack[n].getTop(pac);
                
                cout << "P" << pac.packageNum << endl;
                
                destsStack[n].pop();
                
        }
        
        cout << "Trucks:" << endl;
        
        while (!destsQueue[n].isEmpty()) {
               
                Package pac(-1,-1);
            
                destsQueue[n].getFront(pac);
                
                cout << "T" << pac.truckNum << endl;
                
                destsQueue[n].dequeue();
                
        }
        
        cout << "-------------"  << endl;
        
        n++;

    }

    
    inFile.close();
    
    
}

int Operation::findIndex(vector <string> dests,string searchItem) {
    
    int i{}; 
    
    while (dests[i]!=searchItem) {
        
        i++;
    }
    
    return i;
    
}


int Operation::strToInt(string str) {
    
    if (str[0]=='P' || str[0]=='T')
        str = str.erase(0,1);
        
    int m{};
    
    for (int h = 0 ;h < str.length() ; h++) {
        
        m+= pow(10,h) * (str[str.length()-h-1] -'0');
        
    }
    
    return m;
}

bool Operation::foundItem(Package item) {

    Node* pointer = start;
    
    if (pointer==NULL) {
        
        return 0;
    }
    
    else {
        
        while(pointer -> next!=start) {
            
            if (pointer->item.packageNum == item.packageNum && pointer->item.truckNum == item.truckNum) {
                
                return 1;
            }
            
            pointer = pointer -> next;
            
        }
        
        if (pointer->item.packageNum == item.packageNum && pointer->item.truckNum == item.truckNum) {
                
                return 1;
        }
        
        return 0;
    
    }

}

void Operation::addItem(Package item) {
    
    if (foundItem(item)==1) {
        
        
    }
    
    else {
        
        struct Node* newNode = new Node;

        newNode->item = item;
        
        if(start==NULL) {
            
            newNode->next = newNode;
            
            newNode->prev = newNode;
            
            start = newNode;
            
            return;
        }
        
        else {
            
            newNode -> prev = start->prev;
            
            start->prev ->next = newNode ;
            
            newNode -> next = start;
            
            start ->prev = newNode;
            
        }
    }
}

Package Operation::deleteItem(Package item) {
    
    if (foundItem(item)==0) {
        
        Package t(-10,-10);
        
        return t;
    }
        
    else {

        Node* pointer = start;
        
        Node* lastPointer = start->prev;
        
        if (start->item.packageNum == item.packageNum && start->item.truckNum == item.truckNum) { 
            
            Package t = start->item; 
            
            lastPointer->next = pointer ->next;
            
            pointer ->prev ->next ->prev = lastPointer;
            
            start = lastPointer ->next;

            return t;
            
        }
        
        else if(lastPointer->item.packageNum == item.packageNum && lastPointer->item.truckNum == item.truckNum) {
            
            Package t = lastPointer->item;
            
            Node *tmp = lastPointer;
            
            pointer =lastPointer -> prev ;
            
            pointer ->next = tmp ->next;
            
            start->prev = pointer;
            
            lastPointer = pointer;
              
            return t;
            
        }
        
        else {
            
            while (pointer->next!=start) {
                
                if (pointer->item.packageNum == item.packageNum && pointer->item.truckNum == item.truckNum) {
                    
                    Package t = pointer->item;
                    
                    pointer ->prev ->next = pointer ->next;
                    
                    pointer ->prev ->next -> prev = pointer -> prev;
                    
                    return t;
                    
                }
                
                pointer = pointer ->next;
            }
        }
    
    }

}


