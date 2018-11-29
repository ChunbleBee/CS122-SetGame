#pragma once

#include "Deck.h"

class PlayGame
{
public:
	PlayGame();

	void playGame(); // This is where gameplay actually runs

private:
	sf::RenderWindow mWindow;
	Deck mDeck;
	vector<Card> mCardsInPlay;
	vector<sf::Texture> mTexturesInPlay;
	vector<sf::Sprite> mSpritesInPlay;
};