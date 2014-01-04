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
    string test="3rd 33.4 and 17.5E-9 and thirty-three and 3.143";
    scanner.setNumberOption(Scanner::ScanNumbersAsIntegers);
    
    
    scanner.setInput(test);
    
    while (scanner.hasMoreTokens()){
        string word = scanner.nextToken();
        cout<<"("<<word<<")"<<flush;
    }
    
    cout<<endl;
    scanner.setNumberOption(Scanner::ScanNumbersAsReals);

    scanner.setInput(test);
    
    while (scanner.hasMoreTokens()){
        string word = scanner.nextToken();
         cout<<"("<<word<<")"<<flush;
    }
    
}