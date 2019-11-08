#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "card.h"
using namespace std;

Player::Player(){

}
void Player::addCard(Card c){
  cout << myName << " draws a " << c << endl;
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

Card Player::chooseCardFromHand() const{
 return myHand[rand() % myHand.size()];
}

bool Player::cardInHand(Card c) const{
  vector<Card>::const_iterator it = myHand.begin();
  for(it = myHand.begin(); it != myHand.end(); ++it){
    if(*it == c){
      return true;
    }
  }
  return false;
}

Card Player::removeCardFromHand(Card c){
  vector<Card>::iterator it = myHand.begin();
  for(it = myHand.begin(); it != myHand.end(); ++it){
    if (*it == c){
      myHand.erase(it);
      return c;
    }
  }
}

string Player::showHand() const{
  string s;
  vector<Card>::const_iterator it = myHand.begin();
  for(it = myHand.begin(); it != myHand.end(); ++it){
    s = s + " " + it->toString();
  }
  return s;
}
string Player::showBooks() const{
  string s;
  vector<Card>::const_iterator it = myHand.begin();
  for(it = myBook.begin(); it != myBook.end(); ++it){
    s = s + " " + it->toString();
  }
  return s;
}

int Player::getHandSize() const{
  return myHand.size();
}

int Player::getBookSize() const{
  return myBook.size();
}

//
// optional
bool Player::checkHandForPair(Card &c1, Card &c2){
  vector<Card>::iterator it = myHand.begin();
  vector<Card>::iterator it2 = myHand.begin();
  for(it = myHand.begin(); it != myHand.end(); ++it){
    for(it2 = it + 1; it2 != myHand.end(); ++it2){
      if (it->getRank() == it2->getRank()){
        c1 = *it;
        c2 = *it2;
        return true;
      }
    }
  }
  return false;
}
bool Player::sameRankInHand(Card c) const{
  vector<Card>::const_iterator it = myHand.begin();
  for(it = myHand.begin(); it != myHand.end(); ++it){
    if(it->getRank() == c.getRank()){
      return true;
    }
  }
  return false;
}
