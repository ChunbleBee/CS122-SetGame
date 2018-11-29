#include "PlayGame.h"

PlayGame::PlayGame()
{
	mWindow.create(sf::VideoMode(1280, 720), "Set Game");

	// Put 12 cards into play
	for (int i = 0; i < 12; i++)
	{
		mCardsInPlay[i] = mDeck.dealCard();

		if (!mTexturesInPlay[i].loadFromFile(mCardsInPlay[i].getImage()))
		{
			cout << "error loading card image" << endl;
		}

		mSpritesInPlay[i].setTexture(mTexturesInPlay[i]);

		////// this is just for debugging
		//bool click = false;
		//while (!click)
		//{
		//	sf::Event event;
		//	while (mWindow.pollEvent(event))
		//	{
		//		if (event.type == sf::Event::MouseButtonPressed)
		//			click = true;
		//	}
		//	mWindow.clear();
		//	mWindow.draw(mSpritesInPlay.back());
		//	mWindow.display();
		//}
		//////
	}

	// Move Card Sprites to display positions
	for (int i = 0; i < 12; i++)
	{
		////// this is just for debugging
		//bool click = false;
		//while (!click)
		//{
		//	sf::Event event;
		//	while (mWindow.pollEvent(event))
		//	{
		//		if (event.type == sf::Event::MouseButtonPressed)
		//			click = true;
		//	}
		//	mWindow.clear();
		//	mWindow.draw(mSpritesInPlay[i]);
		//	mWindow.display();
		//}
		//////

		mSpritesInPlay[i].setScale(0.4, 0.4);
		mSpritesInPlay[i].setPosition(10 + (i/3) * 150, 10 + (i%3) * 200);

		////// this is just for debugging
		//click = false;
		//while (!click)
		//{
		//	sf::Event event;
		//	while (mWindow.pollEvent(event))
		//	{
		//		if (event.type == sf::Event::MouseButtonPressed)
		//			click = true;
		//	}
		//	mWindow.clear();
		//	mWindow.draw(mSpritesInPlay[i]);
		//	mWindow.display();
		//}
		//////
	}

	mCardCount = 12;
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
		}

		mWindow.clear();
		for (int i = 0; i < mCardCount; i++)
			mWindow.draw(mSpritesInPlay[i]);
		mWindow.display();
	}
}

