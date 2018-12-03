#include "PlayArea.h"

PlayArea::PlayArea()
{
	mDeck.shuffle();
	mCardsInPlay.reserve(32);
	loadSounds();
}

void PlayArea::drawPlayArea(sf::RenderWindow & window)
{
	for (int i = 0; i < mCardsInPlay.size(); i++)
	{
		mCardsInPlay[i].setScale(0.45, 0.45); // shrink sprites for screen size
		mCardsInPlay[i].setPosition(20 + (i / 3) * 180, 20 + (i % 3) * 236); // move card sprite

		mCardsInPlay[i].refreshTexture();

		window.draw(mCardsInPlay[i]);
	}
}

bool PlayArea::drawCard()
{
	if (!mDeck.isEmpty())
	{
		Card test = mDeck.dealCard();
		mCardsInPlay.push_back(test);

		return true;
	}
	else
		return false;
}

bool PlayArea::isSet(Card const & c1, Card const & c2, Card const & c3)
{
	//shape, color, fill, number, size
	for (int i = 0; i < 5; i++) { //exchange hardcoded 5 w/ difficulty
		if ((c1.getAttributes()[i] == c2.getAttributes()[i] && c1.getAttributes()[i] != c3.getAttributes()[i])
			|| (c1.getAttributes()[i] != c2.getAttributes()[i] && c1.getAttributes()[i] == c3.getAttributes()[i])
			|| (c1.getAttributes()[i] != c2.getAttributes()[i] && c2.getAttributes()[i] == c3.getAttributes()[i])) {
			return false;
		}
	}

	return true;
}

bool PlayArea::anySets()
{
	if (mCardsInPlay.size() > 3)
	{
		for (int i = 0; i < mCardsInPlay.size() - 3; i++)
		{
			for (int j = i + 1; j < mCardsInPlay.size() - 2; j++)
			{
				for (int k = j + 1; k < mCardsInPlay.size() - 1; k++)
				{
					if (isSet(mCardsInPlay[i], mCardsInPlay[j], mCardsInPlay[k]))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

void PlayArea::cardClickCheck(sf::RenderWindow & window)
{
	for (int i = 0; i < mCardsInPlay.size(); i++)
	{
		sf::Vector2f adjusted_mouse_position = window.mapPixelToCoords((sf::Mouse::getPosition(window)));
		if (mCardsInPlay[i].getGlobalBounds().contains(adjusted_mouse_position))
		{
			mCardsInPlay[i].switchSelected();

			if (mCardsInPlay[i].isSelected())
			{
				mCardsSelected.push_back(i);
				if (mCardsSelected.size() < 3)
					mSounds[0].play();
			}
			else
			{
				// remove card index from cards selected
				for (int j = 0; j < mCardsSelected.size(); j++)
				{
					if (mCardsSelected[j] == i)
					{
						mCardsSelected.erase(mCardsSelected.begin() + j);
					}
				}
				mSounds[1].play();
			}
		}
	}
}

void PlayArea::singlePlayerMode(sf::RenderWindow & window)
{
	Stopwatch timeDisplay(sf::Vector2f(1060, 20));
	timeDisplay.start();
	bool gameOver = false;

	while (window.isOpen() && !gameOver)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				cardClickCheck(window);
			}
		}

		// when 3 cards are selected test if they make a set
		if (mCardsSelected.size() == 3)
		{
			// Check if selected cards make a SET
			if (isSet(mCardsInPlay[mCardsSelected[0]], mCardsInPlay[mCardsSelected[1]], mCardsInPlay[mCardsSelected[2]]))
			{
				// If they do remove them
				for (int i = 0; i < mCardsInPlay.size();)
				{
					if (mCardsInPlay[i].isSelected()) {
						mCardsInPlay.erase(mCardsInPlay.begin() + i);
					}
					else {
						i++;
					}
				}
				mSounds[2].play();
			}
			else
			{
				// reset cards selection
				for (int i = 0; i < mCardsInPlay.size(); i++)
				{
					if (mCardsInPlay[i].isSelected()) {
						mCardsInPlay[i].switchSelected();
					}
				}
				mSounds[3].play();
			}

			//clear cards selected
			mCardsSelected.clear();
		}

		// draw cards (in groups of 3) until there is a set or the deck is empty
		while ((mCardsInPlay.size() < 12 || !anySets()) && !gameOver)
		{
			std::cout << mCardsInPlay.size() << std::endl;
			if (mDeck.isEmpty())
				gameOver = true;
			else
			{
				drawCard();
				drawCard();
				drawCard();
			}
		}

		window.clear();
		drawPlayArea(window);
		timeDisplay.draw(window);
		window.display();
	}

	// Final display
	timeDisplay.stop();
	bool continueClick = false;
	while (window.isOpen() && !continueClick)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				continueClick = true;
			}
		}

		window.clear();
		drawPlayArea(window);
		timeDisplay.draw(window);
		window.display();
	}
}

void PlayArea::loadSounds()
{
	// load selection sound (sound 0)
	if (!mBuffers[0].loadFromFile("./Sounds/263133__pan14__tone-beep.wav"))
		cout << "Failed to load sound 0." << endl;
	mSounds[0].setBuffer(mBuffers[0]);

	// load deselection sound (sound 1)
	if (!mBuffers[1].loadFromFile("./Sounds/beep_descending.wav"))
		cout << "Failed to load sound 1." << endl;
	mSounds[1].setBuffer(mBuffers[1]);

	// load SET! sound (sound 2)
	if (!mBuffers[2].loadFromFile("./Sounds/263124__pan14__sine-octaves-up-beep.wav"))
		cout << "Failed to load sound 2." << endl;
	mSounds[2].setBuffer(mBuffers[2]);

	// load not a set sound (sound 3)
	if (!mBuffers[3].loadFromFile("./Sounds/263123__pan14__sine-tri-tone-down-negative-beep-amb-verb.wav"))
		cout << "Failed to load sound 3." << endl;
	mSounds[3].setBuffer(mBuffers[3]);
}
