#include "CardInPlay.h"

CardInPlay::CardInPlay(Card & enteringPlay) : Card(enteringPlay)
{
	if (!mTexture.loadFromFile(this->getImage()))
		cout << "Error loading Texture form file" << endl;
	setTexture(mTexture);

	this->mSelection = false;
}

void CardInPlay::switchSelected()
{
	if (isSelected()) // change to false
	{
		mSelection = false;
		sf::Sprite::setColor(sf::Color(255, 255, 255, 255)); // set color is defined in both card and sprite
	}
	else // change to true
	{
		mSelection = true;
		sf::Sprite::setColor(sf::Color(255, 255, 255, 127)); // set color is defined in both card and sprite
	}
}

void CardInPlay::setSelected(bool selection)
{
	if (selection)
		sf::Sprite::setColor(sf::Color(255, 255, 255, 127)); // set color is defined in both card and sprite
	else
		sf::Sprite::setColor(sf::Color(255, 255, 255, 255)); // set color is defined in both card and sprite

	mSelection = selection;
}

void CardInPlay::changeCard(Card & enteringPlay)
{
	this->setShape(enteringPlay.getShape());
	this->Card::setColor(enteringPlay.getColor()); // set color is defined in both card and sprite
	this->setFill(enteringPlay.getFill());
	this->setNumber(enteringPlay.getNumber());
	this->setSize(enteringPlay.getSize());
	this->setImage(enteringPlay.getImage());

	if (!mTexture.loadFromFile(this->getImage()))
		cout << "Error loading Texture form file" << endl;
}

void CardInPlay::refreshTexture()
{
	setTexture(mTexture);
}
