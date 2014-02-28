//
//  maphashpriv.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 2/25/14.
//
//

#ifndef Ch_12_Coursework_maphashpriv_h
#define Ch_12_Coursework_maphashpriv_h

/*
 * File: mappriv.h
 * ---------------
 * This file contains the private section of the Map template
 * class.  Including this information in a separate file means
 * that clients don't need to look at these details.
 */
/* Constants */
static const int INITIAL_SIZE = 700;
/* Type for a linked list cell */
struct cellT {
    string key;
    ValueType value;
    cellT *link;
};
/* Instance variables */
cellT **buckets;
int nBuckets;
int nEntries;
/* A dynamic array of the buckets      */
/* Allocated size of the buckets array */
/* The number of entries in the map    */
/* Private method prototypes */
int hash(string s);
cellT *findCell(cellT *chain, string key);
cellT *findCellInsert(cellT *chain, string key);  //created to return the previous link in the linked list
void deleteChain(cellT *chain);

#endif
