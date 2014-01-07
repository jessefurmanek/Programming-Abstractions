//
//  arraybuff.h
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/6/14.
//
//

#ifndef __Ch_10_Coursework__arraybuff__
#define __Ch_10_Coursework__arraybuff__

#include <iostream>

class EditorBuffer{

public:
//constructor
    EditorBuffer();

//deconstructor
    ~EditorBuffer();
    
void moveCursorForward();
void moveCursorBackward();
void moveCursorToStart();
void moveCursorToEnd();
    
void insertCharacter(char ch);
void deleteCharacter();
void display();


private:
    
    #include "arrbuffpriv.h"
    
};

#endif /* defined(__Ch_10_Coursework__arraybuff__) */
