#include "Card.h"

void Card::buildImageFileName()
{
	string colors = "rgb",
		numbers = "123",
		shapes = "owd",
		fills = "odf";

	char colorChar = colors[getColor()],
		numberChar = numbers[getNumber()],
		shapeChar = shapes[getShape()],
		fillChar = fills[getFill()];

	mImage = string("Set Cards/") + colorChar + numberChar +
		shapeChar + fillChar + string(".PNG");
}

Card::Card(int shape, int color, int fill, int num, int size, string image) {
	mSelection = false;

	this->setShape(shape);
	this->setColor(color);
	this->setFill(fill);
	this->setNumber(num);
	this->setSize(size);
	//if (image.compare("")) {
	//	this->setImage(image);
	//}
	//else {
	//	buildImageFileName();
	//}
}

int Card::getShape() {
	return this->mAttributes[0];
}

int Card::getColor() {
	return this->mAttributes[1];
}

int Card::getFill() {
	return this->mAttributes[2];
}

int Card::getNumber() {
	return this->mAttributes[3];
}

int Card::getSize() {
	return this->mAttributes[4];
}

string Card::getImage() {
	return this->mImage;
}

void Card::setShape(int shape) {
	this->mAttributes[0] = shape;
}

void Card::setColor(int color) {
	this->mAttributes[1] = color;
}

void Card::setFill(int fill) {
	this->mAttributes[2] = fill;
}

void Card::setNumber(int num) {
	this->mAttributes[3] = num;
}

void Card::setSize(int size) {
	this->mAttributes[4] = size;
}

void Card::setImage(string img) {
	this->mImage = img;
}

bool Card::isSelected() {
	return this->mSelection;
}

void Card::switchSelected() {
	this->mSelection = !this->mSelection;
}


ostream & operator << (ostream & stm, Card & c) {
	//shape, color, fill, number, size
	stm << c.getShape() << ", "
		<< c.getColor() << ", "
		<< c.getFill() << ", "
		<< c.getNumber() << ", "
		<< c.getSize() << ", "
		<< c.getImage();

	return stm;
}