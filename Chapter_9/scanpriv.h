//
//  scanpriv.h
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 12/18/13.
//
//

#ifndef Ch_9_Coursework_scanpriv_h
#define Ch_9_Coursework_scanpriv_h
#include <iostream>

/*
 * File: scanpriv.h
 * ----------------
 * This file contains the private data for the simplified version
 * of the Scanner class.
 */

std::string buffer; //the string containing the tokens
int len;        //buffer length
int cp;         //current index of the buffer
spaceOptionT spaceOption;   //space option
stringOptionT stringOption; //string option


void skipSpaces();
int scanToEndOfIdentifier();
int getNextQuote();


#endif
