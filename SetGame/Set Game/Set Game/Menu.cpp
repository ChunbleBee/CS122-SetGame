#include "Menu.h"

Menu::Menu()
{
	mHeader.setString("Set!");
	mHeader.setCharacterSize(60);
	mHeader.setColor(sf::Color::Magenta);
	mHeader.setFont(mFont);
	mHeader.setPosition(640 - (mHeader.getGlobalBounds().width), 60);

	cout << mHeader.getGlobalBounds().width << ","
		<< mHeader.getGlobalBounds().height << endl;

	mOptions.resize(3);
	mOptions[0].setString("Play Game");
	mOptions[1].setString("Show Instructions");
	mOptions[2].setString("Exit");

	for (int i = 0; i < mOptions.size(); i++) {
		mOptions[i].setCharacterSize(30);
		mOptions[i].setColor(sf::Color::Magenta);
		mOptions[i].setFont(mFont);
		mOptions[i].setPosition( 640.0 - (mOptions[i].getGlobalBounds()).height, 120.0 + 60 * (i + 1));
	}

	if (!mFont.loadFromFile("Fonts/comic.ttf"))
	{
		cout << "Error Loading font." << endl;
	}
}

int Menu::renderMenu(sf::RenderWindow & window)
{
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

			window.clear();
			drawText(window);
			window.display();
		}
	}
}

int Menu::checkMenuPressed(sf::RenderWindow & window)
{
	sf::Vector2f adjusted_mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	for (int i = 0; i < mOptions.size(); i++)
	{
		if (mOptions[i].getGlobalBounds().contains(adjusted_mouse_position))
		{
			return i;
		}
	}

	return -1;
}

void Menu::drawText(sf::RenderWindow & window)
{
	window.draw(mHeader);

	for (int i = 0; i < 3; i++)
	{
		window.draw(mOptions[i]);
	}
}