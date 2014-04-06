//
//  main.cpp
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 3/27/14.
//
//

#include <iostream>
#include "simpio.h"
#include "console.h"
#include "strlib.h"
#include "random.h"
#include "genQuickSort.h"
#include "BinarySearch.h"

using namespace std;

int main(){
    string *array = new string[10];
    
    for (int x=0; x<10; x++){
        array[x] = "abc";
    }
   
    array[1]="xyz";
    array[3]="jesse";
    
    for (int x=0; x<10; x++){
        cout<<array[x]<<endl;
    }
    
    SortFn(array, 10);
    
    cout<<endl;
    for (int x=0; x<10; x++){
        cout<<array[x]<<endl;
    }
    
    string test = "jesse";
    cout<<endl;
    cout<<FindKeyInSortedArray(test, array, 10)<<endl;
    
    return 0;
}

template <typename Type>  //generic comparing function for any "Type"
int OperatorCmp(Type one, Type two) {
    if (one == two) return 0;
    if (one < two) return -1;
    return 1;
}



template <typename Type>
void SortFn(Type array[], int n, int (*cmp)(Type, Type)) { //Sort acts as a wrapper for the quicksort alogrithm
    Quicksort(array, 0, n-1);
}

template <typename Type>
int Partition(Type array[], int start, int finish) {
    Type pivot = array[start];
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


template <typename Type>
void Quicksort(Type array[], int start, int finish) {
    if (start >= finish) return;
    int boundary = Partition(array, start, finish);
    Quicksort(array, start, boundary - 1);
    Quicksort(array, boundary + 1, finish);
    
}

template<typename Type>
int BinarySearchFn(Type key, Type array[], int low, int high, int (*cmp)(Type, Type)) {
    if (low > high) return -1;  //if the low integer ends up bigger than the high, the searched for item hasn't been found
    int mid = (low + high) / 2;
    if (key == array[mid]) return mid;
    if (cmp(key, array[mid]) < 0) { //if the key is less than the mid
        return BinarySearchFn(key, array, low, mid - 1);
    } else {  //if the key is greater than the mid
        return BinarySearchFn(key, array, mid + 1, high);
    }
}

template<typename Type>
int FindKeyInSortedArray(Type key, Type array[], int n, int (*cmp)(Type, Type)){  //wrapper function
    return BinarySearchFn(key, array, 0, n - 1); //run binary search
}

template<typename Type>
int BinarySearchWrapper(Type key, Type array[], int n, int (*cmp)(Type, Type)){
    int index=0;
    
    //sort the array
    SortFn(array, n, cmp);
    
    //search
    FindKeyInSortedArray(key, array, n);
    
    return index;
}





