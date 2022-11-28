#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Link.h"

using namespace std;


int main(){

    Node *list = NULL;
    int itemNum;
	char itemName[40];
	char taxability;
	char saleType;
	float unitPrice;

	int user_item;
	double amount;
	//float item_weight;
	int menu_choice;
	double subtotal = 0;
	double tax = 0;
    double total = 0;

	// read in and write out data
	ifstream indata;
	ofstream outdata;

    //open text file
    indata.open("item.txt" , ios :: in);
    //checking to see if file can open or not
    if(!indata) 
	{
		cerr << "Error: unable to open file" << endl;
		exit (1);
	}

    // creating output file for receipt
    outdata.open("receipt.txt", ios::out);
    
	if(!outdata){
		cerr << "Error cannot open file";
		exit(1);
	}

    MenuDisplay();
    cout << "What would you like to do?\n";
    cin >> menu_choice;

    // while choice != exit and print
    while(menu_choice != 4){

        if (menu_choice == 1){
            
           
			
			//cout << "Read in first data";
			// keep reading as long as were not at end and item num not found
			//indata >> itemNum >> itemName >> taxability >> saleType >> unitPrice;
             //use create node here instead

            cout << "Item number to insert: \n";
		    cin >> user_item ;

			indata.clear();
			indata.seekg(0); 
			do
			{
            // search for it in file
                indata >> itemNum >> itemName >> taxability >> saleType >> unitPrice;
				if (indata.eof())
				{	
				cout << "item not found\n";
				indata.clear();
				indata.seekg(0); //goes back to begining of file
				cout << "Item number to insert: \n";
		    	cin >> user_item ;
				//MenuDisplay();

				}
			}
			while (!indata.eof() && itemNum != user_item);
			//if end of file is reached
			
			
            
				// calculating for parameters of creating node
				amount = quantity(saleType);

				subtotal = amount * unitPrice;
				tax = taxable(taxability, subtotal);

				// updating subtotal with tax included
				subtotal += tax;
				total += subtotal;

				// call createnode function
				Node *tmp = createNode(itemNum, itemName, tax, amount,subtotal, unitPrice);
				
				//call insertnode
				list = insertNode(list, tmp);			

		}
		// print currently selected node

		// print info of a node from the list whatever the user chooses??
		// or print current receipt
        else if(menu_choice == 2)
		{
			Printlist(list);
        }
		// delete an item from list
		else if(menu_choice ==3) {

			cout << "Enter the item number you'd like to delete: \n";
			cin >> user_item;
			//update total before deleting from list
			//total = update_total(list, user_item, total);
			list = deleteNode(list, user_item);

			//total = total - tmp->            
        }

		else{
			cout << "INVALID input.\n";
			MenuDisplay();
		}

		MenuDisplay();
		cout << "What would you like to do?\n";
    	cin >> menu_choice;

	}
        
    // User choice = 4 (Quit)
	// print to a text file
    Printfile(list, outdata);

    // close both files
    indata.close();
    outdata.close();

    return 0;
}