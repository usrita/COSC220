#ifndef STUDENTS_H
#define STUDENTS_H

//definition of the struct type students
struct Students{
    char lastname[20];
    char firstname[20];
    int iDnumber;
    Students(); //constructor
    void printStudent();    //print student information

};

#endif