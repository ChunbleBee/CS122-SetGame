#pragma once

#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "PlayArea.h"


using std::cout;
using std::endl;

class Test {
private:

public:
	Test();

	//Test cards
	bool testCard();
	bool testCardDefault();
	bool testCardInput();
	bool testCardSetters();

	//Test deck
	bool testDeck();


	bool testIsSet();
	
	bool testAnySets();

	bool testOverriddenSetSelected();
};