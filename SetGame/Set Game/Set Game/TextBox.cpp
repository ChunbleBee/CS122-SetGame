#include "TextBox.h"

TextBox::TextBox()
{
}

void TextBox::setSelected(bool selection)
{
	selected = selection;
}

void TextBox::addCharacterTyped(sf::Event keypress)
{
	if (selected && keypress.type == sf::Event::TextEntered)
	{
		setString(getString() + static_cast<char>(keypress.text.unicode));
	}
}
