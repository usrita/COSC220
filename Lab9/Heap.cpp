#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap(){
        int arr[] = {4,12,3,19,23,5,32,11,2,24};
        heapSize = 10;

        // call builheap function to build heap from array
    }

int Heap::parent(int i){
    if (i%2 ==0) // even
        return ((i-1)/2);
    else        //odd
        return (i /2);
}

