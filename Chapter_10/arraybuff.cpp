//
//  arraybuff.cpp
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/6/14.
//
//

#include "arraybuff.h"
#include "arrbuffpriv.h"


/*
 * File: arraybuf.cpp
 * ------------------
 * This file implements the EditorBuffer class using an
 * array to represent the buffer.
 */
#include <iostream>

using namespace std;
/* Constants */

/*
 * Implementation notes: EditorBuffer
 * ----------------------------------
 * In this representation of the buffer, the characters are stored
 * in a dynamic array along with integers storing the capacity of
 * the buffer (its allocated size), the length of the buffer (its
 * effective size), and the cursor position.  The cursor position
 * indicates the index position of the character that follows where
 * the cursor would appear on the screen.  The constructor simply
 * initializes that structure.
 */


EditorBuffer::EditorBuffer() {
    rtRow.chString = new char[INITIAL_CAPACITY]; //initialize first row of characters
    rtRow.chLength = new int[INITIAL_CAPACITY];  //initialize the length array
    rtRow.chLength[0] = 0;
    rtRow.rowLink = new RowT[ROW_CAPACITY]; //link to next row
    cursorRow=0;
    cursorPlace = 0;
    lastRow = 0;
}
/*
 * Implementation notes: ~EditorBuffer
 * -----------------------------------
 * The destructor has to free any memory that is allocated
 * along the way in order to supp
 ort the guarantee that
 * the editor buffer not leak memory.  The only dynamically
 * allocated memory is the dynamic array that stores the text.
 */
EditorBuffer::~EditorBuffer() {
    delete[] rtRow.chString;
}

/*
 * Implementation notes: moveCursor methods
 * ----------------------------------------
 * The four moveCursor methods simply adjust the value of the
 * cursor instance variable.
 */
void EditorBuffer::moveCursorForward() {
    if (cursorPlace < rtRow.chLength[cursorPlace]){  //if cursor is less than the length of the ch array
        if(rtRow.chString[cursorPlace+1]==10){ //if the next value is equal to newline
            cursorPlace++;
            cursorRow++;
        }else{
            cursorPlace++;
        }
    }
 }

void EditorBuffer::moveCursorBackward(){
    if (cursorPlace==0){
        if(cursorRow>0){ //if at the first place in row, and NOT in the first row
            cursorRow--;  //move the cursor up one row
            cursorPlace =rtRow.chLength[cursorRow]-1; //set cursor equal to length of char array
        }else{
        cursorPlace--;
        }
    }
}
    
    
void EditorBuffer::moveCursorToStart(){
    cursorPlace=0;
    cursorRow=0;
}

void EditorBuffer::moveCursorToEnd() {
    cursorRow = lastRow;
    cursorPlace = rtRow.chLength[lastRow]-1;
}

/*
 * Implementation notes: insertCharacter and deleteCharacter
 * ---------------------------------------------------------
 * Each of the functions that inserts or deletes characters
 * must shift all subsequent characters in the array, either
 * to make room for new insertions or to close up space left
 * by deletions.
 */

void EditorBuffer::insertCharacter(char ch) {
    if (cursorPlace == rtRow.chLength[cursorRow]) expandCapacity();
    
    for (int i = rtRow.chLength[cursorRow]; i > cursorPlace; i--) {  //starting at the back of the array and until you reach the cursor
        rtRow.chString[i] = rtRow.chString[i - 1];  //move everything up one
    }
    rtRow.chString[cursorPlace] = ch;
    rtRow.chLength[cursorRow]++; //increase the length of the current char array
    cursorPlace++;  //increase the cursor to match where it was previously
}

void EditorBuffer::deleteCharacter() {
    if (cursorPlace < rtRow.chLength[cursorRow]) {
        for (int i = cursorPlace+1; i < tRow.chLength[cursorRow]; i++) {  //starting one ahead of the cursor
            array[i - 1] = array[i];  //shift everything backwards
        }
        rtRow.chLength[cursorRow]--; //decrease the length of the current char array
        cursorPlace--;  //decrease the cursor to match where it was previously
    }
}




/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This private method doubles the size of the array whenever
 * it runs out of space.  To do so, it must allocate a new array,
 * copy all the characters from the old array to the new one, and
 * then free the old storage.
 */

void EditorBuffer::expandCapacity() {
    char *oldChString = rtRow.chString;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++) {
        array[i] = oldArray[i];
    }
    delete[] oldArray;
}


void EditorBuffer::display() {
    for (int i = 0; i < length; i++) {
        cout << ' ' << array[i];
    }
    cout << endl;
    for (int i = 0; i < cursor; i++) {
        cout << " "; }
    cout << '^' << endl;
}
