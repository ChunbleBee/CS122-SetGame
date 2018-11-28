#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::endl;

class Card {
private:
	//shape, color, fill, number, size
	int mAttributes [5];
	string mImage;
	bool mSelection;

public:
	Card(int shape = -1, int color = -1, int fill = -1, int num = -1, int size = -1, string image = "");

	int getShape();
	int getColor();
	int getFill();
	int getNumber();
	int getSize();
	string getImage();

	void setShape(int shape);
	void setColor(int color);
	void setFill(int fill);
	void setNumber(int num);
	void setSize(int size);
	void setImage(string img);

	void switchSelected();

	bool isSelected();
};

ostream & operator << (ostream & stm, Card & c);