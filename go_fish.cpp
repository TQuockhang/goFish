// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void turnOf(Player &p1, Player &p2, Deck &d, uint &turn, ofstream &myfile);


int main( )
{
  ofstream myfile ("gofish_results.txt");
  if(!myfile.is_open()){
    cout << "failed" << endl;
    EXIT_SUCCESS;
  }
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");
    Card c1;
    Card c2;

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has:" << p1.showHand() << endl;
    cout << p2.getName() <<" has:" << p2.showHand() << endl;
    myfile << p1.getName() <<" has:" << p1.showHand() << endl;
    myfile << p2.getName() <<" has:" << p2.showHand() << endl;

    uint turn = rand() % 2;
    bool again = (bool) turn;
    cout << "player " << turn + 1 << " will go first" <<endl;

    while(p1.checkHandForPair(c1, c2)){
      p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2));
    }
    while(p2.checkHandForPair(c1, c2)){
      p2.bookCards(p2.removeCardFromHand(c1), p2.removeCardFromHand(c2));
    }

    while(d.size() > 0 || p1.getHandSize() > 0 || p2.getHandSize() > 0){
      cout << p1.getName() <<" has:" << p1.showHand() << endl;
      cout << p2.getName() <<" has:" << p2.showHand() << endl;
      myfile << p1.getName() <<" has:" << p1.showHand() << endl;
      myfile << p2.getName() <<" has:" << p2.showHand() << endl;
      if(turn == 0){
        turnOf(p1, p2, d, turn, myfile);
      }
      cout << endl;
      if (turn == 1){
        turnOf(p2, p1, d, turn, myfile);
      }
      cout << endl;
    }

    cout << p1.getName() << " has " << p1.showBooks() << endl;
    cout << p2.getName() << " has " << p2.showBooks() << endl;
    myfile << p1.getName() << " has " << p1.showBooks() << endl;
    myfile << p2.getName() << " has " << p2.showBooks() << endl;
    if(p1.getBookSize() > p2.getBookSize()){
      cout << p1.getName() << " is the winner!" << endl;
      myfile << p1.getName() << " is the winner!" << endl;
    }
    else if(p1.getBookSize() < p2.getBookSize()){
      cout << p2.getName() << " is the winner!" << endl;
      myfile << p2.getName() << " is the winner!" << endl;
    }
    else{
      cout << "its a tie" << endl;
      myfile << "its a tie" << endl;
    }
    myfile.close();
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

void turnOf(Player &p1, Player &p2, Deck &d, uint &turn, ofstream &myfile){
  if(p1.getHandSize() == 0){
    if(d.size() > 0){
      p1.addCard(d.dealCard());
    }
    else{
      return;
    }
  }
  Card c1 = p1.chooseCardFromHand();
  Card c2;
  cout << p1.getName() << " asks - do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
  myfile << p1.getName() << " asks - do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
  if(p2.cardInHand(c1)){
    cout << p2.getName() << " says - yes, here you go!" << endl;
    myfile << p2.getName() << " says - yes, here you go!" << endl;
    p1.bookCards(p1.removeCardFromHand(c1), p2.removeCardFromHand(c1));
    myfile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
    turn = turn % 2;
  }
  else{
    cout << p2.getName() << " says - nope. Go Fish!" << endl;
    myfile << p2.getName() << " says - nope. Go Fish!" << endl;
    p1.addCard(d.dealCard());
    if(p1.checkHandForPair(c1, c2)){
      p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2));
    myfile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
      turn = turn % 2;
    }
    else{
      turn = (~turn) % 2;
    }
  }
}
