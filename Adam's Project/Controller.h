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
	int probType;
	int numEBCs;
	int numPFs;
	int numNBCs;
	double YM;

	MaterialData *materialData;
	ElementData *elementData;
	NodeData *nodeData;
	EssentialBCData *essentialBCData;
	PointForceData *pointForceData;
	NaturalBCData *naturalBCData;

public:
	Controller();
	~Controller();

	//Get values for claculating D_matrix
	int getProbType();
	double getYM();
	double getPoisson();

	//Get values for calculating B_matrix
	int getElemID(int i);
	double getNode1(int i);
	double getNode2(int i);
	double getNode3(int i);
	double getNode4(int i);
	double getNode5(int i);
	double getNode6(int i);
	double getNode7(int i);
	double getNode8(int i);
	double getXcoord(int i);
	double getYcoord(int i);
	
	// This method reads in all of the data from the inp file.
	void readData(string fileName);

	// This method writes out all of the data so we can verify correctness
	void writeData(string fileName);

	void elementCoordinateConversion();
};