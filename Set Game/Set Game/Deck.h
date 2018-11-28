#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include <windows.h>
#include "Card.cpp"

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