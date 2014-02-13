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
    
    vecTest.add("Jesse");
    
    cout<<vecTest.getAt(0)<<endl;

      
    return 0;
}

