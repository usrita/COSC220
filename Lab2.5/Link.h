#include <fstream>
#include<iostream>
struct Node{
	int itemNum;
    char itemName[40];
    double unit; // for pound or number of unit
    double tax; 
    double unitPrice;
    double subtotal;
	Node *next;	    // Pointer to the next Node
};
//using namespace std;
// prototypes
void MenuDisplay();
Node *createNode(int, char[40], double, double, double, double);
double update_total(Node* , int , double );
Node *insertNode(Node*, Node*);
Node *deleteNode(Node*, int);
Node *Printlist(Node*);
double taxable(char, double);
double quantity(char);
Node *Printfile(Node*, std::ostream&);


