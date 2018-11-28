#include <SFML/Graphics.hpp>
#include <iostream>
#include "Deck.cpp"

int main()
{
	Deck d;
	// The main function is just an experemental mess right now. 
	// TODO: make this better. yep.
	// seriously this code is trash.

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Set");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	// Load a texture from a file
	sf::Texture texture;
	if (!texture.loadFromFile("Set Cards/r2wd.PNG"))
		return -1;

	sf::Sprite sprite;
	sprite.setTexture(texture);

	sprite.setScale(0.4f, 0.4f);
	sprite.setPosition(10.f, 10.f);
	bool selected = false;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (sprite.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
				{
					if (!selected)
					{
						selected = true;
						sprite.setColor(sf::Color(255, 255, 255, 128)); // half transparent
					}
					else
					{
						selected = false;
						sprite.setColor(sf::Color(255, 255, 255, 255)); // opaque
					}
				}
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	//// Wait for input
	//std::cout << "\nEnter to continue. ";
	//std::cin.get();
	//std::cin.get();

	return 0;
}