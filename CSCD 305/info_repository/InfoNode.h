//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#pragma once
#ifndef INFONODE_H
#define INFONODE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template<class T, class U, class V>
class InfoRepository;

template<class T, class U, class V>
class InfoNode {
	friend class InfoRepository<T, U, V>;
public:
	InfoNode(T& t, U& u, V& v, InfoNode<T, U, V>* p) :dataOne(t), dataTwo(u), dataThree(v),
		next(p) {}

	void print();
private:
	T dataOne;
	U dataTwo;
	V dataThree;
	InfoNode* next;   // points to next node in the list 
};

template<class T, class U, class V>
void InfoNode<T, U, V>::print() {
	const int width =20;
	const char sep = ' ';
	std::cout << left << setw(width) << setfill(sep) << dataOne;
	std::cout << left << setw(width) << setfill(sep) << dataTwo;
	std::cout << left << setw(width) << setfill(sep) << dataThree;
	cout << endl;
}

#endif