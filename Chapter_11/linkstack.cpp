//
//  linkstack.cpp
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/3/14.
//
//

#include "linkstack.h"


Stack::Stack(){  //constructor
    start = new blockT;
    start->blockPt = NULL;
    start->chArray = new char[BLOCK_LENGTH];
    current = start;
}

Stack::~Stack(){  //deconstructor
}


void Stack::push(char ch){
     if(current->blockPT == BLOCK_LENGTH)
         addBlock();
    }else{
        current->chArray[blockPt]=ch;
        blockPT++;
    }


char Stack::pop(){
        
    }


void Stack::peek(){
        
    }
    

void Stack::addBlock(){
        
    }
    
