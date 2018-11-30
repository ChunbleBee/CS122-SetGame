#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayGame.h"

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Set Game");
	PlayGame set;

	std::cout << endl;

	//shape, color, fill, number, size
	Card c1(0, 0, 0, 0, 0, "");
	Card c2(0, 0, 0, 0, 0, "");
	Card c3(0, 0, 0, 0, 0, "");
	std::cout << set.isSet(c1, c2, c3) << std::endl;

	c2.setShape(1);
	std::cout << set.isSet(c1, c2, c3) << std::endl;

	c3.setShape(1);
	std::cout << set.isSet(c1, c2, c3) << std::endl;
	
	c3.setShape(2);
	std::cout << set.isSet(c1, c2, c3) << std::endl;


	set.playGame(window);



	return 0;
}