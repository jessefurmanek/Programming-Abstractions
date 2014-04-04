//
//  genQuickSort.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 4/3/14.
//
//

#ifndef __Ch_12_Coursework__genQuickSort__
#define __Ch_12_Coursework__genQuickSort__

#include <iostream>

template <typename Type>  //generic comparing function for any "Type"
int OperatorCmp(Type one, Type two);

template <typename Type>
void Sort(Type array[], int n, int (*cmp)(Type, Type)=OperatorCmp);  //defaulting the generic sorting fucntion to the operatorcmp function

template <typename Type>
void Quicksort(Type array[], int start, int finish);

#endif /* defined(__Ch_12_Coursework__genQuickSort__) */
