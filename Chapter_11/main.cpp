/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "vector2stacks.h"




using namespace std;

int main() {
    VectorTwoStx <string> testVec;
    
    testVec.add("A");
    testVec.add("B");
    testVec.add("C");
    
    
    testVec.removeAt(1);
    testVec.insertAt(1, "X");
    testVec.insertAt(1, "Y");
    testVec.insertAt(1, "Z");
    testVec.insertAt(1, "8");
    
    testVec.add("Z");
    
    testVec.clear();
    
    
    testVec.add("A");
    testVec.add("B");
    testVec.add("C");
    
    testVec.setAt(0, "Z");
    testVec.add("Y");
    
    
    for(int x=0; x<testVec.size(); x++){
        cout<<testVec[x]<<endl;
    }
   
    
    
   
    return 0;
}

