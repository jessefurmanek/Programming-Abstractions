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
int BinarySearchWrapper(Type key, Type array[], int n, int (*cmp)(Type, Type)){
    int index;
    
    //sort the array
    Sort(array, n, cmp);
    
    //search
    FindKeyInSortedArray(key, array, n);
    
    return index;
}

template<typename Type>
int FindKeyInSortedArray(Type key, Type array[], int n, int cmp){  //wrapper function
    return BinarySearch(key, array, 0, n - 1); //run binary search
}

template<typename Type>
int BinarySearchFn(Type key, Type array[], int low, int high, int cmp) {
    if (low > high) return -1;  //if the low integer ends up bigger than the high, the searched for item hasn't been found
    int mid = (low + high) / 2;
    if (key == array[mid]) return mid;
    if (cmp(key, array[mid]) < 0) { //if the key is less than the mid
        return BinarySearch(key, array, low, mid - 1);
    } else {  //if the key is greater than the mid
        return BinarySearch(key, array, mid + 1, high);
    }
}