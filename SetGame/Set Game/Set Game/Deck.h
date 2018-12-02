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

	Card * getDeck();
	
	void shuffle();

	Card dealCard();
	bool isEmpty();
};