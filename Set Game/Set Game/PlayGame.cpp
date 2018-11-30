#include "PlayGame.h"

PlayGame::PlayGame(int cardCount)
{
	mCardCount = cardCount;
	mCardsInPlay.resize(mCardCount);
	mTexturesInPlay.resize(mCardCount);
	mSpritesInPlay.resize(mCardCount);

	// Put 12 cards into play
	for (int i = 0; i < 21; i++)
	{
		mCardsInPlay[i] = mDeck.dealCard(); // add card to deck

		if (!mTexturesInPlay[i].loadFromFile(mCardsInPlay[i].getImage())) // load card texture
		{
			cout << "error loading card image" << endl;
		}

		mSpritesInPlay[i].setTexture(mTexturesInPlay[i]); // set sprite's texture

	}

	// Move Card Sprites to display positions
	for (int i = 0; i < 21; i++)
	{

		mSpritesInPlay[i].setScale(0.4, 0.4); // shrink sprites for screen size
		mSpritesInPlay[i].setPosition(10 + (i / 3) * 150, 10 + (i % 3) * 200); // move card sprite

	}
}

void PlayGame::playGame(sf::RenderWindow & window)
{
	bool gameOver = false;

	while (window.isOpen() && !gameOver)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				for (int i = 0; i < mCardCount; i++)
				{
					if (mSpritesInPlay[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
					{
						if (mCardsInPlay[i].isSelected()) // deselected
						{
							mSpritesInPlay[i].setColor(sf::Color(255, 255, 255, 255));

							// remove card index from cards selected
							for (int j = 0; j < mCardsSelected.size(); j++)
							{
								if (mCardsSelected[j] == i)
								{
									mCardsSelected.erase(mCardsSelected.begin() + j);
								}
							}
						}
						else // selected
						{
							mSpritesInPlay[i].setColor(sf::Color(255, 255, 255, 127));
							mCardsSelected.push_back(i); //add card index to cards selected
						}
						mCardsInPlay[i].switchSelected();


						cout << "Cards selected: ";
						for (int j = 0; j < mCardsSelected.size(); j++)
							cout << mCardsSelected[j] << " ";
						cout << endl;
					}
				}
			}
		}

		// when 3 cards are selected test if they make a set
		if (mCardsSelected.size() == 3)
		{
			// Check if selected cards make a SET
			if (isSet(mCardsInPlay[mCardsSelected[0]], mCardsInPlay[mCardsSelected[1]], mCardsInPlay[mCardsSelected[2]]))
			{
				// If they do remove them and replace them
				for (int i = 0; i < 3; i++)
				{
					if (mDeck.isEmpty() == false) 
					{
						//replace cards
						mCardsInPlay[mCardsSelected[i]] = mDeck.dealCard();
						//replace textures
						mTexturesInPlay[mCardsSelected[i]].loadFromFile(mCardsInPlay[mCardsSelected[i]].getImage());
					}
					else 
					{
						mCardCount--;
						mCardsInPlay[mCardsSelected[i]] = mCardsInPlay[mCardCount];
						mTexturesInPlay[mCardsSelected[i]] = mTexturesInPlay[mCardCount];
					}
				}

				if (gameOverCheck()) 
				{
					cout << "Game Over!" << endl;
					gameOver = true;
				}
			}

			// deselect the three cards
			for (int i = 0; i < 3; i++)
			{
				//reset transparancy
				mSpritesInPlay[mCardsSelected[i]].setColor(sf::Color(255, 255, 255, 255));
			}
			mCardsSelected.clear();
		}

		window.clear();
		for (int i = 0; i < mCardCount; i++)
			window.draw(mSpritesInPlay[i]);
		window.display();
	}
}



bool PlayGame::isSet(Card & const c1, Card & const c2, Card & const c3)
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

bool PlayGame::gameOverCheck()
{
	int maxIndex = mCardCount;
	if (mDeck.isEmpty() == true) {
		for (int i = 0; i < maxIndex - 3; i++) {
			for (int j = i + 1; j < maxIndex - 2; j++) {
				for (int k = j + 1; k < maxIndex - 1; k++) {
					if (isSet(mCardsInPlay[i], mCardsInPlay[j], mCardsInPlay[k])) {
						return false;
					}
				}
			}
		}

		return true;
	}
	return false;
}
