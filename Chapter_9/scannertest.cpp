//
//  scannertest.cpp
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 1/3/14.
//
//

#include "scannertest.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "scanner.h"
#include "error.h"
#include <fstream>

using namespace std;

void ScannerTest(){
    
    Scanner scanner;
    string test=" \"Hello World!\" ";
    
    
    scanner.setInput(test);
    
    while (scanner.hasMoreTokens()){
        string word = scanner.nextToken();
        cout<<word<<endl;
    }
    
    
}