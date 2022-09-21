/* 
 * File:   main.cpp
 * Author: Sean Gillam
 * Created on 2022-09-18
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <string>
#include <cmath>
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

bool inRange(const char a[],unsigned short &num)
{
    int end = strlen(a);
    for(int i=0;i<end;i++)
    {
        if((int(a[i])<48) || (int(a[i])>57))
        {
            return false;
        }
    }
    int n = stoi(a);
    if ((0 > n) || (n > 65535))
    {
        return false;
    }
    else
    {
        int hold = stoi(a);
        num = hold;
        return true;
    }
}

bool reverse(unsigned short s,signed short &ss)
{
    int hold = s;
    int hold2;
    int length = to_string(hold).length();
    int reversed = 0;
    while(s > 0)
    {
        reversed = reversed*10 + s%10;
        s /= 10;
    }
    if(length<5)
    {
        hold2 = 5-length;
        hold2 = pow(10, hold2);
    }
    reversed = reversed * hold2;
    if(reversed > 32767)
    {
        return false;
    }
    else
    {
        ss = reversed;
        return true;
    }
}

short subtrct(signed short sshort,int n)
{
    if((sshort-n)<0)
    {
        return sshort;
    }
    else
    {
        sshort = sshort - n;
        return sshort;
    }
}
