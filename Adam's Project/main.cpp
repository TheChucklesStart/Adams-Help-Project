
// ReadFile.cpp : Defines the entry point for the console application.
#include <iostream>
#include <fstream>
#include <string>

// This include the contents of the BasicStructures.h file into this file.
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

		//Get material properties
		//Material properties always start on line 3 and contain 13 values each
		//Want to store material properties in an [numMatls][13] array
		MaterialData *materialData = new MaterialData[numMaterials];
		for (int i = 0; i < numMaterials; i++)
		{
			// here we read each element in individually, since we want them to have a name later.  I could replace this with a loop, and we could keep the names, too, but that just might make it more confusing.
			myfile >> materialData[i].id;
			myfile >> materialData[i].YM;
			myfile >> materialData[i].Poisson;
			myfile >> materialData[i].thickness;
			myfile >> materialData[i].d;
			myfile >> materialData[i].e;
			myfile >> materialData[i].f;
			myfile >> materialData[i].g;
			myfile >> materialData[i].h;
			myfile >> materialData[i].i;
			myfile >> materialData[i].j;
			myfile >> materialData[i].k;
			myfile >> materialData[i].l;
		}
		//Get element properties
		//Element properties always start on line 3+numMatls and contain 10 values each
		//Want to store element properties in an [numElems][10] array
		ElementData *elementData = new ElementData[numElements];
		for (int i = 0; i < numElements; i++)
		{
			myfile >> elementData[i].id;
			myfile >> elementData[i].matl;
			myfile >> elementData[i].Node1;
			myfile >> elementData[i].Node2;
			myfile >> elementData[i].Node3;
			myfile >> elementData[i].Node4;
			myfile >> elementData[i].Node5;
			myfile >> elementData[i].Node6;
			myfile >> elementData[i].Node7;
			myfile >> elementData[i].Node8;
		}

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
	system("pause");
	return 0;
}