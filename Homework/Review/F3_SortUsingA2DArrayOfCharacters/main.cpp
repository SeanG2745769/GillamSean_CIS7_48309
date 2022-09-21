/* 
 * File:   main.cpp
 * Author: Sean Gillam
 * Created on 2022-09-18
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now input the array."<<endl;
    rowDet=rowIn;
    for(int i=0; i<rowIn; i++)
    {
        cin>>array[i];
    }
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char a[][COLMAX], int& r)
{
    int col=0;
    for(int i=0; i<r; i++)
    {
        int hold = 0;
        for(int j=0; j<COLMAX; j++)
        {
            if(a[i][j] != '\0')
            {
                hold++;
            }
            else
            {
                break;
            }
        }
        if(col<hold)
        {
            col = hold;
        }
    }
    return col;
}

void sort(char a[][COLMAX], int row, int col)
{
    for(int i=0;i<row-1;i++)
    {
        for(int j=0;j<row-i-1;j++)
        {
            if(a[j][0]>a[j+1][0])
            {
                for(int n=0;n<col;n++)
                {
                    char temp=a[j][n];
                    a[j][n]=a[j+1][n];
                    a[j+1][n]=temp;
                }
            }
        }
    }
}



void print(const char a[][COLMAX],int row,int col)
{
    
    for(int i=0; i<row; i++)
    {
        size_t len = strlen(a[i]);
        for(int j=0; j<len; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}