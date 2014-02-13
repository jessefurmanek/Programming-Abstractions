//
//  vectorll.cpp
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/11/14.
//
//

#include "vectorll.h"
#include "vectorllpriv.h"

#ifndef __Ch_11_Coursework__vectorll__

/*
 * Implementation notes: Vector constructor and destructor
 * -------------------------------------------------------
 * The constructor allocates storage for the dynamic array
 * and initializes the other fields of the object. */

template <typename ElemType>
Vector<ElemType>::Vector() {
    vectorBlock *start = new vectorBlock;
    start->blkPointer

  
}

template <typename ElemType>
Vector<ElemType>::~Vector() {

}


template <typename ElemType>
inline int Vector<ElemType>::size() {

}

template <typename ElemType>
bool Vector<ElemType>::isEmpty() {

}

template <typename ElemType>
void Vector<ElemType>::clear() {
    
}
￼￼￼￼

template <typename ElemType>
ElemType Vector<ElemType>::getAt(int index) {
   
}
template <typename ElemType>
void Vector<ElemType>::setAt(int index, ElemType elem) {
   
}
/*
 * Implementation notes: insertAt, removeAt, add
 * ---------------------------------------------
 * These methods must shift the existing elements in the array to
 * make room for a new element or to close up the space left by a
 * deleted one.
 */
template <typename ElemType>

void Vector<ElemType>::insertAt(int index, ElemType elem) {
  
}

template <typename ElemType>
void Vector<ElemType>::removeAt(int index) {
   
}

template <typename ElemType>
void Vector<ElemType>::add(ElemType elem) {

}

template <typename ElemType>
ElemType & Vector<ElemType>::operator[](int index) {
    
    //overloaded operator
}

//not including the iterator


#endif