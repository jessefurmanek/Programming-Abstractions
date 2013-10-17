//
//  ListSubsets.cpp
//  Ch.6_Coursework
//
//  Created by Jesse Furmanek on 8/30/13.
//
//


#include <iostream>
#include <iomanip>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "strlib.h"
#include "vector.h"


void ListSubsets(string str);
void DisplaySubsets(string startSubset, string endSubset);

void ListSubsets(string str){
    
    DisplaySubsets("", str);
    
    return;
}

void DisplaySubsets(string startSubset, string endSubset){
    
    if(endSubset==""){
        
        cout<<"{"<<startSubset<<"}"<<endl;  //if there are no characters left in endSubset, print startSubset
        
    }else{
            DisplaySubsets(startSubset+endSubset[0],endSubset.substr(1));
            
            DisplaySubsets(startSubset, endSubset.substr(1));
               
    }
    
    return;
}