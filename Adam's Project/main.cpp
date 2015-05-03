// ReadFile.cpp : Defines the entry point for the console application.

#include "stdafx.h"
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

	MaterialData *materialData = NULL;
	ElementData *elementData = NULL;
	NodeData *nodeData = NULL;

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
		materialData = new MaterialData[numMaterials];
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
		elementData = new ElementData[numElements];
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

		nodeData = new NodeData[numNodes];
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

	myfile.close();
	system("pause");
	
//Writing to output file
	//ran into two issues.
	//1. the build said the project contains ToolsVersion="14.0" and that it is unknown or missing
	//2. i copied and pasted everything (header file included) into a new project and was told that materialData and co were undeclared identifiers.  I tried MaterialData and co as well and was told it was illegal use of that operator.
	// How do the material, element, and node properties get called for use now?
	ofstream output("output.txt");
	if (output.is_open())
	{
		output << numNodes << "  " << numElements << "  " << numMaterials << "  " << prodType << '\n';
		for (int i = 0; i<numMaterials;i++)
		{
			output << materialData[i].id << "  " << materialData[i].YM << "  " << materialData[i].Poisson << "  " << materialData[i].thickness << "  " << materialData[i].g << '\n' ;
		}

		for (int k = 0; k<numElements;k++)
		{
			output << elementData[k].id << "  " << elementData[k].matl << "  "  << elementData[k].Node1 << "  " << elementData[k].Node2 << "  " << elementData[k].Node3 << "  ";
			output << elementData[k].Node4 << "  " << elementData[k].Node5 << "  " << elementData[k].Node6 << "  " << elementData[k].Node7 << "  " << elementData[k].Node8 << '\n';
		}
		
		for (int m = 0; m<numNodes;m++)
		{
			output  << nodeData[m].id << "  " << nodeData[m].x << "  " << nodeData[m].y << '\n';
		}

	}
	return 0;
}
