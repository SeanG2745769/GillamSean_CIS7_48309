/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Edited by: Sean Gillam
 * Created on Aug 21st, 2022, 10:35 AM
 * Edited On: Sep 5th, 2022
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library 
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();           //Randomly generates digit characters
void prpLuhn(char[],int); //Prepares the Luhn Sequence
int  cnvrt(char);         //Convert 1 digit char to integer
char cnvrt(int);          //Convert 1 digit integer to a char
void output(char[],int);  //Output the sequence as integers
//Function you are to create
int Luhn(char[],int);    //Calculate and append the Luhn Digit

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Set the Credit Card size
    const int SIZE=17;//One larger than needed for the null terminator
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    
    //Output the preLuhn credit card
    cout<<crdCard<<endl<<endl;
    output(crdCard,SIZE-2);
    cout<<endl;
    
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    int last = Luhn(crdCard,SIZE);
    cout<<"\nThe random number with Luhn Encoding, Output Here!"<<endl;
    cout<<"-> "<<crdCard<<last<<endl;
    
    //Exit Stage Right
    return 0;
}

int Luhn(char cd[],int n){
    cout<<"Applying algorithm:"<<endl;
    int ccc[n];
    for(int i=0;i<n;i++){
        ccc[i]=cd[i]-'0';
    }
    cout<<"Double every other: ";
    for(int i=n;i>0;i--){//doubling every other from the right
        ccc[i]=ccc[i]*2;
        i=i-1;
    }
    for(int i=0;i<n-2;i++){//output
        cout<<ccc[i]<<" ";
    }
    cout<<"\nSum of digits: ";
    int sum = 0;
    for(int i=0;i<n-2;i++){
        sum = sum+ccc[i];
    }
    cout<<sum<<endl;
    sum = sum * (9%10);
    int lastDigit;
    lastDigit = sum % 10;
    cout<<"Multiply by 9: "<<sum<<endl;
    cout<<"Last Digit: "<<lastDigit<<endl;
    
    return lastDigit;
}

void output(char cc[],int n){
    cout<<"The char array output as each integer digit"<<endl;
    for(int i=0;i<n;i++){
        cout<<cnvrt(cc[i]);
    }
    cout<<endl;
}

char  cnvrt(int digit){
    if(digit<0||digit>9){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit+'0';
    //return digit+48;
}

int  cnvrt(char digit){
    if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit-'0';
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+'0';//Ascii Code for numbers '0'=48 and '9'=57
    //return rand()%10+48;//Ascii Code for numbers '0'=48 and '9'=57
}
