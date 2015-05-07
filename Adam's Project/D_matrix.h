#pragma once

#include "stdafx.h"
#include <iostream>
using namespace std;

class D_matrix
{
protected:
	double coeff;
	double stiffness[4][4];
	double d_matrix[4][4];
	int probType;

public:
	D_matrix();
	~D_matrix();

	double calc_Dmatrix(int problemType, double modulus, double nu);
}