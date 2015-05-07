/*
functions for doing matrix inversion and matrix multiplication
*/

#include "stdafx.h"
#include "MatrixFunctions.h"

//MatrixFunctions::MatrixFunctions();
//MatrixFunctions::~MatrixFunctions();

double MatrixFunctions::mmult_function(int r, int s, int t, double in_matrix1[r][s], double in_matrix2[s][t], double out_matrix[r][t])
{
	for (int i= 0, i<r; i++)
	{
		for (int j=0; j<t; j++)
		{
			out_matrix[i][j] = 0;
			for (int k = 0; k<s; k++)
			{
				out_matrix[i][j] = out_matrix[i][j]+(in_matrix1[i][k]*in_matrix2[k][j]);
			}
		}
	}
}


