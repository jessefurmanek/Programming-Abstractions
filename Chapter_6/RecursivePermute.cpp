//
//  RecursivePermute.cpp
//  CourseWork
//
//  Created by Jesse Furmanek on 8/16/13.
//
//

//lists permutations of a substring of a string.  substring length determined by integer

// ListPermutations("ABCDE", 1); lists all permutations of ABCDE, holding A constant.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "strlib.h"
#include "vector.h"
#include "random.h"
#include "stack.h"
#include "tokenscanner.h"
#include "grid.h"


void RecursivePermute(string prefix, string rest, string original);

void ListPermutations(string str, int n) {
    RecursivePermute(str.substr(0,n), str.substr(n, str.length()-n), str);
}

void RecursivePermute(string prefix, string rest, string original) {
    
    if (rest == "") {
        cout << prefix << endl;
    } else {
        for (int i = 0; i < rest.length(); i++) {
            bool dupeFound =false;
            for(int x = 0; x<i; x++){  //set bounds for x<i so the first instance of a later duplicated letter still runs
                if(rest[i]==rest[x]) dupeFound=true;
            }
                if (dupeFound) continue;
                string newPrefix = prefix + rest[i];
                string newRest = rest.substr(0, i) + rest.substr(i+1);
                RecursivePermute(newPrefix, newRest, original);
        }
    }
}
