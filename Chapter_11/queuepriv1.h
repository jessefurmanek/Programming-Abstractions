//
//  queuepriv1.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/5/14.
//
//

#ifndef Ch_11_Coursework_queuepriv1_h
#define Ch_11_Coursework_queuepriv1_h

/*
 * File: queuepriv.h
 * -----------------
 * This file contains the private section of the Queue template
 * class.  Including this information in a separate file means
 * that clients don't need to look at these details.
 */
/*
 * Implementation notes: Queue data structure
 * ------------------------------------------
 * The array-based queue stores the elements in successive index
 * positions in an array, just as a stack does.  What makes the
 * queue structure more complex is the need to avoid shifting
 * elements as the queue expands and contracts.  In the array
 * model, this goal is achieved by keeping track of both the
 * head and tail indices.  The tail index increases by one each
 * time an element is enqueued, and the head index increases by
 * one each time an element is dequeued.  Each index therefore
 * marches toward the end of the allocated array and will
 * eventually reach the end.  Rather than allocate new memory,
 * this implementation lets each index wrap around back to the
 * beginning as if the ends of the array of elements were joined
 * to form a circle.  This representation is called a ring buffer.
 *
 * The elements of the queue are stored in a dynamic array of
 * the specified element type.  If the space in the array is ever
 * exhausted, the implementation doubles the array capacity.
 * Note that the queue capacity is reached when there is still
 * one unused element in the array.  If the queue is allowed to
 * fill completely, the head and tail indices will have the same
 * value, and the queue will appear empty.
 */
/* Constants */

static const int INITIAL_CAPACITY = 10;

/* Instance variables */
ElemType *elements;
int capacity;
int head;
int tail;
int numElements;
/* A dynamic array of the elements     */
/* The allocated size of the array     */
/* The index of the head of the queue  */
/* The index of the tail of the queue  */
/* Private method prototypes */
void expandCapacity();


#endif
