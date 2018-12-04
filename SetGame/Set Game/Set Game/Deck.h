#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include "Card.h"

using std::vector;
using std::cout;

class Deck {
private:
	vector<Card> mCardDeck;
	void buildDeck(int deckSize, int difficulty);

public:
	Deck(int difficulty = 4);

	vector<Card> getDeck();
	
	void shuffle(sf::Int32 seed = time(NULL));
	int cardsLeft();
	Card dealCard();
	bool isEmpty();
};