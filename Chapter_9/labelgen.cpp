//
//  labelgen.cpp
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 1/2/14.
//
//

#include "labelgen.h"
#include <iostream>
#include "string.h"
#include "strlib.h"

LabelGenerator::LabelGenerator(std::string labelName, int labelNum){
    this -> labelName = labelName;
    this -> labelNum  = labelNum;
}
LabelGenerator::~LabelGenerator(){};

std::string LabelGenerator::nextLabel(){
    int labelNumCopy=labelNum;
    std::string space = " ";
    labelNum++;  //increment the label num value;
    return labelName.c_str()+space+integerToString(labelNumCopy);
   
}