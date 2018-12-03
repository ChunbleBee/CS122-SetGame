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
	textTwo.setPosition(700, 560);


	CardInPlay cardOne(Card(1, 2, 1, 1, 1));
	cardOne.setPosition(80, 80);

	CardInPlay cardTwo(Card(1, 1, 1, 1, 1));
	cardTwo.setPosition(420, 80);

	CardInPlay cardThree(Card(1, 0, 1, 1, 1));
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
	text[0].setString("Each Card has Four Attributes, and there are three options for each attribute.");

	text[1].setString("Color");
	text[1].setPosition(100, 80);

	text[2].setString("Number.");
	text[2].setPosition(200, 560);

	text[3].setString("Shape.");
	text[3].setPosition(300, 560);

	text[4].setString("Fill.");
	text[4].setPosition(400, 560);
	
	text[5].setString("Click to continue.");
	text[5].setPosition(700, 560);


	CardInPlay cards[12] = {
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0),
		Card(0, 0, 0, 0, 0)
	};


/*
	cards[0].changeCard(Card(0, 0, 0, 0, 0));
	cards[1].changeCard(Card(0, 0, 0, 0, 0));
	cards[2].changeCard(Card(0, 0, 0, 0, 0));

	cards[3].changeCard(Card(0, 0, 0, 0, 0));
	cards[4].changeCard(Card(0, 0, 0, 0, 0));
	cards[5].changeCard(Card(0, 0, 0, 0, 0));

	cards[6].changeCard(Card(0, 0, 0, 0, 0));
	cards[7].changeCard(Card(0, 0, 0, 0, 0));
	cards[8].changeCard(Card(0, 0, 0, 0, 0));

	cards[9].changeCard(Card(0, 0, 0, 0, 0));
	cards[10].changeCard(Card(0, 0, 0, 0, 0));
	cards[11].changeCard(Card(0, 0, 0, 0, 0));
	*/

	



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


		window.display();
	}
}
