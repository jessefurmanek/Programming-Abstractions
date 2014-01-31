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
    start->blockPos = 0 ; //to allow loop in display
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
    if(cursor==start){
        if(noBlocks()){
            
        }else{
            cursor=cursor->linkF;
            curPos=0;
        }
    }
    else if(curPos==cursor->blockPos-1){ //if cursor is at block capacity
        if(cursor->linkF->linkF!=NULL){
            cursor=cursor->linkF;
            curPos=0;
        }
        
    }else{ //if not at block capacity
        curPos++;  //increment block position
    }
   
}
void EditorBuffer::moveCursorBackward() {
    if(curPos==0){ //if cursor is equal to 0 in the block
        if(cursor->linkB==NULL){  //at start
           
        }else if(cursor->linkB==start){
            cursor=cursor->linkB;  //go backwards to start
            curPos=0;  //set the curPos = 0
        }else{
            cursor=cursor->linkB;  //go backwards
            curPos=cursor->blockPos-1;  //set the curPos to the last used block
        }
        
    }else{ //if not at block capacity
        curPos--;  //increment block position
    }
 
}
void EditorBuffer::moveCursorToStart() {
    curPos = 0;
    cursor = start;
  
}

void EditorBuffer::moveCursorToEnd() {
    cursor = end->linkB;
    curPos = cursor->blockPos-1;
    
}

void EditorBuffer::insertCharacter(char ch) {
    if(noBlocks()){
        insertBlock();
        insertCharacter(ch); //insert character
    }else{
        if(blockFull()){
            insertBlock();  //add block to the end of the current block
            insertShiftLettersRight();  //shift letters right into next block
            insertCharacter(ch);
           
        }else if(cursor==start){
            for(int x=cursor->linkF->blockPos; x>0; x--){
                cursor->linkF->chArray[x]=cursor->linkF->chArray[x-1];  //move chars in charArray to the right in the array
            }
            cursor->linkF->chArray[0]= ch; //insert character as first character
            cursor->linkF->blockPos++;  //increment block counter
    
        }else{
            for(int x=BLOCK_CAPACITY-1; x>curPos; x--){
                cursor->chArray[x]=cursor->chArray[x-1];  //move chars in charArray to the right in the array
            }
            cursor->chArray[curPos+1]=ch;
            cursor->blockPos++;
        }
       
    }
    cout<<"blockPos: "<<cursor->blockPos<<endl;
    cout<<"curPos: "<<curPos<<endl;
    cout<<"numBlocks: "<<numberOfBlocks<<endl;
}


void EditorBuffer::deleteCharacter() {
    
    if(cursor == end->linkB && curPos == end->linkB->blockPos-1){  //if the cursor is at the last block and that that ch in that block
        //do nothing
    }else if(noBlocks()){
        //do nothing
    }else if(cursor == start || curPos == cursor->blockPos-1){
        for(int x=0; x<cursor->linkF->blockPos-1; x++){
            cursor->linkF->chArray[x]=cursor->linkF->chArray[x+1]; //shift chars to left
        }
        cursor->linkF->blockPos--;
        
        if(cursor->linkF->blockPos==0){
            blockT *tempBlock= cursor->linkF;
           
            cursor->linkF = cursor->linkF->linkF;  // set cursor linkF to the value in front of the sooon to be deleted block
            tempBlock->linkF->linkB=cursor;
          
            
            delete[] tempBlock; //delete the blank block
            numberOfBlocks--;
        }
        
    }else{ //if cursor is in the middle or start of a block
        for(int x=curPos+1; x<cursor->blockPos-1; x++){
            cursor->chArray[x]=cursor->chArray[x+1]; //shift chars to left
        }
        
        cursor->blockPos--;
        
        if(cursor->blockPos==0){  //if cursor block is now empty
            blockT *tempBlock= cursor;
            cursor=cursor->linkB;  //set cursor to the previous block
            curPos = cursor->blockPos-1;  //set cursor position to end of block
            cursor->linkF = tempBlock->linkF;  // set cursor linkF to the value in front of the sooon to be deleted block
            tempBlock->linkF->linkB=cursor;  //set the block in front of the block to be deleted's linkB to cursor
            
            delete[] tempBlock; //delete the blank block
            numberOfBlocks--;
        }
        
        
    }

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
    int divisor = BLOCK_CAPACITY/2;
    int newBlockX=0;
    
    for(int x = divisor; x<BLOCK_CAPACITY; x++){
        cursor->linkF->chArray[newBlockX] = cursor->chArray[x];  //set new block equal to the second half of the old block
        newBlockX++;
    }
    
    
    if (BLOCK_CAPACITY%2==0){  //if block capacity is even
        cursor->blockPos=divisor;
        cursor->linkF->blockPos=divisor;
        if (curPos<divisor){
        }else{
            cursor=cursor->linkF;
            curPos-=divisor;
        }
    }else{
        cursor->blockPos=divisor;  //if the block capacity is odd, subtract one
        cursor->linkF->blockPos=divisor+1;
        
        if (curPos<divisor){
        }else{cursor=cursor->linkF;
            
            curPos-=divisor-1;
        }
    }
    
    
}


void EditorBuffer::display() {
    //go to beginning
    bool found=false;
    
    blockT *begPlaceHolder;  //create a dummy pointer to find the beginning
    
    begPlaceHolder = start;
  
    for (blockT *cp = begPlaceHolder->linkF; cp != end; cp = cp->linkF) {
        for(int x=0; x<cp->blockPos; x++){  //iterate through each block's chArray
            cout << ' ' << cp->chArray[x];
        }
    }
    
    cout << endl;
    
  
    if(cursor==start){
            cout<<"^"<<flush; //if there are no blocks, print the cursor
            found=true;
    }else{
        cout<<"  "<<flush;
    
        for (blockT *cp = begPlaceHolder->linkF; cp->linkF != NULL; cp = cp->linkF) {
        
            if(cp==cursor){  //if on the cursor block
                for (int x=0; x<cp->blockPos; x++){
                    if(x==curPos){
                    cout<<'^'<<flush;
                        found=true;
                    }else{
                    cout<<"  "<<flush;
                    }
                }
            }else if(cp->linkF==end && found==false){
                cout<<"^"<<flush;  //print cursor if at the end of the block ;
            }else{//if not on the cursor, print out all the potentional cursor points
                for(int x=0; x< cp->blockPos; x++)
                    cout<<"  "<<flush;  //if not on the cursor block, print a blank for each letter
            }
        
        }

    }
    cout<<endl;
    cout<<"blockPos: "<<cursor->blockPos<<endl;
    cout<<"curPos: "<<curPos<<endl;
}