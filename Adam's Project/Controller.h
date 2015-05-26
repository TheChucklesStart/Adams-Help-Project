 #pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "BasicStructures.h"
#include "ExceptionList.h"
#include "Element.h"
using namespace std;

class ElementData;
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
	int getNode1(int i);
	int getNode2(int i);
	int getNode3(int i);
	int getNode4(int i);
	int getNode5(int i);
	int getNode6(int i);
	int getNode7(int i);
	int getNode8(int i);
	double getXcoord(int i);
	double getYcoord(int i);

	//get values to assemble global matrix
	int getNumNodes();
	int getNumElements();
	int getNumEBCs();

	//get values to assemble load vectors
	int getPFs();
	int getPFNode(int i);
	char* getPFdirection(int i);
	double getPFvalue(int i);

	//output the ElementData class
	ElementData getElemenetClass(int i);

	//call the EssentialBCData Class
	EssentialBCData getEssentialBCClass(int i);

	//Get values for calculating Ke_matrix
	double getThickness();
	
	// This method reads in all of the data from the inp file.
	void readData(string fileName);

	// This method writes out all of the data so we can verify correctness
	void writeData(string fileName);
};