// Grocery Receipt System
// Usra Alaraki
// 09/13/2022

#include <iostream>
#include <fstream>
#include <cstdlib> // for exit function
#include <iomanip>

using namespace std;

double taxable(char taxy, double subtotal){
	const double tax = 0.06;
	double taxx = 0.0;
	if (taxy == 'n'){
	
	}

	// calculate tax for taxable itemint
	else {
		taxx = tax * subtotal;
	}

	return taxx;
}

int quantity(char type){

	int amount = 0;

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

	else{
		return 0;
	}
}

float weight(){
	float pounds = 0;
	cout << "How many pounds would you like to purchase?";
	cin >> pounds;
	return pounds;
}


int main(){

	// read from item.txt file
	// ask user what items they bought (ITEM NUMBER)
	// if this item number does not exist in file, give error message and ask for item number again
	// if item in the file is in the file, find out if it's by single unit or by pound
	// ask user how many or how much (int) weight they bought in pounds (float)
	// if item is taxable, calculate tax; 6%
	// print item num, name, unit (single and weight), unit price(price/unit), tax, subtotal and overall total
	
	int itemNum;
	char itemName[40];
	char taxability;
	char saleType;
	float unitPrice;

	// for user input
	int user_item;
	int amount;
	float item_weight;
	int user_choice = -1;
	double subtotal = 0;
	double tax = 0;
    double total = 0;



	// read in data from text file
	ifstream indata;
	ofstream outdata;
	
	indata.open("item.txt", ios::in);

	if(!indata) //checking to see if file can open or not
	{
		cerr << "Error: unable to open file" << endl;
		exit (1);
	}

	outdata.open("receipt_output.txt", ios::out); //create an output file

	if(!outdata){
		cerr << "Error cannot open file";
		exit(1);
	}

	// ask if they want to select item or quit
	cout<< "1. Buy an item \n"<<
		"2. Quit and Print \n";
	cin >> user_choice;

	outdata << "Item Number"<< setw(31) << "Item Name" << setw(23) << "Unit" << setw(22)<<
		"Unit Price" << setw(17) << "Tax" << setw(23) << "Subtotal"<< "\n"<<
		"------------------------------------------------------------------" <<
		"---------------------------------------------------------------------------------"<< endl;

	while (user_choice != 2) {

		// ask user for item number bought
		cout << "Item number: ";
		cin >> user_item ;
		
		do{

			indata >> itemNum >> itemName >> taxability >> saleType >> unitPrice;
			
			// if reached end of file
			if (indata.eof()){

				cout << "item not found. Enter a valid number: ";
				cin >> user_item;
				indata.clear();
				indata.seekg(0); //goes back to begining of file
			}

		}

	while (!indata.eof() && user_item != itemNum); // keep reading until end of file
		
		// calculating units(amount/item weight) and subtotals
		if (saleType == 'n' || saleType == 's'){
			amount = quantity(saleType);
			subtotal = amount * unitPrice;
			tax = taxable(taxability, subtotal);	
			// updating subtotals with calculated tax
			subtotal = subtotal + tax;
            outdata << setw(5) << itemNum << setw(40) << itemName << setw(20) << amount << setw(20)<<
		    fixed << showpoint << setprecision (2) <<unitPrice << setw(20) << tax << setw(20) <<
			subtotal<< "\n";
		} else{
			// units in weight
			item_weight = weight();
			subtotal = item_weight * unitPrice;
			tax = taxable(taxability, subtotal);
			// updating subtotals with calculated tax
			subtotal = subtotal + tax;

			outdata << setw(5) << itemNum << setw(40) << itemName << setw(20) << fixed << showpoint<<
            setprecision (1) << item_weight << fixed << showpoint << setprecision (2) <<
			setw(20)<< unitPrice << setw(20) << tax << setw(20) <<
            subtotal<< "\n";
			
			//cout << user_item << "\n" << itemName << "\n" << showpoint<< fixed << setprecision(1)<< item_weight<<
			//setprecision(2) << "\n" << unitPrice << "\n" << tax << "\n" << subtotal << endl;
	    }
        // update total after each item
        total += subtotal;
		// ask if they want to select item or quit
	    cout<< "1. Buy an item \n"<< "2. Quit and Print \n";
        cin >> user_choice;
		indata.clear();
		indata.seekg(0);
	}

    // User choice = 2 (Quit)
    outdata << "\n\n" << setw(130) << "Grand Total: " << total << endl;

    // close both files
    indata.close();
    outdata.close();

	return 0;
}
