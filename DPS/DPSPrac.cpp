#include <iostream>
using namespace std;
 
int main(){
    int min, max, sum;
    min = 1;
    max = 9808;
    sum = 0;

    while (sum < 9808){
        // going thru the page numbers
        for (int i = min; i < max; i++ ){
            sum += i;

            if (sum == 9808){
                cout << "From " << min << " to " << i << " are missing";
                break;
            }
            else{
                min += 1;
            }
        }
    }
return 0;
}