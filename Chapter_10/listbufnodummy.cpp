//
//  listbufnodummy.cpp
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/19/14.
//
//


#include "listbufnodummy.h"
#include <iostream>
using namespace std;

/*
 * File: listbuf.cpp
 * -----------------
 * This file implements the EditorBuffer class using a linked
 * list to represent the buffer.
 */



/*
 * Implementation notes: EditorBuffer constructor
 * ----------------------------------------------
 * This function initializes an empty editor buffer, represented
 * as a linked list.  To simplify the link list operation, this
 * implementation adopts the useful programming tactic of
 * keeping an extra "dummy" cell at the beginning of each list,
 * so that the empty buffer has the following representation:
 *
 *     +-------+          +------+
 *     |   o---+-----====>|      |
 *     +-------+    /     +------+
 *     |   o---+---/      | NULL |
 *     +-------+          +------+
 */

EditorBuffer::EditorBuffer() {
    cursor = new cellT;
    cursor->linkF = NULL;
    cursor->linkB = NULL;
    cursor->ch = NULL;
}
/*
 * Implementation notes: EditorBuffer destructor
 * ---------------------------------------------
 * The destructor must delete every cell in the buffer.  Note
 * that the loop structure is not exactly the standard idiom for
 * processing every cell within a linked list, because it is not
 * legal to delete a cell and later look at its link field.  To
 * avoid selecting fields in the structure after it has been
 * deallocated, you have to copy the link pointer before calling
 * delete.
 */
EditorBuffer::~EditorBuffer() {
    cellT *cp = cursor->linkF;
    while (cp != NULL) {
        cellT *next = cp->linkF;
        delete cp;
        cp = next;
    }
}

/*
 * Implementation notes: cursor movement
 * -------------------------------------
 * The four functions that move the cursor have different time
 * complexities because the structure of a linked list is
 * asymmetrical with respect to moving backward and forward.
 * Moving forward one cell is simply a matter of picking up the
 * link pointer; moving backward requires a loop until you reach
 * the current cursor position.  Similarly, moving to the start
 * of the buffer takes constant time, but finding the end requires
 * an O(N) loop.
 */
void EditorBuffer::moveCursorForward() {
    if (cursor->linkF != NULL) {
        cursor = cursor->linkF;
    }
}
void EditorBuffer::moveCursorBackward() {
    if (cursor->linkB != NULL) {
        cursor = cursor->linkB;
    }
}
void EditorBuffer::moveCursorToStart() {
    while(cursor->linkB != NULL){  //while cursor link back does not equal NULL
        moveCursorBackward();  //move cursor back
    }
}
void EditorBuffer::moveCursorToEnd() {
    while (cursor->linkF != NULL) {
        moveCursorForward();
    }
}
/*
 * Implementation notes: insertCharacter
 * -------------------------------------
 * The primary advantage of the linked list representation for
 * the buffer is that the insertCharacter operation can now be
 * accomplished in constant time.  The steps required are:
 *
 * 1. Allocate a new cell and put the new character in it.
 * 2. Copy the cursor pointer indicating both links.
 * 3. Update the link in the current cell to point to the new one.
 * 4. Move the cursor forward over the inserted character.
 */
void EditorBuffer::insertCharacter(char ch) {
    if (cursor->linkB==NULL){ //if in the first position
        cellT *cp = new cellT;
        cp->ch = ch;
        cp->linkF = cursor->linkF;
        cp->linkB = cursor;
        if(cursor->linkF != NULL) cursor->linkF->linkB = cp; //set the link backward
        cursor->linkF = cp;
        cursor->linkB = NULL;
    }else{ //if in the middle
        cellT *cp = new cellT;
        cp->ch = ch;
      
        if(cursor->linkF!=NULL){
            cp->linkF = cursor->linkF;
            cp->linkB = cursor;
            cp->linkF->linkB = cp; //set the link backward from the cell in front of cp
            cursor->linkF = cp;
            
        }else{  //if the cursor is at the end of the buffer
            if(cursor->linkF ==NULL){
            cp->linkF = NULL;  //link for the newly created cell(and now that last cell) is NULL
            cp->linkB = cursor->linkB->linkF;  //link backward for the last cell is to the former last cell
            cursor->linkF = cp;  //change the last cell so that it points forward to the new last cell
            cursor = cp->linkB;
            }else{
                
                
            }
        
 
        }
        
    }
}

/*
 * Implementation notes: deleteCharacter
 * -------------------------------------
 * As with insertCharacter, the list representation makes it
 * possible to implement the deleteCharacter operation in
 * constant time.  The necessary steps are:
 *
 * 1. Remove the current cell from the chain by "pointing around it".
 * 2. Free the cell to reclaim the memory.
 */
void EditorBuffer::deleteCharacter() {
    if (cursor->linkF != NULL) {
        
        if(cursor->linkB != NULL){
            cellT *oldcell = cursor->linkF;  //set a temp cell equal to the next cell in the chain
            cursor->linkF = oldcell->linkF;  //set the cursor link forward equal to the selected char cell's linkF
        
        
            if(cursor->linkF != NULL) cursor->linkF->linkB = cursor->linkB;  //point around the cell that is going to be deleted; ie the cell ahead of the cursor points backwards to where the cursor is currently pointing
            delete oldcell;  //delete pointer
        }else{
           cursor = cursor->linkF;  //set a temp cell equal to the next cell in the chain
           cursor->linkB = NULL;

        }
    }
}
/*
 * Implementation notes: display
 * -----------------------------
 * The display method uses the standard for loop idiom to loop
 * through the cells in the linked list.  The first loop displays
 * the character; the second marks the cursor position.
 */
void EditorBuffer::display() {
    //go to beginning
    
    cellT *begPlaceHolder;  //create a dummy pointer to find the beginning
    
    begPlaceHolder = cursor;
    
    while(begPlaceHolder->linkB != NULL){
        begPlaceHolder = begPlaceHolder->linkB;
    }
    
    for (cellT *cp = begPlaceHolder->linkF; cp != NULL; cp = cp->linkF) {
        cout << ' ' << cp->ch;
    }
    cout << endl;
    for (cellT *cp = begPlaceHolder; cp != cursor; cp = cp->linkF) {
        cout << "  "; }
    cout << '^' << endl;
}