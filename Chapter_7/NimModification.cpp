//
//  NimModification.cpp
//  Ch.7_Coursework
//
//  Created by Jesse Furmanek on 10/17/13.
//
//

#include "NimModification.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include <iostream>
#include "error.h"

using namespace std;

//gives the maximum and minimum score that is possible, symmetrical on 0

const int MAX_MOVE = 4;
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


void PlayNimMod();
moveT NimModFindBestMove(stateT state, int depth, int & Rating);
stateT NimModNewGame();
void NimModDisplayGame(stateT state);
void NimModDisplayMove(moveT move);
moveT NimModGetUserMove(stateT state);
moveT NimModChooseComputerMove(stateT state);
Vector <moveT> NimModGenerateMoveList(stateT state, Vector<moveT> moveList);
bool NimModMoveIsLegal(moveT move, stateT state);
void NimModMakeMove(stateT & state, moveT move);
void NimModRetractMove(stateT & state, moveT move);
bool NimModGameIsOver(stateT state);
void NimModAnnounceResult(stateT state);
playerT NimModWhoseTurn(stateT state);
playerT NimModOpponent(playerT player);
int NimModEvaluatePosition(stateT state, int depth);
int NimModEvaluateStaticPosition(stateT state, int depth);

void PlayNimMod(){
    stateT state = NimModNewGame();  //begin the game with the max number of coins
    moveT move;
    while (!NimModGameIsOver(state)){
        NimModDisplayGame(state);
        switch (NimModWhoseTurn(state)){
            case Human:
                move = NimModGetUserMove(state);  //if its the user's turn, get the user's input
                break;
            case Computer:
                move = NimModChooseComputerMove(state);
                NimModDisplayMove(move);
                break;
        }
        NimModMakeMove(state,move);  //this function updates the state
        
    }
    NimModAnnounceResult(state);
    
}


stateT NimModNewGame(){
    stateT state;
    state.numCoins = 13;
    state.whoseTurn = FIRST_PLAYER;  //set's the turn to the constant FIRST_PLAYER
    state.turnsTaken = 0;  //begins the game with 0 turns taken
    return state;
}

moveT NimModFindBestMove (stateT state, int depth, int & rating){
    Vector<moveT> moveList;  //create a list of possible moves
    
    moveList = NimModGenerateMoveList(state, moveList);  //generate the move list based on the current state
    
    int nMoves = moveList.size();  //store the number of possible moves, derived using the size of the vector.
    
    if(nMoves==0)error("No moves available");
    
    moveT bestMove;
    
    int minRating = WINNING_POSITION +1;  //using winning position +1 assures that the minRating can catch the winning position
    
    for(int x=0; x<nMoves && minRating != LOSING_POSITION; x++){
        
        moveT move = moveList[x];  //create a list of possible moves
        
        
        NimModMakeMove(state, move);  //make the first move
        
        int curRating = NimModEvaluatePosition(state, depth+1);  //begin recursive call
        
        if (curRating < minRating){
            bestMove=move;
            minRating=curRating;
        }
        
        NimModRetractMove(state, move);  //adds the coins back into the pile
        
    }
    
    rating = -minRating;
    
    return bestMove;
}

int NimModEvaluatePosition(stateT state, int depth){
    int rating;
    if(NimModGameIsOver(state) || depth==MAX_DEPTH){  //if the max depth of recursion has been reached.
        return NimModEvaluateStaticPosition(state, depth);
    }
    NimModFindBestMove(state,depth,rating);  //recursive call back to FindBestMove
    
    cout<<rating<<endl;
    return rating;
}

int NimModEvaluateStaticPosition(stateT state, int depth){
    if(state.numCoins==1){  //if there is 1 coin left, that player loses
        return LOSING_POSITION;
    }if(depth ==MAX_DEPTH){
        return  NEUTRAL_POSITION;
    }
    return WINNING_POSITION;
}


moveT NimModGetUserMove(stateT state){
    cout<<"Your move."<<endl;
    moveT move;
    while(true){
        cout<< "How many coins would you like to take?"<<flush;
        move= getInteger();
        if (NimModMoveIsLegal(move, state)) break;
        cout<<"That move is illegal.  Try again"<<endl;
    }
    
    return move;
}

moveT NimModChooseComputerMove(stateT state){
    int rating=0;
    cout<< "My move. "<<endl;
    
    return NimModFindBestMove(state,0,rating);  //depth begins at zero; program starts at the top of the game tree
    
}

Vector<moveT> NimModGenerateMoveList(stateT state, Vector<moveT> moveList){
    for(int x = 1; x<MAX_MOVE+1; x++){
        moveT move = x;
        if (NimModMoveIsLegal(move, state)){
            moveList.add(move);  //add all legal moves to moves list
        }
    }
    return moveList;
}

bool NimModMoveIsLegal(moveT move, stateT state){
    if(move<0 || move>MAX_MOVE || (state.numCoins-move)<1) return false;  //if any of these cases are true, return false
    
    return true;  //else return true.
}

void NimModMakeMove(stateT & state, moveT move){
    state.numCoins -= move; //subtract number of coins from ile
    state.whoseTurn = NimModOpponent(state.whoseTurn);  //switch player
    state.turnsTaken++; // increment turns
    
}

void NimModRetractMove(stateT & state, moveT move){  //used to reverse the game state after 'playing' through the game tree to find the best move
    state.numCoins += move;
    state.whoseTurn = NimModOpponent(state.whoseTurn);
}

bool NimModGameIsOver(stateT state){  //return true if there are no coins left
    return (state.numCoins) == 1 ;
}



playerT NimModWhoseTurn(stateT state){   //not exactly sure why its necessary to make a separate function for this
    return state.whoseTurn;
}

playerT NimModOpponent(playerT player){
    return (player == Human) ? Computer : Human;
}


void NimModAnnounceResult(stateT state){
    if(state.whoseTurn==Computer){
        cout<<"I lose."<<endl;
    }else{
        cout<<"You lose."<<endl;
    }
}

void NimModDisplayGame (stateT state){
    if (NimModGameIsOver(state)){
        cout<<"Game Over!"<<endl<<endl;
    }else{
        cout<<"There are "<<state.numCoins<<" coins left."<<endl<<endl;
    }
}


void NimModDisplayMove(moveT move){
    cout<<"I'll take  "<<move<<" coins"<<endl;
}
