//
//  GenerateGrayCode.cpp
//  Ch.6_Coursework
//
//  Created by Jesse Furmanek on 9/6/13.
//
//


#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
using namespace std;


void GenerateGrayCode(int nDigits);  //wrapper function
void CreateGrayCode(Vector<string> & vecGray, int nDigits);  //actual code, creates a vector to store list


void GenerateGrayCode(int nDigits){
    
    
    Vector<string> vecGray;
    
    vecGray.add("0");
    vecGray.add("1");
    
    CreateGrayCode(vecGray, nDigits);
    
    cout<<vecGray<<endl;
   
    
}

void CreateGrayCode(Vector<string> & vecGray, int nDigits){
    
    if(nDigits==1){
        
        return;
        
    }else{
        for(int x=vecGray.size()-1; x>=0; x--){
            vecGray.add(vecGray[x]);  //adds reverse of vector to the end of the vector
        }
        
        for(int x=0; x<vecGray.size()/2;x++){
            
            vecGray[x]="0"+vecGray[x];  //add zero in front of first half of vector values
            
        }
        
        for(int x=vecGray.size()/2; x<vecGray.size();x++){
            
            vecGray[x]="1"+vecGray[x];  //add one in front of second half of vector values
            
        }
        
        
        CreateGrayCode(vecGray, nDigits-1);  //count down to zero
     
    }
    
   
}