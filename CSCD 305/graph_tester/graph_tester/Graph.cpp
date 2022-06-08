//Author: Pedro Hernandez
//Compiler: Visual Studio 2019
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Graph.h"

//vector<Point3D> points;


bool Graph::loadCityInformation(const char* filename) {
	ifstream file("Terrain.obj");
	if (!file.is_open()) {
		cout << "Error while opening file.";
	}
	else {
		cout << "File contents are: " << endl;
		string line;
		while (getline(file, line)) {
			if (line.find('p') != -1) {
				istringstream str(line);
				string s;
				float p1, p2, p3;

				str >> s >> p1 >> p2 >> p3;
				cityCoordinates.push_back(Point3D(p1, p2, p3));
				cout << line << endl;
			}
			if (line.find('c') != -1) {
				istringstream str(line);
				string s;
				int index = 0;
				//float p1, p2, p3;

				str >> s;
				cityIndices.push_back(index);
				cout << line << endl;
			}
		}
	}
	return true;
}

void Graph::Generate() {
	for (int i = 0; i < cityIndices.size(); i += 3) {
		Connectivity[cityIndices[i]].insert(cityIndices[i + 1]);
		Connectivity[cityIndices[i]].insert(cityIndices[i + 2]);

		Connectivity[cityIndices[i + 1]].insert(cityIndices[i + 1]);
		Connectivity[cityIndices[i + 1]].insert(cityIndices[i + 2]);

		Connectivity[cityIndices[i + 2]].insert(cityIndices[i + 1]);
		Connectivity[cityIndices[i + 2]].insert(cityIndices[i + 2]);
	}
	/*for (int i = 0; i < cityIndices.size(); i += 2) {
		Connectivity[cityIndices[i]].insert(cityIndices[i + 1]);
		Connectivity[cityIndices[i]].insert(cityIndices[i + 2]);
	}
	for (int i = 0; i < cityIndices.size(); i += 1) {
		Connectivity[cityIndices[i]].insert(cityIndices[i + 1]);
		Connectivity[cityIndices[i]].insert(cityIndices[i + 2]);
	}*/
}

void Graph::Print() {
	for (auto it = Connectivity.begin(); it != Connectivity.end(); it++) {
		cout << "  [" << (*it).first << " ]";

		for (auto it2 = (*it).second.begin(); it2 != (*it).second.end(); it2++) {
			cout << (*it2) << " ";
		}
	}
}

void Graph::showConnectivity(int a) {
	for (auto it = Connectivity.find(a)->second.begin(); it != Connectivity.find(a)->second.end(); it++) {
		Point3D x1 = cityCoordinates[*it];
		Point3D y1 = cityCoordinates[*it];
		Point3D z1 = cityCoordinates[*it];
		cout << x1.distanceBetween(y1) << endl;
		cout << y1.distanceBetween(z1) << endl;
		cout << x1.distanceBetween(z1) << endl;
	}
}