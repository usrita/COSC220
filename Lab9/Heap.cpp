#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap(){
        int arr[] = {4,12,3,19,23,5,32,11,2,24};
        heapSize = 10;

        // call builheap function to build heap from array
    }

int Heap::parent(int i){
    if (i % 2 ==0) // even
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

    if (L <= heapSize && max[L] > max[i]){   
        Largest = L;
    } else
        Largest = i;
    if (R <= heapSize && max[R] > max[Largest])
        Largest = R;

    if(Largest != i){
        // swap
        temp = max[i];
        max[i] = max[Largest];
        max[Largest] = temp;

        heapify(Largest);
    }

}