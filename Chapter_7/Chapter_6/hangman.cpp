/*
 * File: main.cpp
 * --------------
 * This is an empty C++ source file.
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "randword.h"
#include "strlib.h"


using namespace std;

void gameSetup(int numLetters, char array[]);
void playHangman(string word, char array[]);

int main(){
    int numLetters = 0;
    
    InitDictionary("dictionary.txt");  //initialize the dictionary of words
    string word = ChooseRandomWord();  //choose a random word from that dictionary
    word = toLowerCase(word);
    
    
    numLetters= word.length();
    char gameArray[numLetters];
    
    
    gameSetup(numLetters, gameArray);
    
    playHangman(word, gameArray);
    
    return 0;
}


void gameSetup(int numLetters, char array[]){
    cout<<"Guess the word!"<<endl;
    
    
    for(int x = 0; x<numLetters; x++){
        array[x]='_';
    }
    
    for(int x = 0; x<numLetters; x++){
        cout<<array[x]<<" "<<flush;
    }
    
    return;
};


void playHangman(string word, char array[]){
    char guessLetter = ' ';
    string guessWord=word;
    int correctGuesses = 8;
    bool won = false;
    
    for(int x=0; x<word.length(); x++){ //initializing guessWord
        guessWord[x]= '_';
    }
    
    
    while(correctGuesses>0){
        cout<<"You have "<<correctGuesses<<" guesses left."<<endl;
        cout<<"Guess a letter: "<<flush;
        cin>>guessLetter;
        guessLetter= tolower(guessLetter);
        bool guessedRight =false;
        
        for(int x=0; x<word.length(); x++){
            if(word[x]==guessLetter){
                array[x]=guessLetter; //iterates through the letters
                guessWord[x]=guessLetter;
                guessedRight=true;  //flags that a letter was guessed correctly
            }  
        }
        
        if (guessedRight){
            cout<<"You guessed correctly!"<<endl;  
            for(int x=0; x<word.length(); x++){
                cout<<array[x]<<flush;
            }
            cout<<endl;
        }else {
            cout<<"Wrong!"<<endl;
            correctGuesses--;
        }
        
        if(guessWord==word){  //check if full word was guessed correclty
            cout<<"You win!"<<endl;
            won=true;
            break;
        }
        
    }
    
    if (won){
       
    }else{
    cout<<"You Lose!"<<endl;
    }
    
    return;
}




