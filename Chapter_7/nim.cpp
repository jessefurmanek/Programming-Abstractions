//
//  nim.cpp
//  Ch.7_Coursework
//
//


#include <iostream>
#include "console.h"
#include "simpio.h"
#include "nim.h"
using namespace std;


const int N_COINS = 7;  //= initial number of coins
const int MAX_MOVE=3;  //maximum number of coins that a player may take
const int NO_GOOD_MOVE = -1;  //sentinel (symbolic indicator) indicating that no good move is available



enum playerT { Human, Computer };  //creates an enuerated type of Player, that distiguishes the turns for the human player

void GiveInstructions();
void AnnounceWinner(int nCoins, playerT whoseTurn);
int GetUserMove(int nCoins);
bool MoveIsLegal(int nTaken, int nCoins);
int ChooseComputerMove(int nCoins);
int FindGoodMove(int nCoins);
bool IsBadPosition(int nCoins);
void RunNim();



void RunNim(){
    int nCoins, nTaken;
    playerT whoseTurn;
    
    GiveInstructions();
    nCoins = N_COINS;
    whoseTurn = Human;
    while (nCoins>1){
        cout<<"There are " <<nCoins<< " coins in the pile."<<endl;
        switch(whoseTurn){
            case Human:
                nTaken = GetUserMove(nCoins);  //If human, get number of coins from player input
                whoseTurn = Computer;  //switch the player to the computer;
                break;
            case Computer:
                nTaken = ChooseComputerMove(nCoins);
                whoseTurn = Human;
                break;
        }
        nCoins -=nTaken;
    }
    AnnounceWinner(nCoins, whoseTurn);
}

void GiveInstructions() {
    cout << "Hello.  Welcome to the game of nim."  << endl;
    cout << "In this game, we will start with a pile of" << endl;
    cout << N_COINS  << " coins on the table. " << endl;
    cout << "On each turn, you" << endl;
    cout << "and I will alternately take between 1 and" << endl;
    cout << MAX_MOVE << " coins from the table." << endl;
    cout << "The player who" << endl;
    cout << "takes the last coin loses." << endl;
    cout << endl;
}

void AnnounceWinner(int nCoins, playerT whoseTurn){
    if (nCoins == 0){
        cout<<"You took the last coin.  You Lose."<<endl;
    }else{
        cout<<"There is only one coin left." <<endl;
        switch(whoseTurn){
            case Human: cout<< "I win." <<endl; break;
            case Computer: cout<< "I lose." <<endl; break;
        }
    }
}

int GetUserMove(int nCoins){  //this function take the number of coins left in the pile as its argument, and returns the pile sans user chosen coins.
    int nTaken, limit;
    
    while(true){
        cout<<"How many coins will you take?"<<endl;
        nTaken = getInteger();
        if(MoveIsLegal(nTaken, nCoins)) break;
        
        limit = (nCoins<MAX_MOVE) ? nCoins:MAX_MOVE;  //if the user chooses a number greater than 3, warn and advise the user of legal plays
        
        cout<<"Please choose a number between 1 and "<<limit<<endl;
        cout<<"There are "<<nCoins<<" left in the pile."<<endl;
    }
    return nTaken;
    
}


bool MoveIsLegal(int nTaken, int nCoins){
    return (nTaken>0 && nTaken<nCoins && nTaken<=MAX_MOVE);  //return true is move is legal i.e. non-negative and < max moves and available coins
}

int ChooseComputerMove(int nCoins){
    int nTaken = FindGoodMove(nCoins);  //chooses the number of coins taken by the computer by passing the #coins left in the pile in the FindGoodMove function.
    
    if (nTaken == NO_GOOD_MOVE) nTaken = 1;  //if there's no good move for the computer, Computer takes one
    
    
    cout<<"I took "<<nTaken<<" coins"<<endl;
    
    return nTaken;  //return the number of coins taken
}

bool IsBadPosition(int nCoins){  //returns true if only one coin remains (i.e. the player is in a bad position)
    if(nCoins == 1) return true;  //it's a bad position if there is only one coin left
            
    return FindGoodMove(nCoins) == NO_GOOD_MOVE;  //call FindGoodMove, if it returns NO_GOOD_MOVE, its a bad position (returns true). else its a good position (returns false)
}

int FindGoodMove(int nCoins){
    
    for(int nTaken=1; nTaken<=MAX_MOVE; nTaken++){
        
        if (IsBadPosition(nCoins-nTaken)) return nTaken;  /*if the nCoins taken returns a bad position i.e. the opponent would be in a bad position, return the int value */
    }
    return NO_GOOD_MOVE;
}









