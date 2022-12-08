#include <iostream>
#include "TNode.h"

using namespace std; 

class BST{

    private:
    TNode* root; // do I set this equal to parent??
    TNode* maximum(TNode* tree);
    TNode* minimum(TNode* tree);
    TNode* successor(TNode* tree);
    TNode* predecessor(TNode* tree);
    TNode* createNode();
    void clearTree(TNode*);

    public: 
    // constructor
    BST();

    // destructor 
    ~BST();

    void inOrder(TNode* );
    void preOrder(TNode* );
    void postOrder(TNode* );
    void bstInsert();
    void bstDelete(TNode *);
    TNode* bstSearch(int value);

    TNode* getRoot();

};

