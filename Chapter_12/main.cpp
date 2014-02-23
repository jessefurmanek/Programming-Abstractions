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
    testMap.put("Jenna", "Walker");
    testMap.put("Alpha", "Tuna");
    testMap.put("Zebra", "Luna");
    testMap.put("Charlie", "Sauna");
    
    cout<<testMap.containsKey("test")<<endl;
    cout<<testMap.containsKey("Jesse")<<endl;
    cout<<testMap.containsKey("Jenna")<<endl;
    cout<<testMap.containsKey("Alpha")<<endl;
    
    
    cout<<testMap.get("Jesse")<<endl;
    cout<<testMap.get("Jenna")<<endl;
    cout<<testMap.get("Alpha")<<endl;
    cout<<testMap.get("Zebra")<<endl;
    cout<<testMap.get("Charlie")<<endl;  
   
    
    return 0;
}