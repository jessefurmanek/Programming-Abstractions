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
    char secondCmd;
    char justLetter;
    bool hasNumbers= false;
    bool insertFoo = false;
    for (int i = 0; i < line.length(); i++) {
        
        if(isdigit(line[i])){  //if the character is a digit
            justNumbers = justNumbers+line[i];
            hasNumbers=true;
        }else if(line[i]=='-'){
            justNumbers = justNumbers+line[i];
            hasNumbers=true;
        }else if(i==0){  //if the first character is a letter
            justLetter = toupper(line[i]);
            
            if(justLetter=='I' ||justLetter=='S'|| justLetter=='R'){
                insertFoo = true;
            }
        }else{
            if (insertFoo){
                restOfString= line[i]+ restOfString;
            }else{
                secondCmd = toupper(line[i]);
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
            if(numOfTimes>0){
                if(numOfTimes==1){
                    buffer.deleteCharacter();
                  
                }else{for(int x=0; x<numOfTimes; x++){
                    buffer.deleteCharacter();
                   
                    }
                }
            }else{
                for(int x=0; x<abs(numOfTimes); x++){
                    buffer.deleteCharBackwards();
                
                }
               
            }
              break;
        }
        case 'F':  {
            if(numOfTimes>0){
                for(int x=0; x<numOfTimes; x++){
                    buffer.moveCursorForward();
                }
            }else{
                for(int x=0; x<abs(numOfTimes); x++){
                    buffer.moveCursorBackward();
                }
            }
            break;
        }
        case 'B': {
            if(numOfTimes>0){
                for(int x=0; x<numOfTimes; x++){
                    buffer.moveCursorBackward();
                }
            }else{
                for(int x=0; x<abs(numOfTimes); x++){
                    buffer.moveCursorForward();
                }
            }
            break;
        }
        case 'W': {
            switch(secondCmd){
                case 'F': {
                    buffer.moveForwardWord(); break;
                }
                case 'B' :{
                    buffer.moveBackwardWord(); break;
                }
                case 'D': buffer.deleteWord(); break;
                    
            }
            break;
            
        }case 'C': {
            if(numOfTimes>0){
                buffer.copy(numOfTimes);
            }
            break;
        }case 'X':{
            int totalChar = buffer.getCapacity();
            
            buffer.moveCursorToStart();
            buffer.copy(totalChar);  //copy the total length of the buffer
            
            for(int x = 0; x<totalChar; x++){
                buffer.deleteCharacter();
            }
            break;
        }case 'S':{
            int y=0;
            std::string copyString = restOfString;
            
            for(int x=restOfString.length()-1; x>=0; x--){
                restOfString[y]=copyString[x];  //correct reversing string effect
                y++;
            }
            
            if(buffer.search(restOfString)){
                cout<<"String Found"<<endl;
            }else{
                cout<<"Not Found"<<endl;
            };
            
            break;
        }case 'R':{
           
            std::string copyString = restOfString;  //create a copy of the search & replace string
            std::string replaceString;
            restOfString.clear();
            bool afterSlash = false;
    
            
            for(int x=copyString.length()-1; x>=0; x--){  //parse out search and replace string
                
                
                if(!afterSlash){ //if before the slash, set to search string
                    if(copyString[x]=='/'){
                        
                        afterSlash=true;
                    
                    }else{
                        restOfString+=copyString[x];  //correct reversing string effect
                        
                    }
                }else{ //if after the slash, set replacement string
                    replaceString=copyString[x]+replaceString;
                    
                }
            }
            
            
            if(buffer.search(restOfString)){
                
                int cursorPos =buffer.search(restOfString);
                
                buffer.moveCursorToStart();
               
                
                cout<<"CursorPos: "<<cursorPos<<endl;
                
                for(int x=0; x<cursorPos; x++){
                    buffer.moveCursorForward();
               
                }
               
                for(int x=0; x<restOfString.length(); x++){
                    buffer.moveCursorBackward();
                   
                }
              
                
                for(int x=0; x<restOfString.length(); x++){  //delete the searched for string
                    buffer.deleteCharacter();
                }
                
                for(int x=0; x<replaceString.length(); x++){
                    buffer.insertCharacter(replaceString[x]);
                }
                //if found, replace
                //delete found string
                //replace with replcement
            }else{
                cout<<"Not Found"<<endl;
            };
            
            break;
        }case 'G':{
            
            cout<<buffer.toString()<<endl;
            
            break;
        }
        case 'J': buffer.moveCursorToStart(); break;
        case 'E': buffer.moveCursorToEnd(); break;
        case 'P': buffer.paste(); break;
        case 'Q': exit(0);
        default:  cout << "Illegal command" << endl; break;
        }
    }