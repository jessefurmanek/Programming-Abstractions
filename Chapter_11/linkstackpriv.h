//
//  linkstackpriv.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/3/14.
//
//

#ifndef Ch_11_Coursework_linkstackpriv_h
#define Ch_11_Coursework_linkstackpriv_h

const int BLOCK_LENGTH = 3;

struct blockT {
    blockT *blockPt;
    char *chArray;
    
    
};

blockT *start;
blockT *current;
int cellFill; //keeps track of how full the stack is

void addBlock(); //add another block if the current block is full

#endif
