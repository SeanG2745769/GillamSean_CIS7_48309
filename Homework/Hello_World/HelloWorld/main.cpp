//System Libraries Here
#include <iostream>
using namespace std;

enum test
{
    zero,
    one,
    two,
    three
};

int main(int argc, char** argv) 
{
    int i;
    for(auto test : {zero, one, two, three})
    {
        i = test;
        cout<<i;
    }
    return 0;
}