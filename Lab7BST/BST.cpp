#include <iostream>
#include "BST.h"

using namespace std;

//constructor
BST:: BST(){

    root = NULL;
}

BST:: ~BST(){
    clearTree(root);
}

void BST :: clearTree(TNode* node){
    if (node != NULL){

        if(node->leftchild == NULL && node->rightchild == NULL){
            delete node;
        }
        else{
        clearTree(node->leftchild);
        clearTree(node->rightchild);
        }
    }
}

TNode* BST:: maximum(TNode* node){
    TNode * temp = node;

    while(temp->rightchild != NULL){
        temp = temp->rightchild;
    }
    return temp;
}

// to find successor
TNode* BST:: minimum(TNode* node){


    TNode * temp = node;

    while(temp->leftchild != NULL){
        temp = temp->leftchild;
    }
    return temp;
}

TNode* BST:: successor(TNode * node){
    TNode* temp1 = node;
    TNode* temp2 = nullptr;

    if(temp1->rightchild != NULL){
        return minimum(temp1->leftchild);
    }
    // right child is null, look in left
    else{
        temp2 = temp1->parent;

        while (temp2!= NULL && temp1 == temp2->rightchild){
            temp1 = temp2;
            temp2= temp2->parent;
        }
        return temp2;
    }

}

TNode* BST :: getRoot(){
    return root;
}

TNode* BST :: createNode(){

    TNode* newnode = new TNode();

    cout << "Input an integer: \n";
    cin >> newnode->data;

    return newnode;
}



void BST :: inOrder(TNode* node){

   if(node!= nullptr){
    inOrder(node->leftchild);
    node->printNode();
    inOrder(node->rightchild);

   }

}

void BST :: preOrder(TNode* node){

   if(node!= nullptr){
    
    node->printNode();
    preOrder(node->leftchild);
    preOrder(node->rightchild);

   }

}

void BST :: postOrder(TNode* node){

   if(node!= nullptr){
    
    postOrder(node->leftchild);
    postOrder(node->rightchild);
    node->printNode();

   }

}

//search
TNode* BST :: bstSearch(int value){

    TNode* temp = root;

    while(temp!= NULL && temp->data != value){
        if(temp->data > value){
            temp = temp->leftchild;
        }
        else 
            temp = temp->rightchild;
    }
    return temp;

}

void BST :: bstInsert(){

    TNode* newnode = createNode();
    // keep track of current node
    TNode* temp1 = root;
    // to keep track of parent node
    TNode* temp2 = nullptr;

    if(bstSearch(newnode->data)!= NULL){
        cout << "Already in tree!\n";
        return;
    }

    while(temp1 != NULL){
        temp2 = temp1;
        if(newnode->data < temp1->data){
            temp1 = temp1->leftchild;
        }
        else{
            temp1 = temp1->rightchild;
        }
    }

    newnode-> parent = temp2;

    // tree is empty
    if(temp2 == NULL){
        root = newnode;
    }

    // less than parent
    else if(newnode->data < temp2->data){
        temp2-> leftchild = newnode;
    }

    // greater than parent
    else
        temp2->rightchild = newnode;

}

void BST :: bstDelete(TNode* delnode){

    // no node in tree
    // if(bstSearch(delnode->data)== NULL){
    //     cout << "Value not in tree\n";
    //     return;
    // }

    if(delnode == NULL){
        cout << "Value not in tree\n";
        return;
    }
    TNode* temp1 = nullptr;
    TNode* temp2 = nullptr;

    if(delnode-> leftchild == NULL || delnode ->rightchild == NULL){
        temp1 = delnode;
    }
    else{
        temp1 = successor(delnode);
    }

    if(temp1->leftchild != NULL){
        temp2= temp1->leftchild;
    }
    else{
        temp2 = temp1->rightchild;
    }

    if(temp2 != NULL){
        temp2->parent = temp1->parent;
    }
    if(temp1->parent == NULL){
        root = temp2;
    }
    else if(temp1 == temp1->parent->leftchild){
        temp1->parent->leftchild = temp2;
    }
    else{
        temp1->parent->rightchild = temp2;
    }

    if(temp1 != delnode){
        delnode->data = temp1->data;
    }
    delete temp1;

}