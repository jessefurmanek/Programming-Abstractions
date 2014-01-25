//
//  bufferlp.h
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/23/14.
//
//

#ifndef __Ch_10_Coursework__bufferlp__
#define __Ch_10_Coursework__bufferlp__

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
    void display();
    
private:
    
#include "bufferlppriv.h"
    
};


#endif /* defined(__Ch_10_Coursework__bufferlp__) */
