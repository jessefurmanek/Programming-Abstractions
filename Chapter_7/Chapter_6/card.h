//
//  card.h
//  CourseWork
//
//  Created by Jesse Furmanek on 7/28/13.
//
//
/*
 
 • A type rankT that allows you to represent the rank of a card. The values of type rankT include the integers between 2 and 10 but should also include the constants Ace, Jack, Queen, and King.
 
 • A type suitT consisting of the four suits: Clubs, Diamonds, Hearts, and Spades.
 • A type cardT that combines a rank and a suit.
 
 • A function NewCard(rank, suit) that creates a cardT from the rank and suit values.
 
 • Two functions, Rank(card) and Suit(card), that allow the client to select the rank and suit of a cardT value. These functions could easily be replaced by code that selected the appropriate components of the card, but defining them as functions means that the client need not pay attention to the underlying structure of the type.
 
 • A function CardName(card) that returns a string identifying the card. The result of CardName begins with a rank indicator (which is one of A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, or K), followed by a one-character suit (C, D, H, or S). Note that the result is usually a two-character string, but contains three characters if the rank is a 10. */


#ifndef CourseWork_card_h
#define CourseWork_card_h
#include <string>

enum rankT {
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

enum suitT{
    Clubs,
    Diamonds,
    Hearts,
    Spades
};


struct cardT{
    rankT rank;
    suitT suit;
};

cardT NewCard(rankT, suitT);

rankT Rank(cardT);

suitT Suit(cardT);

std::string CardName(cardT);

#endif
