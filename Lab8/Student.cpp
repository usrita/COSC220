// functions for students class
#include <iostream>
#include "Students.h"

using namespace std;

//Constructor, take in student info
Students::Students(){
    cout << "Enter First name: \n";
    cin >> firstname;
    cout << "Enter Last name: \n";
    cin >> lastname;
    cout << "Enter ID number: \n";
    cin >> iDnumber;

}
// // print student function
// void Students::printStudent(){
//     cout << "Last name: " << lastname << endl;
//     cout << "First name: " << firstname << endl;
//     cout << "ID number: " << iDnumber << endl;

// }
