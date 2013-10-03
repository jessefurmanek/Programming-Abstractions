//
//  nQueens.cpp
//  Ch.7_Coursework
//
//  Created by Jesse Furmanek on 9/25/13.
//
//

#include "nQueens.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"

struct movePositionT { //create an object that stores the position of the Knight
    int x;
    int y;
};


void RunNQueens(int nQueens, int BoardSize);
bool MakeMove(Grid<char> & Board, movePositionT queenMove, int curQueens, int nQueens);
void GenerateMoveList(Grid<char> & Board, int curQueens, Vector<movePositionT> & CurrentMoveList);
void MarkMove(Grid<char> & Board, movePositionT queenMove, int & curQueens);
void ReverseMove(Grid<char> & Board, int curQueens);
void MarkBoard(Grid<char> & Board, int startRow, int startCol, int dRow, int dCol, int Iterations, char charQueens);
void PrintBoard(int BoardSize, Grid<char> & Board);
void AdjustBoard(Grid<char> & Board, int curQueens);
void ClearXs(Grid<char> & Board, int curQueens);

void RunNQueens(int nQueens, int BoardSize){  //wrapper function
    int curQueens = 0;
    
    int x = 0;
    int y = 0;
    movePositionT initialPosition;
    
    initialPosition.x=x;
    initialPosition.y=y;  //set initial queen position
    
    Grid<char> Board(BoardSize,BoardSize);
    
    if(MakeMove(Board, initialPosition, curQueens, nQueens)){
        cout<<"true!"<<endl;
    }else cout<<"false"<<endl;
    
    PrintBoard(BoardSize,Board);
   
}


bool MakeMove(Grid<char> & Board, movePositionT queenMove,int curQueens, int nQueens){
    Vector<movePositionT> CurrentMoveList;
    Vector<movePositionT> NewCurrentMoveList;
    
    GenerateMoveList(Board, curQueens, CurrentMoveList);  //create a vector of all possible moves, marks board to show where queens can attack

    if(curQueens==nQueens) return true;
    
    if(CurrentMoveList.size()==0) {
       
        return false;
    }
    
  
    
    for(int i =0; i<CurrentMoveList.size(); i++){
        
            queenMove = CurrentMoveList[i]; //assign the current move to the 'i' move in the vector
        
            MarkMove(Board, queenMove, curQueens); //marks move, increases curQueens by 1
            AdjustBoard(Board, curQueens);  //mark possible moves by queens with Xs
        
            if(MakeMove(Board, queenMove, curQueens, nQueens)) return true;
        
        
        curQueens--;
        
        ReverseMove(Board, curQueens);
        ClearXs(Board, curQueens);  //remove Xs from the board
        AdjustBoard(Board, curQueens);  //
      

    
    }
    return false;
    
}


void MarkMove(Grid<char> & Board, movePositionT queenMove, int & curQueens){
    char charQueens = curQueens+49;  //convert integer to character
    Board[queenMove.x][queenMove.y]= charQueens;
    curQueens++;
}

void ReverseMove(Grid<char> & Board, int curQueens){
    char charQueens= curQueens+49;
    for(int x=0; x<Board.numCols(); x++){
        for(int y = 0; y<Board.numRows(); y++){
            if (Board[x][y] == charQueens) {  //look through the grid to find the last queen placed, remove that queen
                Board[x][y] = NULL;
                return;
            }
        }
    }
    
}

void AdjustBoard(Grid<char> & Board, int curQueens){
    int IterUpRight;
    int IterDownRight;
    int IterDownLeft;
    int IterUpLeft;
    
    
    for(int i =0; i<curQueens; i++){  //iterate through every queen currently on the board
        char charQueens = i+49;         //convert the 'queen number' to a character
        for(int j=0; j<Board.numRows(); j++){  //rows "y" axis
            for(int k=0; k<Board.numCols(); k++){ //columns "x" axis
                if(Board[j][k]== charQueens){
                    
                    //set up diagonal length for iteration
                    IterUpRight = (abs(Board.numCols()-k<abs(0-j))) ? abs(Board.numCols()-k): abs(0-j);
                    IterDownRight = (abs(Board.numCols()-k)<(Board.numRows()-j) ? Board.numCols()-k: Board.numRows()-j);
                    IterDownLeft = Board.numRows()-j<abs(0-k) ? Board.numRows()-j: abs(0-k);
                    IterUpLeft = (abs(0-k)<abs(0-j)) ? abs(0-k)+1: abs(0-j)+1;
                    
                    
                    MarkBoard(Board, j, k, -1, 0, j+1, charQueens);  //go up
                    
                    
                    MarkBoard(Board, j, k, -1, 1, IterUpRight,charQueens );  //up right
                    
                    
                    MarkBoard(Board, j, k, 0, 1, Board.numCols()-k,charQueens);   //right
                    
                    
                    MarkBoard(Board, j, k, 1, 1, IterDownRight,charQueens);  //down right
                    
                    
                    
                    MarkBoard(Board, j, k, 1, 0, Board.numRows()-j,charQueens);   //down
                    
                    
                    MarkBoard(Board, j, k, 1, -1, IterDownLeft,charQueens);   //down left
                    
                    
                    MarkBoard(Board, j, k, 0, -1, k+1,charQueens);   //left
                    
                    
                    MarkBoard(Board, j, k, -1, -1, IterUpLeft,charQueens);  //up left
                    
                    
                }
            }
        }
    }
    
}



void GenerateMoveList(Grid<char> & Board, int curQueens, Vector<movePositionT> & CurrentMoveList){
    CurrentMoveList.clear();
    
    AdjustBoard(Board, curQueens);
    
    movePositionT temp;
    
    for(int x= 0; x<Board.numCols(); x++){   //crate a vector of all current moves
        for(int y=0; y<Board.numRows(); y++){
            if(Board[x][y]==NULL){
                temp.x=x;
                temp.y=y;
                CurrentMoveList.add(temp);
                
            }
        }
    }
}


void MarkBoard(Grid<char> & Board, int startRow, int startCol, int dRow, int dCol, int Iterations, char charQueens){
    for(int x=0; x<Iterations; x++){
        if(Board[startRow][startCol]==NULL){
            Board[startRow][startCol]='X';
        }
        startRow+=dRow;
        startCol+=dCol;
    }
    
}

void ClearXs(Grid<char> & Board, int curQueens){
    for(int x=0; x<Board.numCols(); x++){
        for(int y = 0; y<Board.numRows(); y++){
            if (Board[x][y] == 'X') {  //look through the grid to find X's, remove them
                Board[x][y] = NULL;
            }
        }
    }
    
}

void PrintBoard(int BoardSize, Grid<char> & Board){
    for(int i = 0; i<BoardSize; i++){           //print board
        for (int j=0; j<BoardSize; j++){
            if(Board[i][j]/10>=1){
                cout<<Board[i][j]<<" "<<flush;
            }else{
                cout<<" "<<Board[i][j]<<" " <<flush;
            }
        }
        cout<<endl;
    
    }
}




