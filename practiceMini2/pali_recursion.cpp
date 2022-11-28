#include <iostream>
using namespace std;

bool palindrome(int start, int end, char*word){
    //base case 1

    if (start>= end)
        return true;
    
    // second base
    if (word[start] != word[end])
        return false;
    else
        return palindrome(start +1, end-1, word);

}

