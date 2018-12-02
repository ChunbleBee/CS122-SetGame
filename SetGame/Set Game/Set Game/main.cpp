#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "PlayGame.h"
#include "PlayArea.h"

#include "Test.cpp"

int main()
{
	Test t;
	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Set Game");

	//CardInPlay CIP(Card(0, 0, 0, 0, 0, "Set Cards/r2wd.png"));
	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}
	//	window.clear();
	//	window.draw(CIP);
	//	window.display();
	//}

	PlayArea solo;
	solo.singlePlayerMode(window);

	PlayGame set;


	return 0;
}