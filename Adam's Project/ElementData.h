#pragma once
#include "stdafx.h"
#include "Controller.h"
#include <iostream>
using namespace std;

class ElementNodes : public Controller
{
protected:
	int Node1;
	int Node2;
	int Node3;
	int Node4;
	int Node5;
	int Node6;
	int Node7;
	int Node8;

public:
	ElementNodes(int val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8, Controller &controller);
	//NodeCoords(double coord1, double coord2, Controller &controller);
	void printData(ostream &out) const;
};
