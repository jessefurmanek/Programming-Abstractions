//
//  BinaryVsLinear.cpp
//  Ch.8_Coursework
//
//  Created by Jesse Furmanek on 12/11/13.
//
//

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


//create random vector and random key

Vector<int> RandomVec(int n);
int RandomKey(int n);
void Quicksort(Vector<int> & vec, int start, int finish);
int Partition(Vector<int> & vec, int start, int finish);
void runTest();
double runLinear(Vector<int> & vec, double LinComp, int key);
double runBinary(Vector<int> & vec, double BinComp, int key);
double runBinaryWork(Vector<int> & vec, double BinComp, int key, int lh, int rh);


void runTest(){
    
    
    
    for(int n=10; n<=10000; n=n*10){ //iterate through multiples of ten
        double LinAve = 0;
        double BinAve = 0;
        
        for(int x=0; x<3; x++){
            
            int key = randomInteger(0, n);
            Vector<int> testVector;
            testVector = RandomVec(n);
            
            //run Linear Search
            LinAve+=runLinear(testVector, 0, key);
            
            //run Vector Search
            BinAve+=runBinary(testVector,0,key);
            
        }
        BinAve/=3;
        LinAve/=3;
        if(n==10){
            cout<<"   N   |  Linear  |  Binary"<<endl;
            cout<<"-------+----------+----------"<<endl;
            cout<<setw(5)<<n<<flush;
            cout<<setw(10)<<LinAve<<setw(12)<<BinAve<<endl;
        }else{
            cout<<setw(5)<<n<<flush;
            cout<<setw(10)<<LinAve<<setw(12)<<BinAve<<endl;
        }
      
        
    }
    
    
}


Vector<int> RandomVec(int n){
    Vector<int> tempVec;
    
    for(int x = 0; x<n; x++){
        tempVec.add(randomInteger(0, n));  // create vector of random numbers
    }
    
    //sort vector
    Quicksort(tempVec, 0, n-1);


    return tempVec;
}


int RandomKey(int n){
    int randKey = randomInteger(0, n);
 
    return randKey;
}

void Quicksort(Vector<int> & vec, int start, int finish) {
    if (start >= finish) return;
    int boundary = Partition(vec, start, finish);
    Quicksort(vec, start, boundary - 1);
    Quicksort(vec, boundary + 1, finish);
    
}

int Partition(Vector<int> & vec, int start, int finish) {
    int pivot = vec[start];
    int lh = start + 1;
    int rh = finish;
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

double runLinear(Vector<int> & vec, double LinComp, int key){
    for(int x = 0; x<vec.size(); x++){
        if(vec[x] == key) return LinComp;
        LinComp++;
    }
    return LinComp;
}

double runBinary(Vector<int> & vec, double BinComp, int key){
   
    int rh = vec.size()-1;
    int lh = 0;
    
   return runBinaryWork(vec, 1, key, lh,rh);
    
}

double runBinaryWork(Vector<int> & vec, double BinComp, int key, int lh, int rh){
    int mid=(lh+rh)/2;
    
    if (lh>rh) return BinComp;
    if(vec[mid]==key) return BinComp;  //if the middle is equal to the key, # of comparisons is 1
    if(vec[mid]<key){
        return runBinaryWork(vec, BinComp+1, key, mid+1, rh);  //if the mid is less than the key, the key is located in the right side of the vector
                                                                //add one to mid to prevent infinite loop i.e. if key is less, it'll keep catching on this loop
    }else{
        return runBinaryWork(vec, BinComp+1, key, lh,mid-1);  //if the mid is less than the key, the key is located in the left side of the vector
    }

}
