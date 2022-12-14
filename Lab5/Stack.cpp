#include <iostream>
#include "Stack.h"

using namespace std;

//constructor
template<class DataType>
Stack<DataType>::Stack(int stackMaxSize){

top = nullptr;
maxSize = stackMaxSize;
numNodes = 0;

}

// Destructor
template<class DataType>
Stack<DataType>::~Stack(){

    StackNode<DataType> *delNode = nullptr, *current = top;

    // delete node one by one
    for (int i = 0; i < numNodes; i++)
    {
        delNode = current;
        current = current->next;
        delete delNode;
    }
}

template<class DataType>
bool Stack<DataType>::isEmpty()const{
    if (numNodes == 0)
        return true;
    else
        return false;
}

template<class DataType>
bool Stack<DataType>::isFull()const{
    if(numNodes == maxSize)
        return true;
    else
        return false;
}

// push: adds a node to the top of the stack
template<class DataType>
void Stack<DataType>::push(const DataType data){

    if (isFull() == true){
        cout << " Stack is full, cannot push new data \n";
        }
    
    else{
        //Create a pointer to point to the top of the 
        //stack and a pointer to point to the new node
        StackNode<DataType> *new_node = new StackNode<DataType>;

        //set the new nodes data value equal to the data passed to the function
    
        new_node->data = data;
        new_node->next = nullptr;

        //check if the stack is empty
        if(top == nullptr){
            top = new_node;
        }
        //add the node to the top of the stack
        else{
            new_node->next = top;
            top = new_node;
        }

        //increment number of nodes
        numNodes++;
        }
}
// pop, removes top node from stack
template<class DataType>
void Stack<DataType>::pop(){

    //holds the node to be deleted
    StackNode<DataType> *delNode = nullptr;

    //check if stack is empty
    if(top == NULL){
        cout << "Stack is empty, nothing to pop \n";
    }
    else{
        // remove the top fo the stack
        delNode = top;
        top = delNode->next;
        delete delNode;

        //Decrement number of nodes
        numNodes --;
    }

}


template<class DataType>
DataType Stack<DataType>::topStack() const{

    return top->data;
}

