#ifndef BST_H
#define BST_H
#include "TNode.h"
#include"Students.h"

using namespace std; 

template <class T>
class BST{

    private:
    TNode<T> *root; // points to root node of BST
    TNode<T> *maximum(TNode<T>* tree);
    TNode<T>* minimum(TNode<T>* tree);
    TNode<T>* successor(TNode<T>* tree);
    TNode<T>* predecessor(TNode<T>* tree);
    TNode<T>* createNode();
    void clearTree(TNode<T>*);

    public: 
    BST();// constructor
    ~BST(); // destructor 

    void inOrder(TNode<T>* );
    void preOrder(TNode<T>* );
    void postOrder(TNode<T>* );
    void bstInsert();
    void bstDelete(TNode<T> *);
    TNode<T>* bstSearch(int value);

    TNode<T>* getRoot();

};

#endif