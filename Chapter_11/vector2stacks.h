//
//  vector2stacks.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/13/14.
//
//

#ifndef __Ch_11_Coursework__vector2stacks__
#define __Ch_11_Coursework__vector2stacks__

#include <iostream>
#include "error.h"

/*
 problem 6: reimplement the vector using two stacks
 */
template <typename ElemType>
class Vector {
public:

    Vector();
 
    ~Vector();
    
    
    
    int size();
    
    
    
    bool isEmpty();
    
    void clear();
    
    ElemType getAt(int index);
    
    void setAt(int index, ElemType value);
    
    void insertAt(int index, ElemType elem);
    
    
    void removeAt(int index);
    
    void add(ElemType elem);
    
    ElemType & operator[](int index);
    
private:
    
#include "vectorllpriv.h"
    
};

template <typename ElemType>
Vector<ElemType>::Vector() {
 
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

template <typename ElemType>
ElemType Vector<ElemType>::getAt(int index) {
    
   
    
}

template <typename ElemType>
void Vector<ElemType>::setAt(int index, ElemType elem) {
    

    
}

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

}


#endif /* defined(__Ch_11_Coursework__vector2stacks__) */
