final: card_demo.o player.o deck.o card.o
	g++ -ogoFish card_demo.o player.o deck.o card.o
driver: card_demo.cpp player.h Deck.h card.h
	g++ -c card_demo.cpp
player.o: player.cpp card.h
		g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
Card.o: card.cpp card.h
	g++ -c card.cpp
