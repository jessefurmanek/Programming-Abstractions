/*
 * File: main.cpp
 * --------------
 * This is an empty C++ source file.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "nim.h"

using namespace std;

void RunNim();
int FindGoodMove(int nCoins);
bool IsBadPosition(int nCoins);
int ChooseComputerMove(int nCoins);

int main() {
    
    
    cout<<FindGoodMove(5)<<endl;
    
    return 0;
}


