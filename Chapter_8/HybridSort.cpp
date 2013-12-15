//
//  HybridSort.cpp
//  Ch.8_Coursework
//
//  Created by Jesse Furmanek on 12/13/13.
//
//

#include "HybridSort.h"
#include "BinaryVsLinear.h"
#include <ctime>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"
#include "random.h"
#include <time.h>
#include <iomanip>

void Quicksort(Vector<int> & vec, int start, int finish);
int Partition(Vector<int> & vec, int start, int finish);
void MergeSort(Vector<int> & vec);
void Merge(Vector<int> & vec, Vector<int> & v1, Vector<int> & v2) ;
void HybridFindTest();
Vector<int> RandomVec(int n);

void HybridFindTest(){
    int n=1;
    bool keepGoing = true;
    while(n<=10000 && keepGoing){ //begin with a vector of one size and increase
        double MergeSortAve = 0;
        double QSAve = 0;
        double start;
        double finish;
        double clocksPer = CLOCKS_PER_SEC;
        
        for(int x=0; x<10000; x++){  //test 10000 times and average the times
            
            Vector<int> testVector;
            testVector = RandomVec(n);
            Vector<int> testVectorClone = testVector;
            
            
            //run Merge Sort
            
            start=clock(); //start clock
            
            start = start/clocksPer*1000;
            
            MergeSort(testVector); //run Merge Sort
            
            finish=clock();  //stop clock
            finish = finish/clocksPer*1000;
            
            MergeSortAve+=(finish-start);
            
            
            //run QuickSort
            start = clock();
            start = start/clocksPer*1000;
            
            Quicksort(testVectorClone, 0, testVectorClone.size()-1); //run QuickSort using Medians
            
            finish = clock();
            finish = finish/clocksPer*1000;
            
            QSAve+=(finish-start);
            
        }
        MergeSortAve/=10000;
        QSAve/=10000;  //Average out the runs
        if(QSAve<MergeSortAve){
            cout<<"QSAverage: "<<QSAve<<endl;
            cout<<"MergeSortAve: "<<MergeSortAve<<endl;
            cout<<"Vector Size: "<<n<<endl;  //print the size of the vector where it takes longer to run merge sort than quicksort;
            keepGoing = false;
        }else{
            n++;
        }
    }
}

void MergeSort(Vector<int> & vec) {
    int n = vec.size();
    if (n <= 1) return;
    Vector<int> v1;
    Vector<int> v2;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            v1.add(vec[i]);
        } else {
            v2.add(vec[i]);
        }
    }
    MergeSort(v1);
    MergeSort(v2);
    vec.clear();
    Merge(vec, v1, v2);
}

void Merge(Vector<int> & vec, Vector<int> & v1, Vector<int> & v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    int p1 = 0;
    int p2 = 0;
    while (p1 < n1 && p2 < n2) {
        if (v1[p1] < v2[p2]) {
            vec.add(v1[p1++]);
        } else {
            vec.add(v2[p2++]);
        }
    }
    while (p1 < n1) vec.add(v1[p1++]);
    while (p2 < n2) vec.add(v2[p2++]);
}