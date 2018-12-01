#pragma once

#include <vector>
#include "Deck.h"

using std::vector;

class PlayGame
{
public:
	PlayGame(int cardCount = 21); // Setup

	void playGame(sf::RenderWindow & window); // This is where gameplay actually runs

	bool isSet(Card & const c1, Card & const c2, Card & const c3); //Checks if three given cards are a set.

	bool gameOverCheck(); //Checks to see if the game is over.

	bool anySets(); // Checks if there are any sets in play.

private:
	Deck mDeck;
	vector<Card> mCardsInPlay;
	vector<sf::Texture> mTexturesInPlay;
	vector<sf::Sprite> mSpritesInPlay;
	int mCardCount;
	vector<int> mCardsSelected;
};