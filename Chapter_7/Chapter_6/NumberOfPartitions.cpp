//
//  NumberOfPartitions.cpp
//  Ch.6_Coursework
//
//  Created by Jesse Furmanek on 9/6/13.
//
//


#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
using namespace std;


int NumberOfPartitions(int target, Vector<int> vecInts);
int CalcNumberOfPartitions(int target, Vector<int> vecInts, Vector<int> vecBlank);

int NumberOfPartitions(int target, Vector<int> vecInts){
    
    Vector<int> VecBlank;
    
    return CalcNumberOfPartitions(target, vecInts,VecBlank);

}

int CalcNumberOfPartitions(int target, Vector<int> vecInts, Vector<int> vecBlank){
    if(vecInts.size() == 0){
        int sum =0;
        for(int x = 0; x<vecBlank.size(); x++){
            sum+=vecBlank[x];
        }
        
        cout<<"sum "<<sum<<endl;
        
        if (sum==target){  //if the sum of the subsets is equal to the target, add 1 to the return
            return 1;
        }else{
            return 0;
        }
    }
    Vector<int> BlankVec;  //create a vector to represent the initial state of the destination vector
    
    BlankVec=vecBlank;
    
    vecBlank.add(vecInts[0]);
    vecInts.remove(0);
    
    
    cout<<"vecInts "<<vecInts<<endl;
    cout<<"vecBlank "<<vecBlank<<endl;
    
    return CalcNumberOfPartitions(target, vecInts, vecBlank)+CalcNumberOfPartitions(target, vecInts, BlankVec);

    
}