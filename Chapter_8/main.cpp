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
#include "SortToTenThousand.h"

using namespace std;

void SortTo10k (Vector<int> & vec);

int main() {
    Vector<int> vec;
    
    for(int x=0; x<500000; x++){
        vec.add(randomInteger(0, 10000));
    }
    
    SortTo10k(vec);
    
    
  
    
    return 0;
}

