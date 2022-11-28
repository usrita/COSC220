#include<iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

LinkedList::LinkedList(){
    list = nullptr;
}
LinkedList::~LinkedList(){
    Node * current = list;
    if (list-> next == nullptr && list != NULL)
        delete list;
    while(list->next != NULL){
        list = list->next;
        delete current;
    }
}

Node * LinkedList:: createNode(){
    Node* newNode = new Node;

    return newNode;
}

Node * LinkedList:: searchLocation(int ID){
    
    Node* temp = list;

    // begining of list matches id number or list is empty
    if(list ->idNumber == NULL || list->idNumber == ID){
        return list;
    }
    // keep moving through list
    // return one before
    while(temp->next != NULL && temp->idNumber < ID){
        temp = temp->next;
    }
   
    return temp;
    // if(temp->idNumber == ID){
    //     return temp;
    // } 
    // else{cout << "ID NOT FOUND IN LIST \n";}
}


void LinkedList::insertNode(){
int studID;
Node * search = new Node;

cout << "Enter student ID: \n";
cin >> studID;

// create node function
createNode();
search = searchLocation(studID);

//LinkedList list = 
if (search->idNumber == studID){
    cout << "This student is already in the list! \n";
}





}

