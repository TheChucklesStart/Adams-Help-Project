#pragma once

#include "stdafx.h"
#include "Controller.h"
#include <iostream>
using namespace std;

class calc_D_matrix: public Controller
{
protected:
	double coeff;
	double stiffness[4][4];
	double D_matrix[4][4];
	int ProblemType;
	double YM;
	double Poisson;

public:
	calc_D_matrix(float val1, float val2, Controller &contrroller);
	~calc_D_matrix();
	
	//Functions
void printData(ostream &out) const;
};

