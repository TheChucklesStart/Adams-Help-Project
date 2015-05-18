#pragma once

#include "stdafx.h"
#include "Controller.h"
#include "calc_B_matrix.h"
#include "calc_D_matrix.h"
#include <iostream>
using namespace std;

class calc_M_matrix
{
protected:
	//int elem_id;
	double **M_matrix;
	double **temp_matrix1;
	double **temp_matrix2;

public:
	calc_M_matrix(calc_B_matrix &calc_B_matrix, calc_D_matrix &calc_D_matrix);
	~calc_M_matrix();

	//Functions
	double getMmatrix();
	void printData(ostream &out) const;
};