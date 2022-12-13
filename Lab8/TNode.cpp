#include <iostream>
#include "TNode.h"

using namespace std;

//constructor
template <class T>
TNode<T>:: TNode(T node){

    parent = nullptr;
    leftchild = nullptr;
    rightchild = nullptr;
    data = node; 
}

template <class T>
void TNode <T>:: printNode(){
    if(parent != NULL)
        cout << "Parent: "<< parent->data << endl;
    else
        cout << "Parent: NULL\n";

    if (leftchild != NULL)
    {
        cout << "leftchild: " << leftchild->data << endl;
    }
    else
        cout << "Leftchild: NULL" << endl;

    if(rightchild != NULL)
        cout << "Rightchild: " << rightchild->data<< endl;

    else
        cout << "Rightchild: NULL\n";
    
    cout << "Data: "<< data << endl << endl;
}