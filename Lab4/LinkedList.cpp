#include<iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

LinkedList::LinkedList(){
    list = nullptr;
}
LinkedList::~LinkedList(){
    Node * current = list, *delnode = NULL;
    while(current != NULL){
        delnode = current;
        current = current->next;
        delete delnode;
    }
}

Node * LinkedList:: createNode(){
    Node* newNode = new Node;

    return newNode;
}

Node * LinkedList:: searchLocation(int ID){
    
    Node* temp = list;

    // begining of list matches id number or list is empty
    if(list == NULL || list->idNumber == ID){
        return list;
    }
    // keep moving through list
    // return one before
    while(temp->next != NULL && temp->next->idNumber < ID){
        temp = temp->next;
    }
   
    // returns node before one we wanna delete
    return temp;

}


void LinkedList::insertNode(){
Node * newnode = new Node, *search = nullptr;

search = searchLocation(newnode->idNumber);

if (search == NULL)
        list = newnode;
    else if ((search->next == NULL && search->idNumber == newnode->idNumber) || (search->next != NULL && search->next->idNumber == newnode->idNumber) || (search->idNumber == newnode->idNumber)){
        cout << "Node already exists in list\n";
        delete newnode;
    }
    else if(newnode->idNumber < search->idNumber){
        newnode->next = search; // might have change search to list
        list = newnode;
    }
    else if (search->next == NULL){
        search->next = newnode;
    }
    else{
        // insert between two nodes
        newnode->next = search->next;
        search->next = newnode;
    }
}

void LinkedList:: deleteNode(int ID){
    Node *delnode = nullptr, *search = nullptr;

    search = searchLocation(ID);

    if (search == NULL)
        cout << "list is empty, cannot delete\n";
    else if ((search->next == NULL && search->idNumber != ID) || (search->idNumber != ID && search->next->idNumber != ID)){
        cout << "Node is not in the list\n";
    }
    else if (search->idNumber == ID){
        delnode = search;
        list = search->next;
        delete delnode;
    }
    else{
        delnode = search->next;
        search->next = search->next->next;
        delete delnode;

    }

}

void LinkedList:: searchNode(){

    int ID;
    cout << "Input Id to search: \n";
    cin >> ID;

    Node *search = nullptr;
    search = searchLocation(ID);

    if (search == NULL)
        cout << "list is empty, cannot delete\n";
    else if ((search->next == NULL && search->idNumber != ID) || (search->idNumber != ID && search->next->idNumber != ID)){
        cout << "Node is not in the list\n";
    }

    else if (search->idNumber == ID){
        search->printNode();
    }
    else{
        search->next->printNode();
    }
}

void LinkedList::printList(){

    Node *current = list;

    if (list == NULL)
        cout << "List is empty!\n";
    while (current!= NULL){
        current->printNode();
        current = current->next;
    }

}