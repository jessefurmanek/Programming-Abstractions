//
//  queuell.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/9/14.
//
//

#ifndef __Ch_11_Coursework__queuell__
#define __Ch_11_Coursework__queuell__

#include <iostream>
#include "error.h"

template <typename ElemType>

class Queue {
    
public:
    /*
     * Constructor: Queue
     * Usage: Queue<int> queue;
     * ------------------------
     * The constructor initializes a new empty queue containing
     * the specified value type.
     */
    Queue();
    /*
     * Destructor: ~Queue
     * Usage: (usually implicit)
     * -------------------------
     * The destructor deallocates any heap storage associated
     * with this queue.
     */
    ~Queue();
    /*
     * Method: size
     * Usage: nElems = queue.size();
     * -----------------------------
     * Returns the number of elements in this queue.
     */
    int size();
    /*
     * Method: isEmpty
     * Usage: if (queue.isEmpty()) . . .
     * ---------------------------------
     * Returns true if this queue contains no elements, and false
     * otherwise.
     */
    bool isEmpty();
    /*
     * Method: clear
     * Usage: queue.clear();
     * ---------------------
     * This method removes all elements from this queue.
     */
    void clear();
    /*
     * Method: enqueue
     * Usage: queue.enqueue(elem);
     * ---------------------------
     * Adds the specified element to the end of this queue.
     */
    void enqueue(ElemType elem);
    /*
     * Method: dequeue
     * Usage: first = queue.dequeue();
     * -------------------------------
     * Removes the first element from this queue and returns it.
     * Raises an error if called on an empty queue.
     */
    
    void enqueue(ElemType elem, double setPriority);
    
    
    void reverse(); //reverses the queue;
    
    
    ElemType dequeue();
    /*
     * Method: peek
     * Usage: topElem = queue.peek();
     * ------------------------------
     * Returns the value of first element from this queue without
     * removing it.  Raises an error if called on an empty queue.
     */
    ElemType peek();
    
private:
    
 #include "queuellpriv.h"
    
};

template <typename ElemType>


Queue<ElemType>::Queue() {
    start = new queueBlock;
    start->blockPtr=NULL;
    start->priority=0;
    current=start;
    queueSize =0;
}
/*
 * Implementation notes: ~Queue destructor
 * ---------------------------------------
 * The destructor frees any memory that is allocated by the
 * implementation.  Freeing this memory guarantees the client
 * that the queue abstraction will not "leak memory" in the
 * process of running an application.
 */
template <typename ElemType>
Queue<ElemType>::~Queue() {
    
    queueBlock *cp = start;
    while (cp->blockPtr != NULL) {
        queueBlock *next = cp->blockPtr;
        delete cp;
        cp = next;
    }
    
}

/*
 * Implementation notes: size
 * --------------------------
 * The size of the queue can be calculated from the head and tail
 * indices by using modular arithmetic.
 */
template <typename ElemType>
int Queue<ElemType>::size() {
    return queueSize;
    
}
/*
 * Implementation notes: isEmpty
 * -----------------------------
 * The queue is empty whenever the head and tail pointers are
 * equal.  Note that this interpretation means that the queue
 * cannot be allowed to fill the capacity entirely and must
 * always leave one unused space.
 */
template <typename ElemType>
bool Queue<ElemType>::isEmpty() {
    return queueSize==0;                  //if queue is empty, the number of elemetns should be zero
}
/*
 * Implementation notes: clear
 * ---------------------------
 * The clear method need not take account of where in the
 * ring buffer any existing data is stored and can simply
 * set the head and tail index back to the beginning.
 */
template <typename ElemType>
void Queue<ElemType>::clear() {
    current=start;
    queueSize=0;
}
/*
 * Implementation notes: enqueue
 * -----------------------------
 * This method must first check to see whether there is
 * enough room for the element and expand the array storage
 * if necessary.  Because it is otherwise impossible to
 * differentiate the case when a queue is empty from when
 * it is completely full, this implementation expands the
 * queue when the size is one less than the capacity.
 */
template <typename ElemType>
void Queue<ElemType>::enqueue(ElemType elem) {
    queueBlock *newBlock = new queueBlock;  //create a new block
    newBlock->valueCell = elem;
    newBlock->priority=0;
    newBlock->blockPtr=NULL;  //set it's pointer to NULL
    current->blockPtr=newBlock;  //set the current block's pointer to the new block
    current = newBlock;  //set thet current block equal to the new block
    queueSize++;
}


template <typename ElemType>
void Queue<ElemType>::enqueue(ElemType elem, double setPriority){
    if(setPriority>0){

        queueBlock *newBlock = new queueBlock;  //create a new block
        newBlock->valueCell = elem;
        newBlock->priority=setPriority; //set the priority equal to the input
        
        queueBlock *finder = start;
        while (finder->blockPtr != NULL && finder->blockPtr->priority<setPriority && finder->blockPtr->priority!=0) {  //while the next pointer is less than or equal to NULL
            queueBlock *next = finder->blockPtr;  //go to the next block
            finder = next;
            /*if(priority>next->priority || next->blockPtr==NULL){
                found=true;
            '}*/  //this is the implicit if statement of the while loop
          
        }
        
        if(finder==current){
            
            newBlock->blockPtr=NULL;  //set it's pointer to NULL
            current->blockPtr=newBlock;  //set the current block's pointer to the new block
            current = newBlock;  //set thet current block equal to the new block
            
        }else{
        
        newBlock->blockPtr=finder->blockPtr;
        finder->blockPtr=newBlock;
        
        }
        queueSize++;
        //set newBlock equal to finder's previous location
        
    }else{
        std::cout<<"Priority must be greater than 0"<<std::endl;
    }
    
    
}


/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods must check for an empty queue and report an
 * error if there is no first element.
 */
template <typename ElemType>
ElemType Queue<ElemType>::dequeue() {
    
    if(current!=start){
        queueBlock *tempBlock = start->blockPtr;   //move start ahead to the next block
        
        start->blockPtr=tempBlock->blockPtr;  //point start to the block ahead of the current next block
        
        ElemType tempCell=tempBlock->valueCell;  //store the value of the cell to be returned
       
        delete tempBlock;
        
        queueSize--;
        
        return tempCell;
        
    }else{
        error("trying to dequeue an empty queue");
    }
    
    return NULL;
    
}
template <typename ElemType>
ElemType Queue<ElemType>::peek() {
 
    if(start->blockPtr!=NULL){
        return start->blockPtr->valueCell;
    }else{
          error("trying to dequeue an empty queue");
    }
}


template <typename ElemType>
void Queue<ElemType>::reverse(){
    //not quite 
    
}


#endif 

/* defined(__Ch_11_Coursework__queuell__) */
