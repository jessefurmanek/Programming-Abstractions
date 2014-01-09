//
//  arrbuffpriv.h
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/6/14.
//
//

#ifndef Ch_10_Coursework_arrbuffpriv_h
#define Ch_10_Coursework_arrbuffpriv_h

const int INITIAL_CAPACITY = 20;
const int ROW_CAPACITY = 7;

struct RowT{
    std::string *strArray;  //string pointer
    int *strLength;  //integer pointer to hold array of lengths
    RowT *rowLink;  //link to next row
};




RowT *start;

int cursorRow;
int cursorPlace;
RowT rtRow;
int lastRow;

char *array;

void expandLineCapacity();
void expandRowCapacity();
#endif
