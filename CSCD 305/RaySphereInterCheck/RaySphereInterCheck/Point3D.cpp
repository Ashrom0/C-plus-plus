//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#include "Point3D.h" 

Point3D::Point3D() :x{ 0 }, y{ 0 }, z{ 0 } {}

Point3D::Point3D(double xP, double yP, double zP) : x{ xP }, y{ yP }, z{ zP } {}


double Point3D::getX() const {
	return this->x;
}
double Point3D::getY() const {
	return this->y;
}
double Point3D::getZ() const {
	return this->z;
}


Point3D& Point3D::setX(double xP) {
	this->x = xP;
	return (*this);
}
Point3D& Point3D::setY(double yP) {
	this->y = yP;
	return (*this);
}
Point3D& Point3D::setZ(double zP) {
	this->z = zP;
	return (*this);
}

Point3D& Point3D::addPoints(const Point3D& P) {
	this->x += P.x;
	this->y += P.y;
	this->z += P.z;
	return (*this);
}

Point3D& Point3D::subtractPoints(const Point3D& P) {
	this->x -= P.x;
	this->y -= P.y;
	this->z -= P.z;
	return (*this);
}

double  Point3D::multiplyPoints(const Point3D& P) {

	double val = (this->x * P.x) + (this->y * P.y) + (this->z * P.z);
	return val;
}

double Point3D::squarePoints() {
	double val = (x * x) + (y * y) + (z * z);
	return val;
}
