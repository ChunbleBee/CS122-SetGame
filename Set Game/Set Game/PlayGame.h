#pragma once

#include <vector>
#include "Deck.h"

using std::vector;

class PlayGame
{
public:
	PlayGame(); // Setup

	void playGame(); // This is where gameplay actually runs

	bool isSet(Card & const c1, Card & const c2, Card & const c3);

private:
	sf::RenderWindow mWindow;
	Deck mDeck;
	Card mCardsInPlay[21];
	sf::Texture mTexturesInPlay[21];
	sf::Sprite mSpritesInPlay[21];
	int mCardCount;
	int mCardsSelected;
};