//
//  queueimp1.cpp
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/5/14.
//
//

#ifdef queueimp1_h
/*
 * File: queueimpl.cpp
 * -------------------
 * This file contains the array-based implementation of the
 * Queue class.
 */

/*
 * Implementation notes: Queue constructor
 * ---------------------------------------
 * The constructor must allocate the array storage for the queue
 * elements and initialize the fields of the object.
 */
template <typename ElemType>
Queue<ElemType>::Queue() {
    capacity = INITIAL_CAPACITY;
    elements = new ElemType[capacity];
    head = 0;
    tail = 0;
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
    return (tail + capacity - head) % capacity;
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
    return head == tail;
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
    head = tail = 0;
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
    if (size() == capacity - 1) expandCapacity();
    elements[tail] = elem;
    tail = (tail + 1) % capacity;
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
    return result;
}
template <typename ElemType>
ElemType Queue<ElemType>::peek() {
    if (isEmpty()) {
        error("peek: Attempting to peek at an empty queue");
    }
    return elements[head];
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
    tail = count;
    delete[] oldElements;
}

#endif
