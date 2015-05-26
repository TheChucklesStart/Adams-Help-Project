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
	double fx1 = 0;
	double fy1 = 0;
	double fx2 = 0;
	double fy2 = 0;
	double fx3 = 0;
	double fy3 = 0;
	double fx4 = 0;
	double fy4 = 0;
	double fx5 = 0;
	double fy5 = 0;
	double fx6 = 0;
	double fy6 = 0;
	double fx7 = 0;
	double fy7 = 0;
	double fx8 = 0;
	double fy8 = 0;
	double **NodeEqnMatrix;
	double *LoadVector;

public:
	calc_load_vector(ElementData &element, Controller &contoller, calc_B_matrix &calc_B_matrix, double zeta, double eta);
	~calc_load_vector();
	double getLoadVector();
	void printData(ostream &out) const;
};
