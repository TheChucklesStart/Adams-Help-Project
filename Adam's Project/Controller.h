#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BasicStructures.h"
#include "ExceptionList.h"
using namespace std;

class Controller
{
protected:
	int numNodes;
	int numElements;
	int numMaterials;
	int prodType;
	int numEBCs;
	int numPFs;
	int numNBCs;

	MaterialData *materialData;
	ElementData *elementData;
	NodeData *nodeData;
	EssentialBCData *essentialBCData;
	PointForceData *pointForceData;
	NaturalBCData *naturalBCData;

public:
	Controller();
	~Controller();

	// This method reads in all of the data from the inp file.
	void readData(string fileName);

	// This method writes out all of the data so we can verify correctness
	void writeData(string fileName);
};