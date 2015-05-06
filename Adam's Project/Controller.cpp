#include "Controller.h"

Controller::Controller()
{
	numNodes = 0;
	numElements = 0;
	numMaterials = 0;
	prodType = 0;
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

	//Get boundary and force data
	myfile >> numEBCs;
	myfile >> numPFs;
	myfile >> numNBCs;

	essentialBCData = new EssentialBCData[numEBCs];
	for (int i = 0; i < numEBCs; i++)
	{
		myfile >> essentialBCData[i].id;
		myfile >> essentialBCData[i].node;
		myfile >> essentialBCData[i].direction;
		myfile >> essentialBCData[i].value;
	}

	pointForceData = new PointForceData[numPFs];
	for (int i = 0; i < numPFs; i++)
	{
		myfile >> pointForceData[i].id;
		myfile >> pointForceData[i].node;
		myfile >> pointForceData[i].direction;
		myfile >> pointForceData[i].value;
	}

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

	output << numNodes << "  " << numElements << "  " << numMaterials << "  " << prodType << '\n';
	for (int i = 0; i<numMaterials;i++)
	{
		output << materialData[i].id << "  " << materialData[i].YM << "  " << materialData[i].Poisson << "  " << materialData[i].thickness << "  " << materialData[i].g << '\n';
	}

	for (int k = 0; k<numElements;k++)
	{
		output << elementData[k].id << "  " << elementData[k].matl << "  " << elementData[k].Node1 << "  " << elementData[k].Node2 << "  " << elementData[k].Node3 << "  ";
		output << elementData[k].Node4 << "  " << elementData[k].Node5 << "  " << elementData[k].Node6 << "  " << elementData[k].Node7 << "  " << elementData[k].Node8 << '\n';
	}

	for (int m = 0; m<numNodes;m++)
	{
		output << nodeData[m].id << "  " << nodeData[m].x << "  " << nodeData[m].y << '\n';
	}

	output << numEBCs << "  " << numPFs << "  " << numNBCs << '\n';

	for (int i = 0; i<numEBCs;i++)
	{
		output << essentialBCData[i].id << "  " << essentialBCData[i].node << "  " << essentialBCData[i].direction << "  " << essentialBCData[i].value << '\n';
	}

	for (int i = 0; i<numPFs;i++)
	{
		output << pointForceData[i].id << "  " << pointForceData[i].node << "  " << pointForceData[i].direction << "  " << pointForceData[i].value << '\n';
	}

	for (int i = 0; i<numNBCs;i++)
	{
		output << naturalBCData[i].id << "  " << naturalBCData[i].leftnode << "  " << naturalBCData[i].midnode << "  " << naturalBCData[i].rightnode << "  " << naturalBCData[i].value << '\n';
	}

	output.close();
}
