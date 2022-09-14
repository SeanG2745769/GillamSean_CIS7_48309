/* 
 * File:   main.cpp
 * Author: Sean Gillam
 */
//Load Libraries
#include <iostream>
//Declare Namespace
using namespace std;
//Preload Functions
void table(bool, bool);
void table2(bool, bool);
//main
int main(int argc, char** argv)
{
    //Initializing values
    bool p, q;
    //Initial Statement 1
    cout<<"Proving: (p&&q)||~(p||q) = !(p^q)"<<endl;
    cout<<"p q p&&q p||q ~(p||q) p^q !(p^q) (p&&q)||~(p||q)"<<endl;
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
    //Initial Statement 2
    cout<<"Proving: (p||q)&&~(p&&q)= p^q"<<endl;
    cout<<"p q p&&q p||q ~(p&&q) (p||q)&&~(p&&q) p^q"<<endl;
    //Line 1
    p = true;
    q = true;
    table2(p,q);
    //Line 2
    p = true;
    q = false;
    table2(p,q);
    //Line 3
    p = false;
    q = true;
    table2(p,q);
    //Line 4
    p = false;
    q = false;
    table2(p,q);
    //Exit
    return 0;
}
//p q p&&q p||q ~(p||q) p^q !(p^q) (p&&q)||~(p||q)
void table(bool i, bool j)
{
    cout<<(i?'T':'F')<<" "//p
        <<(j?'T':'F')<<"   "//q
        <<(i&&j?'T':'F')<<"    "//p&&q
        <<(i||j?'T':'F')<<"      "//p||q
        <<(!(i||j)?'T':'F')<<"    "//~(p||q)
        <<(i^j?'T':'F')<<"     "//p^q
        <<(!(i^j)?'T':'F')<<"          "//!(p^q)
        <<((i&&j)||(!(i||j))?'T':'F')//(p&&q)||~(p||q)
        <<endl;
}

//p q p&&q p||q ~(p&&q) (p||q)&&~(p&&q) p^q
void table2(bool i, bool j)
{
    cout<<(i?'T':'F')<<" "//p
        <<(j?'T':'F')<<"   "//q
        <<(i&&j?'T':'F')<<"    "//p&&q
        <<(i||j?'T':'F')<<"      "//p||q
        <<(!(i&&j)?'T':'F')<<"          "//~(p&&q)
        <<((i||j)&&(!(i&&j))?'T':'F')<<"         "//(p||q)&&~(p&&q)
        <<((i^j)?'T':'F')//(p^q)
        <<endl;
}