//
//  SortTimer.cpp
//  Ch.8_Coursework
//
//  Created by Jesse Furmanek on 11/13/13.
//
//

#include "SortTimer.h"
#include <ctime>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"
#include "random.h"
#include <time.h>
#include "InsertionSort.h"

using namespace std;

void SortTimerFunction();
Vector <int> Sort(Vector<int> & vec);

void SortTimerFunction(){
    
    for(int x=10; x<=10000; x=x*10){
        double start=clock(); //start clock
        double clocksPer = CLOCKS_PER_SEC;
        start = start/clocksPer*1000;
        Vector<int> tempVec;
        for(int y=0; y<x; y++){  //create vector with random number
            tempVec.add(randomInteger(0, x));
        }
        Sort(tempVec);
        
        double finish=clock();  //stop clock
        finish = finish/clocksPer*1000;
        
        double elapsed=finish-start;
        
       
        cout<<"For "<<x<<" values, "<<elapsed<<" milliseconds elapsed"<<endl;  //print time
    }
    
}

