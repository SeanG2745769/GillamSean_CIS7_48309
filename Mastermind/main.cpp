/* 
 * File:   main.cpp
 * Author: Sean Gillam 
 * 
 * Created on October 19, 2022, 11:08 PM
 */

//User libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

//namespace declaration
using namespace std;

//Global Constants
const int ATTEMPTS = 10;

//Prototypes
void lab(int &, bool &);
void menu(int &, bool &);
void game(int &, bool &);
void settings(int &, bool &);

//main function
int main(int argc, char** argv)
{
    //setting rand seed
    srand(static_cast<unsigned int>(time(0)));
    //Setting default values
    int  pegs = 4;
    bool dups = false;
    
    //Welcome and enter main menu
    cout<<"Welcome to Mastermind!"<<endl<<endl;
    cout << "Rules:\n"
            "- The computer picks a sequence of colors. The number of colors\n"
            "  is the code length. The default code length is 4 but it can be\n"
            "  changed when starting a new game in settings.\n\n"
            "- The objective of the game is to guess the exact positions of\n"
            "  the colors in the computer's sequence.\n\n"
            "- By default, a color can be used only once in a code sequence.\n"
            "  If you start a new game with the Allow duplicates true in\n"
            "  settings, then any color can be used any number of times in\n"
            "  the code sequence.\n\n"
            "- For each color in your guess that is in the correct color and\n"
            "  correct position in the code sequence, the computer display a\n"
            "  2 on the right side of the current guess.\n\n"
            "- For each color in your guess that is in the correct color but\n"
            "  is NOT in the correct position in the code sequence, the\n"
            "  computer display a 1 on the right side of the current guess.\n\n"
            "- You win the game when you manage to guess all the colors in\n"
            "  the code sequence and when they all in the right position.\n\n"
            "- You lose the game if you use all attempts without guessing the\n"
            "  computer code sequence.";
    menu(pegs, dups);
    
    //Exit Stage Right
    return 0;
}

void menu(int &pegs, bool &dups)
{
    bool menuCheck=true;
    int menuChoice;
    cout<<"\n\nChoose an option below: "<<endl;
    while(menuCheck)
    {
        menuCheck = true;
        cout<<"0: Run Lab 1A"<<endl;
        cout<<"1: Play Game"<<endl;
        cout<<"2: Settings"<<endl;
        cout<<"3: Quit"<<endl;
        cout<<"->";
        cin>>menuChoice;
        if(menuChoice<0||menuChoice>3)
            cout<<"Invalid try again.\n";
        else
            menuCheck=false;
    }
    switch(menuChoice)
    {
        case 0 : lab(pegs, dups);
        case 1 : game(pegs, dups);
        case 2 : settings(pegs, dups);menu(pegs, dups);
        case 3 : exit(0);
    }
}

void lab(int &pegs, bool &dups)
{
    //Counters
    int fourRight=0;
    int threeRight=0;
    int twoRight=0;
    int oneRight=0;
    int zeroRight=0;
    int fourWrong=0;
    int threeWrong=0;
    int twoWrong=0;
    int oneWrong=0;
    int zeroWrong=0;
    int fourSum=0;
    int threeSum=0;
    int twoSum=0;
    int oneSum=0;
    int zeroSum=0;
    
    //Generate random code using parameters
    pegs = 4; //reset to 4 pegs for the purposes of this lab portion
    int code[pegs];
    int guess[pegs];
    bool dupCheck = false;
    int k=ATTEMPTS-1;
    
    if(!dups)
    {
        do
        {
            dupCheck=false;
            for(int i=0;i<pegs;i++)
                code[i]=1+(rand()%8);
            for(int i=0;i<pegs;i++)
                for(int j=0;j<pegs;j++)
                    if((code[i]==code[j])&&(i!=j))
                        dupCheck=true;
        }while(dupCheck);
    }
    else if(dups)
        for(int i=0;i<pegs;i++)
            code[i]=1+(rand()%8);
    
    
    //Initialize game board arrays
    int   board[ATTEMPTS][pegs];
    int   response[ATTEMPTS][pegs];
    bool  correct[pegs];
    int   numberOf[9];
    bool  winCheck=false;
    int   correctPegs;
    int   closePegs;
    bool  closeCheck;
    bool  inputCheck;
    const string color[9]={"00","Rd","Gn","Bl","Ye","Br","Og","Bk","Wh"};
    
    //fill board with zeros
    for(int i=0;i<ATTEMPTS;i++)
        for(int j=0;j<pegs;j++)
            board[i][j]=0;
    
    //fill response with zeros
    for(int i=0;i<ATTEMPTS;i++)
        for(int j=0;j<pegs;j++)
            response[i][j]=0;
    
    int gcode;
    //Ask for overide code?
    do
    {
        cout<<"Auto Generate Code?(y=1/n=0): ";
        cin>>gcode;
    }while(gcode<0||gcode>1);
    
    if (!gcode)
    {
        cout<<"Please enter 4 digit code: ";
        for(int i=0;i<4;i++)
        {
            cout<<"Digit "<<i+1<<": ";
            cin>>code[i];
        }
    }
    
    //fill starting point with zeros
    for(int i=0;i<4;i++)
    {
        guess[i]=0;
    }
    
    cout<<"Code   Guess  #right  #right in wrong spot   Sum\n";
    for(int h=0;h<10000;h++)
    {
        //outputing code
        for(int i=0;i<4;i++)
            cout<<code[i];
        cout<<"   ";
        
        
        
        //outputing guess
        for(int i=0;i<4;i++)
            cout<<guess[i];
        cout<<"     ";
        
        //check inputs
        correctPegs=0;
        closePegs=0;
        for(int i=0;i<pegs;i++)
            correct[i]=false;
        for(int i=0;i<9;i++)
            numberOf[i]=0;
        if(!dups)
        {
            for(int i=0;i<pegs;i++)
            {
                
                if(guess[i]==code[i])
                {
                    correctPegs++;
                    correct[i]=true;
                }
            }
            for(int i=0;i<pegs;i++)
            {
                closeCheck = false;
                if(!correct[i])
                {
                    for(int j=0;j<pegs;j++)
                    {
                        if((guess[i]==code[j])&&(!correct[j]))
                            closeCheck = true;
                    }
                    if(closeCheck)
                        closePegs++;
                }
            }
        }
        else if(dups)
        {
            for(int i=0;i<pegs;i++)
            {
                if(code[i]==1)
                    numberOf[1]++;
                else if(code[i]==2)
                    numberOf[2]++;
                else if(code[i]==3)
                    numberOf[3]++;
                else if(code[i]==4)
                    numberOf[4]++;
                else if(code[i]==5)
                    numberOf[5]++;
                else if(code[i]==6)
                    numberOf[6]++;
                else if(code[i]==7)
                    numberOf[7]++;
                else if(code[i]==8)
                    numberOf[8]++;
            }
            for(int i=0;i<pegs;i++)
            {
                if(guess[i]==code[i])
                {
                    correctPegs++;
                    correct[i]=true;
                    numberOf[guess[i]]--;
                }
            }
            for(int i=0;i<pegs;i++)
            {
                closeCheck = false;
                if(!correct[i])
                {
                    for(int j=0;j<pegs;j++)
                    {
                        if((guess[i]==code[j])&&(!correct[j]))
                            if(numberOf[code[j]]>0)
                            {
                                closeCheck = true;
                                numberOf[code[j]]--;
                            }
                    }
                    if(closeCheck)
                        closePegs++;
                }
            }
        }
        
        
        cout<<correctPegs<<"           "<<closePegs<<"                 "
                <<correctPegs+closePegs<<endl;
        if(correctPegs==4)
            fourRight++;
        if(correctPegs==3)
            threeRight++;
        if(correctPegs==2)
            twoRight++;
        if(correctPegs==1)
            oneRight++;
        if(correctPegs==0)
            zeroRight++;
        if(closePegs==4)
            fourWrong++;
        if(closePegs==3)
            threeWrong++;
        if(closePegs==2)
            twoWrong++;
        if(closePegs==1)
            oneWrong++;
        if(closePegs==0)
            zeroWrong++;
        if((correctPegs+closePegs)==4)
            fourSum++;
        if((correctPegs+closePegs)==3)
            threeSum++;
        if((correctPegs+closePegs)==2)
            twoSum++;
        if((correctPegs+closePegs)==1)
            oneSum++;
        if((correctPegs+closePegs)==0)
            zeroSum++;
        
        //incrementing guess array
        if(guess[3]==9)
        {
            if(guess[2]==9)
            {
                if(guess[1]==9)
                {
                    if(guess[0]==9)
                    {
                        //then we are done
                    }
                    else
                    {
                        guess[0]++;
                        guess[1]=0;
                        guess[2]=0;
                        guess[3]=0;
                    }
                }
                else
                {
                    guess[1]++;
                    guess[2]=0;
                    guess[3]=0;
                }
            }
            else
            {
                guess[2]++;
                guess[3]=0;
            }
        }
        else
            guess[3]++;
        
    }
    
    //results
    cout<<"Results:"<<endl;
    cout<<"3A) 4 Right: "<<fourRight<<endl;
    cout<<"3B) 4 Wrong: "<<fourWrong<<endl;
    cout<<"3C) 4 Sum:   "<<fourSum<<endl;
    cout<<"4A) 3 Right: "<<threeRight<<endl;
    cout<<"4B) 3 Wrong: "<<threeWrong<<endl;
    cout<<"4C) 3 Sum:   "<<threeSum<<endl;
    cout<<"5A) 2 Right: "<<twoRight<<endl;
    cout<<"5B) 2 Wrong: "<<twoWrong<<endl;
    cout<<"5C) 2 Sum:   "<<twoSum<<endl;
    cout<<"6B) 1 Right: "<<oneRight<<endl;
    cout<<"6A) 1 Wrong: "<<oneWrong<<endl;
    cout<<"6C) 1 Sum:   "<<oneSum<<endl;
    cout<<"7A) 0 Right: "<<zeroRight<<endl;
    cout<<"7B) 0 Wrong: "<<zeroWrong<<endl;
    cout<<"7C) 0 Sum:   "<<zeroSum<<endl;
    
    
    
    menu(pegs, dups);
}

void game(int &pegs, bool &dups)
{
    //Generate random code using parameters
    int code[pegs];
    bool dupCheck = false;
    int k=ATTEMPTS-1;
    
    if(!dups)
    {
        do
        {
            dupCheck=false;
            for(int i=0;i<pegs;i++)
                code[i]=1+(rand()%8);
            for(int i=0;i<pegs;i++)
                for(int j=0;j<pegs;j++)
                    if((code[i]==code[j])&&(i!=j))
                        dupCheck=true;
        }while(dupCheck);
    }
    else if(dups)
        for(int i=0;i<pegs;i++)
            code[i]=1+(rand()%8);
    
    
    //Initialize game board arrays
    int   board[ATTEMPTS][pegs];
    int   response[ATTEMPTS][pegs];
    bool  correct[pegs];
    int   numberOf[9];
    bool  winCheck=false;
    int   correctPegs;
    int   closePegs;
    bool  closeCheck;
    bool  inputCheck;
    const string color[9]={"00","Rd","Gn","Bl","Ye","Br","Og","Bk","Wh"};
    
    //fill board with zeros
    for(int i=0;i<ATTEMPTS;i++)
        for(int j=0;j<pegs;j++)
            board[i][j]=0;
    
    //fill response with zeros
    for(int i=0;i<ATTEMPTS;i++)
        for(int j=0;j<pegs;j++)
            response[i][j]=0;
    
    //Begin game loop here
    
    while(!winCheck)
    {   
        //output game board
        //_____________________________________
        //||Rd|Gn|Bl|Ye|Br|Og|Bk|Wh||000000||
        //||-----------------------||0000||
        //||-----------------------||----||
        //top of game board
        cout<<"\n\n__";
        for(int i=0;i<pegs;i++)
            cout<<"___";
        cout<<"_______";
        if((pegs>4)&&(pegs<8))
            cout<<"__ Key: 0 = No Color Found\n";
        else if(pegs>6)
            cout<<"____ Key: 0 = No Color Found\n";
        else
            cout<<" Key: 0 = No Color Found"<<endl;
        //pieces of game board
        for(int i=0;i<ATTEMPTS;i++)
        {
            cout<<"||";
            for(int j=0;j<pegs;j++)
                cout<<color[board[i][j]]<<"|";
            cout<<"|";
            for(int j=0;j<pegs;j++)
                cout<<response[i][j];
            cout<<"||";
            if(i==0)
                cout<<"      1 = Color Found Wrong Pos\n";
            else if(i==1)
                cout<<"      2 = Color Found Right Pos\n";
            else
                cout<<endl;
        }
        
        //bottom of game board
        cout<<"͞͞";
        for(int i=0;i<pegs;i++)
            cout<<"͞͞͞";
        cout<<"͞͞͞͞͞͞͞";
        if((pegs>4)&&(pegs<8))
            cout<<"͞͞\n";
        else if(pegs>6)
            cout<<"͞͞͞͞\n";
        else
            cout<<endl;
        
        //ask for input
        for(int i=0;i<pegs;i++)
        {
            cout<<"1=Rd,2=Gn,3=Bl,4=Ye,5=Br,6=Og,7=Bk,8=Wh"<<endl;
            do
            {
                inputCheck=true;
                cout<<"Please enter color "<<i+1<<": ";
                cin>>board[k][i];
                if((board[k][i]<1)||(board[k][i]>8))
                {
                    cout<<"Invalid Input! Try again!"<<endl;
                    inputCheck=false;
                }
            }while(!inputCheck);
        }
        
        //check input
        correctPegs=0;
        closePegs=0;
        for(int i=0;i<pegs;i++)
            correct[i]=false;
        for(int i=0;i<9;i++)
            numberOf[i]=0;
        if(!dups)
        {
            for(int i=0;i<pegs;i++)
            {
                
                if(board[k][i]==code[i])
                {
                    correctPegs++;
                    correct[i]=true;
                }
            }
            for(int i=0;i<pegs;i++)
            {
                closeCheck = false;
                if(!correct[i])
                {
                    for(int j=0;j<pegs;j++)
                    {
                        if((board[k][i]==code[j])&&(!correct[j]))
                            closeCheck = true;
                    }
                    if(closeCheck)
                        closePegs++;
                }
            }
        }
        else if(dups)
        {
            for(int i=0;i<pegs;i++)
            {
                if(code[i]==1)
                    numberOf[1]++;
                else if(code[i]==2)
                    numberOf[2]++;
                else if(code[i]==3)
                    numberOf[3]++;
                else if(code[i]==4)
                    numberOf[4]++;
                else if(code[i]==5)
                    numberOf[5]++;
                else if(code[i]==6)
                    numberOf[6]++;
                else if(code[i]==7)
                    numberOf[7]++;
                else if(code[i]==8)
                    numberOf[8]++;
            }
            for(int i=0;i<pegs;i++)
            {
                if(board[k][i]==code[i])
                {
                    correctPegs++;
                    correct[i]=true;
                    numberOf[board[k][i]]--;
                }
            }
            for(int i=0;i<pegs;i++)
            {
                closeCheck = false;
                if(!correct[i])
                {
                    for(int j=0;j<pegs;j++)
                    {
                        if((board[k][i]==code[j])&&(!correct[j]))
                            if(numberOf[code[j]]>0)
                            {
                                closeCheck = true;
                                numberOf[code[j]]--;
                            }
                    }
                    if(closeCheck)
                        closePegs++;
                }
            }
        }
        //set response
//        cout<<"\n\nCORRECT PEGS="<<correctPegs<<endl; // DEBUGGING CODE
//        cout<<"CLOSE PEGS="<<closePegs<<endl<<endl;   // DEBUGGING CODE
        for(int i=0;i<correctPegs;i++)
            response[k][i]=2;
        for(int i=correctPegs;i<(correctPegs+closePegs);i++)
            response[k][i]=1;
                
        //increment attempt counter
        k--;
        
        //Game Over Win
        if(correctPegs==pegs)
        {
            cout<<"\nCorrect! You Win!";
            cout<<"Code: ";
            for(int i=0;i<pegs;i++)
                cout<<color[code[i]]<<" ";
            cout<<endl<<endl;
            menu(pegs, dups);
        }
        else if(k<0)
        {
            cout<<"Out of Tries!"<<endl;
            cout<<"Code: ";
            for(int i=0;i<pegs;i++)
                cout<<color[code[i]]<<" ";
            cout<<endl<<endl;
            menu(pegs, dups);
        }
    }
}

void settings(int &pegs, bool &dups)
{
    int setChoice, pegChoice,dupChoice;
    bool setCheck = true;
    bool pegCheck = true;
    bool setDupCheck = true;
    cout<<"\n\nSettings: \n";
    while(setCheck)
    {   
        cout<<"1: Change Number of Pegs\n";
        cout<<"2: Allow or Disallow Duplicates\n";
        cout<<"3: Return to Menu\n";
        cout<<"->";
        cin>>setChoice;
        if(setChoice<1||setChoice>3)
        {
            cout<<"Invalid try again.\n";
        }
        else
            setCheck=false;
    }
    switch(setChoice)
    {
        case 1 :
            while(pegCheck)
            {
                cout<<"\n\nCurrent Setting: "<<pegs<<endl;
                cout<<"Choose Peg Number"<<endl;
                cout<<"1 : Four  Pegs"<<endl;
                cout<<"2 : Six   Pegs"<<endl;
                cout<<"3 : Eight Pegs"<<endl;
                cout<<"->";
                cin>>pegChoice;
                if(pegChoice<1||pegChoice>3)
                    cout<<"Invalid try again.\n";
                else
                    pegCheck=false;
            }
            switch(pegChoice)
            {
                case 1 : pegs=4; break;
                case 2 : pegs=6; break;
                case 3 : pegs=8;
            }
            settings(pegs, dups);
        case 2 :
            while(setDupCheck)
            {
                cout<<"\n\nCurrent Setting: ";
                if(dups)
                    cout<<"True"<<endl;
                else
                    cout<<"False"<<endl;
                cout<<"Allow duplicate colors in code?"<<endl;
                cout<<"(1=True : 0=False)->";
                cin>>dupChoice;
                if(dupChoice<0||dupChoice>1)
                    cout<<"Invalid try again.\n";
                else
                    setDupCheck=false;
            }
            dups=dupChoice;
            settings(pegs, dups);
        case 3 : menu(pegs, dups);
    }
}