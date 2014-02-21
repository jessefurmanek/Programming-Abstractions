//
//  firstmap.cpp
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 2/20/14.
//
//

#include "firstmap.h"
#include "simpio.h"
using namespace std;

void question1(){
    
    int romarray[256];
    
    for(int x='A'; x<'z'; x++){
        romarray[x]= 0;
    }
    
    
    romarray['I'] = 1;
    romarray['V'] = 5;
    romarray['X']= 10;
    romarray['L']= 50;
    romarray['C']= 100;
    romarray['D']= 500;
    romarray['M']= 1000;
    
    
    romarray['i'] = 1;
    romarray['v'] = 5;
    romarray['x']= 10;
    romarray['l']= 50;
    romarray['c']= 100;
    romarray['d']= 500;
    romarray['m']= 1000;
    

    
    
    cout<<"Input Roman Numerals>>"<<flush;
    string strRomInput =  getLine();
    
    
    int sum=0;
    
    for(int x=0; x<strRomInput.length(); x++){
        
        if(x != strRomInput.length()-1){  //if not in the last position of the string
            if(romarray[strRomInput[x]]<romarray[strRomInput[x+1]]){
                
                char a =strRomInput[x];
                char b =strRomInput[x+1];
                
                sum-=romarray[strRomInput[x]];
            }else{
                sum+=romarray[strRomInput[x]];
            }
        }else{
            sum+=romarray[strRomInput[x]];
        }
        
    }
    
    
    cout<<endl;
    cout<<">>"<<sum<<endl;
    
    
}