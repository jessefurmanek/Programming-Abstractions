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
#include "BinaryVsLinear.h"

void QuicksortMed(Vector<int> & vec, int start, int finish);
int PartitionMed(Vector<int> & vec, int start, int finish);
void Quicksort(Vector<int> & vec, int start, int finish);
void PickMedian(Vector<int> & vec, int start, int finish);
void QuickSortTest();
Vector<int> RandomVec(int n);


void QuickSortTest(){
    for(int n=10; n<=10000; n=n*10){ //iterate through multiples of ten
        double QSAve = 0;
        double QSMedAve = 0;
        
        for(int x=0; x<3; x++){
            
            Vector<int> testVector;
            testVector = RandomVec(n);
            Vector<int> testVectorClone = testVector;
            
            
            //run QuickSort Search
            
            double start=clock(); //start clock
            double clocksPer = CLOCKS_PER_SEC;
            start = start/clocksPer*1000;
            
            Quicksort(testVector, 0, testVector.size()-1); //run QuickSort
            
            double finish=clock();  //stop clock
            finish = finish/clocksPer*1000;
            
            QSAve+=(finish-start);
            
            
            //run QuickSort with Median Search
            start = clock();
            start = start/clocksPer*1000;
            
            PickMedian(testVectorClone, 0, testVectorClone.size()-1);  //Choose median
            QuicksortMed(testVectorClone, 0, testVectorClone.size()-1); //run QuickSort using Medians
            
            finish = clock();
            finish = finish/clocksPer*1000;
            QSMedAve+=(finish-start);
            
        }
        QSAve/=3;
        QSMedAve/=3;  //Average out the runs
        if(n==10){
            cout<<"   N   | QuickSort|  QSMedian"<<endl;
            cout<<"-------+----------+----------"<<endl;
            cout<<setw(5)<<n<<flush;
            cout<<setw(10)<<QSAve<<setw(12)<<QSMedAve<<endl;
        }else{
            cout<<setw(5)<<n<<flush;
            cout<<setw(10)<<QSAve<<setw(12)<<QSMedAve<<endl;
        }
        
        
    }
    
    
}

void QuicksortMed(Vector<int> & vec, int start, int finish) {
    if (start >= finish) return;
    int boundary = PartitionMed(vec, start, finish);

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
        while (lh < rh && vec[rh] >= pivot) rh--;
        while (lh < rh && vec[lh] < pivot) lh++;
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

void PickMedian(Vector<int> & vec, int start, int finish){
    int mid = (start+finish)/2;
    
    if(vec[start]>=vec[finish]){
        if(vec[start]<=vec[mid]){
            return; //start is the median
        }else if(vec[finish]>=vec[mid]){
            int temp = vec[start];
            vec[start] = vec[finish];
            vec[finish] = temp;  //finish is the median, switch start and finish positions
        }else{
            int temp = vec[start];
            vec[start] = vec[mid];
            vec[mid] = temp;  //mid is the median, switch start and finish positions

        }
    }else if(vec[start]>=vec[mid]){
        return; //start is the median
    }else if(vec[mid]>=vec[finish]){
        int temp = vec[start];
        vec[start] = vec[finish];
        vec[finish] = temp;  //finish is the median, switch start and finish positions
    }else{
        int temp = vec[start];
        vec[start] = vec[mid];
        vec[mid] = temp;  //mid is the median, switch start and finish positions

    }

    return;
}
