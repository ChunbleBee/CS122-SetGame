#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::endl;
using std::cout;
using std::cin;

class Card {
private:
	//shape, color, fill, number, size
	int mAttributes [5];
	string mImage;
	bool mSelection;

public:
	void buildImageFileName();

	Card(int shape = 0, int color = 0, int fill = 0, int num = 0, int size = 0, string image = "");

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