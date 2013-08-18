//
//  ListMnemonics.cpp
//  Ch.6_Coursework
//
//  Created by Jesse Furmanek on 8/17/13.
//
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "strlib.h"
#include "vector.h"
#include "lexicon.h"


void PermutePhoneNumberToWord(string letString, Vector<string> LetterHolder, int x, int y);
void ListMnemonics(string str);

void ListMnemonics(string str) {
    Vector<string> LetterHolder;
    
    for(int x=0; x<str.length(); x++){
        
        switch(str[x]){
            case ('2'):
                LetterHolder.add("ABC");
                break;
            case ('3'):
                LetterHolder.add("DEF");
                break;
            case ('4'):
                LetterHolder.add("GHI");
                break;
            case ('5'):
                LetterHolder.add("JKL");
                break;
            case ('6'):
                LetterHolder.add("MNO");
                break;
            case ('7'):
                LetterHolder.add("PQRS");
                break;
            case ('8'):
                LetterHolder.add("TUV");
                break;
            case ('9'):
                LetterHolder.add("WXYZ");
                break;
            default:
                break;
        }
        
    }
    
 PermutePhoneNumberToWord("", LetterHolder, 0, 0);
}

void PermutePhoneNumberToWord(string letString, Vector<string> LetterHolder, int x, int y) {
    
    if(letString.size()==LetterHolder.size()){
        Lexicon english("EnglishWords.txt");
        if(english.contains(letString)){
            cout<<letString<<endl;
        }
        
    }else{
        for(int i=0; i<LetterHolder[x].size(); i++){
            
        PermutePhoneNumberToWord(letString+LetterHolder[x][i], LetterHolder, x+1, i);

        }
    }
    
}