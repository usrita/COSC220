// Usra Alaraki
// 09/29/2022

// Main program here


#include <iostream>
#include "Link.h"

using namespace std;

// prototype
void MenuDisplay();

int main (){
int choice;
Node *list = NULL;
int idNum;

// do this before menu?
// after creting node, put in list?
// or name this list?

//*Newnode = NULL;
//newNode = createNode();

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
     list = insertNode(list, createNode());
}

//Delete a node
else if ( choice == 2){
    cout << "Type ID number you want to delete: \n";
    cin >> idNum;
    
    list = deleteNode(list, idNum);
}

// Print list
else if (choice == 3){
    printList(list);

}
// search node, or seacrh and print info of node
else if (choice == 4){
    cout << "Type the id# you want to search: \n";
    cin >> idNum;
    searchNode(list, idNum);

}

else{
 
}
    MenuDisplay();
    cout << "What would you like to do? \n";
    cin >> choice;
}

if (choice == 5)
{
    cout << "Goodbye! \n";
}

return 0;
}

// Menu
void MenuDisplay(){

    cout<< "\n\n\n1. Insert a node \n"<< "2. Delete a node \n"<<
        "3. Print List \n"<<
        "4. Search a node/ search and print information of node \n"<<
        "5. Quit the program \n";
}
