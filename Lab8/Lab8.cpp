#include <iostream>
#include "BST.h"
#include "TNode.h"
#include "Students.h"

using namespace std;

void DisplayMenu();

int main(){

    int user_input = 0, node_val;
    char sub_input = ' ';
    TNode<int>* intnodePtr;
    BST<int> inttree;

    while (user_input != 4){
        
        DisplayMenu();
        cout << "What would you like to do? \n";
        cin >> user_input;

    // input validation
    while (user_input != 1 && user_input != 2 && user_input != 3  && user_input!= 4){
        cout << "Invalid input, enter again: \n";
        cin >> user_input;
    }

        switch(user_input){
            
            // insert
            case 1:
                inttree.bstInsert();
                break;

            //delete
            case 2:
                cout<< "Enter value to delete\n";
                cin >>node_val;

                intnodePtr = inttree.bstSearch(node_val);
                inttree.bstDelete(intnodePtr);
                break;


            //print
            case 3:
            cout << "a. in order, b. post order, c. preorder \n";

            cout << "What would you like to do? \n";
            cin >> sub_input;

            while (sub_input != 'a' && sub_input != 'b' && sub_input != 'c')
            {
                cout << "Invalid input, enter again: \n";
                cin >> sub_input;
            }

            switch(sub_input){
                //inorder
                case 'a':
                    inttree.inOrder(inttree.getRoot());
                    break;

                case 'b':
                     inttree.postOrder(inttree.getRoot());
                    break;

                case 'c':
                    inttree.preOrder(inttree.getRoot());
                    break;
            }
            break;

            case 4:
            cout << "Goodbye\n";
            break;
        }
    }

    return 0;

}

void DisplayMenu(){
    cout << "1. Insert Element to the binary search tree. \n"<<
        "2. Delete elements from the binary search tree. \n" <<
        "3. Check binary tree by printing [a. in order, b. post order, c. preorder] \n"<<
        "4. End Program \n ";
}