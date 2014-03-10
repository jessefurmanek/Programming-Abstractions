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
static const int INITIAL_SIZE = 4;
static const int REHASH_THRESHOLD = 5;
/* Type for a linked list cell */

struct counterObject{
    int nBuckets;  //counts the number of buckets in the array
    int nEntries; //counts the number of entries in the map
};

struct cellT {
    string key;
    ValueType value;
    int nCells;  //counter the number of entries in a bucket row
    cellT *link;
};



/* Instance variables */
cellT **buckets;
cellT **newBuckets;
counterObject counter;
int *cellCounter; //an array to count the number of cells in each bucket;


/* Private method prototypes */
int hash(string s);
cellT *findCell(cellT *chain, string key);
cellT *findCellInsert(cellT *chain, string key);  //created to return the previous link in the linked list
void deleteChain(cellT *chain);

#endif
