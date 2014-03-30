//
//  main.cpp
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 3/27/14.
//
//

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "q6hash.h"
#include "strlib.h"

using namespace std;

int main(){
    Map<int> test;
    Map<int> copytest;
    
    
    
    for (int x = 0; x<10; x++){
        test.put("test"+integerToString(x), x);
    }
    
    test.copyEntriesInto(copytest);
    
    for (int x = 0; x<10; x++){
        test.put("test"+integerToString(x), 2*x);
    }
    
    
    
    for (int x = 0; x<10; x++){
        cout<<copytest.get("test"+integerToString(x))<<endl;
    }
    
    for (int x = 0; x<10; x++){
        cout<<test.get("test"+integerToString(x))<<endl;
    }
   
    
    return 0;
}