// pointer2.cpp
#include <iostream>
using namespace std;
int main()
{

int A1 [6] = {1,2,3,4,5,6};
int *p = A1;

cout << "p[1]" << p[1]+1 <<endl;
cout << "A[1]" << A1[1] <<endl;


char A [6] = "ABCDE";
char *ptr [4] = {"ABC", "DEFG", "HIJ", "KL"};

cout << "A" << A << endl << endl;

cout << ptr << endl;
cout << *ptr << "\n\n";

cout << "ptr + 1" << ptr + 1<< endl;
cout << "**(ptr+1)" << *(ptr+1) << "\n\n";

cout << ptr[1] << endl;
cout << *(ptr[1]) << "\n\n";

cout << ptr[1] +1 << endl;
cout << *(ptr[1] +1) << endl << endl;

cout << " *ptr[1] +1 "<<*ptr[1] +1 << endl;


cout  << *ptr[1]<< endl;
cout << ptr[0+1] << endl;

//cout << "A: " << *A << endl;
//cout << "A +2: "<< A +2 << endl;

// ptr = A + 1;

// cout << ptr << endl;
// cout << ptr -1 << endl;

return 0;
}
