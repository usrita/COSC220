struct Node{
	char lastName[20];  // Student's Last name
	char firstName[20]; // Students First name
	int idNumber;	    // Student's ID Number
	Node *next;	    // Pointer to the next Node
};


// Function Prototypes
Node *createNode();
Node *insertNode(Node*, Node*);
Node *searchNode(Node*, int);
Node *deleteNode(Node*, int);
void printList(Node*);


