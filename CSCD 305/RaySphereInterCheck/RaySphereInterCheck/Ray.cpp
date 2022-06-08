//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#include "Ray.h" 
#include <iostream>

Ray::Ray() :origin{ }, direction{ } {}

Ray::Ray(Point3D origin, Point3D direction) : origin{ origin }, direction{ direction } {}

Point3D Ray::getOrigin() const {
	return this->origin;
}

Point3D Ray::getDirection() const {
	return this->direction;
}

Ray& Ray::setOrigin(Point3D origin) {
	this->origin = origin;
	return (*this);
}

Ray& Ray::setDirection(Point3D direction) {
	this->direction = direction;
	return (*this);
}

void Ray::checkIntersection(Sphere& s) {
	double A, B, C;
	A = direction.squarePoints();

	this->origin.subtractPoints(s.center);
	B = this->origin.multiplyPoints(direction);

	C = origin.squarePoints() - (s.radius * s.radius);

	double ans = (B * B) - (A * C);

	std::cout << "B * B – A * C = " << ans << std::endl;
	if (ans < 0)
		std::cout << "Ray does not touch or intersect the sphere." << std::endl;
	else
		std::cout << "Ray either touches or intersects the sphere." << std::endl;

}
