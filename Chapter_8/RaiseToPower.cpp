//
//  RaiseToPower.cpp
//  Ch.8_Coursework
//
//  Created by Jesse Furmanek on 11/12/13.
//
//

#include "RaiseToPower.h"


double RaiseToPower(double x, int n){
    if(n==1){
        return x;
    }else{
        return RaiseToPower(x, n/2)*RaiseToPower(x,n-n/2);
    }
}