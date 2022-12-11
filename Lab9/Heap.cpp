// implementing fucntions from heap class from header file
#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap(){
        int arr[] = {4,12,3,19,23,5,32,11,2,24};
        heapSize = 10;

        // call builheap function to build heap from array
    }

int Heap::parent(int i){

    // if (i == 0){
    //     cout << "No parent";
    //    // return; ??
    // }
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

    if (L <= heapSize && A[L] > A[i]){   
        Largest = L;
    } else
        Largest = i;
    if (R <= heapSize && A[R] > A[Largest])
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
    int temp;
    buildHeap();
    
    for (int i = heapSize-1; i >= 1; i--){
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        heapSize--;
        heapify(0);
    }

}

//find maximum value in heap
int Heap::  maximum(){
    int max = A[0];
    for (int i = 0; i < heapSize; i++){
        if (max < A[i])
            max = A[i];
    }
    return max;
}

//extract max
int Heap::extractmax(){
    /*int index_max;
    for (int i = 0; i <= heapSize; i++){
        if (A[i] == maximum())
            index_max = i;
    }*/
    int max_value = A[0];
    A[0] = A[heapSize-1];

    //decrement size of heap
    heapSize--;
    heapify(0);
    return max_value;
}

// print heap
void Heap:: printHeap(){

    for (int i = 0; i < heapSize; i++ ){
        cout << A[i] << "\n" << "Parent: "<<
            parent(i) << "\n" << "Leftchild: "<<
            leftChild(i) << "\n" << "Rightchild: "<<
            rightChild(i) << "\n\n";
    }
}