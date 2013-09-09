/*
 * File: main.cpp
 * --------------
 * This is an empty C++ source file.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "strlib.h"
#include "vector.h"
#include "random.h"
#include "vector.h"
#include "tokenscanner.h"
#include "grid.h"

using namespace std;

/* Main program */

bool IsMeasurable(int target, Vector<int> vecArray);

bool IsMeasurableWork(int target, Vector<int> vecSame, Vector<int> vecOther, Vector<int> vecArray);



int main() {
    Vector<int> vecInts;
    
    vecInts.add(8);
    vecInts.add(3);
    vecInts.add(4);
    vecInts.add(2);
    
    
    cout<<IsMeasurable(18, vecInts)<<endl;
    
    
    
    return 0;
}

