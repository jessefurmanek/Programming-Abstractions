//
//  stackarraybuff.h
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/10/14.
//
//

#ifndef __Ch_10_Coursework__stackarraybuff__
#define __Ch_10_Coursework__stackarraybuff__

#include <iostream>

class EditorBuffer{
    
public:
    //constructor
    EditorBuffer();
    
    //deconstructor
    ~EditorBuffer();
    
    void moveCursorBackward();
    void moveCursorForward();
    void moveCursorToStart();
    void moveCursorToEnd();
    
    void insertCharacter(char ch);
    void deleteCharacter();
    void deleteCharBackwards();
    void display();
    
    void deleteWord();
    void moveForwardWord();
    void moveBackwardWord();
    void copy(int count);
    void paste();
    
private:
    
#include "stackarraybuffpriv.h"
    
};


#endif /* defined(__Ch_10_Coursework__stackarraybuff__) */
