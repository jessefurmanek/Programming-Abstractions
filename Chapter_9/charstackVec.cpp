//
//  charstackVec.cpp
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 12/22/13.
//
//

#include "charstackVec.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "vector.h"

CharStackVec::CharStackVec(){  //constructor
    capacity = INITIAL_CAPACITY;
    count = 0;  //sets the initial stack size = 0;
}

CharStackVec::~CharStackVec(){
}


int CharStackVec::sizeVec(){
    return count;
}

bool CharStackVec::isEmptyVec(){
    return count==0;  //return false if the count = 0;
}

void CharStackVec::clearVec(){
    count = 0;
}



void CharStackVec::pushVec(char chElement){
    elements.add(chElement);
    count++; //the next element in the array is equal to the pushed character, increment count
    
}

char CharStackVec::popVec(){
    if(isEmptyVec()) error("pop: Trying to pop empty stack");
    
    char popped = elements[count-1];
    count--;
    elements.remove(count);
    return popped;  //return the previous element, decrement count
    
}

char CharStackVec::peekVec(){
    if(isEmptyVec()) error("peek: Trying to peek at an empty stack");
    
    return elements[count-1];
    
}



