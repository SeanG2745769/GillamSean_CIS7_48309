/* 
 * File:   main.cpp
 * Author: Sean Gillam
 * Created On: 2022-09-22
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library 
#include <cstring>
using namespace std;

//Enum Data Type
enum CrdCard {
        AmericanExpress,
        Visa,
        MasterCard,
        Discover,
        ALL
    };

//Function Prototypes
char rndDgit();           //Randomly generates digit characters
int  cnvrt(char);         //Convert 1 digit char to integer
char cnvrt(int);          //Convert 1 digit integer to a char
int  Luhn(char[],int);     //Calculate and append the Luhn Digit
void genCC(CrdCard,char[], int);
bool validCC(char[]);
void flipDig(char[]);
bool validCC(char[]);
void copyArr(char[],char[],int);
void transpose(char[]);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Set the Credit Card size
    const int SIZE=17;//One larger than needed for the null terminator
    char cArray[SIZE];
    char tempArray[SIZE];
    
    bool  checkCC;
    int   countT1F = 0;
    int   countF1F = 0;
    int   countT2F = 0;
    int   countF2F = 0;
    int   countTT = 0;
    int   countFT = 0;
    float percentT;
    float percentF;
    
    for(int i=0;i<10000;i++)
    {
        int choice = rand()%4+1;
        bool wrong = false;
        do
        {
            switch(choice)
            {
                case 0:genCC(AmericanExpress,cArray,SIZE-1);break; //AE is 15 digits
                case 1:genCC(Visa,cArray,SIZE);break; //visa 13 or 16 handled later
                case 2:genCC(MasterCard,cArray,SIZE);break;
                case 3:genCC(Discover,cArray,SIZE);break;
                case 4:genCC(ALL,cArray,SIZE);break;
                default: cout<<"Try again.\n";wrong = true;
            }
        }while(wrong == true);
        
        copyArr(cArray,tempArray,SIZE);
        flipDig(tempArray);
        checkCC=validCC(tempArray);
        if(checkCC==true)
            countT1F++;
        if(checkCC==false)
            countF1F++;
        copyArr(cArray,tempArray,SIZE);
        flipDig(tempArray);
        flipDig(tempArray);
        checkCC=validCC(tempArray);
        if(checkCC==true)
            countT2F++;
        if(checkCC==false)
            countF2F++;
        copyArr(cArray,tempArray,SIZE);
        transpose(tempArray);
        checkCC=validCC(tempArray);
        if(checkCC==true)
            countTT++;
        if(checkCC==false)
            countFT++;
    }
    
    cout<<"1 Flip:\n";
    percentT = (countT1F / 10000.0)*100.0;
    cout<<"Percentage of Valid Cards = "<<percentT<<endl;
    percentF = (countF1F /10000.0)*100.0;
    cout<<"Percentage of Invalid Cards = "<<percentF<<endl<<endl;
    cout<<"2 Flip:\n";
    percentT = (countT2F / 10000.0)*100.0;
    cout<<"Percentage of Valid Cards = "<<percentT<<endl;
    percentF = (countF2F /10000.0)*100.0;
    cout<<"Percentage of Invalid Cards = "<<percentF<<endl<<endl;
    cout<<"Transpose:\n";
    percentT = (countTT / 10000.0)*100.0;
    cout<<"Percentage of Valid Cards = "<<percentT<<endl;
    percentF = (countFT /10000.0)*100.0;
    cout<<"Percentage of Invalid Cards = "<<percentF;
    
    //Exit Stage Right
    return 0;
}

void genCC(CrdCard Card,char c[], int size)
{
    //setting constant arrays for visa prefixes
    const char v[7][4] = {{'4','5','3','9'},{'4','5','5','6'},{'4','9','1','6'},
                          {'4','5','3','2'},{'4','9','2','9'},{'4','4','8','5'},
                          {'4','7','1','6'}};
    int num;
    if (Card == ALL)
    {
        num = rand()%4;
        if(num==0)
        {
            Card=AmericanExpress;
            size=size-1;//AE is 15 digits
        }
        else if(num==1)
            Card=Visa;
        else if(num==2)
            Card=MasterCard;
        else if(num==3)
            Card=Discover;
    }
    switch(Card)
    {
        case AmericanExpress: // size conversion for 15 digits handled earlier
            c[0]='3';
            num = rand()%2;
            if(num==0)
                c[1]='4';
            if(num==1)
                c[1]='7';
            for(int i=2;i<size-2;i++)
                c[i]=rndDgit();
            c[size-2] = cnvrt(Luhn(c,size));
            c[size-1]= '\0';
            break;
        case Visa:
            num = rand()%2;
            if(num==1)//if num==0 then 16 digit visa
                size=size-3;//13 digit visa half the time
            num = rand()%7;//(max-min+1)+min = (6-0+1)+0
            for(int i=0;i<4;i++)
                c[i]=v[num][i];
            for(int i=4;i<size-2;i++)
                c[i]=rndDgit();
            c[size-2] = cnvrt(Luhn(c,size));
            c[size-1]='\0';
            break;
        case MasterCard:
            c[0]='5';
            num = 1+rand()%(5-1+1);//(max-min+1)+min = (5-1+1)+1
            if(num==1)
                c[1]='1';
            else if(num==2)
                c[1]='2';
            else if(num==3)  //there has got to be a better way to do this...
                c[1]='3';
            else if(num==4)
                c[1]='4';
            else if(num==5)
                c[1]='5';
            for(int i=2;i<size-2;i++)
                c[i]=rndDgit();
            c[size-2] = cnvrt(Luhn(c,size));
            c[size-1]='\0';
            break;
        case Discover:
            c[0]='6';
            c[1]='0';
            c[2]='1';
            c[3]='1';
            for(int i=4;i<size-2;i++)
                c[i]=rndDgit();
            c[size-2] = cnvrt(Luhn(c,size));
            c[size-1]='\0';
    }
}

int Luhn(char cd[],int n)
{
    int ccc[n];
    for(int i=0;i<n;i++)
    {
        ccc[i]=cd[i]-'0';
    }
    for(int i=n-1;i>-1;i--)
    {
        ccc[i]=ccc[i]*2;
        if(ccc[i]>9)
            ccc[i]=ccc[i]-9;
        i--;
    }
    //Sum of Digits
    int sum = 0;
    for(int i=0;i<n-2;i++)
    {
        sum = sum+ccc[i];
    }
    //Getting Last Digit
    int lastDigit;
    sum = sum*9;
    lastDigit = sum % 10;
    
    return lastDigit;
}

void flipDig(char cf[])
{
    int length = strlen(cf);
    int flip = rand()%length;//(max-min+1)+min
    cf[flip] = (rand()%(9-0+1)+0)+'0';
}

bool validCC(char cv[])
{
    int length = strlen(cv);
    int sum = 0;
    bool second = false;
    for(int j=length-1;j>=0;j--)
    {
        int hold = cv[j] - '0';
        if(second == true)
            hold = hold *2;
        sum += hold/10;
        sum += hold%10;
        second = !second;
    }
    
    return (sum%10==0);
}

void transpose(char at[])
{
    int hold1;
    int hold2;
    int length = strlen(at);
    do
    {
        hold1 = rand()%length;
        hold2 = rand()%length;
    }while(hold1==hold2);
    swap(at[hold1],at[hold2]);
}

void copyArr(char orig[],char copy[], int size_f)
{
    for(int i=0;i<size_f;i++)
    {
        copy[i]=orig[i];
    }
}

char  cnvrt(int digit)
{
    if(digit<0||digit>9)
    {
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit+'0';
    //return digit+48;
}

int  cnvrt(char digit)
{
    if(digit<'0'||digit>'9')
    {
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit-'0';
}

char rndDgit()
{
    return rand()%10+'0';//Ascii Code for numbers '0'=48 and '9'=57
    //return rand()%10+48;//Ascii Code for numbers '0'=48 and '9'=57
}
