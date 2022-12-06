#include "Node.h"
#include <iostream>

using namespace std;

// constructor definition
Node::Node(){
    cout << "Last name: \n";
    cin >> lastNAme;

    cout << "First name: \n";
    cin >> firstNAme;

    cout << "ID number: \n";
    cin >> idNumber;
}

// define print function
void Node::printNode(){

    cout << "id: " <<idNumber;
    cout << "First:" << firstNAme;
    cout << "LAst: " <<  lastNAme << endl;
    
}
