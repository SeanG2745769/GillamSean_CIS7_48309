/* 
 * File:   main.cpp
 * Author: Sean Gillam
 * Created on 2020-07-05
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    cin>>array;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char array_f[])
{
    int sizeArray_f = strlen(array_f);
    return sizeArray_f;
}

void sort(char array_f[], int sizeIn_f)
{
    char temp;
    for(int i=0; i<sizeIn_f; i++)
    {
        for(int j=1; j<sizeIn_f-i; j++)
        {
            if(array_f[j-1]>array_f[j])
            {
                temp=array_f[j-1];
                array_f[j-1]=array_f[j];
                array_f[j]=temp;
            }
        }
    }
}

void print (const char array_f[], int sizeIn_f)
{
    for(int i = 0; i < sizeIn_f; i++)
    {
        cout << array_f[i];
    }
    cout<<endl;
}