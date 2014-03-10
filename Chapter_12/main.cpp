/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "maphash.h"
#include "strlib.h"


using namespace std;

int main(){
    
    Map<int> testRun;
    string testStr = "Test ";
    
    for(int x=1; x<1000; x++){
        string inputString = testStr;
        testRun.put(inputString+=integerToString(x), x);
    }
 
    testRun.DisplayHashTableStatistics();

    return 0;
    
}