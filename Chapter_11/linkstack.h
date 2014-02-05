//
//  linkstack.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/3/14.
//
//

#ifndef __Ch_11_Coursework__linkstack__
#define __Ch_11_Coursework__linkstack__

#include <iostream>

class Stack{
    
public:
    Stack();  //constructor
    
    ~Stack();  //deconstructor
    
    
    //set prototypes for the basic stack commands
    void push(char ch);
    char pop();
    char peek();

    
private:
    
#include "linkstackpriv.h"
    
};

#endif /* defined(__Ch_11_Coursework__linkstack__) */
