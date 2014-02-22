//
//  mapimplpriv.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 2/21/14.
//
//

#ifndef Ch_12_Coursework_mapimplpriv_h
#define Ch_12_Coursework_mapimplpriv_h


/*
 * File: mappriv.h
 * ---------------
 * This file contains the private section of the map.h interface
 * for the array-based map.
 */
/*
 * Type: keyValuePairT
 * -------------------
 * This type represents a key-value pair.  This implementation of
 * the Map class stores these entries in an array.
 */
struct keyValuePairT {
    string key;
    ValueType value;
};
/* Constants */
static const int INITIAL_CAPACITY = 100;
/* Instance variables */
keyValuePairT *array;
int capacity;
int count;
/* A dynamic array of key/value pairs */
/* The allocated size of the array    */
/* The current number of entries      */
/* Private function prototypes */
int findKey(string key);
void expandCapacity();



#endif
