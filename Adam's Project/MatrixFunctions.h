#pragma once
#include "stdafx.h"
using namespace std;

class MatrixFunctions
{
public:
	double invert(int n, double m_coeff[][2], double b[], double x[]);
	void multiplyA(int r, int s, int t, double inMatrix1[][2], double inMatrix2[][1], double outMatrix[][1]);
	void multiplyB(int r, int s, int t, double inMatrix1[][4], double inMatrix2[][4], double outMatrix[][4]);
	void multiplyC(int r, int s, int t, double inMatrix1[][4], double inMatrix2[][16], double outMatrix[][16]);
};