#include <iostream>
#include "LinkedList.h"

using namespace std;

// prototype
void MenuDisplay();

int main (){

int choice;
LinkedList list = LinkedList();
int idNum;

MenuDisplay();

cout << "What would you like to do? \n";
cin >> choice;

// input validation
while (choice != 1 && choice != 2 && choice != 3  && choice != 4 && choice!= 5){
    cout << "Invalid input, enter again: \n";
    cin >> choice;
}
// take user input as long as they dont want to quit
while (choice != 5){

// Insert mode
if (choice == 1){
    //Node *newNode = createNode();
    
    //insertNode(list, newNode);
     list.insertNode();
}

//Delete a node
else if ( choice == 2){
    cout << "Type ID number you want to delete: \n";
    cin >> idNum;
    
    list.deleteNode(idNum);
    }

// Print list
else if (choice == 3){
    list.printList();

}
// search node, or seacrh and print info of node
else if (choice == 4){
    list.searchNode();

}

    MenuDisplay();
    cout << "What would you like to do? \n";
    cin >> choice;
}
cout << "Goodbye! \n";

return 0;

}

// Menu
void MenuDisplay(){

    cout<< "\n\n\n1. Insert a node \n"<< "2. Delete a node \n"<<
        "3. Print List \n"<<
        "4. Search a node/ search and print information of node \n"<<
        "5. Quit the program \n";
}
