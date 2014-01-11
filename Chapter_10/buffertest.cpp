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
    switch (toupper(line[0])) {
        case 'I': for (int i = 1; i < line.length(); i++) {
            buffer.insertCharacter(line[i]);
        }
            break;
        case 'D': buffer.deleteCharacter(); break;
        case 'F': buffer.moveCursorForward(); break;
        case 'B': buffer.moveCursorBackward(); break;
        case 'J': buffer.moveCursorToStart(); break;
        case 'E': buffer.moveCursorToEnd(); break;
        case 'Q': exit(0);
        default:  cout << "Illegal command" << endl; break;
    } }