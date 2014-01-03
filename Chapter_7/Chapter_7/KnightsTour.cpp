//
//  KnightsTour.cpp
//  Ch.7_Coursework
//
//  Created by Jesse Furmanek on 9/23/13.
//
//

#include "KnightsTour.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"


enum KnightsMoves { LUpRight, rUpRight, rDownRight, LDownRight, LDownLeft, rDownLeft, rUpLeft, LUpLeft};  //create enum class for all possible Knight Moves

struct KPosT { //create an object that stores the position of the Knight
    int x;
    int y;
};

void displayKnightsTour();
bool FindNextMove(Grid<int> & Board, KPosT curPos, int & counter);
bool IsLegalMove(Grid<int> & Board, KPosT curPos, KnightsMoves curMove);
KPosT MoveKnight(Grid<int> & Board, KPosT curPos, KnightsMoves curMove);

void displayKnightsTour(){
    Grid <int> Board(8,8);  //initialize the board
    int counter = 1;  // initialize the first mark
    
    KPosT StartingPoint;
    StartingPoint.x = 7;
    StartingPoint.y = 0;
    
    Board[StartingPoint.x][StartingPoint.y] = counter;  //set starting point
    
  
    
    FindNextMove(Board, StartingPoint, counter);
    
    for(int i = 0; i<8; i++){
        for (int j=0; j<8; j++){
            if(Board[i][j]/10>=1){
            cout<<Board[i][j]<<" "<<flush;
            }else{
                cout<<" "<<Board[i][j]<<" " <<flush;
            }
        }
            cout<<endl;
    }
    

    return;
    
}

bool FindNextMove(Grid <int> & Board, KPosT curPos, int & counter){
    if (counter == 64) {
        Board[curPos.x][curPos.y]=64;
        return true;
    }
    
    Board[curPos.x][curPos.y]=counter;
    counter++;
    KnightsMoves curMove;
    
    for(int x = 0; x<8; x++){  //iterate through the move types
        curMove = KnightsMoves(x);
        
        if (IsLegalMove(Board, curPos, curMove)){
             if(FindNextMove(Board, MoveKnight(Board, curPos, curMove), counter)) return true;
        }
    }
    Board[curPos.x][curPos.y]=0;
    counter--;
    return false;
    
}

bool IsLegalMove(Grid<int> & Board, KPosT curPos, KnightsMoves curMove){
    int x = curPos.x;
    int y = curPos.y;
    
    switch (curMove){
        case LUpRight: x+=1; y+=2; break;
        case rUpRight: x+=2; y+=1; break;
        case rDownRight: x+=2; y-=1; break;
        case LDownRight:  x+=1; y-=2; break;
        case LDownLeft: x-=1; y-=2; break;
        case rDownLeft: x-=2; y-=1; break;
        case rUpLeft: x-=2; y+=1; break;
        case LUpLeft: x-=1; y+=2; break;
    }
    
    if( y>7||x>7||x<0||y<0 || Board[x][y]>0) return false;  //if the selection is off the board OR if the space is already taken
    
    
    return true;
}

KPosT MoveKnight(Grid<int> & Board, KPosT curPos, KnightsMoves curMove){  //moves Knight to next position
    
    int x = curPos.x;
    int y = curPos.y;
    
    switch (curMove){
        case LUpRight: x+=1; y+=2; break;
        case rUpRight: x+=2; y+=1; break;
        case rDownRight: x+=2; y-=1; break;
        case LDownRight:  x+=1; y-=2; break;
        case LDownLeft: x-=1; y-=2; break;
        case rDownLeft: x-=2; y-=1; break;
        case rUpLeft: x-=2; y+=1; break;
        case LUpLeft: x-=1; y+=2; break;
    }
    
    curPos.x = x;
    curPos.y= y;  //set position to new position.
    
    return curPos;
}


