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

int numberOfBlocks =0;
int curPos = 0;
int curBlock =0;


struct blockT {
    char ch;
    blockT *linkF;  //link forward
    blockT *linkB;  //link backward
    char *chArray;
    int blockPos;  //number of elements in the charArray
};

//prototype for adding a block;
void addBlock();


#endif
