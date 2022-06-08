//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#include "Sphere.h"

Sphere::Sphere() :center{ }, radius{ 0 } {}

Sphere::Sphere(Point3D center, double radius) : center{ center }, radius{ radius } {}

Point3D Sphere::getCenter() const {
	return this->center;
}

double Sphere::getRadius() const {
	return this->radius;
}

Sphere& Sphere::setCenter(Point3D center) {
	this->center = center;
	return (*this);
}
Sphere& Sphere::setRadius(double radius) {
	this->radius = radius;
	return (*this);
}