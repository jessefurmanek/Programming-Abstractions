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
#include "error.h"

/*
 Using a linked list vector makes the add and clear function run slower; but the insert and remove functions run faster
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
    start = new vectorBlock;
    start->blkPointer=NULL;
    length =0;
    
}

template <typename ElemType>
Vector<ElemType>::~Vector() {
    vectorBlock *cp = start;
    while (cp->blkPointer != NULL) {
        vectorBlock *next = cp->blkPointer;
        delete cp;
        cp = next;
    }
    
    delete cp;
}


template <typename ElemType>
inline int Vector<ElemType>::size() {
    return length;
    
}

template <typename ElemType>
bool Vector<ElemType>::isEmpty() {
    
    return length==0;
}

template <typename ElemType>
void Vector<ElemType>::clear() {
    //delete everything
    
    vectorBlock *cp = start->blkPointer;
    while (cp->blkPointer!= NULL) {
        vectorBlock *next = cp->blkPointer;
        delete cp;
        cp = next;
    }
    
    start->blkPointer=NULL;
    length=0;
}

template <typename ElemType>
ElemType Vector<ElemType>::getAt(int index) {
    
    if (index < 0 || index > length-1) {
        error("Vector selection index out of range");
    }
    
    int x = 0;
    vectorBlock *current;
    
    for (current =start->blkPointer;  x<index; current = current->blkPointer){
       //iterate through the vector to get to the index point
        x++;
    }
    
    return current->data;
    
}

template <typename ElemType>
void Vector<ElemType>::setAt(int index, ElemType elem) {
    
    if(start->blkPointer==NULL) error("Trying to set at an empty vector");
    
    int x = 0;
    vectorBlock *current;
    
    for (current = start->blkPointer;  x<index; current = current->blkPointer){
        //iterate through the vector to get to the index point
        x++;
    }
    
    current->data=elem;
    
}

template <typename ElemType>
void Vector<ElemType>::insertAt(int index, ElemType elem) {
  
    if(start->blkPointer==NULL) error("Trying to insert into an empty vector");
    
    int x = 0;
    vectorBlock *current;
    
    for (vectorBlock *cp = start;  x<index; cp = cp->blkPointer){
            current = cp;  //iterate through the vector to get to the index point
    }
    
    
    if(current->blkPointer==NULL){  //if at the end of the vector
        vectorBlock *newBlock = new vectorBlock;
        newBlock->data=elem;
        newBlock->blkPointer=NULL;
        current->blkPointer=newBlock;
        
    }else{
    
        vectorBlock *newBlock = new vectorBlock;
        newBlock->data=elem;
        newBlock->blkPointer=current->blkPointer;
        current->blkPointer=newBlock;
    }
    length++;
    
}

template <typename ElemType>
void Vector<ElemType>::removeAt(int index) {
    
    if(start->blkPointer==NULL) error("Trying to delete an empty vector");
    
    int x = 0;
    vectorBlock *current;
    
    for (current =start;  x<index; current = current->blkPointer){
        //iterate through the vector to get to the index point
        x++;
    }
    

    if(current->blkPointer->blkPointer==NULL){  //if at the end of the vector
        vectorBlock *temp = current->blkPointer;
        current->blkPointer=NULL;
        delete temp;
    }else{
        vectorBlock *temp = current->blkPointer;
        current->blkPointer=temp->blkPointer;
        delete temp;
    }
    
    length--;
}

template <typename ElemType>
void Vector<ElemType>::add(ElemType elem) {

    vectorBlock *current;
    
    for (current = start;  current->blkPointer!=NULL; current = current->blkPointer){
    }
    
    vectorBlock *newBlock = new vectorBlock;
    newBlock->data=elem;
    newBlock->blkPointer=NULL;
    current->blkPointer = newBlock;
    
    length++;
    
}

template <typename ElemType>
ElemType & Vector<ElemType>::operator[](int index) {
    
    if (index < 0 || index > length-1) {
        error("Vector selection index out of range");
    }
    
    int x = 0;
    vectorBlock *current;
    
    for (current =start->blkPointer;  x<index; current = current->blkPointer){
        //iterate through the vector to get to the index point
        x++;
    }
    
    return current->data;
}

//not including the iterator



#endif /* defined(__Ch_11_Coursework__vectorll__) */
