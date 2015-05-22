#include "stdafx.h"
#include "Controller.h"

Controller::Controller()
{
	numNodes = 0;
	numElements = 0;
	numMaterials = 0;
	probType = 0;
	numEBCs = 0;
	numPFs = 0;
	numNBCs = 0;

	materialData = NULL;
	elementData = NULL;
	nodeData = NULL;
	essentialBCData = NULL;
	pointForceData = NULL;
	naturalBCData = NULL;
}

Controller::~Controller()
{
	if (materialData != NULL) delete[] materialData;
	if (elementData != NULL) delete[] elementData;
	if (nodeData != NULL) delete[] nodeData;
	if (essentialBCData != NULL) delete[] essentialBCData;
	if (pointForceData != NULL) delete[] pointForceData;
	if (naturalBCData != NULL) delete[] naturalBCData;
}

void Controller::readData(string fileName)
{
	string line;
	ifstream myfile(fileName);
	if (!myfile.is_open())
	{
		cout << "Unable to open file.";
		throw IO_ERROR;
	}

	//Skip title line
	getline(myfile, line);

	//Get geometric values
	myfile >> numNodes;
	myfile >> numElements;
	myfile >> numMaterials;
	myfile >> probType;

	//Get material properties
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
	elementData = new ElementData[numElements];
	for (int i = 0; i < numElements; i++)
	{
		elementData[i].controller = this;
		myfile >> elementData[i].id;
		myfile >> elementData[i].material;
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
	for (int i = 0; i < numNodes; i++)
	{
		myfile >> nodeData[i].id;
		myfile >> nodeData[i].x;
		myfile >> nodeData[i].y;
	}

	//Get boundary and force data
	myfile >> numEBCs;
	myfile >> numPFs;
	myfile >> numNBCs;
	
	//Get essential BCs
	essentialBCData = new EssentialBCData[numEBCs];
	for (int i = 0; i < numEBCs; i++)
	{
		myfile >> essentialBCData[i].id;
		myfile >> essentialBCData[i].node;
		myfile >> essentialBCData[i].direction;
		myfile >> essentialBCData[i].value;
	}

	//Get point forces
	pointForceData = new PointForceData[numPFs];
	for (int i = 0; i < numPFs; i++)
	{
		myfile >> pointForceData[i].id;
		myfile >> pointForceData[i].node;
		myfile >> pointForceData[i].direction;
		myfile >> pointForceData[i].value;
	}

	//Get natural BCs
	naturalBCData = new NaturalBCData[numNBCs];
	for (int i = 0; i < numNBCs; i++)
	{
		myfile >> naturalBCData[i].id;
		myfile >> naturalBCData[i].leftnode;
		myfile >> naturalBCData[i].midnode;
		myfile >> naturalBCData[i].rightnode;
		myfile >> naturalBCData[i].value;
	}

	myfile.close();
}

void Controller::writeData(string fileName)
{
	ofstream output(fileName);
	if (!output.is_open())
	{
		cout << "Unable to open file.";
		throw IO_ERROR;
	}

	output << " ******************************************************************\n";
	output << " *                                                                *\n";
	output << " *                     ME 862 Final Project                       *\n";
	output << " *                                                                *\n";
	output << " ******************************************************************\n\n";
	
	output << "     Nodes = " << numNodes << "     Elements = " << numElements << "     Materials = " << numMaterials << '\n';
	output << endl;

	output << " ********************* Material Data ******************************\n\n";
	for (int i = 0; i<numMaterials;i++)
	{
		output << " ID =    " << materialData[i].id << "  E =   " << materialData[i].YM << "  Nu =   " << materialData[i].Poisson << '\n';
	}
	output << endl;
	output << " ********************* Element Data *******************************\n\n";
	output << " ElemID  Material           Node Connectivity\n";

	for (int k = 0; k<numElements;k++)
	{
		output << "     " << elementData[k].id << "        " << elementData[k].material << "     " << elementData[k].Node1 << "     " << elementData[k].Node2 << "   " << elementData[k].Node3;
		output << "   " << elementData[k].Node4 << "   " << elementData[k].Node5 << "     " << elementData[k].Node6 << "    " << elementData[k].Node7 << "     " << elementData[k].Node8 << '\n';
	}

	output << endl;
	output << " ********************** Nodal Data ********************************\n\n";
	
	for (int m = 0; m<numNodes;m++)
	{
		output << " ID =      " << nodeData[m].id << "  X =   " << nodeData[m].x << "  Y =   " << nodeData[m].y << '\n';
	}

	output << endl;

	//output << numEBCs << "  " << numPFs << "  " << numNBCs << '\n';

	output << " ********************** Essential BC Data *************************\n\n";
	for (int i = 0; i<numEBCs;i++)
	{
		output << " Node =    " << essentialBCData[i].node << "   " << essentialBCData[i].direction << " =   " << essentialBCData[i].value << '\n';
	}

	output << endl;
	output << " ********************** Point Load BC Data ************************\n\n";

	for (int i = 0; i<numPFs;i++)
	{
		output << " Node =    " << pointForceData[i].node << ", " << pointForceData[i].direction << " =   " << pointForceData[i].value << '\n';
	}

	output << endl;
	output << " ********************** Natural BC Data ***************************\n\n";

	for (int i = 0; i<numNBCs;i++)
	{
		output << " Nodes =    " << naturalBCData[i].leftnode << "  " << naturalBCData[i].midnode << "  " << naturalBCData[i].rightnode << "  " << naturalBCData[i].value << '\n';
	}



	output.close();
}

int Controller::getProbType()
{
	return probType;
}

double Controller::getYM()
{
	return materialData[0].YM;
}

double Controller::getPoisson()
{
	return materialData[0].Poisson;
}

int Controller::getElemID(int i)
{
	return elementData[i].id;
}

int Controller::getNode1(int i)
{
	return elementData[i].Node1;
}
int Controller::getNode2(int i)
{
	return elementData[i].Node2;
}
int Controller::getNode3(int i)
{
	return elementData[i].Node3;
}
int Controller::getNode4(int i)
{
	return elementData[i].Node4;
}
int Controller::getNode5(int i)
{
	return elementData[i].Node5;
}
int Controller::getNode6(int i)
{
	return elementData[i].Node6;
}
int Controller::getNode7(int i)
{
	return elementData[i].Node7;
}
int Controller::getNode8(int i)
{
	return elementData[i].Node8;
}

double Controller::getXcoord(int i)
{
	return nodeData[i].x;
}

double Controller::getYcoord(int i)
{
	return nodeData[i].y;
}

double Controller::getThickness()
{
	return materialData[0].thickness;
}

int Controller::getNumNodes()
{
	return numNodes;
}

int Controller::getNumElements()
{
	return numElements;
}

ElementData Controller::getElemenetClass(int i)
{
	return elementData[i].controller;
}