//
//  buffertest.cpp
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/8/14.
//
//

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "stackarraybuff.h"


using namespace std;

void ExecuteCommand(EditorBuffer & buffer, string line);

void BufferTest(){
    EditorBuffer buffer;
        while (true) {
            cout << "*"<<flush;
            string cmd = getLine();
            if (cmd != "") {
               ExecuteCommand(buffer, cmd);
               buffer.display();
            }else{
                buffer.display();
            }
          
        }
}

void ExecuteCommand(EditorBuffer & buffer, string line) {
    string justNumbers;
    string restOfString;
    char justLetter;
    bool hasNumbers= false;
    bool insertFoo = false;
    for (int i = 0; i < line.length(); i++) {
        
        if(isdigit(line[i])){  //if the first character is a digit
            justNumbers = justNumbers+line[i];
            hasNumbers=true;
        }else if(i==0){  //if the first character is a letter
            justLetter = line[i];
            if(toupper(line[i])=='I'){
                insertFoo = true;
            }
        }else{
            if (insertFoo){
                restOfString= line[i]+ restOfString;
                cout<<restOfString<<endl;
            }
        }
    }
    
    int numOfTimes =1;
    if(hasNumbers){
        numOfTimes = stringToInteger(justNumbers);
    }
    
    switch (toupper(justLetter)) {
        case 'I': for (int i = 0; i < restOfString.length(); i++) {
            buffer.insertCharacter(restOfString[i]);
        }
            break;
        case 'D': {
            for(int x=0; x<numOfTimes; x++){
                buffer.deleteCharacter();
            }
             break;
        }
        case 'F':  {
            for(int x=0; x<numOfTimes; x++){
               buffer.moveCursorForward();
            }
            break;
        }
        case 'B': {
            for(int x=0; x<numOfTimes; x++){
               buffer.moveCursorBackward();
            }
            break;
        }
        case 'J': buffer.moveCursorToStart(); break;
        case 'E': buffer.moveCursorToEnd(); break;
        case 'Q': exit(0);
        default:  cout << "Illegal command" << endl; break;
    } }