// functions for students class
#include <iostream>
#include "Students.h"

using namespace std;

//Constructor, take in student info
Students::Students(int null1,int null2){
    cout << "Enter First name: \n";
    cin >> firstname;
    cout << "Enter Last name: \n";
    cin >> lastname;
    cout << "Enter ID number: \n";
    cin >> iDnumber;

}
Students ::Students(int item){
    iDnumber = item;
}
bool Students ::operator == (const Students node){
    return(iDnumber == node.iDnumber);

} // compare ID number 
bool Students:: operator > (const Students node){
    return(iDnumber > node.iDnumber);

}
bool Students:: operator < (const Students node){
    return(iDnumber < node.iDnumber);
}

ostream& operator <<(ostream& stream, const Students *student){
    stream<< student->lastname << " " << student->firstname << " " << student->iDnumber;
    return stream;
}
// // print student function
// void Students::printStudent(){
//     cout << "Last name: " << lastname << endl;
//     cout << "First name: " << firstname << endl;
//     cout << "ID number: " << iDnumber << endl;

// }
