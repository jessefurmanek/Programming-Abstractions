//
//  ThreePileNim.cpp
//  Ch.7_Coursework
//
//  Created by Jesse Furmanek on 11/3/13.
//
//

#include "ThreePileNim.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include <iostream>
#include "error.h"


const int MAX_MOVE = 3;
const int WINNING_POSITION  = 10;
const int NEUTRAL_POSITION  = 0;
const int LOSING_POSITION   = -WINNING_POSITION;
const int NO_GOOD_MOVE = -1;

enum playerT { Human, Computer };  //create an enumerated class for the players

struct stateT{  //defines the game state
    int pileOne;
    int pileTwo;
    int pileThree;
    int numCoins;
    playerT whoseTurn;
};

struct moveT{
    int pile;  //moveT keeps track of which pile the player is taking from
    int coinsTaken;
};

const int MAX_DEPTH = 10;  //the maximum depth of the recursion
const playerT FIRST_PLAYER = Computer;  //assigning a playerT constant to set the Computer as the first player

void PlayNimThreePile();
moveT ThreePileNimFindBestMove(stateT state, int depth, int & Rating);
stateT ThreePileNimNewGame();
void ThreePileNimDisplayGame(stateT state);
void ThreePileNimDisplayMove(moveT move);
moveT ThreePileNimGetUserMove(stateT state);
moveT ThreePileNimChooseComputerMove(stateT state);
Vector <moveT> ThreePileNimGenerateMoveList(stateT state, Vector<moveT> moveList);
bool ThreePileNimMoveIsLegal(moveT move, stateT state);
void ThreePileNimMakeMove(stateT & state, moveT move);
void ThreePileNimRetractMove(stateT & state, moveT move);
bool ThreePileNimGameIsOver(stateT state);
void ThreePileNimAnnounceResult(stateT state);
playerT ThreePileNimWhoseTurn(stateT state);
playerT ThreePileNimOpponent(playerT player);
int ThreePileNimEvaluatePosition(stateT state, int depth);
int ThreePileNimEvaluateStaticPosition(stateT state, int depth);
void PrintMoveList( Vector<moveT> moveList);
bool TwoPilesBlank(stateT state);


void PlayThreePileNim(){
    stateT state = ThreePileNimNewGame();  //begin the game with the max number of coins
    cout<<"In this version of nim, the coins are not combined into a single pile but are instead arranged in three rows. A move in this game consists of taking any number of coins, subject to the condition that all the coins must come from the same row. The player who takes the last coin loses."<<endl;
    
    moveT move;
    ThreePileNimDisplayGame(state);
    
    while (!ThreePileNimGameIsOver(state)){
        switch (ThreePileNimWhoseTurn(state)){
            case Human:
                move = ThreePileNimGetUserMove(state);  //if its the user's turn, get the user's input
                break;
            case Computer:
                move = ThreePileNimChooseComputerMove(state);
                ThreePileNimDisplayMove(move);
                cout<<endl;
                break;
        }
        ThreePileNimMakeMove(state,move);  //this function updates the state and makes a move
        
        ThreePileNimDisplayGame(state);
    }

    ThreePileNimAnnounceResult(state);
}

stateT ThreePileNimNewGame(){  //set the parameters for a new game
    stateT state;
    state.pileOne=5;
    state.pileTwo=4;
    state.pileThree=3;
    state.numCoins= state.pileOne+ state.pileTwo+ state.pileThree;
    state.whoseTurn = FIRST_PLAYER;  //set's the turn to the constant FIRST_PLAYER
    return state;
}



moveT ThreePileNimFindBestMove (stateT state, int depth, int & rating){
    Vector<moveT> moveList;  //create a list of possible moves
    
    moveList = ThreePileNimGenerateMoveList(state, moveList);  //generate the move list based on the current state
    
    
    int nMoves = moveList.size();  //store the number of possible moves, derived using the size of the vector.
   
    
    if(nMoves==0){
        cout<<"NumCoins: "<<state.numCoins<<endl;
        ThreePileNimDisplayGame(state);
        error("No moves available");
    }
    moveT bestMove;
    
    int minRating = WINNING_POSITION +1;  //using winning position +1 assures that the minRating can catch the winning position
    
    for(int x=0; x<nMoves && minRating != LOSING_POSITION; x++){
        
        moveT move = moveList[x];  //create a list of possible moves
        
        ThreePileNimMakeMove(state, move);  //make the first move from the list of possibly moves
        
        int curRating = ThreePileNimEvaluatePosition(state, depth+1);  //begin recursive call
       
        if (curRating < minRating){
            bestMove=move;
            minRating=curRating;
        }
        
        ThreePileNimRetractMove(state, move);  //adds the coins back into the pile
        
    }

    
    rating = -minRating;
    
    return bestMove;
}


int ThreePileNimEvaluatePosition(stateT state, int depth){
    int rating;
    if(ThreePileNimGameIsOver(state) || depth==MAX_DEPTH){  //if the game is over OR the max depth of recursion has been reached.
        return ThreePileNimEvaluateStaticPosition(state, depth);
    }
    
    ThreePileNimFindBestMove(state,depth,rating);  //recursive call back to FindBestMove
    
    return rating;
}

int ThreePileNimEvaluateStaticPosition(stateT state, int depth){
    
    if(state.numCoins==1){  //if there is one coin left
            return LOSING_POSITION;  //don't need to include who's turn it is, the -minRating takes care of that
        
    }else if(depth ==MAX_DEPTH){
        return  NEUTRAL_POSITION;
    }
    return WINNING_POSITION;
}


void ThreePileNimMakeMove(stateT & state, moveT move){
  
    switch(move.pile){
        case 1: state.pileOne-=move.coinsTaken; break;  //subtract number of coins from appropriate pile
        case 2: state.pileTwo-=move.coinsTaken; break;
        case 3: state.pileThree-=move.coinsTaken;break;
        default: error("That's an error");break;
    }
    state.numCoins-=move.coinsTaken;  //subtract number of coins for pile total
    state.whoseTurn = ThreePileNimOpponent(state.whoseTurn);  //switch player
}

void ThreePileNimRetractMove(stateT & state, moveT move){  //used to reverse the game state after 'playing' through the game tree to find the best move
    switch(move.pile){
        case 1: state.pileOne+=move.coinsTaken; break; //subtract number of coins from appropriate pile
        case 2: state.pileTwo+=move.coinsTaken; break;
        case 3: state.pileThree+=move.coinsTaken; break;
        default: error("That's an error"); break;
    }
    state.numCoins+=move.coinsTaken;
    state.whoseTurn = ThreePileNimOpponent(state.whoseTurn);
}


moveT ThreePileNimGetUserMove(stateT state){
    cout<<"Your move."<<endl;
    moveT move;
    while(true){
        cout<< "What pile do you want to take from?"<<flush;
        move.pile= getInteger();
        cout<< "How many coins would you like to take?"<<flush;
        move.coinsTaken= getInteger();
        if (ThreePileNimMoveIsLegal(move, state)) break;
        cout<<"That move is illegal.  Try again"<<endl;
    }
    
    return move;
}

moveT ThreePileNimChooseComputerMove(stateT state){
    int rating=0;
    cout<< "My move. "<<endl;
    
    return ThreePileNimFindBestMove(state,0,rating);  //depth begins at zero; program starts at the top of the game tree
    
}

Vector<moveT> ThreePileNimGenerateMoveList(stateT state, Vector<moveT> moveList){
    moveT move;
    
    for(int x = 1; x<MAX_MOVE+1; x++){  //for each move
        for(int y =1; y<4; y++){  //and for each pile
            move.pile=y;
            move.coinsTaken=x;
            
            if (ThreePileNimMoveIsLegal(move, state)){
                 moveList.add(move);  //add all legal moves to moves list
                
            }

        }
       
    }
    
    return moveList;
}

bool ThreePileNimMoveIsLegal(moveT move, stateT state){
   
    if(!TwoPilesBlank(state)){  //if two piles are not empty, player can take as many coins as are in a pile
        
        if(move.coinsTaken<1 || move.coinsTaken>MAX_MOVE){
            //move must be greater than zero, less than the max move
        
            return false;
        
        }else if(move.pile==1 && (state.pileOne-move.coinsTaken)<0){  //if the move takes more coins than are in the pile which the player is selecting from, return false
            return false;

        }else if(move.pile==2 && (state.pileTwo-move.coinsTaken)<0){
            return false;
            
        }else if(move.pile==3 && (state.pileThree-move.coinsTaken)<0){
            return false;
            
        }else return true;  //else return true.
        
    }else{ //if only onle pile left, player can't take empty pile with move
        if(move.coinsTaken<1 || move.coinsTaken>MAX_MOVE){  //move must be greater than zero, less than the max move
            return false;
            
        }else if(move.pile==1 && (state.pileOne-move.coinsTaken)<1){  //player can't empty the pile
            return false;
            
        }else if(move.pile==2 && (state.pileTwo-move.coinsTaken)<1){
            return false;
            
        }else if(move.pile==3 && (state.pileThree-move.coinsTaken)<1){
            return false;
            
        }else return true;  //else return true.

        
    }
}



bool ThreePileNimGameIsOver(stateT state){  //return true if there is one coin left
    return (state.numCoins) == 1;
}


playerT ThreePileNimWhoseTurn(stateT state){   //not exactly sure why its necessary to make a separate function for this
    return state.whoseTurn;
}

playerT ThreePileNimOpponent(playerT player){
    return (player == Human) ? Computer : Human;
}


void ThreePileNimAnnounceResult(stateT state){
    ThreePileNimDisplayGame(state);

    
    if(state.whoseTurn==Computer){
        cout<<"I lose."<<endl;
    }else{
        cout<<"You lose."<<endl;
    }
}

void ThreePileNimDisplayGame (stateT state){
    cout<<"Pile One: "<<state.pileOne<<endl;
    cout<<"Pile Two: "<<state.pileTwo<<endl;
    cout<<"Pile Three: "<<state.pileThree<<endl<<endl;
}


void ThreePileNimDisplayMove(moveT move){
    cout<<"I'll take  "<<move.coinsTaken<<" coins from pile "<<move.pile<<"."<<endl;
}

void PrintMoveList( Vector<moveT> moveList){
    cout<<"MoveList:"<<endl<<endl;
    
    for(int x = 0; x<moveList.size(); x++){  //for each move
        cout<<"Pile: "<<moveList[x].pile<<endl;
        cout<<"Move: "<<moveList[x].coinsTaken<<endl;
        
    }
    cout<<endl;
    
}

bool TwoPilesBlank(stateT state){  //if two piles are blank, reeturn true
    if((state.pileOne==0 && state.pileTwo==0) || (state.pileOne==0 && state.pileThree==0) || (state.pileTwo==0 && state.pileThree==0)){
        return true;
    }
    return false;
}




