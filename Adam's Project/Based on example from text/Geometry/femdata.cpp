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
	char d_title[100];
	inp >> d_title;
	inp >> d_numNodes;
	inp >> d_numElems;
	inp >> d_numMats;
	inp >> d_probType;
	for (int i = 0; i<d_numMats;i++)
	{
		d_matprops[i] = new femMaterial(id);
	}

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
	for (int i = 0; i<d_numMats;i++)
	{
		d_matprops[i]->printData(out);
	}
}
