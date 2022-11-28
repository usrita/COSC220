// Using template functions
#include <iostream>
using namespace std;

template< class T >
void printArray( const T *, const int );

int main()
{
const int aCount = 5, bCount = 7, cCount = 6;
int a[ aCount ] = { 1, 2, 3, 4, 5 };
double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
char c[ cCount ] = "HELLO"; // 6th position for null
cout << "Array a contains:" << endl;
printArray<int> ( a, aCount ); // integer template function
cout << "Array b contains:" << endl;
printArray<double> ( b, bCount ); // double template function
cout << "Array c contains:" << endl;
printArray<char> ( c, cCount ); // character template function
return 0;
}

template< class T >
void printArray( const T *array, const int count )
{
for ( int i = 0; i < count; i++ )
cout << array[ i ] << " ";
cout << endl;
}
