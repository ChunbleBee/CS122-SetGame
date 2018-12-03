#pragma once

#include <SFML/Graphics.hpp>
#include "CardInPlay.h"

class HowToPlay
{
public:
	HowToPlay();

	void demo(sf::RenderWindow & window);

	void pageOne(sf::RenderWindow & window);
	void pageTwo(sf::RenderWindow & window);
	void pageThree(sf::RenderWindow & window);
	void pageFour(sf::RenderWindow & window);

private:
	sf::Font mFont;
};