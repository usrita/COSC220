// To test program with two type of stack

#include <iostream>
#include "Stack.h"
#include "Students.h"

using namespace std;

//template class<DataType>
Stack<Students> sStack;  // a stack with student data type do I need to make a it a pointer?? and why
Stack<int> iStack; // a stack with type int

/*
Menu: select int or student data type
1. push: push a new data to the top of the stack
2. pop: pop data from top of stack
3. topStack: display contents of top of stack
4. Quit program
*/

//prototype
void Displaymenu();
int main()
{
    //Stack<DataType> obj;
    char stack_choice;
    int sizemax, menu;

    cout << "Create integer (i) stack or student (s) stack? \n";

    if (stack_choice == 'i'){
        Stack<int> iStack; // a stack with type int
        
        cout << "Enter max size of int stack \n";
        cin >> sizemax;

        Stack<int> (sizemax);
    }
    else if(stack_choice == 's'){
        Stack<Students*> sStack;  // a stack with student data type do I need to make a it a pointer?? and why

        cout << "Enter max size of int stack \n";
        cin >> sizemax;
        
        Stack<Students*> (sizemax);
    }
    else
        cout << "Invalid input! \n" << "Goodbye! \n";

    Displaymenu();

    cout << "What would you like to do ?\n";
    cin >> menu;

    switch (menu)
    {
        // push to top
        case 1:
        int push_num;

        cout<< "Enter int to push: \n";
        cin >> push_num;
        iStack.push(push_num);
        break;

        // pop top
        case 2:
        iStack.pop();
        break;

        // print top
        case 3:
        iStack.topStack();
        break;

        // Quit
        case 4:
        cout << "Goodbye! \n";
    }
    

}

//Display menu
void Displaymenu()
{
    cout << "1. Push new data \n" <<
    "2. Pop current top data \n" <<
    "3. Disply top \n" <<    
    "4. Quit \n";        
}


