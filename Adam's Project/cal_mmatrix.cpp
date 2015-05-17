#include "stdafx.h"
#include "Controller.h"
#include "calc_B_matrix.h"
#include "calc_M_matrix.h"
#include "MatrixFunctions.h"

calc_M_matrix::calc_M_matrix(double mat1[][4], double mat2[][16], double val1, double mat3[][4], calc_B_matrix &calc_B_matrix, calc_D_matrix &calc_D_matrix)
{
	//Retrieve matrices
	det_Jacob = val1;
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 16; b++)
		{
			B_matrix[a][b] = mat2[a][b];
		}
	}
	for (int c = 0; c < 16; c++)
	{
		for (int d = 0; d < 4; d++)
		{
			B_transpose[c][d] = mat1[c][d];
		}
	}
	for (int e = 0; e < 4; e++)
	{
		for (int f = 0; f < 4; f++)
		{
			D_matrix[e][f] = mat3[e][f];
		}
	}
	
	//Initialize matrix operations
	MatrixFunctions Moperations;
		
	//Matrix multiplication
	Moperations.multiplyB(16, 4, 4, B_transpose, D_matrix, temp_matrix1);
	Moperations.multiplyC(16, 4, 16, temp_matrix1, B_matrix, temp_matrix2);
	
	//double loop to for M matrix
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			M_matrix[i][j] = temp_matrix2[i][j] * det_Jacob;
		}
	}
}

double calc_M_matrix::getMmatrix()
{
	return M_matrix[16][16];
}

void calc_M_matrix::printData(ostream &out) const
{
	for (int i = 0; i <16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			out << M_matrix[i][j] << " ";
		}
		out << endl;
	}
}