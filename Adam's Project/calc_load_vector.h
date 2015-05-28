#pragma once
#include "stdafx.h"
#include "Controller.h"
#include "Element.h"
#include "calc_B_matrix.h"
#include <iostream>
using namespace std;

class calc_load_vector
{
protected:
	int numPFs;
	double detJacob;
	int Node[8];
	double **NodeEqnMatrix;
	double LoadVector[16];
	double ForceVector[16];

public:
	calc_load_vector(ElementData &element, Controller &contoller, calc_B_matrix & calc_B_matrix, double zeta, double eta);
	~calc_load_vector();
	double getLoadVector();
	void printData(ostream &out) const;
};
