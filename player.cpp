#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "card.h"
using namespace std;

Player::Player(){

}
void Player::addCard(Card c){
  cout << myName << "draws a" << c << endl;
  myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
  cout << myName << "books the " << c1.getRank() << endl;
  myBook.push_back(c1);
  myBook.push_back(c2);
}

//optional
// bool Player::checkHandForBook(Card &c1, Card &c2);
// bool Player::rankInHand(Card c) const;
//
// Card Player::chooseCardFromHand() const;

bool Player::cardInHand(Card c) const{
  vector<Card>::iterator it = myHand.begin();
  for(it = myHand.begin(); it != myHand.end(); ++it){
    if(*it == c){
      return true;
    }
  }
  return false;
}

Card Player::removeCardFromHand(Card c){
  vector<Card>::iterator it = myHand.begin();
  for(it = myHand.begin(); *it != c && it != myHand.end(); ++it){
  }
  myHand.erase(it);

  return c;
}

string Player::showHand() const{
  string s;
  for(int i = 0; i <= myHand.size(); i++){
    s = s + myHand[i].toString();
  }
}
// string Player::showBooks() const{}
//
int Player::getHandSize() const{
  return myHand.size();
}

int Player::getBookSize() const{
  return myBook.size();
}

//
// optional
// bool Player::checkHandForPair(Card &c1, Card &c2);
// bool Player::sameRankInHand(Card c) const;
