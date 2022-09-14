/* 
 * File:   main.cpp
 * Author: Sean Gillam
 */

#include <iostream>

using namespace std;
void table(bool, bool);
int main(int argc, char** argv) 
{
    //Initialize Variables
    bool p, q;
    //Heading
    cout<<"p q ~p ~q p&&q p||q p^q p^q^q p^q^p !(p&&q) !p||!q !(p||q) !p^!q"<<endl;
    //Line 1
    p = true;
    q = true;
    table(p,q);
    //Line 2
    p = true;
    q = false;
    table(p,q);
    //Line 3
    p = false;
    q = true;
    table(p,q);
    //Line 4
    p = false;
    q = false;
    table(p,q);
    //Exit
    return 0;
}
void table(bool i, bool j)
{
    cout<<(i?'T':'F')<<" "//p
        <<(j?'T':'F')<<"  "//q
        <<(!i?'T':'F')<<"  "//~p
        <<(!j?'T':'F')<<"   "//~q
        <<(i&&j?'T':'F')<<"    "//p&&q
        <<(i||j?'T':'F')<<"   "//p||q
        <<((i^j)?'T':'F')<<"    "//p^q
        <<((i^j^j)?'T':'F')<<"     "//p^q^q
        <<((i^j^i)?'T':'F')<<"       "//p^q^p
        <<(!(i&&j)?'T':'F')<<"      "//!(p&&q)
        <<(((!i)||(!j))?'T':'F')<<"       "//!p||!q
        <<(!(i||j)?'T':'F')<<"      "//!(p||q)
        <<(((!i)^(!j))?'T':'F')//!p^!q
        <<endl;
}

