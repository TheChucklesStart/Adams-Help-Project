#include "stdafx.h"
#include "ElementData.h"
#include "Controller.h"
using namespace std;

ElementNodes::Element_Nodes(int val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, Controller &controller)
{
	Node1 = val1;
	Node2 = val2;
	Node3 = val3;
	Node4 = val4;
	Node5 = val5;
	Node6 = val6;
	Node7 = val7;
	Node8 = val8;
}

void ElementNodes::printData(ostream &out) const
{
	out << Node1;
	out << Node2;
	out << Node3;
	out << Node4;
	out << Node5;
	out << Node6;
	out << Node7;
	out << Node8;
}