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
#include "map.h"
#include "tokenscanner.h"
#include <string>
#include "strlib.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <iomanip>

/* Private function prototypes */
void CreateFrequencyTable(ifstream & infile, Map<string, int> & wordCounts); void DisplayWordCounts(Map<string, int> & wordCounts);
void AskUserForInputFile(ifstream & infile);
bool IsAllAlpha(string & str);
void wordfrequency();

#endif /* defined(__Ch_12_Coursework__wordfreq__) */
