//
//  Rational.h
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 12/23/13.
//
//

#ifndef __Ch_9_Coursework__Rational__
#define __Ch_9_Coursework__Rational__

#include <iostream>
#include "string.h"

class Rational{
    
public:
   
    Rational(int num, int den);  //constructor
    
    ~Rational();  //deconstructor
    
    Rational add(Rational numAdd);
    Rational sub(Rational numSub);
    Rational mul(Rational numMul);
    Rational div(Rational numDiv);
    
    int getN();
    int getD();
    
    bool equals(Rational numEquals);  //whether the rational number is equal to another rational number
    char compareTo(Rational numComp);  //return the appropriate comparison sign
    std::string toString();  //returns a string value for the real number
    
    
private:
    int n, d;

};

#endif /* defined(__Ch_9_Coursework__Rational__) */
