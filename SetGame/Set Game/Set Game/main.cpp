#include <SFML/Graphics.hpp>
#include <iostream>

#include "PlayGame.h"
#include "PlayArea.h"
#include "HowToPlay.h"

#include "Test.h"

int main()
{
	Test t;

	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Set Game");

	HowToPlay instructions;
	instructions.demo(window);

	PlayArea solo;
	solo.singlePlayerMode(window);

	PlayGame set;


	return 0;
}
