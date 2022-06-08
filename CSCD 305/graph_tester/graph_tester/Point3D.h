//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#pragma once 
#ifndef POINT3D_H
#define POINT3D_H
#include <iostream>
using namespace std;

class Point3D {
	double x, y, z;
public:
	Point3D(); // Default Constructor
	Point3D(double, double, double); // Constructor with Parameter
	double getX() const;
	double getY() const;
	double getZ() const;
	Point3D& setX(double);
	Point3D& setY(double);
	Point3D& setZ(double);
	Point3D& addPoints(const Point3D&);
	Point3D& subtractPoints(const Point3D&);
	double multiplyPoints(const Point3D& vec);
	double distanceBetween(const Point3D& p);
	double squarePoints();
};
#endif
