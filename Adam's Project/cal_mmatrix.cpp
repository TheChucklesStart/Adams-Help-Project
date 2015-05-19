#include "stdafx.h"
#include "Controller.h"
#include "calc_B_matrix.h"
#include "calc_M_matrix.h"
#include "MatrixFunctions.h"

calc_M_matrix::calc_M_matrix(calc_B_matrix &calc_B_matrix, calc_D_matrix &calc_D_matrix)
{
	M_matrix = MatrixFunctions::allocateMatrix(16, 16);
	temp_matrix1 = MatrixFunctions::allocateMatrix(16, 4);
	temp_matrix2 = MatrixFunctions::allocateMatrix(16, 16);
		
	//Matrix multiplication
	MatrixFunctions::multiply(16, 4, 4, calc_B_matrix.getBtranspose(), calc_D_matrix.getDmatrix(), temp_matrix1);
	MatrixFunctions::multiply(16, 4, 16, temp_matrix1, calc_B_matrix.getBmatrix(), temp_matrix2);
	
	//double loop to for M matrix
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			M_matrix[i][j] = temp_matrix2[i][j] * calc_B_matrix.getJacobianDet();
		}
	}
}

calc_M_matrix::~calc_M_matrix()
{
	MatrixFunctions::deleteMatrix(M_matrix, 16, 16);
	MatrixFunctions::deleteMatrix(temp_matrix1, 16, 4);
	MatrixFunctions::deleteMatrix(temp_matrix2, 16, 16);
}

double** calc_M_matrix::getMmatrix()
{
	return M_matrix;
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