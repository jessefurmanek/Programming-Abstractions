//
//  QuickSortMedian.cpp
//  Ch.8_Coursework
//
//  Created by Jesse Furmanek on 12/12/13.
//
//

#include "QuickSortMedian.h"
#include <ctime>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"
#include "random.h"
#include <time.h>
#include <iomanip>


void QuicksortMed(Vector<int> & vec, int start, int finish);
int PartitionMed(Vector<int> & vec, int start, int finish);
int PickMedian(Vector<int> vec, int start, int finish);


void QuicksortMed(Vector<int> & vec, int start, int finish) {
    if (start >= finish) return;
    int boundary = PartitionMed(vec, start, finish);
    cout<<vec<<endl;
    QuicksortMed(vec, start, boundary - 1);
    QuicksortMed(vec, boundary + 1, finish);

    
}

int PartitionMed(Vector<int> & vec, int start, int finish) {
    //designate the median of the first, last, and middle elements
    
    int pivot = vec[start];
    int lh;
    int rh;
    
    lh = start + 1;
    rh = finish;
    
    while (true) {
        cout<<"pivot "<<pivot<<endl;
        while (lh < rh && vec[rh] >= pivot) rh--;
        cout<<"rh "<<rh<<endl;
        while (lh < rh && vec[lh] < pivot) lh++;
        cout<<"lh "<<lh<<endl;
        if (lh == rh) break;
        int temp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = temp;
    }
    if (vec[lh] >= pivot) return start;
    vec[start] = vec[lh];
    vec[lh] = pivot;
    return lh;
}

int PickMedian(Vector<int> vec, int start, int finish){
    int mid = (start+finish)/2;
    
    if(vec[start]>=vec[finish]){
        if(vec[start]<=vec[mid]){
            return start;
        }
        if(vec[finish]>=vec[mid]){
            return finish;
        }else{
            return mid;
        }
    }else if(vec[start]>=vec[mid]){
        return start;
    }else if(vec[mid]>=vec[finish]){
        return finish;
    }else{
        return mid;
    }
    cout<<"error"<<endl;
    return finish;
}
