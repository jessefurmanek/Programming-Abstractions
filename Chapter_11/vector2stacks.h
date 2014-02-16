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
#include "stack.h"


/*
 problem 6: reimplement the vector using two stacks
 */
template <typename ElemType>
class VectorTwoStx {
public:

    VectorTwoStx();
 
    ~VectorTwoStx();
    
    
    
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
    
#include "vector2stxpriv.h"
    
};

template <typename ElemType>
VectorTwoStx<ElemType>::VectorTwoStx() {
    midPt = 0;
    
}

template <typename ElemType>
VectorTwoStx<ElemType>::~VectorTwoStx() {

}


template <typename ElemType>
inline int VectorTwoStx<ElemType>::size() {
    
    return (stackone.size()+stacktwo.size());
}

template <typename ElemType>
bool VectorTwoStx<ElemType>::isEmpty() {
    
    return (stackone.size()+stacktwo.size()==0);
}

template <typename ElemType>
void VectorTwoStx<ElemType>::clear() {
    int stackoneInitsize = stackone.size();
    int stacktwoInitsize = stacktwo.size();
    
    for(int x=0; x<stackoneInitsize; x++){  //pop off all elements of stackone
        stackone.pop();
    }
    
    for(int x=0; x<stacktwoInitsize; x++){
        stacktwo.pop();                       //pop off all elemetns of stacktwo
    }
 
}

template <typename ElemType>
ElemType VectorTwoStx<ElemType>::getAt(int index) {
    if(index<0 || index>=(stackone.size()+stacktwo.size())){
        error("index is not within a valid range");
    }
    
    int  stackoneInitsize = stackone.size();
    
    if(index<stackone.size()){
        for(int x=1; x<stackoneInitsize-index; x++){  /*x=1 is used to compensate for the fact that the largest size will always be one greater than the largest index in stack one */
            stacktwo.push(stackone.pop());  //move excess stack one letters to stack two
        }
        return stackone.peek();
    }else{
        for(int x=0; x<(index-stackoneInitsize); x++){
            stackone.push(stacktwo.pop());  //move excess stack two letters to stack one
        }
        
        return stacktwo.peek();
    }
   
    error("index is not within a valid range");
    return 0;  //because no one likes a compile error
}

template <typename ElemType>
void VectorTwoStx<ElemType>::setAt(int index, ElemType elem) {
    if(index<0 || index>=(stackone.size()+stacktwo.size())){
        error("index is not within a valid range");
    }
    
    int  stackoneInitsize = stackone.size();
    
    if(index<stackone.size()){
        for(int x=1; x<stackoneInitsize-index; x++){  /*x=1 is used to compensate for the fact that the largest size will always be one greater than the largest index in stack one */
            stacktwo.push(stackone.pop());  //move excess stack one letters to stack two
        }
        stackone.pop();  //remove requested index
        stackone.push(elem); //set requested index
    }else{
        for(int x=0; x<(index-stackoneInitsize); x++){
            stackone.push(stacktwo.pop());  //move excess stack two letters to stack one
        }
        
        stacktwo.pop();  //remove requested index
        stacktwo.push(elem); //set requested index
    }

    
}

template <typename ElemType>
void VectorTwoStx<ElemType>::insertAt(int index, ElemType elem) {
    if(index<0 || index>=(stackone.size()+stacktwo.size())){
        error("index is not within a valid range");
    }
    
    int  stackoneInitsize = stackone.size();
   
    if(index<stackone.size()){
        for(int x=0; x<(stackoneInitsize-index); x++){
        stacktwo.push(stackone.pop());     //if the index is in stack one, move every element including the inserted at element to stack two
        }
        
        stackone.push(elem);
    }else{  /* if the index value is greater or equal to the size of the index, the index is going to be located on the second stack.  therefore, move excess elements from stack 2 to get to the referenced index.
             */
        for(int x=0; x<(index-stackoneInitsize); x++){  /* subtract index from stack 1 size to reset index count on stack2.  meaning, if the index is on the top of the second stack, the index value will be equal to the size of stack1, as stack1 end on a value one less than the size of the stack.  this means if the index value is equal to the top of stack 2, subtracting the size of stack1 will not pop any values off of stack2.  the element will then be pushed to stack1, in effect inserting in constant time.... i think.
                */
            stackone.push(stacktwo.pop());
        }
        
        stackone.push(elem);
    }

    
}

template <typename ElemType>
void VectorTwoStx<ElemType>::removeAt(int index) {
    if(index<0 || index>=(stackone.size()+stacktwo.size())){
        error("index is not within a valid range");
    }
    
    if(index<stackone.size()){
        for(int x=1; x<stackone.size()-index; x++){  /*x=1 is used to compensate for the fact that the largest size will always be one greater than the largest index in stack one */
            stacktwo.push(stackone.pop());  //move excess stack one letters to stack two
        }
        stackone.pop();  //remove requested index
    }else{
        for(int x=0; x<(stackone.size()-index); x++){
            stackone.push(stacktwo.pop());  //move excess stack two letters to stack one
        }
        
        stacktwo.pop();  //remove requested index
    }
}

template <typename ElemType>
void VectorTwoStx<ElemType>::add(ElemType elem) {
    
    int stacktwoInitsize=stacktwo.size();
    
    for(int x=0; x<stacktwoInitsize; x++){
        stackone.push(stacktwo.pop());   //put all of stacktwos elements onto stackone
    }

    stackone.push(elem); //push the new element onto stackone
    
    
}

#endif /* defined(__Ch_11_Coursework__vector2stacks__) */
