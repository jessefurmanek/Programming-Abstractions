//
//  MajorityLinear.cpp
//  Ch.8_Coursework
//
//  Created by Jesse Furmanek on 12/16/13.
//
//

#include "MajorityLinear.h"
#include <ctime>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"
#include "random.h"
#include <time.h>
#include <iomanip>

Vector<int> RandomVecNoSort(int n);
void RunMajLinear();



void RunMajLinear(){
    Vector<int> vec; //create vector
    vec.add(3);
    vec.add(5);
    vec.add(1);
    vec.add(3);
    vec.add(1);
    vec.add(1);
    vec.add(1);
    vec.add(6);
    vec.add(6);
    vec.add(6);
    vec.add(6);
    vec.add(1);
    vec.add(1);
    vec.add(1);
    vec.add(1);
    
    
    int majority = vec[0];
    int counter = 0;
    
    for(int x = 0; x<vec.size(); x++){
        if(vec[x]==majority){
            counter++;
        }else{
            counter--;
        }
        
        if (counter<0){
            majority = vec[x+1];  //if the number is no longer the potential majority, reset the majority as the next number in the vector (as it will begin the vector count at +1)
        }
    }
    
    counter = 0;  //reset the counter, test the majority value to make sure its the majority
    
    for(int y=0; y<vec.size(); y++){
        if(vec[y] == majority){
            counter++;
        }
    }
    
    double average;
    double count = counter;
    
    average=count/vec.size();
    
    if(average>.5){
        cout<<"The majority is "<<majority<<"."<<endl;
    }else{
        cout<<"There is no majority."<<endl;
        cout<<vec<<endl;
    }
    
    
}



Vector<int> RandomVecNoSort(int n){
    Vector<int> tempVec;
    
    for(int x = 0; x<n; x++){
        tempVec.add(randomInteger(0, n));  // create vector of random numbers
    }
    
    return tempVec;
}