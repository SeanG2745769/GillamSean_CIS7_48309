/* 
 * File:   main.cpp
 * Author: Sean Gillam
 * Created on 2022-09-18
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

void read(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

int stat(const int a[],int n, int &M, int &L)
{
    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            M = a[i];
        }
        else if(M < a[i])
        {
            M = a[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            L = a[i];
        }
        else if(L > a[i])
        {
            L = a[i];
        }
    }
    int sum_f = 0;
    for(int i=0;i<n;i++)
    {
        sum_f = (sum_f + a[i]);
    }
    return sum_f;
}

void print(const int a[],int size_f,int sum_f,int max_f,int min_f)
{
    for(int i=0;i<size_f;i++)
    {
        cout<<"a["<<i<<"] = "<<a[i]<<endl;
    }
    cout<<"Min  = "<<min_f<<endl;
    cout<<"Max  = "<<max_f<<endl;
    cout<<"Sum  = "<<sum_f<<endl;
}