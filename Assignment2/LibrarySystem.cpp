#include <iostream>
#include <string>
#include "LibrarySystem.h"

using namespace std;

struct NodeFirst 
{ 
    int userId;
    string userName; 
    struct NodeFirst *next; 
    struct NodeFirst *prev; 
};

struct NodeSecond 
{ 
    int userId;
    int movieId;
    string movieTitle;
    int year;
    struct NodeSecond *next; 
};

struct NodeThird 
{
    int movieId;
    string movieTitle;
    int year;
    struct NodeThird *next; 
};

struct NodeFirst* startUser;

struct NodeSecond* startChecked;

struct NodeThird* startNonChecked;

LibrarySystem::LibrarySystem()
{
    startUser = NULL;
    
    startChecked = NULL;
    
    startNonChecked = NULL;
}

LibrarySystem::~LibrarySystem()
{
}

void LibrarySystem::addMovie( const int movieId, const string movieTitle, const int year ) {
    
    if (foundNonCheckedMovie(movieId)==0) {
        
        cout << "Movie " << movieId << " has been added" << endl;
        
    }
    
    if (foundNonCheckedMovie(movieId)==1) {
        
        cout << "Movie " << movieId <<" already exist" << endl;
    }
    
    else {
        
        struct NodeThird* newNode = new NodeThird;

        newNode->movieId = movieId;
        
        newNode->movieTitle = movieTitle;
        
        newNode->year = year;
        
        if(startNonChecked==NULL) {
            
            newNode->next = newNode;
            
            startNonChecked = newNode;
            
            return;
        }
        
        else {
            
            NodeThird* pointer = startNonChecked;
            
            while(pointer -> next!=startNonChecked ) {
            
                pointer = pointer -> next;
            
            }

            pointer -> next = newNode;
            
            newNode -> next = startNonChecked;
            
            return;
            
        }
        
    }
    
}

void LibrarySystem::deleteMovie( const int movieId ){
    
    if (foundNonCheckedMovie(movieId)==1) {
        
        cout << "Movie " << movieId << " has not been checked out" << endl;
        
        cout << "Movie " << movieId << " has been deleted" << endl;
        
        NodeThird* pointer = startNonChecked;

        NodeThird* prevPointer = startNonChecked;
        
        NodeThird* lastPointer = startNonChecked;
        
        while(lastPointer -> next!=startNonChecked ) {
            
            lastPointer = lastPointer -> next;
        
        }
        
        if (startNonChecked->movieId == movieId) {
            
            while(pointer -> next!=startNonChecked ) {
            
                pointer = pointer -> next;
            
            }
            
            if (startNonChecked != startNonChecked->next) {
                
                pointer ->next = startNonChecked->next;
                
                startNonChecked = startNonChecked->next;
                
            }
            
            else {
                
                startNonChecked = startNonChecked->next = NULL;
                
            }
            
        }
        
        else if (lastPointer->movieId == movieId) {
            
            pointer = pointer -> next;
            
            while(pointer -> next!=startNonChecked ) {
                
                prevPointer = prevPointer ->next;
                
                pointer = pointer -> next;
        
            }
            
            if (startChecked != startChecked->next) { 
                
                prevPointer -> next = startNonChecked; 
                
            }
                
            else {
            
                startNonChecked = startNonChecked->next = NULL;
            
            }
            
        }
        
        else {
            
            pointer = pointer -> next;
            
            while(pointer -> next -> movieId!= movieId) {
                
                prevPointer = prevPointer ->next;
                
                pointer = pointer -> next;
        
            }
            
            prevPointer = prevPointer ->next;
                
            pointer = pointer -> next;
            
            prevPointer -> next = pointer -> next;
            
            pointer -> next  = NULL;
            
        }
    }
    
    else if (foundCheckedMovie(movieId)==1) {
        
        cout << "Movie " << movieId << " has been checked out" << endl;
        
        cout << "Movie " << movieId << " has been deleted" << endl;
        
        NodeSecond* pointer = startChecked;

        NodeSecond* prevPointer = startChecked;
        
        NodeSecond* lastPointer = startChecked;
        
        while(lastPointer -> next!=startChecked ) {
            
            lastPointer = lastPointer -> next;
        
        }
        
        if (startChecked->movieId == movieId) {

            while(pointer -> next!=startChecked ) {
            
                pointer = pointer -> next;
            
            }
            
            if (startChecked != startChecked->next) {
                
                pointer ->next = startChecked->next;
            
                startChecked = startChecked->next;
                
            }
            
            else {
                
                startChecked = startChecked->next = NULL;
                
            }
            
        }
        
        else if (lastPointer->movieId == movieId) {
            
            pointer = pointer -> next;
            
            while(pointer -> next!=startChecked ) {
                
                prevPointer = prevPointer ->next;
                
                pointer = pointer -> next;
        
            }
            
            if (startChecked != startChecked->next) { 
                
                    prevPointer -> next = startChecked; 
                
            }
                
            else {
            
                startChecked = startChecked->next = NULL;
            
            }
            
        }
        
        else {
            
            pointer = pointer -> next;
            
            while(pointer -> next -> movieId!= movieId) {
                
                prevPointer = prevPointer ->next;
                
                pointer = pointer -> next;
        
            }
            
            prevPointer = prevPointer ->next;
                
            pointer = pointer -> next;
            
            prevPointer -> next = pointer -> next;
            
            pointer -> next  = NULL;
            
        }
        
    }
    
    else {
            
            cout << "Movie " << movieId << " does not exist"<< endl;
    }
}

void LibrarySystem::addUser( const int userId, const string userName ) {
    
    if (foundUser(userId)==1) {
        
        cout << "User " << userId << " already exists" << endl; 
    }
    
    else {
        
        cout << "User " << userId << " has been added" << endl; 
        
        struct NodeFirst* newNode = new NodeFirst;

        newNode->userId = userId;
        
        newNode->userName = userName;
        
        if(startUser==NULL) {
            
            newNode->next = newNode;
            
            newNode->prev = newNode;
            
            startUser = newNode;
            
            return;
        }
        
        else {
            
            newNode -> prev = startUser->prev;
            
            startUser->prev ->next = newNode ;
            
            newNode -> next = startUser;
            
            startUser ->prev = newNode;
            
        }
    }
}

void LibrarySystem::deleteUser( const int userId ) {
    
    if (foundUser(userId)==0) {
        
        cout << "User " << userId << " does not exist" << endl;
        
    }
    
    else {
        
        NodeSecond* first = startChecked ;
        
        cout << "User " << userId << " has been deleted" << endl;

        if (first!=NULL) {
            
            NodeSecond* tmp ;
            
            NodeSecond* ptr = startChecked;
        
            NodeSecond* prevPointer = startChecked;
            
            NodeSecond* lastPtr = startChecked;
            
            ptr = ptr -> next;
            
            int k = 1;
            
            while(lastPtr -> next!=startChecked ) {
                
                k ++;
                
                lastPtr = lastPtr -> next;
            
            }
            
            if (k>2) {
                
                while (ptr != lastPtr) {
                
                    if (ptr -> userId == userId ) {
                        
                        prevPointer -> next = ptr -> next;
                        
                        tmp = ptr -> next;
                        
                        cout << "Movie " << ptr ->movieId << " has been deleted" << endl;
                        
                        ptr -> next  = NULL;
                        
                        ptr = tmp;
                        
                    }
                    
                    else {
                        
                        prevPointer = prevPointer ->next;
                        
                        ptr = ptr -> next;
                    }
                    
            
                }
            
            }
            
            ptr = startChecked;

            prevPointer = startChecked;
            
            lastPtr = startChecked;
            
            while(lastPtr -> next!=startChecked ) {
                
                lastPtr = lastPtr -> next;
            
            }
            
            if (startChecked->userId == userId) {
                
                cout << "Movie " << startChecked->movieId << " has been deleted" << endl;

                while(ptr -> next!=startChecked ) {
                
                    ptr = ptr -> next;
                
                }
                
                if (startChecked != startChecked->next) {
                
                    ptr ->next = startChecked->next;
            
                    startChecked = startChecked->next;
                
                }
            
                else {
                
                    startChecked = startChecked->next = NULL;
                
                }
            
            }
            
            if (lastPtr->userId== userId) {
                
                cout << "Movie " << lastPtr->movieId << " has been deleted" << endl;
                
                ptr = startChecked;
            
                prevPointer = startChecked;
                
                ptr = ptr -> next;
                
                while(ptr -> next!=startChecked ) {
                    
                    prevPointer = prevPointer ->next;
                    
                    ptr = ptr -> next;
            
                }
                
                if (startChecked != startChecked->next) { 
                
                    prevPointer -> next = startChecked; 
                
                }
                
                else {
                
                    startChecked = startChecked->next = NULL;
                
                }
                
            }
            
        }
        
        NodeFirst* pointer = startUser;
        
        NodeFirst* lastPointer = startUser->prev;
        
        if (startUser->userId == userId) { 
            
            lastPointer->next = pointer ->next;
            
            pointer ->prev ->next ->prev = lastPointer;
            
            startUser = lastPointer ->prev;

            return;
            
        }
        
        else if(lastPointer->userId==userId) {
            
            NodeFirst *tmp = lastPointer;
            
            pointer =lastPointer -> prev ;
            
            pointer ->next = tmp ->next;
            
            startUser->prev = pointer;
            
            lastPointer = pointer;
            
            
        }
        
        else {
            
            while (pointer->next!=startUser) {
                
                if (pointer->userId == userId) {
                    
                    pointer ->prev ->next = pointer ->next;
                    
                    pointer ->prev ->next -> prev = pointer -> prev;
                    
                    return;
                    
                }
                
                pointer = pointer ->next;
            }
        }
        
    }
}

void LibrarySystem::checkoutMovie( const int movieId, const int userId ) {
    
    if (foundUser(userId)==0) {
        
        cout << "User " << userId << " does not exist for checkout" << endl;
        
    }
    
    else if (foundCheckedMovie(movieId)== 0 && foundNonCheckedMovie(movieId)==1) {
        
        struct NodeThird* tmp = deleteNonCheckedMovie(movieId);
    
        struct NodeSecond* newNode = new NodeSecond;
        
        newNode->movieId = tmp->movieId;
        
        newNode-> movieTitle = tmp->movieTitle;
        
        newNode->year = tmp->year;
        
        newNode->userId = userId;
        
        cout << "Movie " << tmp->movieId << " has been checked out by User " << userId << endl;
        
        if(startChecked==NULL) {
            
            newNode->next = newNode;
            
            startChecked = newNode;
            
            return;
        }
        
        else {
            
            NodeSecond* pointer = startChecked;
            
            while(pointer -> next!=startChecked ) {
            
                pointer = pointer -> next;
            
            }

            pointer -> next = newNode;
            
            newNode -> next = startChecked;
            
            return;
        }
    }
    
    else {
        
        cout << "Movie " << movieId << " does not exist for checkout" << endl;
        
    }
    
}

void LibrarySystem::returnMovie( const int movieId ) {
    
    if (foundNonCheckedMovie(movieId)==1) { 
        
        NodeThird* pointer = startNonChecked ;
            
        while(pointer -> next!=startNonChecked ) {
            
            if (pointer->movieId== movieId) {
                
                cout << "Movie " << movieId << " has not been checked out" << endl;
                
                return;
            }
            
            pointer = pointer -> next;
        
            if (pointer->movieId == movieId) {
                    
                cout << "Movie " << movieId << " has not been checked out" << endl;
                
                return;
            }
            
        }
    
    }
    
    else if (foundCheckedMovie(movieId)==1) {
        
        NodeSecond* pointer = startChecked ;
            
        while(pointer -> next!=startChecked ) {
            
            if (pointer->movieId== movieId) {
                
                cout << "Movie " << movieId << " has been returned" << endl;
                
                returnCheckedMovie(movieId);
                
                return;
            }
            
            pointer = pointer -> next;
        
            if (pointer->movieId == movieId) {
                    
                cout << "Movie " << movieId << " has been returned" << endl;
                
                returnCheckedMovie(movieId);
                
                return;
            }
            
        }
        
    }
    
    else {
            
        cout << "Movie " << movieId << " not exist in the library" << endl;
    }
    
}

void LibrarySystem::showAllMovies() {
    
    cout << "Movie id - Movie name - Year - Status" << endl;
    
    NodeThird* pointerFirst = startNonChecked;
    
    if (pointerFirst != NULL) {
        
        while (pointerFirst -> next!=startNonChecked) {
            
            cout << pointerFirst -> movieId << " " << pointerFirst -> movieTitle << " " << pointerFirst -> year << " Not checked out" << endl ;
            
            pointerFirst = pointerFirst -> next;
        
    }
        
    cout << pointerFirst -> movieId << " " << pointerFirst -> movieTitle << " " << pointerFirst -> year << " Not checked out" << endl ;
        
    }
    
    NodeSecond* pointerSecond = startChecked;
    
    if (pointerSecond != NULL) {
        
        while (pointerSecond -> next!=startChecked) {
                
                cout << pointerSecond -> movieId << " " << pointerSecond -> movieTitle << " " << pointerSecond -> year << " Checked out by User " << pointerSecond -> userId << endl ;
                
                pointerSecond = pointerSecond -> next;
            
        }
            
        cout << pointerSecond -> movieId << " " << pointerSecond -> movieTitle << " " << pointerSecond -> year << " Checked out by User " << pointerSecond -> userId << endl ;

    }
}

void LibrarySystem::showMovie( const int movieId ) {
    
    if (foundNonCheckedMovie(movieId)==1) { 
        
        NodeThird* pointer = startNonChecked ;
            
        while(pointer -> next!=startNonChecked ) {
            
            if (pointer->movieId== movieId) {
                
                cout << pointer-> movieId << " " << pointer-> movieTitle << " " << pointer-> year << " Not checked out" << endl;
                
                return;
            }
            
            pointer = pointer -> next;
        
            if (pointer->movieId == movieId) {
                    
                cout << pointer-> movieId << " " << pointer-> movieTitle << " " << pointer-> year << " Not checked out" << endl;
                
                return;
            }
            
        }
    
    }
    
    else if (foundCheckedMovie(movieId)==1) {
        
        NodeSecond* pointer = startChecked ;
            
        while(pointer -> next!=startChecked ) {
            
            if (pointer->movieId== movieId) {
                
                cout << pointer-> movieId << " " << pointer-> movieTitle << " " << pointer-> year << " Checked out by User " << pointer-> userId << endl;
                
                return;
            }
            
            pointer = pointer -> next;
        
            if (pointer->movieId == movieId) {
                    
                cout << pointer-> movieId << " " << pointer-> movieTitle << " " << pointer-> year << " Checked out by User " << pointer-> userId << endl;
                
                return;
            }
            
        }
        
        
    }
    
    else {
            
        cout << "Movie with the id " << movieId << " does not exist" << endl;
    }
    
    
}

void LibrarySystem::showUser( const int userId ) {
    
    NodeFirst* pointer = startUser ;
    
    if (foundUser(userId)==0) {
        
        cout << "User " << userId<< " does not exist in the system" << endl;
        
        return;
    }
    
    else {
        
        while(pointer -> next!=startUser ) {
            
            if (pointer->userId == userId) {
                
                cout << "User id: " << userId << " " << "User name: " << pointer->userName << endl;
                
                cout << "User " <<userId << " checked out the following Movies:"<< endl;
                
                checkedMovies(userId);
                
                return;
            }
            
            pointer = pointer -> next;
            
        }
        
        if (pointer->userId == userId) {
                
                cout << "User id: " << userId << " " << "User name: " << pointer->userName << endl;
                
                cout << "User " <<userId << " checked out the following Movies:"<< endl;
                
                checkedMovies(userId);
                
                return;
        }
        
        cout << "User " << userId<< " does not exist in the system" << endl;
        
        return;
        
    }
    
}

bool LibrarySystem::foundUser( const int userId ) {

    NodeFirst* pointer = startUser ;
    
    if (pointer==NULL) {
        
        return 0;
    }
    
    else {
        
        while(pointer -> next!=startUser ) {
            
            if (pointer->userId == userId) {
                
                return 1;
            }
            
            pointer = pointer -> next;
            
        }
        
        if (pointer->userId == userId) {
                
                return 1;
        }
        
        return 0;
    
    }

}

bool LibrarySystem::foundNonCheckedMovie( const int movieId ) {

    NodeThird* pointer = startNonChecked ;
    
    if (pointer==NULL) {
        
        return 0;
    }
    
    else {
        
        while(pointer -> next!=startNonChecked ) {
            
            if (pointer->movieId== movieId) {
                
                return 1;
            }
            
            pointer = pointer -> next;
            
        }
        
        if (pointer->movieId == movieId) {
                
            return 1;
            
        }
        
        return 0;
    
    }

}

bool LibrarySystem::foundCheckedMovie( const int movieId ) {

    NodeSecond* pointer = startChecked ;
    
    if (pointer==NULL) {
        
        return 0;
    }
    
    else {
        
        while(pointer -> next!=startChecked ) {
            
            if (pointer->movieId== movieId) {
                
                return 1;
            }
            
            pointer = pointer -> next;
            
        }
        
        if (pointer->movieId == movieId) {
                
                return 1;
        }
        
        return 0;
    
    }

}

NodeThird* LibrarySystem::deleteNonCheckedMovie( const int movieId ){
    
    struct NodeThird* tmp = new NodeThird;
        
    NodeThird* pointer = startNonChecked;

    NodeThird* prevPointer = startNonChecked;
    
    NodeThird* lastPointer = startNonChecked;
    
    while(lastPointer -> next!=startNonChecked ) {
        
        lastPointer = lastPointer -> next;
    
    }
    
    if (startNonChecked->movieId == movieId) {

        while(pointer -> next!=startNonChecked ) {
        
            pointer = pointer -> next;
        
        }
        
        pointer ->next = startNonChecked->next;
        
        tmp = startNonChecked;
        
        startNonChecked = startNonChecked->next;
        
        return tmp;
        
    }
    
    else if (lastPointer->movieId == movieId) {
        
        pointer = pointer -> next;
        
        while(pointer -> next!=startNonChecked ) {
            
            prevPointer = prevPointer ->next;
            
            pointer = pointer -> next;
    
        }
        
        tmp = prevPointer -> next;
        
        prevPointer -> next = startNonChecked;
        
        pointer -> next = NULL;
        
        return tmp;
        
    }
    
    else {
        
        pointer = pointer -> next;
        
        while(pointer -> next -> movieId!= movieId) {
            
            prevPointer = prevPointer ->next;
            
            pointer = pointer -> next;
    
        }
        
        prevPointer = prevPointer ->next;
            
        pointer = pointer -> next;
        
        tmp = prevPointer -> next ;
        
        prevPointer -> next = pointer -> next;
        
        pointer -> next  = NULL;
        
        return tmp;
        
    }
}

NodeSecond* LibrarySystem::deleteCheckedMovie( const int movieId ){
    
    struct NodeSecond* tmp = new NodeSecond;
        
    NodeSecond* pointer = startChecked;

    NodeSecond* prevPointer = startChecked;
    
    NodeSecond* lastPointer = startChecked;
    
    while(lastPointer -> next!=startChecked ) {
        
        lastPointer = lastPointer -> next;
    
    }
    
    if (startChecked->movieId == movieId) {

        while(pointer -> next!=startChecked ) {
        
            pointer = pointer -> next;
        
        }
        
        pointer ->next = startChecked->next;
        
        tmp = startChecked;
        
        startChecked = startChecked->next;
        
        return tmp;
        
    }
    
    else if (lastPointer->movieId == movieId) {
        
        pointer = pointer -> next;
        
        while(pointer -> next!=startChecked ) {
            
            prevPointer = prevPointer ->next;
            
            pointer = pointer -> next;
    
        }
        
        tmp = prevPointer -> next;
        
        prevPointer -> next = startChecked;
        
        pointer -> next = NULL;
        
        return tmp;
        
    }
    
    else {
        
        pointer = pointer -> next;
        
        while(pointer -> next -> movieId!= movieId) {
            
            prevPointer = prevPointer ->next;
            
            pointer = pointer -> next;
    
        }
        
        prevPointer = prevPointer ->next;
            
        pointer = pointer -> next;
        
        tmp = prevPointer -> next ;
        
        prevPointer -> next = pointer -> next;
        
        pointer -> next  = NULL;
        
        return tmp;
        
    }
}

void LibrarySystem::checkedMovies( const int userId ){
    
    NodeSecond* pointer = startChecked ;
    
    if (pointer==NULL) {
        
        return;
    }
    
    else {
        
        int i = 0;
        
        while(pointer -> next!=startChecked ) {
            
            if (pointer->userId==userId) {
                
                i++;
                
                if (i==1) {
                    
                    cout << "Movie id - Movie name - Year" << endl;
                    
                }
                
                cout << pointer->movieId << " " << pointer->movieTitle << " " << pointer-> year << endl;
            }
            
            pointer = pointer -> next;
            
        }
        
        if (pointer->userId==userId) {
            
            i++;
            
            if (i==1) {
                    
                    cout << "Movie id - Movie name - Year" << endl;
                    
            }
            
            cout << pointer->movieId << " " << pointer->movieTitle << " " << pointer-> year << endl;
            
        }
        
        return;
    
    }
}

void LibrarySystem::returnCheckedMovie( const int movieId ) {
    
    if (foundCheckedMovie(movieId)== 1 && foundNonCheckedMovie(movieId)==0) {
        
        struct NodeSecond* tmp = deleteCheckedMovie(movieId);
    
        struct NodeThird* newNode = new NodeThird;
        
        newNode->movieId = tmp->movieId;
        
        newNode-> movieTitle = tmp->movieTitle;
        
        newNode->year = tmp->year;
        
        if(startNonChecked==NULL) {
            
            newNode->next = newNode;
            
            startNonChecked = newNode;
            
            return;
        }
        
        else {
            
            NodeThird* pointer = startNonChecked;
            
            while(pointer -> next!=startNonChecked ) {
            
                pointer = pointer -> next;
            
            }

            pointer -> next = newNode;
            
            newNode -> next = startNonChecked;
            
            return;
        }
    }
    
}
