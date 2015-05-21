#pragma once

#include "stdafx.h"
#include "Controller.h"
#include "MatrixFunctions.h"
//#include "Element.h"
#include <iostream>
using namespace std;

class calc_D_matrix
{
protected:
	double coeff;
	double** stiffness;
	double** D_matrix;
	int ProblemType;
	double YM;
	double Poisson;

public:
	calc_D_matrix(int val1, double val2, double val3, Controller &controller);
	~calc_D_matrix();
	
	//Functions
	double** getDmatrix();
	void printData(ostream &out) const;
};

