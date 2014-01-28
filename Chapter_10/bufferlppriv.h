//
//  bufferlppriv.h
//  
//
//  Created by Jesse Furmanek on 1/23/14.
//
//

#ifndef _bufferlppriv_h
#define _bufferlppriv_h

int BLOCK_CAPACITY=4;


//prototype for adding a block;
void appendBlock();
void insertBlock();
void insertShiftLettersRight();
bool noBlocks();
bool blockFull();


int numberOfBlocks;
int curPos;
int curBlock;


struct blockT {
    blockT *linkF;  //link forward
    blockT *linkB;  //link backward
    char *chArray;
    int blockPos;  //number of elements in the charArray
    
};
blockT *cursor;
blockT *start;
blockT *end;






#endif
