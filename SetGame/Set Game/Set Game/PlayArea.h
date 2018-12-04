#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <list>
#include "CardInPlay.h"
#include "Deck.h"
#include "Stopwatch.h"
#include "TextBox.h"

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

	void hostMultiplayer(sf::RenderWindow & window);
	void clientMultiplayer(sf::RenderWindow & window);

	void setFound(); // call when a set is found

	sf::Int32 connectMultiplayer(sf::RenderWindow & window, char mode); // return rngSeed
	void hostSetup(sf::RenderWindow & window);
	void clientSetup(sf::RenderWindow & window);


	void loadSounds();

private:
	Deck mDeck;
	vector<CardInPlay> mCardsInPlay;
	vector<sf::Int32> mCardsSelected;

	sf::SoundBuffer mBuffers[4];
	sf::Sound mSounds[4];

	sf::Font mFont;

	sf::Text mGameMessage;
	sf::Text mMenuButton;

	sf::Vector2f mAdjustedMousePosition;

	sf::Int32 mScore;
	sf::Text mScoreDisplay;

	sf::TcpSocket mSocket;
};