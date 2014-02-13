/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "vectorll.h"




using namespace std;

int main() {
    Vector<string> vecTest;
    
    vecTest.add("Vectors");
    vecTest.add("for");
    vecTest.add("the");
    vecTest[2]="the win";
    
    vecTest.clear();
    
    
    vecTest.add("New Vectors");
    vecTest.add("for");
    vecTest.add("the");
    vecTest[2]="the win";
    
    for(int x=0; x<vecTest.size(); x++){
        cout<<vecTest.getAt(x)<<endl;

    }
    
    return 0;
}

