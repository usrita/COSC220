#include <iostream>
#include "TNode.h"

using namespace std; 

template <class T>
class BST{

    private:
    TNode* root; // points to root node of BST
    TNode* maximum(TNode* tree);
    TNode* minimum(TNode* tree);
    TNode* successor(TNode* tree);
    TNode* predecessor(TNode* tree);
    TNode* createNode();
    void clearTree(TNode*);

    public: 
    BST();// constructor
    ~BST(); // destructor 

    void inOrder(TNode* );
    void preOrder(TNode* );
    void postOrder(TNode* );
    void bstInsert();
    void bstDelete(TNode *);
    TNode* bstSearch(int value);

    TNode* getRoot();

};

