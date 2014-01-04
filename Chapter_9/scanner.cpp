//
//  Scanner.cpp
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 12/18/13.
//
//


#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "scanner.h"
#include "scanpriv.h"
#include <cctype>

/*
 * File: scanner.cpp
 * -----------------
 * Implementation for the simplified Scanner class.
 */

/*
 * The details of the representation are inaccessible to the client,
 * but consist of the following fields:
 *
 * buffer -- String passed to setInput
 * len -- Length of buffer, saved for efficiency
 * cp-- Current character position in the buffer
 * spaceOption -- Current character position in the buffer
 */

Scanner::Scanner() {  //instantiates a scanner object
    buffer = "";
    spaceOption = PreserveSpaces;
    stringOption = SkipQuotes;
    numberOption = ScanNumbersAsIntegers;
}

Scanner::~Scanner() {
    /* Empty */
}

void Scanner::setInput(std::string str) {
    buffer = str;
    len = buffer.length();
    cp = 0;
}

/*
 * Implementation notes: nextToken
 * -------------------------------
 * The code for nextToken follows from the definition of a token.
 */

std::string Scanner::nextToken() {
    if (cp == -1) {
        error("setInput has not been called");
    }
    
    if (spaceOption == IgnoreSpaces) skipSpaces();
    if (stringOption == SkipQuotes) skipQuotes();
    
    int start = cp;
    if (start >= len) return "";
    
    if (stringOption == ScanQuotesAsStrings){  //if scanning quotes
        if(buffer[cp]== 34){  //the string will be equal to the next quote in the file
            int finish = getNextQuote();
            return buffer.substr(start, finish - start + 1);
        }else if(isalnum(buffer[cp])){
            int finish = scanToEndOfIdentifier();
            return buffer.substr(start, finish - start + 1);
        }
    }else if(isalnum(buffer[cp])){
            if(isnumber(buffer[cp])){
                if(numberOption == ScanNumbersAsReals){  //if scanning number as reals, do this
                    int finish = getEndOfRealNumber();
                    return buffer.substr(start, finish - start + 1);
                }else{ //if number option == ScanNumbersAsIntegers
                    int finish = scanToEndOfIdentifier();
                    return buffer.substr(start, finish - start + 1);
                }
            
            }else{  //if buffer[cp] is not a number
                int finish = scanToEndOfIdentifier();
                return buffer.substr(start, finish - start + 1);
            }
    }else{}
    
    cp++;
    return buffer.substr(start, 1);
}

bool Scanner::hasMoreTokens() {
    if (cp == -1) {
        error("setInput has not been called");
    }
    if (spaceOption == IgnoreSpaces) skipSpaces();
    
    return (cp < len);
}

void Scanner::setSpaceOption(spaceOptionT option) {
    spaceOption = option;
}

void Scanner::setStringOption(stringOptionT option) {
    stringOption = option;
}

void Scanner::setNumberOption(numberOptionT option) {
    numberOption = option;
}


Scanner::spaceOptionT Scanner::getSpaceOption() {
    return spaceOption;
}

Scanner::stringOptionT Scanner::getStringOption() {
    return stringOption;
}

Scanner::numberOptionT Scanner::getNumberOption() {
    return numberOption;
}


/* Private functions */
/*
 * Private method: skipSpaces
 * Usage: skipSpaces();
 * -------------------
 * This function advances the position of the scanner until the
 * current character is not a whitespace character.
 */


void Scanner::skipSpaces() {
    while (cp < len && isspace(buffer[cp])) {
        cp++; }
}

void Scanner::skipQuotes() {
    while (cp < len && buffer[cp]==34) {
        cp++; }
}




/*
 * Private method: scanToEndOfIdentifier
 * Usage: finish = scanToEndOfIdentifier();
 * ----------------------------------------
 * This function advances the position of the scanner until it
 * reaches the end of a sequence of letters or digits that make
 * up an identifier.  The return value is the index of the last
 * character in the identifier; the value of the stored index
 * cp is the first character after that.
 */
int Scanner::scanToEndOfIdentifier() {
    while (cp < len && isalnum(buffer[cp])) {
        cp++; }
 
    return cp - 1;
}

int Scanner::getNextQuote(){
   
    while (cp < len && buffer[cp+1]!= 34) {
        cp++; }
   
    return cp - 1;
    
}


int Scanner::getEndOfRealNumber(){
    
    while (cp < len && isnumber(buffer[cp])) {  //while number is a digit
        cp++; }
    
    if (cp < len && buffer[cp]==46) {  //if number has a decimal point which does not end the sentence
        if(cp+1<len){
            cp++;
        }
    }
    
    while (cp < len && isnumber(buffer[cp])) { //if number has decimals
        cp++; }
    
    if(cp < len && buffer[cp]==69) { //if number has no base raise to the power i.e. E
        cp++;
    }
    
    if(cp < len){
        if(buffer[cp]==43 || buffer[cp]==45) { //if number has '+' or '-' symbol
            cp++;
        }
    }
    
    while (cp < len && isnumber(buffer[cp])) { //if number has decimals
        cp++; }
    
    
    
    return cp - 1;
}



