//
//  labelgen.h
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 1/2/14.
//
//

#ifndef __Ch_9_Coursework__labelgen__
#define __Ch_9_Coursework__labelgen__

#include <iostream>
#include "string.h"

class LabelGenerator{
public:
    LabelGenerator(std::string labelName, int labelNum);
    ~LabelGenerator(); //deconstructor
    
    std::string nextLabel();

private:
    std::string labelName;
    int labelNum;
};

#endif /* defined(__Ch_9_Coursework__labelgen__) */
