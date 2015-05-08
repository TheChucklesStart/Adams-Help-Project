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
	calc_D_matrix(int val1, float val2, float val3, Controller &controller);
	~calc_D_matrix();
	
	//Functions
void printData(cout) const;
};

