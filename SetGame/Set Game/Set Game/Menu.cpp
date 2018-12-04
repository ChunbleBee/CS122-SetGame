#include "Menu.h"

Menu::Menu()
{
	if (!mFont.loadFromFile("Fonts/comic.ttf"))
	{
		cout << "Error Loading font." << endl;
	}

	mHeader = sf::Text("Set!", mFont, 120);
	mHeader.setColor(sf::Color::Magenta);
	mHeader.setPosition(640 - mHeader.getGlobalBounds().width/2, 40);

	mOptions.resize(5);
	mOptions[0] = sf::Text("Play Single Player", mFont, 30);
	mOptions[1] = sf::Text("Host Multiplayer", mFont, 30);
	mOptions[2] = sf::Text("Join Multiplayer", mFont, 30);
	mOptions[3] = sf::Text("How To Play", mFont, 30);
	mOptions[4] = sf::Text("Exit", mFont, 30);

	for (int i = 0; i < mOptions.size(); i++)
	{
		mOptions[i].setColor(sf::Color::Magenta);
		mOptions[i].setPosition(640 - mOptions[i].getGlobalBounds().width/2, 140 + 60 * (i + 1));
	}
}

int Menu::renderMenu(sf::RenderWindow & window)
{
	int frameCount = 0;

	while (window.isOpen()) {
		sf::Event ev;

		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}
			if (ev.type == sf::Event::MouseButtonPressed)
			{
				int out = checkMenuPressed(window);
				if (out != -1)
				{
					return out;
				}
			}
		}

		frameCount++;

		if (frameCount > 5)
		{
			changeTextColor(window);
			frameCount = 0;
		}
		window.clear();
		drawText(window);
		window.display();
	}
}

int Menu::checkMenuPressed(sf::RenderWindow & window)
{
	sf::Vector2f adjMousePos = adjustedMousePosition(window);
	for (int i = 0; i < mOptions.size(); i++)
	{
		if (mOptions[i].getGlobalBounds().contains(adjMousePos))
		{
			return i;
		}
	}

	return -1;
}

void Menu::drawText(sf::RenderWindow & window)
{
	window.draw(mHeader);

	for (int i = 0; i < mOptions.size(); i++)
	{
		window.draw(mOptions[i]);
	}
}

void Menu::changeTextColor(sf::RenderWindow & window) {
	sf::Vector2f adjMousePos = adjustedMousePosition(window);
	if (mHeader.getGlobalBounds().contains(adjMousePos)) {
		mHeader.setColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	}

	for (int i = 0; i < mOptions.size(); i++) {
		if (mOptions[i].getGlobalBounds().contains(adjMousePos)) {
			mOptions[i].setColor(sf::Color(rand() % 256, rand() % 256, rand() % 256, 255));
		}
	}
}

sf::Vector2f Menu::adjustedMousePosition(sf::RenderWindow & window) {
	return 	window.mapPixelToCoords(sf::Mouse::getPosition(window));
}