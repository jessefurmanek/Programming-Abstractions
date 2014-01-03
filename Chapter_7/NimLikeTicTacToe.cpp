//
//  NimLikeTicTacToe.cpp
//  Ch.7_Coursework
//
//  Created by Jesse Furmanek on 10/15/13.
//
//


/*
 Rewrite the simple nim game from Figure 7-5 so that it uses the more general structure developed for tic-tac-toe. Your new program should not change the implementations of the functions main, FindBestMove, and EvaluatePosition, which should remain exactly as they appear in Figure 7-6. Your job is to come up with appropriate definitions of stateT, moveT, and the various game-specific functions in the implementation so that the program plays nim instead of tic-tac-toe.
 */

#include "NimLikeTicTacToe.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include <iostream>
#include "error.h"

using namespace std;

//gives the maximum and minimum score that is possible, symmetrical on 0

const int MAX_MOVE = 3;
const int WINNING_POSITION  = 10;
const int NEUTRAL_POSITION  = 0;
const int LOSING_POSITION   = -WINNING_POSITION;
const int NO_GOOD_MOVE = -1;

enum playerT { Human, Computer };
/*
 * Type: moveT
 * -----------
 * For any particular game, the moveT type must keep track of the
 * information necessary to describe a move.  For tic-tac-toe,
 * a moveT is simply an integer identifying the number of one of
 * the nine squares, as follows:
 */

typedef int moveT;  //move should remain an integer-- it represents the number of pieces taken

struct stateT{  //defines the game state
    int numCoins;
    playerT whoseTurn;
    int turnsTaken;
    
};

const int MAX_DEPTH = 9;  //the maximum depth of the recursion
const playerT FIRST_PLAYER = Computer;  //assigning a playerT constant to set the Computer as the first player


void PlayNim();
moveT NimFindBestMove(stateT state, int depth, int & Rating);
stateT NimNewGame();
void NimDisplayGame(stateT state);
void NimDisplayMove(moveT move);
moveT NimGetUserMove(stateT state);
moveT NimChooseComputerMove(stateT state);
Vector <moveT> NimGenerateMoveList(stateT state, Vector<moveT> moveList);
bool NimMoveIsLegal(moveT move, stateT state);
void NimMakeMove(stateT & state, moveT move);
void NimRetractMove(stateT & state, moveT move);
bool NimGameIsOver(stateT state);
void NimAnnounceResult(stateT state);
playerT NimWhoseTurn(stateT state);
playerT NimOpponent(playerT player);
int NimEvaluatePosition(stateT state, int depth);
int NimEvaluateStaticPosition(stateT state, int depth);

void PlayNim(){
    stateT state = NimNewGame();  //begin the game with the max number of coins
    moveT move;
    while (!NimGameIsOver(state)){
        NimDisplayGame(state);
        switch (NimWhoseTurn(state)){
            case Human:
                move = NimGetUserMove(state);  //if its the user's turn, get the user's input
                break;
            case Computer:
                move = NimChooseComputerMove(state);
                NimDisplayMove(move);
                break;
        }
        NimMakeMove(state,move);  //this function updates the state
        
    }
    NimAnnounceResult(state);
    
}


stateT NimNewGame(){
    stateT state;
    state.numCoins = 13;
    state.whoseTurn = FIRST_PLAYER;  //set's the turn to the constant FIRST_PLAYER
    state.turnsTaken = 0;  //begins the game with 0 turns taken
    return state;
}

moveT NimFindBestMove (stateT state, int depth, int & rating){
    Vector<moveT> moveList;  //create a list of possible moves
    
    moveList = NimGenerateMoveList(state, moveList);  //generate the move list based on the current state
    
    int nMoves = moveList.size();  //store the number of possible moves, derived using the size of the vector.
    
    if(nMoves==0)error("No moves available");
    
    moveT bestMove;
    
    int minRating = WINNING_POSITION +1;  //using winning position +1 assures that the minRating can catch the winning position
    
    for(int x=0; x<nMoves && minRating != LOSING_POSITION; x++){
        
        moveT move = moveList[x];  //create a list of possible moves
        
        
        NimMakeMove(state, move);  //make the first move
        
        int curRating = NimEvaluatePosition(state, depth+1);  //begin recursive call
    
        if (curRating < minRating){
            bestMove=move;
            minRating=curRating;
        }
        
        NimRetractMove(state, move);  //adds the coins back into the pile
        
    }
    
    rating = -minRating;
 
    return bestMove;
}

int NimEvaluatePosition(stateT state, int depth){
    int rating;
    if(NimGameIsOver(state) || depth==MAX_DEPTH){  //if the max depth of recursion has been reached.
        return NimEvaluateStaticPosition(state, depth);
    }
    NimFindBestMove(state,depth,rating);  //recursive call back to FindBestMove
    
    cout<<rating<<endl;
    return rating;
}

int NimEvaluateStaticPosition(stateT state, int depth){
    if(state.numCoins==1){  //if there is 1 coin left, that player loses
          return LOSING_POSITION;
    }if(depth ==MAX_DEPTH){
       return  NEUTRAL_POSITION;
    }
     return WINNING_POSITION;
}


moveT NimGetUserMove(stateT state){
    cout<<"Your move."<<endl;
    moveT move;
    while(true){
        cout<< "How many coins would you like to take?"<<flush;
        move= getInteger();
        if (NimMoveIsLegal(move, state)) break;
        cout<<"That move is illegal.  Try again"<<endl;
    }
    
    return move;
}

moveT NimChooseComputerMove(stateT state){
    int rating=0;
    cout<< "My move. "<<endl;
    
    return NimFindBestMove(state,0,rating);  //depth begins at zero; program starts at the top of the game tree
    
}

Vector<moveT> NimGenerateMoveList(stateT state, Vector<moveT> moveList){
    for(int x = 1; x<MAX_MOVE+1; x++){
        moveT move = x;
        if (NimMoveIsLegal(move, state)){
            moveList.add(move);  //add all legal moves to moves list
        }
    }
      return moveList;
}

bool NimMoveIsLegal(moveT move, stateT state){
    if(move<0 || move>MAX_MOVE || (state.numCoins-move)<1) return false;  //if any of these cases are true, return false
    
    return true;  //else return true.
}

void NimMakeMove(stateT & state, moveT move){
    state.numCoins -= move; //subtract number of coins from ile
    state.whoseTurn = NimOpponent(state.whoseTurn);  //switch player
    state.turnsTaken++; // increment turns
    
}

void NimRetractMove(stateT & state, moveT move){  //used to reverse the game state after 'playing' through the game tree to find the best move
    state.numCoins += move;
    state.whoseTurn = NimOpponent(state.whoseTurn);
}

bool NimGameIsOver(stateT state){  //return true if there are no coins left
    return (state.numCoins) == 1 ;
}



playerT NimWhoseTurn(stateT state){   //not exactly sure why its necessary to make a separate function for this
    return state.whoseTurn;
}

playerT NimOpponent(playerT player){
    return (player == Human) ? Computer : Human;
}


void NimAnnounceResult(stateT state){
    if(state.whoseTurn==Computer){
        cout<<"I lose."<<endl;
    }else{
        cout<<"You lose."<<endl;
    }
}

void NimDisplayGame (stateT state){
    if (NimGameIsOver(state)){
        cout<<"Game Over!"<<endl<<endl;
    }else{
        cout<<"There are "<<state.numCoins<<" coins left."<<endl<<endl;
    }
}


void NimDisplayMove(moveT move){
    cout<<"I'll take  "<<move<<" coins"<<endl;
}

