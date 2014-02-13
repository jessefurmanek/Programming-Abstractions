//
//  vectorllpriv.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/11/14.
//
//

#ifndef Ch_11_Coursework_vectorllpriv_h
#define Ch_11_Coursework_vectorllpriv_h


struct vectorBlock{
    ElemType data;
    vectorBlock *blkPointer;
};

int length;  //store size of the vector
vectorBlock *start;


#endif
