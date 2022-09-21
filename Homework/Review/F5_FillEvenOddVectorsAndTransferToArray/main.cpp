/* 
 * File:   main.cpp
 * Author: Sean Gillam
 * Created on 2022-09-18
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even_f, vector<int> &odd_f)
{
    int count,hold,evenC,oddC;
    cout<<"Input the number of integers to input.\n";
    cin>>count;
    cout<<"Input each number.\n";
    for(int i=0;i<count;i++)
    {
        cin>>hold;
        if(hold%2==0)
        {
            even_f.push_back(hold);
        }
        else
        {
            odd_f.push_back(hold);
        }
    }
}

void prntVec(vector<int> even_f, vector<int> odd_f, int width)
{
    cout<<"    Vector      Even       Odd\n";
    int n = 0;
    int j;
    for(const int& i : even_f)
    {
        cout<<"                   "<<i<<setw(width);
        if(n<(odd_f.size()))
        {
            for(j=n;j<n+1;j++)
            {
                cout<<odd_f.at(j)<<endl;
            }
            n++;
        }
        else
        {
            cout<<" "<<endl;
        }
    }
    if((even_f.size())<(odd_f.size()))
    {
        while(j<odd_f.size())
        {
            cout<<"                    "<<setw(width)<<odd_f.at(j)<<endl;
            j++;
        }
    }
}

void copy(vector<int> even_f, vector<int> odd_f,int a[][COLMAX])
{
    int aCol;
    int evenL = even_f.size();
    int oddL = odd_f.size();
    for(int i=0;i<evenL;i++)
    {
        a[i][0]=even_f.at(i);
    }
    for(int j=0;j<oddL;j++)
    {
        a[j][1]=odd_f.at(j);
    }
}

void prntAry(const int a[][COLMAX],int evenL,int oddL,int width)
{
    cout<<"     Array      Even       Odd\n";
    int n = 0;
    int j;
    for(int i=0;i<evenL;i++)
    {
        cout<<"                   "<<a[i][0]<<setw(width);
        if(n<oddL)
        {
            for(j=n;j<n+1;j++)
            {
                cout<<a[j][1]<<endl;
            }
            n++;
        }
        else
        {
            cout<<" "<<endl;
        }
    }
    if(evenL<oddL)
    {
        while(j<oddL)
        {
            cout<<"                    "<<setw(width)<<a[j][1]<<endl;
            j++;
        }
    }
    
}