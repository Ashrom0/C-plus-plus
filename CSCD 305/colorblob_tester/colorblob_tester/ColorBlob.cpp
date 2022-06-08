//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#include "ColorBlob.h" 
using namespace std;

//CHECK
ColorBlob::ColorBlob() : width{ 2 }, height{ 2 }{
	data = new Color * [height];
	for (int i = 0; i < height; i++)
		data[i] = new Color[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			data[i][j] = Color();
	}
}


//CHECK
ColorBlob::ColorBlob(int w, int h, Color c) : width(w), height(h) {
	data = new Color * [height];
	for (int i = 0; i < height; i++)
		data[i] = new Color[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			data[i][j] = c;
	}
}

//copy constructor CHECK
ColorBlob::ColorBlob(const ColorBlob& c) : width(c.width), height(c.height) {
	data = new Color * [height];
	for (int i = 0; i < height; i++)
		data[i] = new Color[width];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			data[i][j] = c.data[i][j];
}

//copy assignment operator CHECK
ColorBlob& ColorBlob::operator=(const ColorBlob& v) {
	if (&v != this) {
		for (int i = 0; i < height; i++)
			delete[] data[i];
		delete[] data;
		height = v.height;
		width = v.width;
		data = new Color * [v.height];

		for (int i = 0; i < height; i++)
			for (int j = 0; j < v.height; j++)
				data[i][j] = v.data[i][j];
	}
	return *this;
}

//destructor CHECK
ColorBlob::~ColorBlob() {
	for (int i = 0; i < height; i++)
		delete[] data[i];

	delete[] data;
	data = nullptr;
	height = 0;
	width = 0;
}

//move constructor CHECK
ColorBlob::ColorBlob(ColorBlob&& c) : width{ c.width }, height{c.height} {
	data = c.data;
	width = c.width;
	height = c.height;
	c.data = nullptr;
	c.height = 0;
	c.width = 0;
}

//Move assignment operator CHECK
ColorBlob& ColorBlob::operator=(ColorBlob&& v) {
	if (&v != this) {
		for (int i = 0; i < height; i++)
			delete[] data[i];

		delete[] data;

		height = v.height;
		width = v.width;
		data = v.data;

		v.data = nullptr;
		v.height = 0;
		v.width = 0;
	}
	return *this;
}

bool operator==(const ColorBlob& cOne, const ColorBlob& cTwo) {
	if (cOne.width != cTwo.width || cOne.height != cTwo.height) return 0;

	for (int i = 0; i < cOne.height; i++) {
		for (int j = 0; j < cOne.width; j++) {
			if (cOne.data[i][j] == cTwo.data[i][j]) continue;
			else
				return 0;
		}
	}

	return 1;
}

ColorBlob operator+(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo) {
	int cWidth, cHeight;

	if (cBlobOne.width <= cBlobTwo.width)
		cWidth = cBlobTwo.width;
	else
		cWidth = cBlobTwo.width;

	if (cBlobOne.height <= cBlobTwo.height)
		cHeight = cBlobOne.height;
	else
		cHeight = cBlobTwo.height;

	ColorBlob c(cWidth, cHeight, Color());
	for (int i = 0; i < c.height; i++)
		for (int j = 0; j < c.width; j++) {

			c.data[i][j] = cBlobOne.data[i][j] + cBlobTwo.data[i][j];
		}

	return c;
}

ColorBlob operator-(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo) {
	int h = min(cBlobOne.height, cBlobTwo.height);
	int w = min(cBlobOne.width, cBlobTwo.width);
	ColorBlob blob = ColorBlob(h, w, Color());
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			blob.data[i][j] = cBlobOne.data[i][j] - cBlobTwo.data[i][j];
		}
	}
	return blob;
}

ColorBlob operator*(const ColorBlob& cBlobOne, const Color& c) {
	ColorBlob newBlob(cBlobOne.height, cBlobOne.width);
	for (int i = 0; i < newBlob.height; i++) {
		for (int j = 0; j < newBlob.width; j++) {
			newBlob.data[i][j] = cBlobOne.data[i][j] * c;
		}
	}
	return newBlob;
}

bool operator!(const ColorBlob& cBlob) {
	if (cBlob.height != 0 && cBlob.width != 0)
		return true;
	return false;
}

ostream& operator<<(ostream& ostr, const ColorBlob& cBlob) {
	for (int i = 0; i < cBlob.height; i++) {
		for (int j = 0; j < cBlob.width; j++) {
			ostr << "[" << i << "]" << "[" << j << "]:" << cBlob.data[i][j] << "  ";
		}
		ostr << endl;
	}
	return ostr;
}

istream& operator>>(istream& istr, ColorBlob& cBlob) {
	for (int i = 0; i < cBlob.height; i++) {
		for (int j = 0; j < cBlob.width; j++) {
			//cout << "[" << i << "]" << "[" << j << "]:";
			istr >> cBlob.data[i][j];
		}
	}
	return istr;
}