//
//  GenerateBinaryCode.cpp
//  Ch.6_Coursework
//
//  Created by Jesse Furmanek on 9/5/13.
//
//

#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;


void BinaryCodeWrapper(int nBits);
void GenerateBinaryCode(string str, int num);


void BinaryCodeWrapper(int nBits){
    GenerateBinaryCode("" , nBits);
}



void GenerateBinaryCode(string str, int num){
    
    
    if(str.length()==num){
        cout<<str<<endl;
    }else{
        
        GenerateBinaryCode(str+"0", num);
        GenerateBinaryCode(str+"1", num);
        
    }
    
    
    
}