#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::ostream;
using std::endl;
using std::cout;
using std::cin;

class Card {
protected:
	//shape, color, fill, number, (size - unused)
	vector<int> mAttributes;
	string mImage;
	bool mSelection;

public:
	void buildImageFileName();

	Card(int shape = 0, int color = 0, int fill = 0, int num = 0, int size = 0, string image = "");
	Card(Card const & copyCard);

	int getShape() const;
	int getColor() const;
	int getFill() const;
	int getNumber() const;
	int getSize() const;
	string getImage() const;
	vector<int> getAttributes() const;

	void setShape(int shape);
	void setColor(int color);
	void setFill(int fill);
	void setNumber(int num);
	void setSize(int size);
	void setAttribute(int value, int index);
	void setImage(string img);

	virtual void switchSelected();
	virtual void setSelected(bool selection);

	bool isSelected() const;

};

ostream & operator << (ostream & stm, Card & c);