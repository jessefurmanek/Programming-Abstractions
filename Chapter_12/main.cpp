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
void Sort(Type array[], int n, int (*cmp)(Type, Type));

template <typename Type>
int OperatorCmp(Type one, Type two);

int main(){
    Map<int> test;
    Map<int> copytest;
    
    Map<int> *testArray = new Map<int>[1];
    testArray[0] = test;
    
    for (int x = 0; x<10; x++){
        test.put("test"+integerToString(x), x);
    }
    
    test.copyEntriesInto(copytest);
    
    for (int x = 0; x<10; x++){
        test.put("test"+integerToString(x), 2*x);
    }
    
    
    
    for (int x = 0; x<10; x++){
        cout<<copytest.get("test"+integerToString(x))<<endl;
    }
    
    for (int x = 0; x<10; x++){
        cout<<test.get("test"+integerToString(x))<<endl;
    }
   
    
    int *array = new int[5];
    array[0] = 5;
    array[1] = 24;
    array[2] = 2;
    array[3] = 14;
    array[4] = 51;
    
    
    Sort(array, 7, OperatorCmp(1, 1));
    
    return 0;
}

template <typename Type>
int OperatorCmp(Type one, Type two) {
    if (one == two) return 0;
    if (one < two) return -1;
    return 1;
}

template <typename Type>
void Sort(Type array[], int n, int (*cmp)(Type, Type)) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (cmp(array[j],array[minIndex]) < 0) minIndex = j;
        }
        Type temp =array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    } }