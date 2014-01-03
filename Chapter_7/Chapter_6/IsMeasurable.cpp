//
//  IsMeasureable.cpp
//  Ch.6_Coursework
//
//  Created by Jesse Furmanek on 9/8/13.
//
//

#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
using namespace std;


bool IsMeasurable(int target, Vector<int> vecArray);

bool IsMeasurableWork(int target, int same, int other, Vector<int> vecArray);




bool IsMeasurable(int target, Vector<int> vecArray){ //wrapper function
    
    int same = 0;
    int other = 0;
    
    return IsMeasurableWork(target, same, other, vecArray);  //wrapper adds an additional placeholder vector to create subsets
    
}

bool IsMeasurableWork(int target, int same, int other, Vector<int> vecArray){
    if(vecArray.isEmpty()){
        if(same==target || abs(same-other)==target){
            return true;
        }
    }else{
        int weight =vecArray[0];
        vecArray.remove(0);
        
        return IsMeasurableWork(target, same+weight, other, vecArray) || IsMeasurableWork(target, same, other+weight, vecArray) || \
        IsMeasurableWork(target, same, other, vecArray);
        
    }

    return false;
}