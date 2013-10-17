//
//  card.cpp
//  CourseWork
//
//  Created by Jesse Furmanek on 7/28/13.
//
//

#include "card.h"
#include <string>
#include <iostream>
#include "random.h"


/* • A function CardName(card) that returns a string identifying the card. The result of CardName begins with a rank indicator (which is one of A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, or K), followed by a one-character suit (C, D, H, or S). Note that the result is usually a two-character string, but contains three characters if the rank is a 10. */


cardT NewCard(rankT rank, suitT suit);

rankT Rank(cardT card){
    rankT rank =card.rank;
    return rank;
}

suitT Suit(cardT card){
    suitT suit = card.suit;
    return suit;
    
}

std::string CardName(cardT card){
    std::string strCard = "AA";
    std::string suit;
    std::string rank;
    
    switch(card.suit){
        case (0):
            suit = 'C';
            break;
        case (1):
            suit = 'D';
            break;
        case (2):
            suit = 'H';
            break;
        case (3):
            suit = 'S';
            break;
        default:
            std::cout<<"Error in picking suit"<<std::endl;
    }
    
    switch(card.rank){
        case (1):
            rank = 'A';
            break;
        case (2):
            rank = '2';
            break;
        case (3):
            rank = '3';
            break;
        case (4):
            rank = '4';
            break;
        case (5):
            rank = '5';
            break;
        case (6):
            rank = '6';
            break;
        case (7):
            rank = '7';
            break;
        case (8):
            rank = '8';
            break;
        case (9):
            rank = '9';
            break;
        case (10):
            rank = "10";
            break;
        case (11):
            rank = 'J';
            break;
        case (12):
            rank = 'Q';
            break;
        case (13):
            rank = 'K';
            break;
        default: //leave rank as rankT value as it should be equal to the card value
            break;
    }
    
    strCard=rank+suit;

    return strCard;
    
}
