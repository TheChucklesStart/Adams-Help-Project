#pragma once
#include "stdafx.h"
using namespace std;

class MatrixFunctions
{
public:
	//Constructor-Destructor
	//MatrixFunctions();
	//~MatrixFunctions();

	//Functions
	double mmult_function(int r, int s, int t, double in_matrix1[r][s], double in_matrix2[s][t], double out_matrix[r][t]);
}