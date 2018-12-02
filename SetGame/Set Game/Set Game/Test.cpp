#include "Test.h"

Test::Test()
{
	if (testCard())
	{
		/*if (testDeck())
		{
			if (testIsSet())
			{
				
			}
		}*/
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

	for (int i = 0; i < attributes.size(); i++) {
		if (attributes[i] != 0)
		{
			cout << " Failed making default attributes. ";
			return false;
		}
	}

	if (c.getImage().compare("") != 0) {
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
							if (c.isSelected()){
									return true;
							} else {
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
	
	

	return false;
}