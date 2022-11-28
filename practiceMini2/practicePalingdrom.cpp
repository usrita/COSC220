#include <iostream>
using namespace std;

// writing a function that checks if a word is palingdrom
// aka the same wtritten backwards like TENET

//prototype

bool palingdrom(char[], int);

int main(){

    char A [6] = "KAYOK";
    int size = 5;
    
    if( palingdrom(A, size) == true){
        cout<<"PLAINDROME"<<endl;
    }


    return 0;
}

bool palingdrom(char arr [], int size){
   // picture on phone 7:57 10/11/22
    

    char temp;
    char temp2;
    for (int i = 0; i < size; i++){
        int num = i + 1;
       temp=arr[i]; 
       temp2=arr[size - num];
       if(temp != temp2){
        cout << "Not a pall";
        return false;

        
       }


    }

    return true;

    cout << "Is a pall";
}