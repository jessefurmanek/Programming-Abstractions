/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "labelgen.h"

using namespace std;


int main() {
        LabelGenerator figureNumbers("Figure", 1);
        LabelGenerator pointNumbers("P", 0);
        cout << "Figure numbers: ";
    
        for (int i = 0; i < 3; i++) {
            if (i > 0) cout << ", ";
            cout << figureNumbers.nextLabel();
        }
        cout << endl << "Point numbers:  ";
        for (int i = 0; i < 5; i++) {
            if (i > 0) cout << ", ";
            cout << pointNumbers.nextLabel();
        }
        cout << endl << "More figures:   ";
        for (int i = 0; i < 3; i++) {
            if (i > 0) cout << ", ";
            cout << figureNumbers.nextLabel();
        }
        cout << endl;
    
    return 0;
}

