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
    start->linkF = end;
    start->blockPos = 1; //to allow loop in display
    end->linkF=NULL;  //set the end block's link backward to NULL
    end->linkB=start;
    end->blockPos =1;
  
    
    
    numberOfBlocks=0; //set number of blocks equal to zero
    curPos = 0;  //set current cursor position = 0;
    curBlock = 0;  //set current block (as in the one which the cursor is currently on = 0

}


EditorBuffer::~EditorBuffer() {
    
    //need to iterate through the blocks and delete them all
 
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
    newBlock->blockPos=0;
}

void EditorBuffer::insertShiftLettersRight(){
    
    
}


void EditorBuffer::display() {
    //go to beginning
    
    blockT *begPlaceHolder;  //create a dummy pointer to find the beginning
    
    begPlaceHolder = start;
    
    if(numberOfBlocks==0){
        cout<< " ^"<<endl;  //if there are no blocks, print the cursor
        
    } else{
    for (blockT *cp = begPlaceHolder->linkF; cp->linkF != NULL; cp = cp->linkF) {
        for(int x=0; x<cp->blockPos; x++){  //iterate through each block's chArray
            cout << ' ' << cp->chArray[x];
        }
    }
    cout << endl;
    for (blockT *cp = begPlaceHolder; cp->linkF != NULL; cp = cp->linkF) {
        if(cp==cursor){  //if on the cursor block
            for(int x= 0; x<cp->blockPos; x++){
                if(curPos == x){
                    cout << '^' <<flush;
                }else{
                    cout << ' ' << flush;
                }
                
            }
            
        }else{
            for(int x=0; x<cp->blockPos; x++)
            cout<< ' ' <<flush;  //if not on the cursor block, print a blank for each letter
        }
        
    }
    }
    
    cout<<endl;
}