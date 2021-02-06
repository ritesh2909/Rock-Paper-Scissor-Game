#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int generateRandomNumber(int n)
{
    srand(time(NULL));  //srand takes the seed as input and is defined inside stdlib.h
    return rand() % n;
}

int igreater(char char1, char char2)
{
//returns 1 if c1>c2 and 0 otherwise . If c1==c2 it will return -1

    if(char1==char2)
    {
        return -1;
    }

    else if((char1 == 'R') && (char2=='S'))
    {
        return 1;
    }
    else if((char2 == 'R') && (char1=='S'))
    {
        return 0;
    }


    else if((char1 == 'P') && (char2=='R'))
    {
        return 1;
    }
    else if((char2 == 'P') && (char1=='R'))
    {
        return 0;
    }


    else if((char1 == 'S') && (char2=='P'))
    {
        return 1;
    }
    
    else 
    {
        return 0;
    }
}


int main()
{

        int playerscore = 0,compscore = 0,temp;
        char playerchar , compchar;
        char dict[] = { 'R','P','S' };


    cout<<"Welcome to the Rock-Paper-Scissor game\n\n";
    

    for(int i = 0 ; i < 3 ; i++)
    {
        // player's turn, input by user

        cout<<"\nPlayer 1's Turn\n";
        cout<<"1. For Rock\n2. For Paper\n3. For Scissor\t";
        cin>>temp;
        getchar();
        playerchar = dict[temp-1];
        cout<<"\nYou Choose\t"<<playerchar;

        // computer's turn generated

        cout<<"\n\nComputer's Turn\n\n";
        cout<<"1. For Rock\n2. For Paper\n3. For Scissor\n";
        temp = generateRandomNumber(3) +1;
        compchar = dict[temp-1];
        cout<<"\nCPU Choose\t"<<compchar;

 
        if (igreater(compchar, playerchar)==1)
        {
            compscore++;
            cout<<"\nCPU Got It !!\n";
        }
        else if(igreater(compchar, playerchar)==-1)
        {
            compscore++;
            playerscore++;
            cout<<"\nIt's a Draw !!\n";
        }

        else
        {
            playerscore++;
            cout<<"\nYou Got It !!\n";
        }


        cout<<"\nYOU: "<<playerscore<<"\tCPU: "<<compscore<<endl;

    }
   
        if(playerscore>compscore)
        {
            cout<<"\nYOU WIN\n";
            cout<<"CONGRATULATIONS\n";
        }

        else if(playerscore==compscore)
        {
            cout<<"\nIT'S A DRAW\n";
        }

        else
        {
            cout<<"\n COMPUTER WINS\n";
        }

    return 0;
}
