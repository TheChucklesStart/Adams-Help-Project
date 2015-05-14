#pragma once
#include "stdafx.h"
using namespace std;

class MatrixFunctions
{
public:
	double f_gauss_jordan_elim(int n, double m_coeff[][10], double b[], double x[]);
	void multiply(int r, int s, int t, double inMatrix1[][10], double inMatrix2[][10], double outMatrix[][10]);
};