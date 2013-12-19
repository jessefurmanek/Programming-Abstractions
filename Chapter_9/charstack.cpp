//
//  charstack.cpp
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 12/18/13.
//
//

#include "charstack.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"


CharStack::CharStack(){  //constructor
    elements = new char[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
    count = 0;  //sets the initial stack size = 0;
}

CharStack::~CharStack(){
    delete[] elements; //deletes the dynamic array
}

int CharStack::size(){
    return count;
}

bool CharStack::isEmpty(){
    return count==0;  //return false if the count = 0;
}

void CharStack::clear(){
    count = 0;
}


void CharStack::expandCapacity(){
    capacity*=2;
    char *array = new char[capacity];  //create a temporary array with twice the capacity
    for (int i=0; i<count;i++){
        array[i] = elements[i];
    }
    delete[] elements;
    elements = array;  //copy the temp array's elements into the new "elements" array
}

void CharStack::push(char chElement){
    if(count==capacity) expandCapacity(); //if the stack needs more space, make it bigger
    elements[count++] = chElement;  //the next element in the array is equal to the pushed character, increment count
    
}

char CharStack::pop(){
    if(isEmpty()) error("pop: Trying to pop empty stack");
    
    return elements[count--]; //return the previous element, decrement count
    
}

char CharStack::peek(){
    if(isEmpty()) error("peek: Trying to peek at an empty stack");
    
     return elements[count-1];

}



