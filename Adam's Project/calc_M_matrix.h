#pragma once

#include "stdafx.h"
#include "Controller.h"
#include "calc_B_matrix.h"
#include "calc_D_matrix.h"
#include <iostream>
using namespace std;

class calc_M_matrix : public calc_B_matrix, public calc_D_matrix
{
protected:
	//int elem_id;
	double Jacobian[2][2];
	double B_transpose[16][4];
	double B_matrix[4][16];
	double D_matrix[4][4];
	double M_matrix[16][16];
	double det_Jacob;
	double temp_matrix1[16][4];
	double temp_matrix2[16][16];

public:
	calc_M_matrix(double mat1[][4], double mat2[][16], double val1, double mat3[][4], calc_B_matrix &calc_B_matrix, calc_D_matrix &calc_D_matrix);
	//~calc_D_matrix();

	//Functions
	double getMmatrix();
	void printData(ostream &out) const;
};