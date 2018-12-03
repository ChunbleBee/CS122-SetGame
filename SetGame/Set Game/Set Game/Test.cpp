#include "Test.h"

Test::Test()
{
	if (testCard())
	{
		if (testDeck())
		{
			if (testIsSet())
			{
				/*
					if(){
						if (){
							cout << "All tests passed!" << endl;
						}
					}
				*/	
			}
		}
	}
}

bool Test::testCard()
{
	cout << "Testing default Card constructor...";
	
	if (testCardDefault())
	{
		cout << " Passed!" << endl << "Testing non-default constructor...";
	
		if (testCardInput())
		{
			cout << " Passed!" << endl << "Testing card setters...";
			if (testCardSetters()) {
				cout << " Passed!" << endl;
				return true;
			}
			else {
				cout << " Failed!";
			}
		}
		else
		{
			cout << " Failed";
		}
	}
	else {
		cout << " Failed! ";
	}

	return false;
}

bool Test::testCardDefault()
{
	Card c;

	//shape, color, fill, number, (size - unused)
	vector<int> attributes = c.getAttributes();

	for (int i = 0; i < attributes.size(); i++)
	{
		if (attributes[i] != 0)
		{
			cout << " Failed making default attributes. ";
			return false;
		}
	}

	/*colors = "rgb",
		numbers = "123",
		shapes = "owd",
		fills = "odf";*/
	if (c.getImage().compare("Set Cards/r1oo.PNG") != 0)
	{
		cout << " Failed making default image string. ";
		return false;
	}

	return true;
}

bool Test::testCardInput()
{
	Card c(1, 1, 1, 1, 1, "An Image");

	if (c.getShape() == 1)
	{
		if (c.getColor() == 1)
		{
			if (c.getFill() == 1)
			{
				if (c.getNumber() == 1)
				{
					if (c.getSize() == 1)
					{
						if (c.getImage().compare("An Image") == 0)
						{
							return true;
						}
						else
						{
							cout << " Failed to set Image String! ";
						}
					}
					else
					{
						cout << " Failed to set Size! ";
					}
				}
				else
				{
					cout << " Failed to set Amount! ";
				}
			}
			else
			{
				cout << " Failed to set Fill! ";
			}
		}
		else
		{
			cout << " Failed to set color! ";
		}
	}
	else
	{
		cout << " Failed to set shape! ";
	}

	return false;
}

bool Test::testCardSetters()
{
	Card c;

	c.setShape(1);
	if (c.getShape() == 1)
	{
		c.setColor(1);
		if (c.getColor() == 1)
		{
			c.setFill(1);
			if (c.getFill() == 1)
			{
				c.setNumber(1);
				if (c.getNumber() == 1)
				{
					c.setSize(1);
					if (c.getSize() == 1)
					{
						c.setImage("An Image");
						if (c.getImage().compare("An Image") == 0)
						{
							c.setSelected(true);
							if (c.isSelected())
							{
									return true;
							}
							else
							{
								cout << " Failed to set selected mode!";
							}
						}
						else
						{
							cout << " Failed to set Image String! ";
						}
					}
					else
					{
						cout << " Failed to set Size! ";
					}
				}
				else
				{
					cout << " Failed to set Amount! ";
				}
			}
			else
			{
				cout << " Failed to set Fill! ";
			}
		}
		else
		{
			cout << " Failed to set color! ";
		}
	}
	else
	{
		cout << " Failed to set shape! ";
	}

	return false;
}

bool Test::testDeck()
{
	Deck d;
	
	cout << "Checking default deck... ";
	vector<Card> c = d.getDeck();

	for (int i = 0; i < c.size(); i++) {
		if (c[i].getShape() != i % 3
		|| c[i].getColor() != div(i, 3).quot % 3
		|| c[i].getFill() != div(i, 9).quot % 3
		|| c[i].getNumber() != div(i, 27).quot % 3
		|| c[i].getSize() != div(i, 81).quot % 3) {
			cout << "Failed to set default deck!" << endl;
			return false;
		}
	}

	cout << "Passed! " << endl << "Testing card deal... ";

	d.dealCard();
	d.dealCard();
	d.dealCard();

	//shape, color, fill, number, (size - unused)
	if (d.dealCard().getColor() != 1) //First non-red card in deck
	{
		cout << "Failed!" << endl;
		
	}


	cout << "Passed! \nTesting isEmpty()... ";	
	if (d.isEmpty() == false)
	{
		//Mills through d, deleting all cards. -4 for the previous cards deleted.
		while (d.cardsLeft() > 0)
		{
			d.dealCard();
		}

		if (d.isEmpty() == true)
		{
			cout << "Passed!" << endl << "All deck tests passed!" << endl;
		}
		else
		{
			cout << "Failed at empty deck test!";
			return false;
		}
	}
	else
	{
		cout << "Failed to test non-empty deck!";
	}


	return true;
}

bool Test::testIsSet()
{
	PlayArea p;
	Card c1, c2, c3;


	cout << "Testing isSet() with trivial set... ";
	if (p.isSet(c1, c2, c3))
	{
		cout << "Passed Trivial set! \nTesting non-equal set... ";
		for (int i = 0; i < 5; i++) {
			c2.setAttribute(1, i);
			c3.setAttribute(2, i);
		}
		if (p.isSet(c1, c2, c3))
		{
			cout << "Passed non-equal set test! \nTesting non-set...";
			c3.setColor(1); //Set to same color as c2
			
			if (p.isSet(c1, c2, c3) == false)
			{
				cout << "Passed non-set test!" << endl;
				return true;
			}
			else
			{
				cout << "Non-set test failed!" << endl;
				return false;
			}
		}
		else
		{
			cout << "Failed non-equal set test!" << endl;
			return false;
		}
	}
	else
	{
		cout << "Failed trivial set!" << endl;
	}
	return false;
}