#include <iostream>
#ifndef TNODE_H
#define TNODE_H

using namespace std;

// struct or class?? 
struct TNode{

    private:
    TNode *parent;  //pointer to parent node
    TNode *left;    //pointer to left child
    TNode *right;   //pointer to right child
    int data;        //space will be used with template for lab8

    public:
    //constructor 
    TNode(){

    }
    void printNode(){

    }



};

#endif