#include "PlayGame.h"

PlayGame::PlayGame()
{
	mWindow.create(sf::VideoMode(1280, 720), "Set Game");

	// Put 12 cards into play
	for (int i = 0; i < 12; i++)
	{
		mCardsInPlay.push_back(mDeck.dealCard());

		sf::Texture texture;
		if (!texture.loadFromFile(mCardsInPlay.back().getImage()))
		{
			cout << "error loading card image" << endl;
		}
		mTexturesInPlay.push_back(texture);

		sf::Sprite sprite;
		sprite.setTexture(mTexturesInPlay.back());
		mSpritesInPlay.push_back(sprite);

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
		for (int i = 0; i < mSpritesInPlay.size(); i++)
			mWindow.draw(mSpritesInPlay[i]);
		mWindow.display();
	}
}

