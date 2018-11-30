#pragma once

#include "Deck.h"

class PlayGame
{
public:
	PlayGame(); // Setup

	void playGame(); // This is where gameplay actually runs

	bool tempisSet(Card c1, Card c2, Card c3) { return true; }

private:
	sf::RenderWindow mWindow;
	Deck mDeck;
	Card mCardsInPlay[21];
	sf::Texture mTexturesInPlay[21];
	sf::Sprite mSpritesInPlay[21];
	int mCardCount;
	vector<int> mCardsSelected;
};