#pragma once

#include "Card.h"

class CardInPlay : public Card, public sf::Sprite
{
public:
	CardInPlay(Card & enteringPlay = Card());
	void switchSelected();
	void setSelected(bool selection);
	void changeCard(Card & enteringPlay);
	void refreshTexture();
private:
	sf::Texture mTexture;
};