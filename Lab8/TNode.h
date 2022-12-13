#include <iostream>
using namespace std;

#ifndef TNODE_H
#define TNODE_H

template <class T>
class TNode{

    template<class> friend class BST;
    
    private:
    TNode *parent;  //pointer to parent node ROOTNODE
    TNode *leftchild;    //pointer to left child
    TNode *rightchild;   //pointer to right child
    T data;        // data, anytype

    public:
    
    TNode(); //constructor initilize all ptrs as NULL
    void printNode();
};

#endif