#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Link.h"

using namespace std;

// Menu
void MenuDisplay(){

    // NEED TO ASK!! What do you mean by currently selected? is that where we are pointing??????????
    // Or print wat

    cout<< "\n\n\n1. Insert a new item \n"<< 
        "2. Print currently Selected item \n"<<
        "3. Delete item from the currently selected item list \n"<<
        "4. Create a receipt and stop \n"<< endl;
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
	else if (temp->itemNum == newNode->itemNum)
	{
		cout << "Invalid ID number, already exists in list \n";
		delete newNode;
	}	

	// is the value of the new node less than the start of the list

	else if(temp->itemNum > newNode->itemNum) {
		// shifting everything in list one 
		newNode->next = temp;
		list = newNode;
	}
	else{

		// while not at end of list bc next would point to nothing
		while (temp->next != NULL && temp->next->itemNum < newNode->itemNum){
			temp = temp->next;
		}
		if (temp->next != NULL && temp->next->itemNum == newNode->itemNum)
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

Node *deleteNode(Node* list, int item_id){
	
	Node *temp1 = list; 
	Node *temp2 = NULL;

	if (temp1 == NULL){
		cout << "List is empty, cant delete\n";
		return temp1;
	}

	// if begining of list is the id number we're looking for
	if (list->itemNum == item_id){
		// updating grand total
		//grand_total -= list->subtotal;
		list = temp1->next;
		delete temp1;
		cout << "Item was removed from list";

		return list;
	}

	while(temp1 != NULL && temp1->itemNum != item_id){

		temp2 = temp1;
		temp1 = temp1->next;
	}
	if (temp1 == NULL){
		cout <<"ID not found in list\n";
	}
	else{
		temp2->next = temp1->next;
		delete temp1;
		cout << "Id number was found and removed \n";
	} 
	
	return list;
}

double update_total(Node* list, int item_id, double current_total){
	Node *temp1 = list; 
	Node *temp2 = NULL;

	if (temp1 == NULL){
		//cout << "List is empty, cant delete\n";
		return current_total;
	}
	// if begining of list is the id number we're looking for
	if (list->itemNum == item_id){
		// updating grand total
		
		current_total -= list->subtotal;
		return current_total;
	}

	while(temp1 != NULL && temp1->itemNum != item_id){
		temp2 = temp1;
		temp1 = temp1->next;
	}
	// if we got to the end of the list
	if (temp1 == NULL){
		return current_total;
	}
	// if the number was found
	else{
		//grand_total -= temp1->subtotal;
		temp2->next = temp1->next;
		//delete temp1;
		current_total -= temp1->subtotal;
		return current_total;
	}
}


Node *Printlist(Node* list){
	
	double grand_total = 0;
	Node *temp = list;

	if (temp == NULL){
		cout << "List is empty" ;
	}
	else{

	cout << "Item Number"<< setw(31) << "Item Name" << setw(23) << "Unit" << setw(22)<<
		"Unit Price" << setw(17) << "Tax" << setw(23) << "Subtotal"<< "\n"<<
		"------------------------------------------------------------------" <<
		"---------------------------------------------------------------------------------"<< endl;
	
    // left before setw and 25 for everything
	while(temp != NULL){

		cout<< setw(5) << temp->itemNum << setw(40) << temp->itemName << setw(20) << temp->unit << setw(20) << 
		temp->unitPrice << setw(20) << temp->tax << setw(20) << temp->subtotal << setw(20) << endl;

		grand_total += temp->subtotal;

		temp = temp->next;
	}

	cout<< "\n\n" <<setw(140) << "Grand Total: " << grand_total << endl;
		
}

	return list;
}

double quantity(char type)
    {
	double amount = 0;

	if (type == 'n'){
		cout << "How many would you like?";
                cin >> amount;
                return amount;
	    }
    // single only
	else if (type == 's'){
		amount = 1;
		return amount;
	    }

    // weight 
	else{
        cout << "How many pounds would you like to purchase?";
        cin >> amount;
		return amount;
	    }

    }

Node *createNode(int itemnum, char itemname[40], double tax, double amount, double subtotal, double unitPrice){
	
    Node *newItemNode = new Node;

    for (int i = 0; i <40; i++){
        newItemNode->itemName[i] = itemname[i];
    }
    newItemNode->itemNum = itemnum;
	newItemNode->unit = amount;
	newItemNode->unitPrice = unitPrice;
	newItemNode->tax = tax;
	newItemNode->subtotal = subtotal;
	newItemNode->next = NULL;
	
	return newItemNode;
}

double taxable(char taxy, double subtotal){
	const double tax = 0.06;
	double taxx = 0.0;
	if (taxy == 'n'){
	
	}
	// calculate tax for taxable item int
	else {
		taxx = tax * subtotal;
	}
	return taxx;
}
Node *Printfile(Node* list, ostream& receipt){
	
	double grand_total = 0;
	Node *temp = list;

	if (temp == NULL){
		receipt << "List is empty" ;
	}
	else{

	receipt<< "Item Number"<< setw(31) << "Item Name" << setw(23) << "Unit" << setw(22)<<
		"Unit Price" << setw(17) << "Tax" << setw(23) << "Subtotal"<< "\n"<<
		"------------------------------------------------------------------" <<
		"---------------------------------------------------------------------------------"<< endl;
	
    // left before setw and 25 for everything
	while(temp != NULL){

		receipt<< setw(5) << temp->itemNum << setw(40) << temp->itemName << setw(20) << temp->unit << setw(20) << 
		temp->unitPrice << setw(20) << temp->tax << setw(20) << temp->subtotal << setw(20) << endl;

		grand_total += temp->subtotal;

		temp = temp->next;
	}

	receipt<< "\n\n" <<setw(133) << "Grand Total: " << grand_total << endl;
		
}

	return list;
}
 