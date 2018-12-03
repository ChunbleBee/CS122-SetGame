#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Stopwatch
{
public:
	Stopwatch(sf::Vector2f position);
	void start();
	void updateTimeText();
	void draw(sf::RenderWindow & window);
	void stop();

	std::string & padStringZeros(std::string &stringToPad, int length);

private:
	bool counting;
	sf::Clock mClock;
	sf::Font mFont;
	sf::Text mTimeElapsed;
	sf::Vector2f mClockPosition;
};