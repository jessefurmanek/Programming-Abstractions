//
//  queueimp1.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/5/14.
//
//

#ifndef __Ch_11_Coursework__queueimp1__
#define __Ch_11_Coursework__queueimp1__

#include "error.h"

/*
 * Template class: Queue<ElemType>
 * -------------------------------
 * This class template models a queue, which is a linear collection
 * of values that resemble a waiting line.  Values are added at
 * one end of the queue and removed from the other.  The fundamental
 * operations are enqueue (add to the tail of the queue) and dequeue
 * (remove from the head of the queue).  Because a queue preserves
 * the order of the elements, the first value enqueued is the first
 * value dequeued.  Queues therefore operate in a first-in-first-out
 * (FIFO) order.  For maximum generality, the Queue class is defined
 * using a template that allows the client to define a queue that
 * contains any type of value, as in Queue<string> or Queue<taskT>.
 */
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
    
#include "queuepriv1.h"
    

    
};


template <typename ElemType>
Queue<ElemType>::Queue() {
    capacity = INITIAL_CAPACITY;
    elements = new ElemType[capacity];
    head = 0;
    numElements=0 ;//change the representation to include the number of elemetns
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
    delete[] elements;
}

/*
 * Implementation notes: size
 * --------------------------
 * The size of the queue can be calculated from the head and tail
 * indices by using modular arithmetic.
 */
template <typename ElemType>
int Queue<ElemType>::size() {
    return numElements;
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
    return numElements==0;  //if queue is empty, the number of elemetns should be zero
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
    head = numElements = 0;
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
    if (size() == capacity) expandCapacity();  //if size is equal to capacity;
    elements[((head+numElements)%capacity)] = elem;
    numElements+=1;
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods must check for an empty queue and report an
 * error if there is no first element.
 */
template <typename ElemType>
ElemType Queue<ElemType>::dequeue() {
    if (isEmpty()) {
        error("dequeue: Attempting to dequeue an empty queue");
    }
    ElemType result = elements[head];
    head = (head + 1) % capacity;
    numElements-=1;
    return result;
}
template <typename ElemType>
ElemType Queue<ElemType>::peek() {
    if (isEmpty()) {
        error("peek: Attempting to peek at an empty queue");
    }
    return elements[head];
}


template <typename ElemType>
void Queue<ElemType>::reverse(){
    
    
    int newHead = (head+numElements)%capacity;  //head is equal to tail
    
    for(int x=1; x<numElements; x++){
        elements[(newHead+x)%capacity]= elements[((head+numElements)%capacity)-x];  //going forward from the new head, set value = to queue in reverse
        
        //problem-- i can't modulo backwardsx
    }
    
}


/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This private method doubles the capacity of the elements array
 * whenever it runs out of space.  To do so, it must allocate a new
 * array, copy all the elements from the old array to the new one,
 * and free the old storage.  Note that this implementation also
 * shifts all the elements back to the beginning of the array.
 */
template <typename ElemType>
void Queue<ElemType>::expandCapacity() {
    int count = size();
    capacity *= 2;
    ElemType *oldElements = elements;
    elements = new ElemType[capacity];
    for (int i = 0; i < count; i++) {
        elements[i] = oldElements[(head + i) % capacity];  
    }
    head = 0;
    delete[] oldElements;
}


#endif




/* defined(__Ch_11_Coursework__queueimp1__) */
