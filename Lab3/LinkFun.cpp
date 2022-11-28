#include "Link.h"
#include <iostream>

using namespace std;

// function to take in information from keyboard
// create a new node pointer returns pointer to new node
Node *createNode(){
	
	Node *newNode = new Node;
	//newNode->lastName;
	cout <<"Last Name: ";
	cin >> newNode->lastName;
	
	cout <<"First Name: ";
	cin >> newNode->firstName;
	
	cout <<"ID Number: ";
	cin >> newNode->idNumber;
	
	newNode-> next = NULL;
	
	return newNode;

}

// points to linked list
// points to the new node
// returns pointer to the linked list

Node *insertNode(Node *list, Node *newNode){
	// insert a new node to the linked list
	// sorted by student ID number
	Node *temp = list;

	// if list is empty
	if (temp == NULL){
		list = newNode;
	
	}
	else if (temp->idNumber == newNode->idNumber)
	{
		cout << "Invalid ID number, already exists in list \n";
		delete newNode;
	}	

	// is the value of the new node less than the start of the list

	else if(temp->idNumber > newNode->idNumber) {
		// shifting everything in list one 
		newNode->next = temp;
		list = newNode;
	}
	else{

		// while not at end of list bc next would point to nothing
		while (temp->next != NULL && temp->next->idNumber < newNode->idNumber){
			temp = temp->next;
		}
		if (temp->next != NULL && temp->next->idNumber == newNode->idNumber)
		{
			cout << "Invalid ID number, already exists in list \n";
			delete newNode;
		}
		// end of list
		else if (temp->next == NULL){
				temp->next = newNode;
		}
		// placing newnode inbetween
		else {
			newNode->next = temp->next;
			temp->next = newNode;
		}
		
	}
	// if a new node ID is already in the list
	// it must inform the user "It's already in the list."
	// does the new node need to be inserted at the end of the list

	return list;
}

Node *searchNode(Node* list, int ID){
	Node *temp = list;

	while(temp != NULL && temp->idNumber != ID){
		temp = temp->next;
	}

	if (temp == NULL){
		cout << "ID not found \n" ;
		return temp;
	}

	else{
		cout << "First name: " << temp->firstName <<
		"\n Last name: " << temp->lastName <<
		"\n ID number: "<< temp->idNumber << endl;

		return temp; 
	}
}

Node *deleteNode(Node* list, int id){
	Node * temp1 = list; 
	Node *temp2 = NULL;

	if (temp1 == NULL){
		cout << "List is empty, cant delete";
		return temp1;
	}

	if (temp1->idNumber == id){
		temp1 = temp1->next;
		delete list;

		return temp1;
	}

	while(temp1 != NULL && temp1->idNumber != id){
		temp2 = temp1;
		temp1 = temp1->next;
	}

	if(temp1 == NULL){
		cout << "ID not found in list\n";
	}

	else{
		temp2->next = temp1->next;
		delete temp1;
		cout << "Id number was found and removed \n";
	}
	return list;
}

void printList(Node *list){
	Node *temp = list;

	if (temp == NULL){
		cout << "List is empty\n";
	}

	while (temp != NULL){

		cout << "First name: " << temp->firstName <<
		"\n Last name: " << temp->lastName <<
		"\n ID number: "<< temp->idNumber << endl;

		temp = temp->next;
	}

}