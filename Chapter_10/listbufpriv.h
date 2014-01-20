//
//  listbufpriv.h
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/19/14.
//
//

#ifndef Ch_10_Coursework_listbufpriv_h
#define Ch_10_Coursework_listbufpriv_h

struct cellT {
    char ch;
    cellT *linkF;  //link forward
    cellT *linkB;  //link backward
};

cellT *cursor;

#endif
