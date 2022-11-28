#ifndef STACK_H
#define STACK_H

template<class DataType>
struct StackNode{
    DataType data;
    StackNode<DataType> *next;
};

template <class DataType>
class Stack{
    private:
    StackNode<DataType> *top; //poiint to the top of node in stack
    int maxSize;             // maximum stack size   
    int numNodes;       // number of nodes in the stack

    public:
    Stack(int = 10); // constructor, create a stack with size x; default is 10
    ~Stack();       // destructor
    bool isEmpty() const;      //check if stack is empty
    bool isFull() const;       // check if stack is full
    void push(const DataType); // push a node to the top of the stack
    void pop();                // pop a node from the top of the stack
    DataType topStack() const; // return data from the top of the stack



};

#endif