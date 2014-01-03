//
//  randword.cpp
//  Blank Project
//
//  Created by Jesse Furmanek on 7/27/13.
//
//

#include "randword.h"
#include "random.h"
#include "console.h"
#include "simpio.h"
#include <string>
#include <iostream>
#include <fstream>

/* take the name of a data file containing a list of words, one per line, and read it into an array declared as a static global variable in the implementation */

std::string *globalArray;
int lineCount=0;

std::string InitDictionary(std::string filename){
    std::string str = "";
    
    
    std::ifstream infile;
    infile.open(filename.c_str());
    
    while(true){
        std::string line;
        getline(infile, line);  //get new line from file, store as string 'line'
        if (infile.fail()){
                   //if the load fails or it reaches to the end of the line, fail
            break;
        }
        lineCount++;
    }
    
    infile.clear();
    infile.seekg(0, std::ios::beg);
    
    globalArray = new std::string[lineCount]; //create an array as big as the number of words in the dictionary
    
    int x=0;
    
    while(true){
        std::string line;
        getline(infile, line);  //get new line from file, store as string 'line'
        if (infile.fail()){
        //if the load fails or it reaches to the end of the line, fail
            break;
        }
        globalArray[x]=line;
        x++;
    }
    
    return str;
        
}

/*returns a word chosen at random from the internally maintained array*/
std::string ChooseRandomWord(){
    std::string word;
    int randomNumber;
    
    randomNumber = randomInteger(0, lineCount);
    
    word = globalArray[randomNumber];
    
    return word;
}






