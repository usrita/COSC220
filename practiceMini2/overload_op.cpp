#include <iostream>
#include <string>

using namespace std;

struct youtubeChannel
{
    string Name;
    int sub_count;

    //constructor
    youtubeChannel(string name, int subss){
        // assigning name to what's being passed 
        // thru here when function is called 
        Name = name;
        sub_count = subss;
    }

};

//overloading operator, so cout operator knows what to do 
// with our user definded object: youtubeChannel
ostream& operator << (ostream& COUTT , youtubeChannel& chan1){
    COUTT<< "Name: " << chan1.Name << endl;
    COUTT<< "Subscribers: " << chan1.sub_count << endl;

    return COUTT;
}

int main()
{
    youtubeChannel ytc1 = youtubeChannel("Ariel", 5000);
    cout << ytc1;

    return 0;
}
