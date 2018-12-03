#include "Deck.h"

void Deck::buildDeck(int deckSize, int difficulty)
{
	//shape, color, fill, number
	//Each given value 1-3

	//Shape = Oval, Diamond, Swirl
	//Color = Red, Purple, Green
	//Fill = Solid, Dashed, Blank

	//Number = 1, 2, 3 Shapes

	//Size = Small, Med, Large

	for (int i = 0; i < deckSize; i++)
	{
		mCardDeck[i] = Card();
		mCardDeck[i].setShape(i % 3);
		mCardDeck[i].setColor(div(i, 3).quot % 3);
		mCardDeck[i].setFill(div(i, 9).quot % 3);
		mCardDeck[i].setNumber(div(i, 27).quot % 3);
		mCardDeck[i].setSize(div(i, 81).quot % 3);
		mCardDeck[i].buildImageFileName();
	}
}

void Deck::shuffle() {
	srand(time(NULL));
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < mCardDeck.size(); j++)
		{
			int rIndex = rand() % mCardDeck.size();
			Card temp = mCardDeck[j];
			mCardDeck[j] = mCardDeck[rIndex];
			mCardDeck[rIndex] = temp;
		}
	}
}

int Deck::cardsLeft()
{
	return this->mCardDeck.size();
}

Deck::Deck(int difficulty)
{
		mCardDeck.resize(pow(3, difficulty));

		buildDeck(mCardDeck.size(), difficulty);
}

vector<Card> Deck::getDeck()
{
	return this->mCardDeck;
}

Card Deck::dealCard()
{
	Card out = mCardDeck.back();
	mCardDeck.pop_back();
	return out;
}

bool Deck::isEmpty()
{
	return (this->mCardDeck.size() == 0);
}