//
//  rationalstack.cpp
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 1/1/14.
//
//


#include "rationalstack.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "vector.h"
#include "charstack.h"

RatStackVec::RatStackVec(){  //constructor
    capacity = INITIAL_CAPACITY;
    count = 0;  //sets the initial stack size = 0;
}

RatStackVec::~RatStackVec(){
}


int RatStackVec::sizeVec(){
    return count;
}

bool RatStackVec::isEmptyVec(){
    return count==0;  //return false if the count = 0;
}

void RatStackVec::clearVec(){
    count = 0;
}



void RatStackVec::pushVec(Rational ratElement){
    NumVec.add(ratElement.getN());
    DenVec.add(ratElement.getD());
    count++; //the next element in the array is equal to the pushed character, increment count
    
}

Rational RatStackVec::popVec(){
    if(isEmptyVec()) error("pop: Trying to pop empty stack");
    
    count--;
    Rational Pop(NumVec[count],DenVec[count]);
    
    NumVec.remove(count);
    DenVec.remove(count);
    
    return Pop; //return the previous element, decrement count
    
}

Rational RatStackVec::peekVec(){
    if(isEmptyVec()) error("peek: Trying to peek at an empty stack");
    
    Rational Peek(NumVec[count-1],DenVec[count-1]);
    return Peek;
}

