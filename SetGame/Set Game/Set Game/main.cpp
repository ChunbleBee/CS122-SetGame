#include <SFML/Graphics.hpp>
#include <iostream>

#include "PlayArea.h"
#include "Menu.h"
#include "HowToPlay.h"

#include "Test.h"

int main()
{

	Test t;

	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Set Game");
	window.setVerticalSyncEnabled(true);

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
				PlayArea p;
				p.hostMultiplayer(window);
			}
			break;

			case 2:
			{
				PlayArea p;
				p.clientMultiplayer(window);
			}
			break;

			case 3:
			{
				HowToPlay h;
				h.demo(window);				
			}
			break;

			default:
			{
				window.close();
			}
		}
	}
	return 0;
}
