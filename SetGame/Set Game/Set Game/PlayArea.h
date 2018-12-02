#pragma once

#include <SFML/Audio.hpp>
#include <list>
#include "CardInPlay.h"
#include "Deck.h"

class PlayArea
{
public:
	PlayArea();
	void drawPlayArea(sf::RenderWindow & window);
	bool drawCard();
	bool isSet(Card const & c1, Card const & c2, Card const & c3); //Checks if three given cards are a set.
	bool anySets(); // Checks if there are any sets in play.
	void cardClickCheck(sf::RenderWindow & window); // Call where there is a click to select a card if the cursor is on a card.
	void singlePlayerMode(sf::RenderWindow & window);

	void loadSounds();

private:
	Deck mDeck;
	vector<CardInPlay> mCardsInPlay;
	vector<int> mCardsSelected;

	sf::SoundBuffer mBuffers[4];
	sf::Sound mSounds[4];
};