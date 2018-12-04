#pragma once

#include <SFML/Graphics.hpp>

class TextBox : public sf::Text
{
public:
	TextBox();
	void setSelected(bool selection);
	void addCharacterTyped(sf::Event keypress);
private:
	bool selected;
};