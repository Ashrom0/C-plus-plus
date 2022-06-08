//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <set>
#include <map>
#include "Point3D.h"
class Graph {

public:
	
	// Extracts information from filename to initialize mVertices and vIndices
	bool loadCityInformation(const char* filename);
	
	// Generates the connectivity map among cities;
	//Calls Link function to generate connectivity information for all cities
	void Generate();
	
	//prints connectivity information of different cities
	void Print();
	
	// Displays connectivity information for a particular city “a” and finds
	//distance information of neighboring cities
	void showConnectivity(int a);

private:
	std::vector<Point3D>cityCoordinates;
	std::vector<int> cityIndices;
	std::map<int, std::set<int>> Connectivity;
};
#endif