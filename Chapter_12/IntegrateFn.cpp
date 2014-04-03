//
//  IntegrateFn.cpp
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 4/2/14.
//
//

#include "IntegrateFn.h"





//doubleFnT sin(double);

double Integrate(doubleFnT mathFunction, double minX, double maxX, int numRect);


double Integrate(doubleFnT mathFunction, double minX, double maxX, int numRect){
    double answer= 0.0;
    
    double width = (maxX-minX)/numRect; //the width of the rectangle
    
    for(int x=1; x<=numRect; x++){  //the height of the rectangle is determined by the function
        double midpoint = (width*x)-width/2;
        double height = mathFunction(midpoint);
        
        answer+=height*width;
        
    }
    
    
    return answer;
}


