//
//  SortToTenThousand.cpp
//  Ch.8_Coursework
//
//  Created by Jesse Furmanek on 11/12/13.
//
//

#include "SortToTenThousand.h"
#include "vector.h"

void SortTo10k (Vector<int> & vec){
    Vector<int> newVec;
    
    for(int x = 0; x<10000; x++){
        for(int y=0; y<vec.size(); y++){
            if(vec[y]==x) newVec.add(x);
        }
    }
    
     vec = newVec;
}

//Size of Vector || Runtime (N value)
//10................n/a
//100...............n/a
//1000..............94ms  10.64 iterations/ms
//5000..............581ms  8.07 iterations/ms
//10000.............1079ms 9.27 iterations/ms
//100000............9381ms 10.66 iteraions/ms
//500000............44105ms 11.34 iterations/ms


//While the iterations/ms isn't constant, it shows that the time value per iteration is relatively proportional to size