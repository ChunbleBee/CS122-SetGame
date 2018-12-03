#include <SFML/Graphics.hpp>
#include <iostream>

#include "PlayArea.h"
#include "Menu.h"
#include "HowToPlay.h"

#include "Test.cpp"

int main()
{
	//Test t;

	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Set Game");

	while (window.isOpen())
	{
		Menu m;
		switch (m.renderMenu(window))
			{
			case 0:
			{
				PlayArea p;
				p.singlePlayerMode(window);
			}
			break;

			case 1:
			{
				HowToPlay h;
				h.demo(window);
			}
			break;

			default:
			{
				exit(0);
			}
		}
	}
	return 0;
}
