#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Menu
{
private:
	sf::Font mFont;
	sf::Text mHeader;
	vector<sf::Text> mOptions;
public:
	Menu();
	int renderMenu(sf::RenderWindow & windows);
	int checkMenuPressed(sf::RenderWindow & window);
	void drawText(sf::RenderWindow & window);
};