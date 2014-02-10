//
//  queuellpriv.h
//  Ch.11_Coursework
//
//  Created by Jesse Furmanek on 2/9/14.
//
//

#ifndef Ch_11_Coursework_queuellpriv_h
#define Ch_11_Coursework_queuellpriv_h
struct queueBlock{
    ElemType valueCell;
    queueBlock *blockPtr;
};


queueBlock *start;
queueBlock *current;
int queueSize;

#endif
