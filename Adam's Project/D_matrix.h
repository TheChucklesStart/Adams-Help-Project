#pragma once

#include "stdafx.h"
#include "Controller.h"
#include <iostream>
using namespace std;

class D_matrix: public Controller
{
protected:
	double coeff;
	double stiffness[4][4];
	double DMATRIX[4][4];
	int ProblemType;
	double YM;
	double Poisson;

public:
	D_matrix(int PT, double YME, double nu);
	~D_matrix();

	//Functions
	int getProbType()
	{
		ProblemType = Controller::probType;
	}
	double getYM() 
	{
		YM = Controller::materialData[1].YM;
	}
	double getNu() 
	{
		Poisson = Controller::materialData[1].Poisson;
	}
}