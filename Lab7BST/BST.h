#include <iostream>
#include "TNode.h"

using namespace std; 

class BST{

    private:
    BST * root; // do I set this equal to parent??
    void maximum(BST* tree);
    void minimum(BST* tree);
    void successor(BST* tree);
    void predecessor(BST* tree);
    BST createNode();

    public: 
    // constructor
    BST();

    // destructor 
    ~BST();

    BST inOrder(BST* tree);
    BST preOrder(BST* tree);
    BST postOrder(BST* tree);
    BST bstInsert();
    BST bstDelete();
    BST bstSearch();

};

