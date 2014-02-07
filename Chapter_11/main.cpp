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
    
    testQueue.enqueue("A");
    testQueue.enqueue("B");
    testQueue.enqueue("C");
    testQueue.enqueue("D");
    testQueue.enqueue("E");
    testQueue.enqueue("F");
    testQueue.enqueue("G");
    testQueue.enqueue("H");
    testQueue.enqueue("I");
    testQueue.enqueue("J");
    testQueue.enqueue("K");
    testQueue.enqueue("L");
    
    int length = testQueue.size();
    for(int x=0; x<length; x++){
        cout<<testQueue.dequeue()<<endl;
    }
    
    cout<<endl;
    
    testQueue.enqueue("A");
    testQueue.enqueue("B");
    testQueue.enqueue("C");
    testQueue.enqueue("D");
    testQueue.enqueue("E");
    testQueue.enqueue("F");
    testQueue.enqueue("J");
    testQueue.enqueue("E");
    testQueue.enqueue("S");
    testQueue.enqueue("S");
    testQueue.enqueue("E");
    testQueue.enqueue("F");
    
    length = testQueue.size();
    for(int x=0; x<length; x++){
        cout<<testQueue.dequeue()<<endl;
    }

    
    return 0;
}

