#include "Stopwatch.h"

Stopwatch::Stopwatch(sf::Vector2f position)
{
	if (!mFont.loadFromFile("Fonts/comic.ttf"))
		cout << "Error Loading font." << endl;

	mTimeElapsed.setFont(mFont);
	mTimeElapsed.setCharacterSize(42);
	mTimeElapsed.setPosition(position);

	start();
}

void Stopwatch::start()
{
	mClock.restart();
	counting = true;
	updateTimeText();
}

void Stopwatch::updateTimeText()
{
	if (counting)
	{
		sf::Time time = mClock.getElapsedTime();

		std::string timeText = std::to_string(time.asMilliseconds() / 60000) + ":" +
			padStringZeros(std::to_string((time.asMilliseconds() % 60000) / 1000), 2) + ":" +
			padStringZeros(std::to_string(time.asMilliseconds() % 1000), 3);

		mTimeElapsed.setString(timeText);
	}
}

void Stopwatch::draw(sf::RenderWindow & window)
{
	updateTimeText();
	window.draw(mTimeElapsed);
}

void Stopwatch::stop()
{
	counting = false;
}

std::string & Stopwatch::padStringZeros(std::string & stringToPad, int length)
{
	if (stringToPad.length() < length)
	{
		stringToPad = std::string(length - stringToPad.length(), '0') + stringToPad;
	}

	return stringToPad;
}


