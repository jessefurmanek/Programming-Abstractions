//
//  BinarySearch.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 4/3/14.
//
//

#ifndef __Ch_12_Coursework__BinarySearch__
#define __Ch_12_Coursework__BinarySearch__

#include <iostream>
#include "genQuickSort.h"

template<typename Type>
int BinarySearch(Type key, Type array[], int n, int (*cmp)(Type, Type) = OperatorCmp);

template<typename Type>
int FindKeyInSortedArray(int key, Type array[], int n);

template<typename Type>
int BinarySearch(Type key, Type array[], int low, int high);

#endif /* defined(__Ch_12_Coursework__BinarySearch__) */
