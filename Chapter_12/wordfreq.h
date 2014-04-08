//
//  wordfreq.h
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 4/6/14.
//
//

#ifndef __Ch_12_Coursework__wordfreq__
#define __Ch_12_Coursework__wordfreq__

#include <iostream>
#include "simpio.h"
#include "tokenscanner.h"
#include <string>
#include "strlib.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "mapimpl.h"
using namespace std;

/* Private function prototypes */
void CreateFrequencyTable(ifstream & infile, Map<int> & wordCounts); void DisplayWordCounts(Map<int> & wordCounts);
void AskUserForInputFile(ifstream & infile);
bool IsAllAlpha(string & str);
void wordfrequency();
void DisplayEntry(string key, int value);

#endif /* defined(__Ch_12_Coursework__wordfreq__) */
