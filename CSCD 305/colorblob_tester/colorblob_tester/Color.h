//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#pragma once 
#ifndef COLOR_H
#define COLOR_H
#include <iostream>
using namespace std;

class Color {
	double red, green, blue;
public:
	Color(); // Default Constructor
	Color(double, double, double); // Constructor with Parameter
	Color(const Color& c); //copy constructor
	//Color& operator=(const Color& c); //copy assignment operator

	double getRed() const;
	double getGreen() const;
	double getBlue() const;
	Color& setRed(double);
	Color& setGreen(double);
	Color& setBlue(double);

	friend bool operator==(const Color& colorOne, const Color& colorTwo);
	friend Color operator+(const Color & colorOne, const Color & colorTwo);
	friend Color operator-(const Color & colorOne, const Color & colorTwo);
	friend Color operator*(const Color & colorOne, const Color & colorTwo);
	friend bool operator!(const Color & colorOne);
	friend ostream & operator<<(ostream&, const Color&);
	friend istream & operator>>(istream&, Color&);
};
#endif
