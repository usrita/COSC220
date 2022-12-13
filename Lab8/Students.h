#include <iostream>
using namespace std;

#ifndef STUDENTS_H
#define STUDENTS_H

//definition of the struct type students
struct Students{
    char lastname[20]; //student last name
    char firstname[20]; //student first name
    int iDnumber;       // student id number
    Students(int,int); 
    Students(){} //constructor
    Students(int);
    bool operator == (const Students); // compare ID number 
    bool operator > (const Students);
    bool operator < (const Students);

    //output operator 
    friend ostream& operator << (ostream& stream, const Students *student);
    //void printStudent();    //print student information

};

#endif