//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#pragma once
#ifndef INFOREPOSITORY_H
#define INFOREPOSITORY_H

#include "InfoNode.h";
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template<class T, class U, class V>
class InfoRepository {
public:
	InfoRepository(std::string name) :first(nullptr), iName(name) {}
	~InfoRepository();
	void addInfo(T t, U u, V v);
	bool isEmpty();
	void printInformation();
	void retrieveInfoNode(const T& t);

private:
	InfoNode<T, U, V>* first;
	std::string iName;
};

template<class T, class U, class V>
InfoRepository<T, U, V>::~InfoRepository() {
	InfoNode<T, U, V>* p = first;
	InfoNode<T, U, V>* c = nullptr;

	while (p != nullptr) {
		if (c != nullptr) {
			delete c;
		}
		c = p;
		p = p->next;
	}
	delete c;
}

template<class T, class U, class V>
void InfoRepository<T, U, V>::addInfo(T t, U u, V v) {
	InfoNode<T, U, V>* p = new InfoNode<T, U, V>(t, u, v, first);
	first = p;
}

template<class T, class U, class V>
bool InfoRepository<T, U, V>::isEmpty() {
	return first == nullptr;
}

template<class T, class U, class V>
void InfoRepository<T, U, V>::printInformation() {
	std::cout << "Printing " << iName << " info.\n";

	InfoNode<T, U, V>* p = first;

	while (p != nullptr) {
		std::cout << std::fixed << std::setprecision(2);
		std::cout << p->dataOne << " " << p->dataTwo << " " << p->dataThree << std::endl;
		p = p->next;
	}
}

template<class T, class U, class V>
void InfoRepository<T, U, V>::retrieveInfoNode(const T& t) {
	std::cout << "\nRetrieving Node with id " << t << "from the database.\n";

	InfoNode<T, U, V>* p = first;

	while (p != nullptr) {
		if (p->dataOne == t) {
			std::cout << "Node with id " << t << " was found in the database.\n";
			std::cout << "\nHere is the info: \n";
			p->print();
			std::cout << endl;
			return;
		}
		p = p->next;
	}
	std::cout << "No Node with id " << t << " exist in the list.";
}

#endif