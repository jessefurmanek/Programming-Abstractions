//
//  wordfreq.cpp
//  Ch.12_Coursework
//
//  Created by Jesse Furmanek on 4/6/14.
//
//

#include "wordfreq.h"
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


/* Main program */
void wordfrequency() {
    ifstream infile;  //instantiate file for input
    Map<int> wordCounts; //create a string key map
    
    AskUserForInputFile(infile); //ask user for filename
    
    CreateFrequencyTable(infile, wordCounts);  //create word frequency based off of file
    
    infile.close();
    
    DisplayWordCounts(wordCounts);  //display the frequency
}

/*
 * Creates a frequency table that reads through the input file
 * and counts how often each word appears.  The client supplies
 * both the input file stream and the map used to keep track of
 * the word count. */



void CreateFrequencyTable(ifstream & infile, Map<int> & wordCounts) {
    TokenScanner scanner;
    scanner.setInput(infile);
    scanner.ignoreWhitespace();
    while (scanner.hasMoreTokens()) {
        string word = toLowerCase(scanner.nextToken());
        if (IsAllAlpha(word)) {
            if (wordCounts.containsKey(word)) {
                int value = wordCounts.get(word);
                value++;
                wordCounts.put(word, value);
            } else {
                wordCounts.put(word,1);
            }
        } }
}
/*
 * Displays the count for each word in the frequency table.
 */
void DisplayEntry(string key, int value) {  
    cout << left << setw(15) << key
    << right << setw(5) << value << endl;
}

void DisplayWordCounts(Map<int> & wordCounts) {
    wordCounts.mapAll(DisplayEntry);
}

void AskUserForInputFile(ifstream & infile) {
    while (true) {
        string filename = "ball_so_hard.txt";
        infile.open(filename.c_str());
        if (!infile.fail()) break;
        cout << "Unable to open " << filename << endl;
        infile.clear();
    }
}

bool IsAllAlpha(string & str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str[i])) return false;
    }
    return true;
}


