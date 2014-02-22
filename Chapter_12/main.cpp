/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "mapimpl.h"

using namespace std;

int main(){

    
    Map<string> testMap;
    
    testMap.put("Jesse", "Furmanek");
    
    cout<<testMap.containsKey("test")<<endl;
    cout<<testMap.containsKey("Jesse")<<endl;
    
    return 0;
}