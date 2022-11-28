#include <iostream>
using namespace std;

bool strEql(char[], char[]);

int main(){

    char A[10] = "academy";
    char B[10] = "academi";

    strEql(A,B);

    char HisName[20] ="Michael Jackson";
    char YourName[]={'C','h','r','i','s','t','i','n','a',' ','A','g','u','i','l','e','r','a','\0'};
    char HerName[] = {'B','r','i','t','n','e','y',' ','S','p','e','a','r','s'}; //depends on system
    cout << "His Name is "<< HisName<<endl;
    cout <<"Your Name is " <<YourName <<endl;
    cout << "Her name is " << HerName <<endl;

    return 0;




}
bool strEql (char A[], char B[])
{
    int i=0;
    bool rval=false;
    while ((A[i]==B[i]) && (A[i]!='\0') && (B[i]!= '\0')){
        i++;
        cout<< "i is now:" << i << endl ;
    }
    if (A[i]== B[i])
    {
        cout << A[i] << "currently\n";
        rval=true;
        cout << "They r equal\n";
    }

    cout << rval << "false?\n";

    return rval;
}