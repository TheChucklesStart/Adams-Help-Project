#include "stdafx.h"
#include "femdata.h"
#include "femnode.h"
#include "femElement.h"
#include "femMaterial.h"

femData::femData()
{
}

femData::~femData()
{
}

void femData::readData(istream &inp)
{
	inp >> d_numNodes;
	inp >> d_numElems;
	inp >> d_numMats;
	inp >> d_probType;

}

void femData::writeData(ostream &out)
{
	out << " ******************************************************************" << '\n';
	out << " *                                                                *" << '\n';
	out << " *                     ME 862 Final Project                       *" << '\n';
	out << " *                                                                *" << '\n';
	out << " ******************************************************************" << '\n';
	out << endl;
	out << "     Nodes = " << d_numNodes << "     Elements = " << d_numElems << "     Materials = " << d_numMats << '\n';
	out << endl;
}
