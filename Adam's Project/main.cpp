
// ReadFile.cpp : Defines the entry point for the console application.
#include <iostream>
#include <fstream>
#include <string>
#include "BasicStructures.h"
using namespace std;


int main(int argc, char* argv[])
{
	//Define parameters and vlaues taken from .inp file
	string line;
	int numNodes;
	int numElements;
	int numMaterials;
	int prodType;
	ifstream myfile("e4plate.inp");
	if (myfile.is_open())
	{
		//Skip title line
		getline(myfile, line);

		//Get geometric values
		myfile >> numNodes;
		myfile >> numElements;
		myfile >> numMaterials;
		myfile >> prodType;

		// read in the second line, which I don't know what it is yet.
		double something[13];
		for (int i = 0; i < 13; i++)
		{
			myfile >> something[i];
		}

		//Get material properties
		//Material properties always start on line 3 and contain 13 values each
		//Want to store material properties in an [numMatls][13] array
		MaterialData *materialData = new MaterialData[numMaterials];
		for (int i = 0; i < numMaterials; i++)
		{
			myfile >> materialData[i].id;
			myfile >> materialData[i].a;
			myfile >> materialData[i].b;
			myfile >> materialData[i].c;
			myfile >> materialData[i].d;
			myfile >> materialData[i].e;
			myfile >> materialData[i].f;
			myfile >> materialData[i].g;
			myfile >> materialData[i].h;
			myfile >> materialData[i].i;
		}
		//Get element properties
		//Element properties always start on line 3+numMatls and contain 10 values each
		//Want to store element properties in an [numElems][10] array
		//for(int i = 0; i < 1+numMatls+numElems; i++)
		//getline(myfile,line);

		NodeData *nodeData = new NodeData[numNodes];
		//Get node properties
		//Node properties always start on line 3+numMatls+numElems and contain 3 values each
		//Want to store node properties in an [numNodes][3] array
		for (int i = 0; i < numNodes; i++)
		{
			myfile >> nodeData[i].id;
			myfile >> nodeData[i].x;
			myfile >> nodeData[i].y;
		}
	}
	else cout << "Unable to open file.";

	//couts to check if the right values got pulled 
	cout << numNodes << '\n' << numElements << '\n' << numMaterials << '\n' << prodType << '\n';
	cout << line << '\n';
	myfile.close();
	return 0;
}