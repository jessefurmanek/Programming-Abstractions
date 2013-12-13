/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"
#include "random.h"
#include "QuickSortMedian.h"



using namespace std;
void QuicksortMed(Vector<int> & vec, int start, int finish);

int main() {
    Vector<int> test;
    test.add(2);
    test.add(8);
    test.add(7);
    test.add(3);
    test.add(4);
    
   
    QuicksortMed(test, 0, test.size()-1);
    cout<<test<<endl;
    
    return 0;
}

