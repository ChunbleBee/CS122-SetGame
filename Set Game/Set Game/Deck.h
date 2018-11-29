#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include "Deck.cpp"
#include "Card.h"

using std::vector;

class Deck {
private:
	vector<Card> mCardDeck;
	void buildDeck(int deckSize, int difficulty);
	void shuffle();

public:
	Deck(int difficulty = 4);

	Card dealCard();
};