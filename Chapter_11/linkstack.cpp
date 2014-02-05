//
//  linkstack.cpp
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/3/14.
//
//

#include "linkstack.h"
#include "error.h"


Stack::Stack(){  //constructor
    start = new blockT;
    start->blockPt = NULL;
    start->chArray = new char[BLOCK_LENGTH];
    cellFill=0;
    current = start;
}

Stack::~Stack(){  //deconstructor
}


void Stack::push(char ch){
    if(cellFill == BLOCK_LENGTH){  //if block is full
         addBlock();
        current->chArray[cellFill]=ch;
        cellFill++;
}else{
        current->chArray[cellFill]=ch;
        cellFill++;
    }

}

char Stack::pop(){
    char returnChar= NULL;
    if(cellFill==0 && current->blockPt==NULL){
        error("Trying to pop an empty stack");
    }else{
        returnChar=current->chArray[cellFill-1];  /*return one less than the current cellfill (as the cellFill is incremented every time a char is added */
        cellFill--;
    }
    
    if(cellFill==0){
        if(current == start){
            
        }else{
            blockT *temp = current;
            current=current->blockPt;
            cellFill=BLOCK_LENGTH;
            delete[] temp;
        }
    }
    
    return returnChar;
}

char Stack::peek(){
    char returnChar=NULL;
    if(cellFill==0 && current->blockPt==NULL){
        error("Trying to peek at an empty stack");
    }else{
          returnChar=current->chArray[cellFill-1];
    }
    return returnChar;
}
    

void Stack::addBlock(){
    blockT *newBlock = new blockT;
    newBlock->blockPt=current;
    newBlock->chArray = new char[BLOCK_LENGTH];  //chArray is equal to new chArray of the default length
    cellFill=0;  //reset the cell counter
    current = newBlock;  //set current block = to current block
}
    
