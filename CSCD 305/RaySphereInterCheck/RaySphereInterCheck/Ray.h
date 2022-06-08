//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#pragma once 
#ifndef RAY_H
#define RAY_H
#include <iostream>
#include "Point3D.h"
#include "Sphere.h"

using namespace std;

class Ray {
	friend class Sphere;

	Point3D origin;
	Point3D direction;
public:
	Ray();
	Ray(Point3D, Point3D);
	Point3D getOrigin() const;
	Point3D getDirection() const;
	Ray& setOrigin(Point3D);
	Ray& setDirection(Point3D);
	void checkIntersection(Sphere& s);
};
#endif
