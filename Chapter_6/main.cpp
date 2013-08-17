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

void RecursivePermute(string prefix, string rest, string original);
void ListPermutations(string str, int n);

int main() {
    
    ListPermutations("BAAA", 0);
    
    return 0;
}

