//
//  BinarySearch.cpp
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 4/3/14.
//
//

#include "BinarySearch.h"
#include "genQuickSort.h"

//The key argument is the value for which the function is searching, and the remaining arguments are equivalent to those used in Sort. The function returns the index of an array element containing the value key, assuming that the value appears in the array at all. If not, BSearch returns –1.


template<typename Type>
int BinarySearch(Type key, Type array[], int n, int (*cmp)(Type, Type)){
    int index;
    
    //sort the array
    Quicksort(array, 0, n);
    
    //search
    FindKeyInSortedArray(key, array, n);
    
    return index;
}

template<typename Type>
int FindKeyInSortedArray(Type key, Type array[], int n){  //wrapper function
    return BinarySearch(key, array, 0, n - 1); //run binary search
}

template<typename Type>
int BinarySearch(Type key, Type array[], int low, int high) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (key == array[mid]) return mid;
    if (key < array[mid]) {
        return BinarySearch(key, array, low, mid - 1);
    } else {
        return BinarySearch(key, array, mid + 1, high);
    }
}