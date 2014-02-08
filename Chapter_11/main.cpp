/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "queueimp1.h"


using namespace std;



int main() {
    Queue<string> testQueue;
    

    
    int length = testQueue.size();


    testQueue.enqueue("A");
    testQueue.enqueue("B");
    testQueue.enqueue("C");
    testQueue.enqueue("D");
    testQueue.enqueue("E");
    testQueue.enqueue("J");
    testQueue.enqueue("E");
    testQueue.enqueue("S");
    testQueue.enqueue("S");
    testQueue.enqueue("E");
    testQueue.enqueue("F");
    testQueue.enqueue("G");
    testQueue.enqueue("H");
    testQueue.enqueue("I");
    testQueue.enqueue("A");
    testQueue.enqueue("B");
    testQueue.enqueue("C");
    testQueue.enqueue("D");
    testQueue.enqueue("E");
    testQueue.enqueue("J");
    testQueue.enqueue("E");
    testQueue.enqueue("S");
    testQueue.enqueue("S");
    testQueue.enqueue("E");
    testQueue.enqueue("F");
    testQueue.enqueue("G");
    testQueue.enqueue("H");
    testQueue.enqueue("I");
    
    
    for(int x=0; x<10; x++){
        testQueue.dequeue();
    }
    

    
    testQueue.reverse();

    
    length = testQueue.size();
    for(int x=0; x<length; x++){
        cout<<testQueue.dequeue()<<endl;
    }

    
    return 0;
}

