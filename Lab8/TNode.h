#include <iostream>
#ifndef TNODE_H
#define TNODE_H

using namespace std;

// struct or class?? 
class TNode{

    friend class BST;
    
    private:
    TNode *parent;  //pointer to parent node ROOTNODE
    TNode *leftchild;    //pointer to left child
    TNode *rightchild;   //pointer to right child
    int data;        //space will be used with template for lab8

    public:
    //constructor 
    TNode();
    void printNode();
};

#endif