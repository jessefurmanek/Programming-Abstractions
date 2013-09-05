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
#include "stack.h"
#include "tokenscanner.h"
#include "grid.h"

using namespace std;

/* Main program */


void GenerateBinaryCode(string str, int num);
void BinaryCodeWrapper(int nBits);


int main() {
    
    BinaryCodeWrapper(4);
    
    return 0;
}

