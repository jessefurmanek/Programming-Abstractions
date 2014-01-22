//
//  bufnodumtest.cpp
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/20/14.
//
//

#include "bufnodumtest.h"
#include "listbufnodummy.h"
#include "simpio.h"
#include <iostream>


using namespace std;

/* Private function prototypes */
void ExecuteCommand(EditorBuffer & buffer, string line);
/* Main program */
void buffernoDummyTest() {
    EditorBuffer buffer;
    while (true) {
        cout << "*";
        string cmd = getLine();
        if (cmd != "") ExecuteCommand(buffer, cmd);
        buffer.display();
    }
}
/*
 * Executes a single editor command.
 */
void ExecuteCommand(EditorBuffer & buffer, string line) {
    switch (toupper(line[0])) {
        case 'I': for (int i = line.length()-1; i>0; i--) {
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