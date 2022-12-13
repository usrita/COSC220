// implementing fucntions from heap class from header file
#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap(){
        int B[10] = {4,12,3,19,23,5,32,11,2,24}; // no error lik this but when I just do A = {} error
        heapSize = 10;
        for (int i = 0; i < heapSize; i++)
            A[i] = B[i];

        for(int i = 10; i < 100; i++)
            A[i] = 0;
        
        // call builheap function to build heap from array
        buildHeap();

    }

int Heap::parent(int i){

    if (i == 0){
        //cout << "No parent";
        return 0; // parent will say 0?
    }
    if (i % 2 == 0) // even
        return ((i-1)/2);
    else        //odd
        return (i /2);    

}

int Heap:: leftChild(int i){
    return (2*i +1);
}

int Heap:: rightChild(int i){
    return (2*i+2);
}

void Heap:: heapify(int i){
    int Largest;

    int L = leftChild(i);
    int R = rightChild(i);
    int temp;

    if (L < heapSize-1 && A[L] > A[i]){   
        Largest = L;
    } else
        Largest = i;
    if (R < heapSize-1 && A[R] > A[Largest])
        Largest = R;

    if(Largest != i){
        // swap
        temp = A[i];
        A[i] = A[Largest];
        A[Largest] = temp;

        heapify(Largest);
    }

}

void Heap::buildHeap(){
    for (int i = ((heapSize/2)-1); i>=0; i--){
        heapify(i);
    }
}

//insert
void Heap:: insert(){

    int newval;
    cout << "Enter number you'd like to insert:\n";
    cin >> newval;

    // insert it at the last empty space?
    int i = heapSize;
    heapSize++;

    // while caluclated parent value is smaller, move parent down index
    // move new value up
    while (i > 0 && A[parent(i)] < newval) {
        A[i] = A[parent(i)];
        i = parent(i);
    }
    // as soon as found an index where parent value
    // is greater than, place new value there.
    A[i] = newval;
}
//heapsort
void Heap:: heapSort(){
    int temp, size;
    size = heapSize;
    buildHeap();
    
    for (int i = size-1; i >= 1; i--){

        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        heapSize--;
        heapify(0);
    }

    // for (int i = 0; i < size; i++)
    //     cout << A[i] << " ";
    // cout << endl;
}

//find maximum value in heap
int Heap::  maximum(){
    buildHeap();
    int max = A[0];
    /*for (int i = 0; i < heapSize; i++){
        if (max < A[i])
            max = A[i];
    }*/
    return max;
}

//extract max
int Heap::extractmax(){
    buildHeap();
    /*int index_max;
    for (int i = 0; i <= heapSize; i++){
        if (A[i] == maximum())
            index_max = i;
    }*/
    int max_value = A[0];
    A[0] = A[heapSize-1];
    A[heapSize-1] = 0;

    //decrement size of heap
    heapSize--;
    heapify(0);
    return max_value;
}

// print heap
void Heap:: printHeap(){

    // pointer of array
    int * Aptr = A;
    int j = 0;

    cout << endl;
    if (heapSize > 1){
        for (int i = 0; i < heapSize; i++ ){
            //set value at location obtained from parent function to parentt variable
                cout << "Node: " << Aptr[i] << "\n";
                if (parent(i) < heapSize && i != 0)
                    cout << "Parent: "<< A[parent(i)] << "\n";
                if (leftChild(i) < heapSize)
                    cout << "Leftchild: "<< A[leftChild(i)] << "\n";
                if (rightChild(i) < heapSize)
                    cout << "Rightchild: "<< A[rightChild(i)] << "\n";
                cout << endl;
        }
    }
    while (A[j]!= 0){
        cout << A[j] << " ";
        j++;

    }

}