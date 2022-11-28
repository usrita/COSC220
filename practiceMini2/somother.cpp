#include<iostream>
#include"SomeOther.h"

using namespace std;

Some::Some(int x) // constructor for class Some
{
    some = x;
    cout << "Some "<< some <<" is created"<<endl;
}
Some::~Some() // Destructor for a class 'Some'
{
    cout << "Some "<<some <<" is destroyed"<<endl;
}
// Constructor for a class 'Others'
Others::Others(int x, int y):Assoc(y)
{
    other = x;
    cout <<"Other " <<other << " is created"<<endl;
}
Others::~Others() // Destructor for a class 'Others
{
    cout <<"Other " <<other << " is destroyed"<<endl;
}
int main()
{
    Others (1,2);
    return 0;
}
