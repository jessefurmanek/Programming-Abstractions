/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "linkstack.h"


using namespace std;



int main() {
    Stack testStack;
    
    char letter = 'c';
    for(int x=0; x<25; x++){
        testStack.push(letter+1);
        letter+=1;
    }
    
    
    for(int x=0; x<25; x++){
        cout<<testStack.pop()<<endl;
    }
    

    return 0;
}

