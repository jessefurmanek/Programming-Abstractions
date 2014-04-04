//
//  genQuickSort.cpp
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 4/3/14.
//
//

#include "genQuickSort.h"

template <typename Type>  //generic comparing function for any "Type"
int OperatorCmp(Type one, Type two) {
    if (one == two) return 0;
    if (one < two) return -1;
}

template <typename Type>
void Sort(Type array[], int n, int (*cmp)(Type, Type)) { //Sort acts as a wrapper for the quicksort alogrithm
    Quicksort(array, 0, n-1);
}


template <typename Type>
void Quicksort(Type array[], int start, int finish) {
    if (start >= finish) return;
    int boundary = Partition(array, start, finish);
    Quicksort(array, start, boundary - 1);
    Quicksort(array, boundary + 1, finish);
}


template <typename Type>
int Partition(Type array[], int start, int finish) {
    int pivot = array[start];
    int lh = start + 1;
    int rh = finish;
    while (true) {
        while (lh < rh && array[rh] >= pivot) rh--;
        while (lh < rh && array[lh] < pivot) lh++;
        if (lh == rh) break;
        Type temp = array[lh];
        array[lh] = array[rh];
        array[rh] = temp;
    }
    if (array[lh] >= pivot) return start;
    array[start] = array[lh];
    array[lh] = pivot;
    return lh;
}