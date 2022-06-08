#pragma once
//Author: Pedro Hernandez
//Compiler: Visual Studio 2019 
#ifndef COLORBLOB_H
#define COLORBLOB_H
#include <iostream>
#include "Color.h"
using namespace std;

class ColorBlob {
	int width, height;
	Color** data;

public:
	//ColorBlob();
	ColorBlob(int width, int height) : ColorBlob(width, height, { 0, 0, 0 }) {}
	ColorBlob(int w, int h, Color c); //delegating constructor
	ColorBlob();  //default constructor calls delegating constructor
	ColorBlob(const ColorBlob&); //copy constructor
	ColorBlob& operator=(const ColorBlob&); // copy assignment operator
	~ColorBlob(); //destructor
	ColorBlob(ColorBlob&&); // move constructor
	ColorBlob& operator=(ColorBlob&& v); // move assignment operator

	friend bool operator==(const ColorBlob&, const ColorBlob&);
	friend ColorBlob operator+(const ColorBlob & cBlobOne, const ColorBlob & cBlobTwo);
	friend ColorBlob operator-(const ColorBlob & cBlobOne, const ColorBlob & cBlobTwo);
	friend ColorBlob operator*(const ColorBlob & cBlobOne, const Color & c);
	friend bool operator! (const ColorBlob & cBlob);
	friend ostream & operator<<(ostream&, const ColorBlob&);
	friend istream & operator>>(istream&, ColorBlob&);

};
#endif
