//
//  Rational.cpp
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 12/23/13.
//
//

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "vector.h"
#include "rational.h"
#include "string.h"
#include <cmath>


Rational::Rational(int n, int d){
    
    
    for (int i = 1; i<std::abs(n); i++){  //reduce the numerator and the denominator
        if(n%i==0){
            if(d%i==0){
                n/=i;
                d/=i;
                i=1;
            }
        }
    }
    
    
    
    if(n<0){
        if(d<0){
            d*=-1;  //if both numbers are negative  the fraction is positive
            n*=-1;
        }
    }else{
        if(d>0){
            
        }else{
            d*=-1;
            n*=-1;  //if the number is negative, make the numerator negative and the denominator positive
        }
        
    }
    
    
    this ->n =n;  //set instance variables = to calculated value
    this ->d =d;
}

Rational::~Rational(){};  //deconstructor

int Rational::getN(){
    return n;
    
}
int Rational::getD(){
    return d;
}


Rational Rational::add(Rational numAdd){
    int RationalN=n*numAdd.d+numAdd.n*d;
    int RationalD= d*numAdd.d;

    
    return(Rational(RationalN,RationalD));
    
};

Rational Rational::sub(Rational numSub){
    int RationalN=n*numSub.d-numSub.n*d;
    int RationalD= d*numSub.d;
    
    
    return(Rational(RationalN,RationalD));
    
};


Rational Rational::mul(Rational numMul){
    int RationalN=n*numMul.n;
    int RationalD= d*numMul.d;
    
    return(Rational(RationalN,RationalD));
};

Rational Rational::div(Rational numDiv){
    int RationalN=n*numDiv.d;
    int RationalD= d*numDiv.n;
    
    return(Rational(RationalN,RationalD));
    
};

bool Rational::equals(Rational numEquals){ //whether the rational number is equal to another rational number
    return (n==numEquals.n && d==numEquals.d);
    
};

char Rational::compareTo(Rational numComp){ //return the appropriate comparison sign
    int RationalN=n*numComp.d;
    int RationalD= d*numComp.n;
    
    if(RationalN/RationalD>1){
        return '>';
    }else if(RationalN/RationalD<1){
        return '<';
    }else{
       return '=';
    }

};

std::string Rational::toString(){ //returns a string value for the real number
    string str;
    
    stringstream ss;
    ss<<n<<'/'<<d;

    str = ss.str();
    
    return str;
};


