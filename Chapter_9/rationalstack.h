//
//  rationalstack.h
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 1/1/14.
//
//

#ifndef __Ch_9_Coursework__rationalstack__
#define __Ch_9_Coursework__rationalstack__

#include <iostream>
#include "vector.h"
#include "rational.h" //include the rational type
#include "charstack.h"

class RatStackVec {
public:
    
    /*
     * Constructor: CharStack
     * Usage: CharStack cstk;
     * ----------------------
     * Initializes a new empty stack that can contain characters.
     */
    
    RatStackVec();
    
    /*
     * Destructor: ~CharStack
     * Usage: (usually implicit)
     * -------------------------
     * Deallocates storage associated with this cstk.  This method is
     * called whenever a CharStack instance variable is deallocated.
     */
    
    ~RatStackVec();
    
    
    /*
     * Method: size
     * Usage: nElems = cstk.size();
     * ----------------------------
     * Returns the number of characters in this stack.
     */
    
    int sizeVec();
    
    /*
     * Method: isEmpty
     * Usage: if (cstk.isEmpty()) . . .
     * --------------------------------
     * Returns true if this stack contains no characters, and false
     * otherwise.
     */
    bool isEmptyVec();
    
    
    /*
     * Method: clear
     * Usage: cstk.clear();
     * --------------------
     * This method removes all characters from this stack.
     */
    void clearVec();
    
    /*
     * Method: push
     * Usage: cstk.push(ch);
     * ---------------------
     * Pushes the character ch onto this stack.
     */
    void pushVec(Rational ratElement);
    
    
    /*
     * Method: pop
     * Usage: topChar = cstk.pop();
     * ----------------------------
     * Removes the top character from this stack and returns it.
     */
    Rational popVec();
    
    
    /*
     * Method: peek
     * Usage: topChar = cstk.peek();
     * -----------------------------
     * Returns the value of top character from this stack without
     * removing it.  Raises an error if called on an empty stack.
     */
    Rational peekVec();
    
    
private:
    // Fill this in when the data structure design is complete
    
    static const int INITIAL_CAPACITY = 100;
    Vector<int> NumVec;  //initialize a vector
    Vector<int> DenVec;
    int capacity;
    int count;     
    
};


#endif /* defined(__Ch_9_Coursework__rationalstack__) */
