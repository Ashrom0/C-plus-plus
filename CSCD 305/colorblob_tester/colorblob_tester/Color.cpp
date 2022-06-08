//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#include "Color.h" 

Color::Color() :red{ 0.5 }, green{ 0.5 }, blue{ 0.5 } {}

Color::Color(double redP, double greenP, double blueP) : red{ redP }, green{ greenP }, blue{ blueP }{}
double Color::getRed() const {
	return this->red;
}

Color::Color(const Color& c) : red(c.red), green(c.green), blue(c.blue) {}

double Color::getGreen() const {
	return this->green;
}
double Color::getBlue() const {
	return this->blue;
}
Color& Color::setRed(double redP) {
	this->red = redP;
	return (*this);
}
Color& Color::setGreen(double greenP) {
	this->green = greenP;
	return (*this);
}
Color& Color::setBlue(double blueP) {
	this->blue = blueP;
	return (*this);
}

bool operator==(const Color& colorOne, const Color& colorTwo) {
	if (colorOne.red != colorTwo.red && colorOne.green != colorTwo.green && colorOne.blue != colorTwo.blue)
		return false;
	return true;
}

Color operator+(const Color& colorOne, const Color& colorTwo) {
	double red = min(colorOne.red + colorTwo.red, 1.0);
	double green = min(colorOne.green + colorTwo.green, 1.0);
	double blue = min(colorOne.blue + colorTwo.blue, 1.0);
	return Color(red, green, blue);
}

Color operator-(const Color& colorOne, const Color& colorTwo) {
	double red = max(colorOne.red - colorTwo.red, 0.0);
	double green = max(colorOne.green - colorTwo.green, 0.0);
	double blue = max(colorOne.blue - colorTwo.blue, 0.0);
	return Color(red, green, blue);
}

Color operator*(const Color& colorOne, const Color& colorTwo) {
	return Color(colorOne.red * colorTwo.red, colorOne.green * colorTwo.green, colorOne.blue * colorTwo.blue);
}

bool operator!(const Color& colorOne) {
	if (colorOne.red != 0 && colorOne.green != 0 && colorOne.blue != 0)
		return true;
	return false;
}

ostream& operator<<(ostream& stream, const Color& c) {
	stream << c.red << "," << c.green << "," << c.blue;
	return stream;
}

istream& operator>>(istream& stream, Color& c) {
	stream >> c.red >> c.green >> c.blue;
	return stream;
}