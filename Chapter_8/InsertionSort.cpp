//
//  InsertionSort.cpp
//  Ch.8_Coursework
//
//  Created by Jesse Furmanek on 11/12/13.
//
//

#include "InsertionSort.h"  //logari
#include "vector.h"


Vector <int> Sort(Vector<int> & vec){
    int vecSize = vec.size();
    for(int rh=0; rh<vecSize; rh++){  //each iteration increases the size of the mini vector
        int lh=0;  //reset left-hand counter to 0 each iteration
        while(lh<rh){
            if(vec[lh]>vec[rh]){
                int temp=vec[lh];
                vec[lh]=vec[rh];
                vec[rh] = temp;
            }
            lh++;
        }
        rh++;  //go to the next number
    }
    return vec;
}

//worst case scenario sort will be N^2.  In the worst case, the algorithm will have to exchange on each iteration, which is equivalent to adding each of the possible "mini-vectors" created by the rh movement. For example, on the first run, the effective vector size is 1, the second run, it is 2 and so on until the algo reaches to full vector size.  The algorithimic complexity should therefore be n(n+1)/2 which simplifies to O(n^2).