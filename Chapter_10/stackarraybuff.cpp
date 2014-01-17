//
//  stackarraybuff.cpp
//  Ch.10_Coursework
//
//  Created by Jesse Furmanek on 1/10/14.
//
//

#include "stackarraybuff.h"
#include <iostream>

using namespace std;
/* Constants */

/*
 * Implementation notes: EditorBuffer
 * ----------------------------------
 * In this representation of the buffer, the characters are stored
 * in a dynamic array along with integers storing the capacity of
 * the buffer (its allocated size), the length of the buffer (its
 * effective size), and the cursor position.  The cursor position
 * indicates the index position of the character that follows where
 * the cursor would appear on the screen.  The constructor simply
 * initializes that structure.
 */



EditorBuffer::EditorBuffer() {
    chArray = new char[INITIAL_CAPACITY]; //initialize the char array
    totalCapacity = INITIAL_CAPACITY; //set initial capacity
    beforeStkCap = 3;
    cursor = 7;
    
    chArray[0]='A';
    chArray[1]='B';
    chArray[2]='C';
    chArray[7]='D';
    chArray[8]='E';
    chArray[9]='F';
    
}
/*
 * Implementation notes: ~EditorBuffer
 * -----------------------------------
 * The destructor has to free any memory that is allocated
 * along the way in order to supp
 ort the guarantee that
 * the editor buffer not leak memory.  The only dynamically
 * allocated memory is the dynamic array that stores the text.
 */
EditorBuffer::~EditorBuffer() {
    delete[] chArray;
}

/*
 * Implementation notes: moveCursor methods
 * ----------------------------------------
 * The four moveCursor methods simply adjust the value of the
 * cursor instance variable.
 */
void EditorBuffer::moveCursorForward() {
   
    if(cursor<totalCapacity){  //if cursor is not passed the last char in the array
        char tempChar = chArray[cursor];
        cursor++; //move cursor ahead
        
        chArray[beforeStkCap] = tempChar;
        beforeStkCap++; //increase length of front stack
        
    }
 
}

void EditorBuffer::moveCursorBackward(){
    if(beforeStkCap>0){
        char tempChar = chArray[beforeStkCap-1];
        beforeStkCap--; //decrease legnth of front stack
        
        chArray[cursor-1] = tempChar;
        cursor--;  //move cursor back one space
    }
  
}


void EditorBuffer::moveCursorToStart(){
    for(int i=cursor-1; i>cursor-beforeStkCap-1; i--){
        chArray[i]=chArray[i-(cursor-beforeStkCap)];
    }
    
    cursor=cursor-beforeStkCap;
    beforeStkCap=0;
    
}

void EditorBuffer::moveCursorToEnd() {
    
    
    for(int i=beforeStkCap; i<(totalCapacity-cursor)+beforeStkCap; i++){
        chArray[i] = chArray[i+cursor-beforeStkCap];
    }
    
    beforeStkCap=beforeStkCap+totalCapacity-cursor;  //set the end of the beforeStk = to beforeStk + afterStk
    cursor=totalCapacity;
    
}

/*
 * Implementation notes: insertCharacter and deleteCharacter
 * ---------------------------------------------------------
 * Each of the functions that inserts or deletes characters
 * must shift all subsequent characters in the array, either
 * to make room for new insertions or to close up space left
 * by deletions.
 */

void EditorBuffer::insertCharacter(char ch) {
    if(cursor==beforeStkCap) expandCapacity();
    
    
    cursor--;
    chArray[cursor] = ch;
}

void EditorBuffer::deleteCharacter() {
    if(cursor<totalCapacity){
        cursor++;
        
    }
   
}

void EditorBuffer::deleteCharBackwards(){
    if(beforeStkCap>0){
       beforeStkCap--;
    };
}


void EditorBuffer::moveForwardWord(){
    bool stop = false;
    for(int i=cursor; i<totalCapacity; i++) {
        if(chArray[i]!=' ' && stop ==false){
            moveCursorForward();
        }else{
            stop = true;
        }
    }
}

void EditorBuffer::moveBackwardWord(){
    bool stop = false;
    for(int i=beforeStkCap; i>0; i--) {
        if(chArray[i]!=' '  && stop == false){
            moveCursorBackward();
        }else{
            stop = true;
        }
    }
}

void EditorBuffer::deleteWord(){
    bool stop = false;
    for(int i=cursor; i<totalCapacity; i++) {
        if(chArray[i]!=' '&& stop ==false){
            deleteCharacter();
        }else{
            stop = true;
        }
    }
}

void EditorBuffer::copy(int count){
    string copyOfString;
    for(int x= cursor; x<cursor+count; x++){
        if(x<totalCapacity){
            copyOfString =chArray[x]+copyOfString;
        }
    }
    
    copyString = copyOfString;
}

void EditorBuffer::paste(){

    for(int x = 0; x<copyString.length(); x++){
        insertCharacter(copyString[x]);
    }
}

int EditorBuffer::getCapacity(){
    return totalCapacity;
}

/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This private method doubles the size of the array whenever
 * it runs out of space.  To do so, it must allocate a new array,
 * copy all the characters from the old array to the new one, and
 * then free the old storage.
 */

void EditorBuffer::expandCapacity() {

    int beforeCursorPosition = totalCapacity-cursor;
    int beforeTotalCapacity= totalCapacity;
    totalCapacity*=2;  //double the capacity
    int afterCursorPosition = totalCapacity-beforeCursorPosition;
    
    char * tempArray = chArray;
    
    chArray = new char[totalCapacity];
    
    for(int i=0; i<beforeStkCap; i++){  //populate the beforeStk
        chArray[i] = tempArray[i];
    }
    
    for(int i = afterCursorPosition; i<totalCapacity; i++){  //populate the afterStk
        chArray[i]=tempArray[i-beforeTotalCapacity];
    }
    cursor=afterCursorPosition;
    
    delete[] tempArray;
}


int EditorBuffer::search(string searchString){
    int strLength = searchString.length();
    int searchInt=0;
    
    for(int x=0; x<beforeStkCap; x++){  //iterate through the letters in the before stack
        int strY=0;//counter for the search string
        int strX=x;
        bool matchString = true;
        
        while(strY<beforeStkCap && matchString){
            if(chArray[strX]==searchString[strY]){
                
                
                strY++;
                strX++;
                searchInt++;
                
                if(strY==strLength) return searchInt;
                
            }else{
                searchInt=0;
                matchString =false;
            }
            
        }
        
     
        int afterStkCounter = strY+(cursor-beforeStkCap);
        
        while (matchString && afterStkCounter<totalCapacity){
            
            if(chArray[afterStkCounter]==searchString[strY]){
                afterStkCounter++;
                strY++;
                searchInt++;
                
                if(strY==strLength) return searchInt;
            }else{
                searchInt=0;
                matchString=false;
            }
            
        }
        
    }
    
    
    searchInt=beforeStkCap-1;
    
    for(int x=cursor; x<totalCapacity; x++){
        int stringCounter = 0;
        int strX=x;
        bool matchString = true;
        
        
        while (matchString && strX<totalCapacity){
            
            if(chArray[strX]==searchString[stringCounter]){
                
               
                stringCounter++;
                strX++;
                searchInt++;
                
                
                if(stringCounter==strLength) return searchInt;
            }else{
                searchInt=0;
                matchString=false;
            }

        }
    }
    
    
    return false;
}




void EditorBuffer::display(){
    
    cout<<"Cursor: "<<cursor<<endl;
    cout<<"Before Stack Cap: "<<beforeStkCap<<endl;
    cout<<"Total Capacity: "<<totalCapacity<<endl;
    
    for(int i = 0; i<beforeStkCap; i++){ //print beforeStk
        cout<<" "<<chArray[i]<<flush;
    }
    
    for(int i =cursor; i<totalCapacity; i++){
        cout<<" "<<chArray[i]<<flush;  //print afterStk
    }
    
    cout<<endl;
    
    
    for(int i = 0; i<beforeStkCap; i++){ //print cursor beforeStk
        if(i==cursor){
            cout<<'^'<<flush;
        }else{
            cout<<"  "<<flush;
        }
    }
    for(int i =cursor; i<totalCapacity; i++){ //print cursor afterStk
        if(i==cursor){
            cout<<'^'<<flush;
        }else{
            cout<<"  "<<flush;
        }
    }
    
    if(cursor==totalCapacity){
        cout<<'^'<<flush;
    }
  
    cout<<endl;
}




