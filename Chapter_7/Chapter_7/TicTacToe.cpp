//
//  TicTacToe.cpp
//  Ch.7_Coursework
//




/*
 * File: tictactoe.cpp
 * -------------------
 * This program plays a game of tic-tac-toe with the user.  The
 * code is designed to make it easy to adapt the general structure
 * to other games.
 */

#include "TicTacToe.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include <iostream>
#include "error.h"

using namespace std;

//gives the maximum and minimum score that is possible, symmetrical on 0

const int WINNING_POSITION  = 1000;
const int NEUTRAL_POSITION  = 0;
const int LOSING_POSITION   = -WINNING_POSITION;

enum playerT { Human, Computer };
/*
 * Type: moveT
 * -----------
 * For any particular game, the moveT type must keep track of the
 * information necessary to describe a move.  For tic-tac-toe,
 * a moveT is simply an integer identifying the number of one of
 * the nine squares, as follows:
 */

typedef int moveT;  //integer representing one of the nine squares on the tic-tac-toe board

struct stateT{  //defines an object that contains a board state, whose turns it is, and the number of turns taken
    Grid<char> board;
    playerT whoseTurn;
    int turnsTaken;
    
};

const int MAX_DEPTH = 5;  //the maximum depth of the recursion
const playerT FIRST_PLAYER = Computer;  //assigning a playerT constant to set the Computer as the first player


void PlayTicTacToe();
void GiveInstructions();
moveT FindBestMove(stateT state, int depth, int & pRating);
stateT NewGame();
void DisplayGame(stateT state);
void DisplayMove(moveT move);
char PlayerMark(playerT player);
moveT GetUserMove(stateT state);
moveT ChooseComputerMove(stateT state);
void GenerateMoveList(stateT state, Vector<moveT> & moveList);
bool MoveIsLegal(moveT move, stateT state);
void MakeMove(stateT & state, moveT move);
void RetractMove(stateT & state, moveT move);
bool GameIsOver(stateT state);
void AnnounceResult(stateT state);
playerT WhoseTurn(stateT state);
playerT Opponent(playerT player);
int EvaluatePosition(stateT state, int depth);
int EvaluateStaticPosition(stateT state);
bool CheckForWinWrapper(stateT state, playerT player);
bool CheckForWin(Grid<char> & board, char mark);
bool CheckLine(Grid<char> & board, char mark,int row, int col, int dRow, int dCol);
bool MoveIsGoodTest(int nCoins);


bool MoveIsGoodTest(int nCoins){
    if (nCoins%4 != 1) return true;
    
    return false;
}

void PlayTicTacToe(){
    GiveInstructions();
    stateT state = NewGame();  //begin the simulation by creating a blank tic tac toe board
    moveT move;
    while (!GameIsOver(state)){
        DisplayGame(state);
        switch (WhoseTurn(state)){
            case Human:
                move = GetUserMove(state);  //if its the user's turn, get the user's input
                break;
            case Computer:
                move = ChooseComputerMove(state);
                DisplayMove(move);
                break;
        }
        MakeMove(state,move);  //this function updates the state
        
    }
    AnnounceResult(state);
    
}


void GiveInstructions() {
    cout << "Welcome to tic-tac-toe.  The object of the game" << endl;
    cout << "is to line up three symbols in a row," << endl;
    cout << "vertically, horizontally, or diagonally." << endl;
    cout << "You'll be " << PlayerMark(Human) << " and I'll be "<< PlayerMark(Computer) << "." << endl;
}


stateT NewGame(){
    stateT state;
    state.board.resize(3,3);
    for (int x = 0; x<3; x++){
        for(int y =0; y<3; y++){
            state.board[x][y]= ' ';  //creates a blank 3 x 3 board
        }
        
    }
    state.whoseTurn = FIRST_PLAYER;  //set's the turn to the constant FIRST_PLAYER
    state.turnsTaken = 0;  //begins the game with 0 turns taken
    return state;
}

void DisplayGame (stateT state){
    if (GameIsOver(state)){
        cout<<"Here's the final position: "<<endl<<endl;
    }else{
        cout<<"Here's the board: "<<endl<<endl;
    }
    
    for(int row=0; row<3; row++){
        if(row!=0) cout<< "---+---+---"<<endl;  //@ 0, its the top of the grid, so there's no need for a line.  for the remaining two numbers, there is.
        for(int col=0; col<3; col++){
            if(col!=0) cout<<"|"<<flush;
            cout<<" "<<state.board[row][col]<<" "<<flush;
        }
        cout<<endl;
    }
    
    cout<<endl;
}

void DisplayMove(moveT move){
    cout<<"I'll move to "<<move<<endl;
}

moveT FindBestMove (stateT state, int depth, int & rating){
    Vector<moveT> moveList;  //create a list of possible moves
    GenerateMoveList(state, moveList);  //generate the move list based on the current state
    int nMoves = moveList.size();  //store the number of possible moves, derived using the size of the vector.
    
    if(nMoves==0)error("No moves available");
    moveT bestMove;
    
    int minRating = WINNING_POSITION +1;  //using winning position +1 assures that the minRating can catch the winning position
    
    for(int x=0; x<nMoves && minRating != LOSING_POSITION; x++){
        
        moveT move = moveList[x];
        
        MakeMove(state, move); //makes move, changes turn
        
        
        
        int curRating = EvaluatePosition(state, depth+1);  //begin recursive call
        
        
        if (curRating < minRating){
            
            bestMove=move;
            minRating=curRating;

        }
        RetractMove(state, move);
    }
    rating = -minRating;
    return bestMove;
}

int EvaluatePosition(stateT state, int depth){
    int rating;
    if(GameIsOver(state) || depth>=MAX_DEPTH){  //if 9 turns have been taken or the max depth of recursion has been reached.
        return EvaluateStaticPosition(state);
    }
    FindBestMove(state,depth,rating);  //recursive call back to FindBestMove
    
    return rating;
}

int EvaluateStaticPosition(stateT state){
    if(CheckForWinWrapper(state,state.whoseTurn)){
        
        return WINNING_POSITION;
    }
    if(CheckForWinWrapper(state, Opponent(state.whoseTurn))){
        return LOSING_POSITION;
    }
    
    return NEUTRAL_POSITION;
    
}

bool CheckForWinWrapper(stateT state, playerT player){
    if (state.turnsTaken<5) return false;
    return(CheckForWin(state.board, PlayerMark(player)));  //sees whether the board is whether a mark is in a winning position
}


bool CheckForWin(Grid<char> & board, char mark){
    for(int x=0; x<3; x++){
        if(CheckLine(board, mark, x, 0,0,1)) return true;
        if (CheckLine(board, mark, 0,x,1, 0)) return true;
    }
    if(CheckLine(board, mark, 0, 0, 1, 1)) return true;  //checks diagonals
    
    return CheckLine(board, mark, 2, 0, -1, 1);
    
}

bool CheckLine(Grid<char> & board, char mark, int row, int col, int dRow, int dCol){
    
    for(int x=0; x<3; x++){
        if(board[row][col] != mark) return false;
        row+=dRow;
        col+=dCol;
    }
    return true;
}

char PlayerMark(playerT player){
    if (player==FIRST_PLAYER){
        return 'X';
    }else{
        return 'O';
    }
}

moveT GetUserMove(stateT state){
    cout<<"Your move."<<endl;
    moveT move;
    while(true){
        cout<< "What square? "<<flush;
        move= getInteger();
        if (MoveIsLegal(move, state)) break;
        cout<<"That move is illegal.  Try again"<<endl;
    }
    
    return move;
}

moveT ChooseComputerMove(stateT state){
    int rating;
    cout<< "My move. "<<endl;
    
    return FindBestMove(state,0,rating);  //depth begins at zero; program starts at the top of the game tree
    
}

void GenerateMoveList(stateT state, Vector<moveT> & moveList){
    for(int x = 1; x<=9; x++){
        moveT move = moveT(x);
        if (MoveIsLegal(move, state)){
            moveList.add(moveT(x));  //add all legal moves to moves list
        }
    }
}

bool MoveIsLegal(moveT move, stateT state){
    if(move <1 || move > 9) return false;
    int row = (move-1)/3;  //subtract 1 because the Grid begins with zero
    int col = (move-1)%3;  //this works because each columns number increases by adding a multiple of 3 e.g. square 7 = 1+3*2 (inc. two rows)
    
    
    return state.board[row][col] ==' ';  //move is legal if the square is blank
}

void MakeMove(stateT & state, moveT move){
    int row =(move-1)/3;
    int col = (move-1)%3;
    state.board[row][col] = PlayerMark(state.whoseTurn);  //mark the board with the players char
    state.whoseTurn = Opponent(state.whoseTurn);  //switch player
    state.turnsTaken++; // increment turns
    
}

void RetractMove(stateT & state, moveT move){  //used to reverse the game state after 'playing' through the game tree to find the best move
    int row =(move-1)/3;
    int col = (move-1)%3;
    state.board[row][col] = ' ';
    state.whoseTurn = Opponent(state.whoseTurn);
    state.turnsTaken--;
}

bool GameIsOver(stateT state){  //if any are true, return true
    return (state.turnsTaken) == 9 \
    || CheckForWinWrapper(state, state.whoseTurn) \
    || CheckForWinWrapper(state, Opponent(state.whoseTurn));
}


void AnnounceResult(stateT state){
    DisplayGame(state);
    if (CheckForWinWrapper(state, Human)){
        cout<<"You Win."<<endl;
    }else if(CheckForWinWrapper(state, Computer)){
        cout<<"I win."<<endl;
    }else{
        cout<<"Cat's game."<<endl;
    }
}


playerT WhoseTurn(stateT state){   //not exactly sure why its necessary to make a separate function for this
    return state.whoseTurn;
}

playerT Opponent(playerT player){
    return (player == Human) ? Computer : Human;
}










