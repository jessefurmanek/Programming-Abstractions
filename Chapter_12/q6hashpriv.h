//
//  q6hashpriv.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 3/26/14.
//
//

#ifndef Ch_12_Coursework_q6hashpriv_h
#define Ch_12_Coursework_q6hashpriv_h


/* Constants */
static const int INITIAL_SIZE = 10;
/* Type for a linked list cell */


struct cellT {
    string key;
    ValueType value;
};

/* Instance variables */
cellT *bucketArray;
int numCells;

/* Private method prototypes */
int hash(string s);
cellT *findCell(cellT *chain, string key);

#endif
