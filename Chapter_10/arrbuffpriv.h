//
//  arrbuffpriv.h
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/6/14.
//
//

#ifndef Ch_10_Coursework_arrbuffpriv_h
#define Ch_10_Coursework_arrbuffpriv_h

const int INITIAL_CAPACITY = 100;
int capacity;
char *array;
char *list;
int length;
int cursor;

void expandCapacity();

#endif
