//
//  vectorll.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/11/14.
//
//

#ifndef __Ch_11_Coursework__vectorll__
#define __Ch_11_Coursework__vectorll__

#include <iostream>


/*
 * Class: Vector
 * -------------
 * This interface defines a class template that stores a homogeneous
 * indexed collection.  The basic operations are similar to those
 * in the built-in array type, with the added features of dynamic
 * memory management, bounds-checking on indexes, and convenient
 * insert/remove operations.  Like an array, but better!  For
 * maximum generality, the Vector is supplied as a class template.
 * The client specializes the vector to hold values of a specific
 * type, such as Vector<int> or Vector<studentT>.
 */
template <typename ElemType>
class Vector {
public:
    /*
     * Constructor: Vector
     * Usage: Vector<int> vec;
     * -----------------------
     * The constructor initializes a new empty vector.
     */
    Vector();
    /*
     * Destructor: ~Vector
     * Usage: (usually implicit)
     * -------------------------
     * Frees the storage associated with this vector.
     */
    ~Vector();
    
    
    /*
     * Method: size
     * Usage: nElems = vec.size();
     * ---------------------------
     * Returns the number of elements in this vector.
     */
    int size();
    
    
    /*
     * Method: isEmpty
     * Usage: if (vec.isEmpty())...
     * -----------------------------
     * Returns true if this vector contains no elements, false otherwise.
     */
    bool isEmpty();
    /*
     * Method: clear
     * Usage: vec.clear();
     * -------------------
     * Removes all elements from this vector.
     */
    void clear();
    /*
     * Method: getAt
     * Usage: val = vec.getAt(3);
     * --------------------------
     * Returns the element at the specified index in this vector.
     * Elements are indexed starting with 0.  A call to vec.getAt(0)
     * returns the first element; vec.getAt(vec.size()-1) returns the
     * last.  Raises an error if index is not in the range [0, size()-1].
     */
    ElemType getAt(int index);
    /*
     * Method: setAt
     * Usage: vec.setAt(3, value);
     * ---------------------------
     * Replaces the element at the specified index in this vector with
     * a new value.  The previous value at that index is overwritten.
     * Raises an error if index is not in the range [0, size()-1].
     */
    void setAt(int index, ElemType value);
    /*
     * Method: insertAt
     * Usage: vec.insertAt(0, value);
     * ------------------------------
     * Inserts the element into this vector before the specified index,
     * shifting all subsequent elements one index higher.  A call to
     * vec.insertAt(0, val) inserts a new element at the beginning;
     * vec.insertAt(vec.size(), val) adds a new element to the end.
     * Raises an error if index is outside the range [0, size()].
     */
    void insertAt(int index, ElemType elem);
    
    /*
     * Method: removeAt
     * Usage: vec.removeAt(3);
     * -----------------------
     * Removes the element at the specified index from this vector,
     * shifting all subsequent elements one index lower.  A call to
     * vec.removeAt(0) removes the first element, while a call to
     * vec.removeAt(vec.size()-1), removes the last.  Raises an error
     * if index is outside the range [0, size()-1].
     */
    void removeAt(int index);
    /*
     * Method: add
     * Usage: vec.add(value);
     * ----------------------
     * Adds an element to the end of this vector.
     */
    void add(ElemType elem);
    /*
     * Method: operator[]
     * Usage: vec[0] = vec[1];
     * -----------------------
     * Overloads [] to select elements from this vector.  This extension
     * allows the client to use traditional array notation to get/set
     * individual elements.  Returns a reference to the element to
     * allow in-place modification of values.  Raises an error if the
     * index is outside the range [0, size()-1].
     */
    ElemType & operator[](int index);
 
private:
#include "vectorllpriv.h"
};

#include "vectorll.cpp"

#endif /* defined(__Ch_11_Coursework__vectorll__) */
