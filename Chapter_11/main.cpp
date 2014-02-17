/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "gridarray.h"




using namespace std;

int main(){
    
    Grid<string>Temp(4, 4);
    
    Temp.setAt(0, 0, "A");
    Temp.setAt(0, 1, "B");
    Temp.setAt(1, 0, "C");
    Temp.setAt(1, 1, "D");
    
    for(int x=0; x<Temp.numRows(); x++){
        for(int y=0; y<Temp.numCols(); y++){
            cout<<"{ "<<Temp.getAt(x,y)<<" }"<<flush;
        }
        cout<<endl;
    }
    
    Temp.resize(5, 5);
    
    Temp.setAt(0, 0, "Jesse");
    
    for(int x=0; x<Temp.numRows(); x++){
        for(int y=0; y<Temp.numCols(); y++){
            cout<<"{ "<<Temp.getAt(x,y)<<" }"<<flush;
        }
        cout<<endl;
    }
    

    
    
    return 0;
}