//File: deck.cpp
//written by Quockhang Truong

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"

using namespace std;

Deck::Deck(){
  myIndex = 0;
  for(int i = Card::spades; i <= Card::clubs; i++){
    for(int j = 1; j < 14; j++){
      myCards[myIndex] = Card(j, (Card::Suit)i);
      myIndex++;
    }
  }
  for(int i = 0; i < 52; i++){
    cout<< myCards[i] << endl;
  }
}
int main(){
  Deck d;
  return 0;
}
