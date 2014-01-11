//
//  stackarraybuffpriv.h
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/10/14.
//
//

#ifndef Ch_10_Coursework_stackarraybuffpriv_h
#define Ch_10_Coursework_stackarraybuffpriv_h

const int INITIAL_CAPACITY = 10;

    char *chArray;  //character array representing two stacks
    int totalCapacity;  //total size of the char array
    int beforeStkCap; // endpoint of first stack
    int cursor; //represents both the cursor and the beginning of the endStack


void expandCapacity();


#endif
