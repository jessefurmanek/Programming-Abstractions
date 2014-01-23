//
//  bufferlp.cpp
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/23/14.
//
//

#include "bufferlp.h"
#include <iostream>
using namespace std;

EditorBuffer::EditorBuffer() {
    blockT *start = new blockT;
    blockT *end = new blockT;
    blockT *cursor= start;
    
    start->linkB = NULL;  //set the start blocks link forward to NULL
    end->linkF=NULL;  //set the end block's link backward to NULL
    cursor->ch = NULL;
}


EditorBuffer::~EditorBuffer() {
 
}

void EditorBuffer::moveCursorForward() {
   
}
void EditorBuffer::moveCursorBackward() {
 
}
void EditorBuffer::moveCursorToStart() {
  
}

void EditorBuffer::moveCursorToEnd() {

}

void EditorBuffer::insertCharacter(char ch) {
  
}


void EditorBuffer::deleteCharacter() {

}

void EditorBuffer::display() {
    //go to beginning
    
}