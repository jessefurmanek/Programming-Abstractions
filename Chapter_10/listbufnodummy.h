//
//  listbufnodummy.h
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/19/14.
//
//

#ifndef __Ch_10_Coursework__listbufnodummy__
#define __Ch_10_Coursework__listbufnodummy__

#include <iostream>

/*
 * Class: EditorBuffer
 * -------------
 * This class defines the class used to represent
 * an editor buffer.
 */
class EditorBuffer {
public:
    /*
     * Constructor: EditorBuffer
     * Usage: EditorBuffer buffer;
     *        EditorBuffer *bp = new EditorBuffer();
     * ---------------------------------
     * The constructor initializes a newly allocated buffer
     * to represent an empty buffer.
     */
    EditorBuffer();
    /*
     * Destructor: ~EditorBuffer
     * Usage: (usually implicit)
     * -------------------------
     * The destructor frees any storage associated with this buffer.
     */
    ~EditorBuffer();
    /*
     * Methods: moveCursorForward, moveCursorBackward
     * Usage: buffer.moveCursorForward();
     *        buffer.moveCursorBackward();
     * -----------------------------------
     * These functions move the cursor forward or backward one
     * character, respectively.  If you call moveCursorForward
     * at the end of the buffer or moveCursorBackward at the
     * beginning, the function call has no effect.
     */
    void moveCursorForward();
    void moveCursorBackward();
    
    /*
     * Methods: moveCursorToStart, moveCursorToEnd
     * Usage: buffer.moveCursorToStart();
     *        buffer.moveCursorToEnd();
     * --------------------------------
     * These functions move the cursor to the start or the end of this
     * buffer, respectively.
     */
    void moveCursorToStart();
    void moveCursorToEnd();
    /*
     * Method: insertCharacter
     * Usage: buffer.insertCharacter(ch);
     * ----------------------------------
     * This function inserts the single character ch into this
     * buffer at the current cursor position.  The cursor is
     * positioned after the inserted character, which allows
     * for consecutive insertions.
     */
    void insertCharacter(char ch);
    /*
     * Method: deleteCharacter
     * Usage: buffer.deleteCharacter();
     * --------------------------------
     * This function deletes the character immediately after
     * the cursor.  If the cursor is at the end of the buffer,
     * this function has no effect.
     */
    void deleteCharacter();
    /*
     * Method: display
     * Usage: buffer.display();
     * ------------------------
     * This function displays the current contents of this buffer
     * on the console.
     */
    void display();
    
    
private:
#include "listbufpriv.h"
    
};


#endif /* defined(__Ch_10_Coursework__listbufnodummy__) */


