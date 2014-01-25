//
//  bufferlp.cpp
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/23/14.
//
//

#include "bufferlp.h"
#include <iostream>
using namespace std;

EditorBuffer::EditorBuffer() {
    start = new blockT;
    end = new blockT;
    cursor= start;
    
    start->linkB = NULL;  //set the start blocks link forward to NULL
    end->linkF=NULL;  //set the end block's link backward to NULL
  
    
    
    numberOfBlocks=0; //set number of blocks equal to zero
    curPos = 0;  //set current cursor position = 0;
    curBlock = 0;  //set current block (as in the one which the cursor is currently on = 0
}


EditorBuffer::~EditorBuffer() {
 
}

void EditorBuffer::moveCursorForward() {
   
}
void EditorBuffer::moveCursorBackward() {
 
}
void EditorBuffer::moveCursorToStart() {
  
}

void EditorBuffer::moveCursorToEnd() {

}

void EditorBuffer::insertCharacter(char ch) {
    if(noBlocks()){
        insertBlock();
        insertCharacter(ch); //insert character
    }else{
        if(blockFull()){
            insertBlock();  //add block to the end of the current block
            insertShiftLettersRight();  //shift letters right into next block
           
            
            
            
        }else if(cursor==start){
            cursor->linkF->chArray[curPos]= ch;
            curPos++;  //increment cursor position counter
            cursor->linkF->blockPos++;  //increment block counter
            
            
        }
       
    }
}


void EditorBuffer::deleteCharacter() {

}

bool EditorBuffer::noBlocks(){
    return numberOfBlocks == 0;
}

bool EditorBuffer::blockFull(){
    return cursor->blockPos==BLOCK_CAPACITY; //if the current block is full
        
}

void EditorBuffer::insertBlock(){
        blockT *newBlock = new blockT;  //add a new block in the chain
        newBlock->linkF = cursor->linkF;
        newBlock->linkB = cursor;
        cursor->linkF->linkB = newBlock;  //connect the block ahead of the newBlock to newBlock
        cursor->linkF = newBlock;
        newBlock->chArray = new char[BLOCK_CAPACITY];  //initialize the newBlock's chArray;
    numberOfBlocks++;
}

void EditorBuffer::insertShiftLettersRight(){
    
    
}


void EditorBuffer::display() {
    //go to beginning
    
    blockT *begPlaceHolder;  //create a dummy pointer to find the beginning
    
    begPlaceHolder = start;
    
    while(begPlaceHolder->linkB != NULL){
        begPlaceHolder = begPlaceHolder->linkB;
    }
    
    for (blockT *cp = begPlaceHolder->linkF; cp != NULL; cp = cp->linkF) {
        cout << ' ' << cp->ch;
    }
    cout << endl;
    for (blockT *cp = begPlaceHolder; cp != cursor; cp = cp->linkF) {
        cout << "  "; }
    cout << '^' << endl;
}