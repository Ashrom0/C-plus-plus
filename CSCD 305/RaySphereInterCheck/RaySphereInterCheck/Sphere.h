//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#pragma once
#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include "Point3D.h"

using namespace std;

class Sphere {

	Point3D center;
	double radius;
public:
	Sphere();
	Sphere(Point3D, double);
	Point3D getCenter() const;
	double getRadius() const;
	Sphere& setCenter(Point3D);
	Sphere& setRadius(double);
};
#endif