/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "queuell.h"
#include "queuell.h"



using namespace std;

int main() {

    Queue<string> testQ;
    
    testQ.enqueue("A");
    testQ.enqueue("B");
    testQ.enqueue("C");
    testQ.enqueue("D");
    testQ.enqueue("E");
    testQ.clear();
    testQ.enqueue("E", 2);
    testQ.enqueue("S",4);
    testQ.enqueue("J", 1);
    testQ.enqueue("S",3);
    testQ.enqueue("E", 5);
    
    testQ.dequeue();
    testQ.dequeue();
    testQ.dequeue();
    testQ.dequeue();
   
    testQ.enqueue("E", 2);
    testQ.enqueue("S",4);
    testQ.enqueue("J", 1);
    testQ.enqueue("S",3);
    
    int qSize =testQ.size();
    
    for(int x=0; x<qSize; x++){
       cout<<testQ.dequeue()<<endl;
    }
    
    return 0;
}

