//
//  charstack.h
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 12/18/13.
//
//

#ifndef __Ch_9_Coursework__charstack__
#define __Ch_9_Coursework__charstack__

#include <iostream>


class CharStack {
public:
    
    /*
     * Constructor: CharStack
     * Usage: CharStack cstk;
     * ----------------------
     * Initializes a new empty stack that can contain characters.
     */
    
    CharStack();
    
    /*
     * Destructor: ~CharStack
     * Usage: (usually implicit)
     * -------------------------
     * Deallocates storage associated with this cstk.  This method is
     * called whenever a CharStack instance variable is deallocated.
     */
    
    ~CharStack();
    
    
    /*
     * Method: size
     * Usage: nElems = cstk.size();
     * ----------------------------
     * Returns the number of characters in this stack.
     */
    
    int size();
    
    /*
     * Method: isEmpty
     * Usage: if (cstk.isEmpty()) . . .
     * --------------------------------
     * Returns true if this stack contains no characters, and false
     * otherwise.
     */
    bool isEmpty();
    
    
    /*
     * Method: clear
     * Usage: cstk.clear();
     * --------------------
     * This method removes all characters from this stack.
     */
    void clear();
    
    /*
     * Method: push
     * Usage: cstk.push(ch);
     * ---------------------
     * Pushes the character ch onto this stack.
     */
    void push(char ch);
    
    
    /*
     * Method: pop
     * Usage: topChar = cstk.pop();
     * ----------------------------
     * Removes the top character from this stack and returns it.
     */
    char pop();
    
    
    /*
     * Method: peek
     * Usage: topChar = cstk.peek();
     * -----------------------------
     * Returns the value of top character from this stack without
     * removing it.  Raises an error if called on an empty stack.
     */
    char peek();
    
    
private:
    // Fill this in when the data structure design is complete

    static const int INITIAL_CAPACITY = 100;
    char *elements;  //initialize a pointer for a dynamic array
    int capacity;  //allocated size of the dynamic array
    int count;     //current count of chars on the stack
    
    void expandCapacity();  //method to expand the array
    
};
    

#endif /* defined(__Ch_9_Coursework__charstack__) */
