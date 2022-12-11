#include <iostream>
#include "Heap.h"


using namespace std;

void DisplayMenu();

int main(){
    int choice = 0;
    Heap heap;

    while(choice != 6){

        DisplayMenu();
        cin >> choice;

        while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
            cout << "invalid choice!\n";
            DisplayMenu();
        }

        switch(choice){

            //insert new element into heap
            case 1:
                heap.insert();
                break;

            //print max val
            case 2:
                heap.maximum();
                break;

            //extract max from heap
            case 3:
                heap.extractmax();
                break;

            //print heap
            case 4:
                heap.printHeap();
                break;

            //sort heap and print sorted heap
            case 5:
                heap.heapSort();
                heap.printHeap();
                break;
        }
    }

    return 0;
}
void DisplayMenu(){
    cout << "1. Insert element into the heap. \n"<<
        "2. Print Maximum value. \n" <<
        "3. Extract maximum value from the heap. \n"<<
        "4. Print heap \n "<<
        "5. Heap Sort, print sorted results and exit.\n"<<
        "6. Quit.\n";

    cout << "Enter choice: ";
}
