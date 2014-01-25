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
    start = new blockT;
    end = new blockT;
    cursor= start;
    
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
        blockT *insertBlock = new blockT;
    
        cursor->linkF->linkB = insertBlock;
        cursor->linkF->linkB->linkF= insertBlock;
}


void EditorBuffer::deleteCharacter() {

}

void EditorBuffer::display() {
    //go to beginning
    
    blockT *begPlaceHolder;  //create a dummy pointer to find the beginning
    
    begPlaceHolder = start;
    
    while(begPlaceHolder->linkB != NULL){
        begPlaceHolder = begPlaceHolder->linkB;
    }
    
    for (blockT *cp = begPlaceHolder->linkF; cp != NULL; cp = cp->linkF) {
        cout << ' ' << cp->ch;
    }
    cout << endl;
    for (blockT *cp = begPlaceHolder; cp != cursor; cp = cp->linkF) {
        cout << "  "; }
    cout << '^' << endl;
}