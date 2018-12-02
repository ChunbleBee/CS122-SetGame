#include "PlayArea.h"

PlayArea::PlayArea()
{
	mCardsInPlay.reserve(32);
}

void PlayArea::drawPlayArea(sf::RenderWindow & window)
{
	for (int i = 0; i < mCardsInPlay.size(); i++)
	{
		mCardsInPlay[i].setScale(0.4, 0.4); // shrink sprites for screen size
		mCardsInPlay[i].setPosition(10 + (i / 3) * 150, 10 + (i % 3) * 200); // move card sprite

		mCardsInPlay[i].refreshTexture();

		window.draw(mCardsInPlay[i]);
	}
}

bool PlayArea::drawCard()
{
	if (!mDeck.isEmpty())
	{
		mCardsInPlay.push_back(CardInPlay(mDeck.dealCard()));
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
	if (mCardsInPlay.size() > 3){
		for (int i = 0; i < mCardsInPlay.size() - 3; i++) {
			for (int j = i + 1; j < mCardsInPlay.size() - 2; j++) {
				for (int k = j + 1; k < mCardsInPlay.size() - 1; k++) {
					if (isSet(mCardsInPlay[i], mCardsInPlay[j], mCardsInPlay[k])) {
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
		if (mCardsInPlay[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			mCardsInPlay[i].switchSelected();

			if (mCardsInPlay[i].isSelected())
			{
				mCardsSelected.push_back(i);
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
			}
		}
		
	}
}

void PlayArea::singlePlayerMode(sf::RenderWindow & window)
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
					if (mCardsInPlay[i].isSelected())
						mCardsInPlay.erase(mCardsInPlay.begin() + i);
					else
						i++;
				}
			}
			else
			{
				// reset cards selection
				for (int i = 0; i < mCardsInPlay.size(); i++)
				{
					if (mCardsInPlay[i].isSelected())
						mCardsInPlay[i].switchSelected();
				}
			}

			//clear cards selected
			mCardsSelected.clear();
		}

		// draw cards (in groups of 3) until there is a set or the deck is empty
		while (!anySets() && !gameOver)
		{
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
		window.display();
	}
}


