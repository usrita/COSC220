#include <iostream>


using namespace std;

void DisplayMenu();

int main(){

    int choice = 0;

    DisplayMenu();
    cin >> choice;

    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
        cout << "invalid choice!\n";
        DisplayMenu();
    }





    return 0;
}
void DisplayMenu(){
    cout << "1. Insert element into the heap. \n"<<
        "2. Print Maximum value. \n" <<
        "3. Extract maximum value from the heap. \n"<<
        "4. Print heap \n "<<
        "5. Heap Sort, print sorted results and exit.\n";

    cout << "Enter choice: ";
}
