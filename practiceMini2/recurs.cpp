#include <iostream>
using namespace std;
// A Function Prototype
int rangeSum(int[], int, int);
int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout <<"The sum of elements 2 through 5 is ";
    cout << rangeSum(numbers, 2, 5)<<endl;
    return 0;
}
// simple function without recursion
int rangeSum(int A[], int start, int end)
{
    int rgsum =0;
    for (int i = start; i <=end; i++)
        rgsum += A[i];
    return rgsum;
}