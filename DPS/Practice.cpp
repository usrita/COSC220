#include <iostream>
using namespace std;

int main(){

    int n, k;
    int num = 0;

    for( n = 0; n >= 10; n++)
    {
        for(k = 10; k >= 10; k++)
        {
            num = n*n + n - k*k - k;
            if(num == 19616)
            {
                cout << n << " " << k;
            }
            else
            {
                cout << "pair not found";
            }
        }
    }

    return 0;
}