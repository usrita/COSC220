#include <iostream>
using namespace std;

class Myclass{
    private: 
        int mydata;
    public:
        Myclass (){;}
        ~Myclass () {;}
        int *SetData (int);
};

int* Myclass:: SetData(int x){

    int* tmp = &mydata;
    mydata = x;
    return tmp;
}

int main(){
    int x = 5;

    Myclass test;
    int* tmp = test.SetData(x);

    cout<< tmp << endl;

    

    return 0;
}