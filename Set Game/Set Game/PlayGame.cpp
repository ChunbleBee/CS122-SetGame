#include "PlayGame.h"

PlayGame::PlayGame()
{
	mWindow.create(sf::VideoMode(1280, 720), "Set Game");

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
		mSpritesInPlay[i].setPosition(10 + (i/3) * 150, 10 + (i%3) * 200); // move card sprite

	}

	mCardCount = 21; // set card count
	mCardsSelected = 0; // set selection count
}

void PlayGame::playGame()
{
	while (mWindow.isOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				for (int i = 0; i < mCardCount; i++)
				{
					if (mSpritesInPlay[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(mWindow))))
					{
						if (mCardsInPlay[i].isSelected())
						{
							mSpritesInPlay[i].setColor(sf::Color(255, 255, 255, 255));
							mCardsSelected--;
						}
						else
						{
							mSpritesInPlay[i].setColor(sf::Color(255, 255, 255, 127));
							mCardsSelected++;
						}
						mCardsInPlay[i].switchSelected();
					}
				}
			}
		}

		//if (mCardsSelected == 3)
		//{
		//	// Check if selected cards make a SET
		//}

		mWindow.clear();
		for (int i = 0; i < mCardCount; i++)
			mWindow.draw(mSpritesInPlay[i]);
		mWindow.display();
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