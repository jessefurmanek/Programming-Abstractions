//
//  Scanner.h
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 12/18/13.
//
//

#ifndef __Ch_9_Coursework__Scanner__
#define __Ch_9_Coursework__Scanner__

#include <iostream>

class Scanner{
    
public:
    
    /*
     * Constructor: Scanner
     * Usage: Scanner scanner;
     * -----------------------
     * The constructor initializes a new scanner object. The scanner
     * starts empty, with no input to scan.
     */
    
    Scanner();
    /*
     * Destructor: ~Scanner
     * Usage: usually implicit
     * -----------------------
     * The destructor deallocates any memory associated with this scanner.
     */
    ~Scanner();
    /*
     * Method: setInput
     * Usage: scanner.setInput(str);
     * -----------------------------
     * This method configures this scanner to start extracting
     * tokens from the input string str. Any previous input string is
     * discarded.
     */
    
    void setInput(std::string str);
    
    /*
     * Method: nextToken
     * Usage: token = scanner.nextToken();
     * -----------------------------------
     * This method returns the next token from this scanner.  If
     * nextToken is called when no tokens are available, it returns the
     * empty string.
     */
    
    std::string nextToken();
    /*
     * Method: hasMoreTokens
     * Usage: if (scanner.hasMoreTokens()) . . .
     * ------------------------------------------
     * This method returns true as long as there are additional
     * tokens for this scanner to read.
     */
    
    bool hasMoreTokens();
    
    /*
     * Methods: setSpaceOption, getSpaceOption
     * Usage: scanner.setSpaceOption(option);
     *        option = scanner.getSpaceOption();
     * ------------------------------------------
     * This method controls whether this scanner
     * ignores whitespace characters or treats them as valid tokens.
     * By default, the nextToken function treats whitespace characters,
     * such as spaces and tabs, just like any other punctuation mark.
     * If, however, you call
     *
     *    scanner.setSpaceOption(Scanner::IgnoreSpaces);
     *
     * the scanner will skip over any white space before reading a
     * token. You can restore the original behavior by calling
     *
     *    scanner.setSpaceOption(Scanner::PreserveSpaces);
     *
     * The getSpaceOption function returns the current setting
     * of this option.
     */
    enum spaceOptionT { PreserveSpaces, IgnoreSpaces };
    enum stringOptionT { SkipQuotes, ScanQuotesAsStrings};
    
    void setSpaceOption(spaceOptionT option);
    void setStringOption(stringOptionT option);
    
    spaceOptionT getSpaceOption();
    stringOptionT getStringOption();

private:
    #include "scanpriv.h"  //include private scanner header to shield implementation from the client
    
};

#endif /* defined(__Ch_9_Coursework__Scanner__) */
