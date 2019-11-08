//File: deck.cpp
//written by Quockhang Truong

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include <fstream>
#include <ctime>

using namespace std;

Deck::Deck(){
  myIndex = 0;
  for(int i = Card::spades; i <= Card::clubs; i++){
    for(int j = 1; j < 14; j++){
      myCards[myIndex] = Card(j, (Card::Suit)i);
      myIndex++;
    }
  }
  myIndex = myIndex - 1;

  unsigned int currentTime =  (unsigned)time(0);
  srand(currentTime);
}

void Deck::shuffle(){   // shuffle the deck, all 52 cards present
  if(this->size() < SINGLECARD){
     return; // nothing to shuffle
  }
  else{
    int temp = myIndex;
    while(temp > EMPTY){
      myCards[temp].swap(myCards[rand()%myIndex]);
      temp--;
    }
  }
}
Card Deck::dealCard(){  // get a card, after 52 are dealt, fail
  if (this->size() > EMPTY){
    Card temp = myCards[myIndex];
    myIndex--;
    return temp;
  }
}
 int  Deck::size() const{ // # cards left in the deck
  return (myIndex + 1);
 }
