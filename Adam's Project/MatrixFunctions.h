#pragma once
#include "stdafx.h"

class MatrixFunctions
{
public:
	static double invert(int n, double **m_coeff, double b[], double x[]);
	static void multiply(int r, int s, double **inMatrix, double *inVector, double *outVector);
	static void multiply(int r, int s, int t, double **inMatrix1, double **inMatrix2, double **outMatrix);
	static double** allocateMatrix(int rows, int columns);
	static void deleteMatrix(double** &matrix, int rows, int columns);
};