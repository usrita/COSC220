#ifndef LINKED_H
#define LINKED_H
#include "Node.h"

class LinkedList
{
    private:
    Node * list;
    Node * createNode();
    Node * searchLocation(int student_ID);

    public:
    LinkedList();
    ~LinkedList();
    void insertNode();
    void deleteNode(int ID);
    void printList();
    void searchNode();

};


#endif