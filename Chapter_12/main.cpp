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
#include "q6hash.h"
#include "strlib.h"

using namespace std;

template <typename Type>
int OperatorCmp(Type one, Type two);

template <typename Type>
void Sort(Type array[], int n, int (*cmp)(Type, Type)=OperatorCmp);  //defaulting the generic sorting fucntion to the operatorcmp function


template <typename Type>
int Partition(Type array[], int start, int finish);

template <typename Type>
void Quicksort(Type array[], int start, int finish);

int main(){
    
    int *array = new int[5];
    array[0] = 5;
    array[1] = 24;
    array[2] = 2;
    array[3] = 14;
    array[4] = 51;
    
    Sort(array, 5);
    
    for (int x = 0; x<5; x++){
        
        cout<<array[x]<<endl;
    }
    
    return 0;
}

template <typename Type>  //generic comparing function for any "Type"
int OperatorCmp(Type one, Type two) {
    if (one == two) return 0;
    if (one < two) return -1;
    return 1;
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

