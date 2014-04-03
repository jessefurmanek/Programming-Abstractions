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
#include "IntegrateFn.h"

using namespace std;
double Integrate(doubleFnT mathFunction, double minX, double maxX, int numRect);

int main(){
   

    cout<< Integrate(sin, 0.0, 3.14, 100)<<endl;
    return 0;
}


