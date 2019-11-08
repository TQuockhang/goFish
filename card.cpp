#include <iostream>
#include <string>
#include "card.h"
using namespace std;

Card::Card(){
  myRank = 1;
  mySuit = spades;
}

Card::Card(int rank, Suit s){
  myRank = rank;
  mySuit = s;
}

string Card::toString() const{ // return string version e.g. Ac 4h Js
  string s = suitString(mySuit) + rankString(myRank);
  return s;

}

bool Card::sameSuitAs(const Card& c) const{
  return (mySuit == c.mySuit);
}

int  Card::getRank() const{
  return myRank;
}

string Card::suitString(Suit s) const{  // return "s", "h",...
  switch(s){
    case spades: return "s";
      break;

    case hearts:return "h";
      break;

    case diamonds: return "d";
      break;

    case clubs: return "c";
      break;
  }
}


string Card::rankString(int r)const{      //   // return "A", "2", ..."Q"
  if(r > 1 || r < 11){
    return std::to_string(r);
  }
  else{
    switch(r){
      case 1: return "A";
        break;

      case 11: return "J";
        break;

      case 12: return "Q";
        break;

      case 13: return "K";
        break;
    }
  }
}

bool Card::operator == (const Card& rhs) const{
  return ((myRank == rhs.myRank)&& (mySuit == rhs.mySuit));
}

bool Card::operator != (const Card& rhs) const{
  return !((myRank == rhs.myRank)&& (mySuit == rhs.mySuit));
}

ostream& operator << (ostream& out, const Card& c){
   out << c.toString() << endl;
   return out;
}
