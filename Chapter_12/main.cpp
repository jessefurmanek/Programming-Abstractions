/*
 * File: main.cpp
 * --------------
 * This is an empty C source file.
 */

//Recursive function to raise 

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "mapimpl.h"

using namespace std;

int main(){

    double x=12.5;
    double total = 0;
    
    while (x>0){
        if(x==12.5){
            total+=x;
            x=x*2/5;
        }else{
            total+=(2*x);
            x=x*2/5;
        }
        
        cout<<total<<endl;
    }
   
    cout<<total<<endl;
    
    return 0;
}