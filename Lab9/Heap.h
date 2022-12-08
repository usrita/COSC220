#include <iostream>

using namespace std;

class Heap{

    private:

        int max[100];
        int heapSize = 0;
        
        int parent(int i); //return index of parent of i
        int leftChild(int i); //return index of left child of i
        int rightChild(int i); //return index of right child of i
        int heapify(int i); // ?

        // member functions
        
        Heap(); // constructor
        Heap buildheap(); // ?
        int insert(); // insert new data into the heap
        void heapSort();
        void extractmax(); //extract maximum value from the heap
        int maximum(); // return maximum value in the heap
        void printHeap(); //print heap

};