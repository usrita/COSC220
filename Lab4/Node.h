#ifndef NODE_H
#define NODE_H
class Node
{
public:
    char lastNAme[20];
    char firstNAme[20];
    int idNumber;
    Node *next;

    Node();
    void printNode();
};

#endif

// constructor 