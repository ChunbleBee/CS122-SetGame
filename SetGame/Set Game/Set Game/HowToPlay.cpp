#include "HowToPlay.h"

HowToPlay::HowToPlay()
{
	if (!mFont.loadFromFile("Fonts/comic.ttf"))
		cout << "Error Loading font." << endl;

}

void HowToPlay::demo(sf::RenderWindow & window)
{
	pageOne(window);
	pageTwo(window);
	pageThree(window);
	pageFour(window);
}

void HowToPlay::pageOne(sf::RenderWindow & window)
{
	sf::Text textOne;
	textOne.setFont(mFont);
	textOne.setString("This is Set! To play select valid sets of three cards like this one.");
	textOne.setCharacterSize(42);


	sf::Text textTwo;
	textTwo.setFont(mFont);
	textTwo.setString("Click to continue.");
	textTwo.setCharacterSize(42);
	textTwo.setPosition(800, 560);


	CardInPlay cardOne(Card(1, 2, 1, 1));
	cardOne.setPosition(80, 80);

	CardInPlay cardTwo(Card(1, 1, 1, 1));
	cardTwo.setPosition(420, 80);

	CardInPlay cardThree(Card(1, 0, 1, 1));
	cardThree.setPosition(760, 80);


	bool nextPage = false;

	while (window.isOpen() && !nextPage)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
				nextPage = true;
		}

		window.clear();

		window.draw(textOne);
		window.draw(textTwo);
		window.draw(cardOne);
		window.draw(cardTwo);
		window.draw(cardThree);

		window.display();
	}
}

void HowToPlay::pageTwo(sf::RenderWindow & window)
{
	sf::Text text[6];
	for (int i = 0; i < 6; i++)
	{
		text[i].setFont(mFont);
		text[i].setCharacterSize(42);
	}
	text[0].setString("Each Card has Four Attributes, and there are three options \nfor each attribute.");

	text[1].setString("Color");
	text[1].setPosition(10, 120);

	text[2].setString("Number");
	text[2].setPosition(230, 120);

	text[3].setString("Shape");
	text[3].setPosition(450, 120);

	text[4].setString("Fill");
	text[4].setPosition(670, 120);

	text[5].setString("Click to continue.");
	text[5].setPosition(800, 560);


	CardInPlay cards[12];

	// Color
	cards[0].changeCard(Card(0, 0, 0, 0));
	cards[1].changeCard(Card(0, 1, 0, 0));
	cards[2].changeCard(Card(0, 2, 0, 0));

	// Number
	cards[3].changeCard(Card(0, 0, 0, 0));
	cards[4].changeCard(Card(0, 0, 0, 1));
	cards[5].changeCard(Card(0, 0, 0, 2));

	// Shape
	cards[6].changeCard(Card(0, 0, 0, 0));
	cards[7].changeCard(Card(1, 0, 0, 0));
	cards[8].changeCard(Card(2, 0, 0, 0));

	// Fill
	cards[9].changeCard(Card(0, 0, 0, 0));
	cards[10].changeCard(Card(0, 0, 1, 0));
	cards[11].changeCard(Card(0, 0, 2, 0));


	bool nextPage = false;

	while (window.isOpen() && !nextPage)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
				nextPage = true;
		}

		window.clear();

		for (int i = 0; i < 6; i++)
		{
			window.draw(text[i]);
		}


		for (int i = 0; i < 12; i++)
		{
			cards[i].setScale(0.35, 0.35); // shrink sprites for screen size
			cards[i].setPosition(10 + (i / 3) * 220, 180 + (i % 3) * 170); // move card sprite

			cards[i].refreshTexture();

			window.draw(cards[i]);
		}

		window.display();
	}
}

void HowToPlay::pageThree(sf::RenderWindow & window)
{
	sf::Text text[6];
	for (int i = 0; i < 6; i++)
	{
		text[i].setFont(mFont);
		text[i].setCharacterSize(42);
	}
	text[0].setString("In a valid Set for eash of the four atributes the cards are \nall the same or all different. Never two alike and one different.");

	text[1].setString("Set");
	text[1].setPosition(10, 120);

	text[2].setString("Set");
	text[2].setPosition(230, 120);

	text[3].setString("Not a Set");
	text[3].setPosition(420, 120);

	text[4].setString("Not a Set");
	text[4].setPosition(640, 120);

	text[5].setString("Click to continue.");
	text[5].setPosition(800, 560);


	CardInPlay cards[12];

	// Color
	cards[0].changeCard(Card(0, 0, 2, 1));
	cards[1].changeCard(Card(0, 1, 2, 1));
	cards[2].changeCard(Card(0, 2, 2, 1));

	// Number
	cards[3].changeCard(Card(2, 1, 0, 0));
	cards[4].changeCard(Card(1, 2, 1, 1));
	cards[5].changeCard(Card(0, 0, 2, 2));

	// Shape
	cards[6].changeCard(Card(0, 2, 0, 0));
	cards[7].changeCard(Card(2, 2, 0, 2));
	cards[8].changeCard(Card(2, 2, 0, 1));

	// Fill
	cards[9].changeCard(Card(0, 1, 0, 0));
	cards[10].changeCard(Card(0, 1, 2, 2));
	cards[11].changeCard(Card(0, 1, 2, 1));


	bool nextPage = false;

	while (window.isOpen() && !nextPage)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
				nextPage = true;
		}

		window.clear();

		for (int i = 0; i < 6; i++)
		{
			window.draw(text[i]);
		}


		for (int i = 0; i < 12; i++)
		{
			cards[i].setScale(0.35, 0.35); // shrink sprites for screen size
			cards[i].setPosition(10 + (i / 3) * 220, 180 + (i % 3) * 170); // move card sprite

			cards[i].refreshTexture();

			window.draw(cards[i]);
		}

		window.display();
	}
}

void HowToPlay::pageFour(sf::RenderWindow & window)
{
	sf::Text text;
	text.setFont(mFont);
	text.setCharacterSize(42);
	text.setString("The game ends when the deck is empty and the cards in play \ncannot make a Set.\n\nIn multiplayer both players start with the same deck. \nTry to finish the game before your opponent!");

	sf::Text text2;
	text2.setFont(mFont);
	text2.setCharacterSize(42);
	text2.setString("Click to continue.");
	text2.setPosition(800, 560);

	bool nextPage = false;

	while (window.isOpen() && !nextPage)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
				nextPage = true;
		}

		window.clear();

		window.draw(text);
		window.draw(text2);

		window.display();
	}
}
