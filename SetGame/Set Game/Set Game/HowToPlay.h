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

private:
	sf::Font mFont;
};