#pragma once

#include "stdafx.h"

class calc_B_matrix
{
protected:
	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;
	double x4;
	double y4;
	double x5;
	double y5;
	double x6;
	double y6;
	double x7;
	double y7;
	double x8;
	double y8;
	double **Jacobian;
	double **B_transpose;
	double **B_matrix;
	double det_Jacob;

public:
	calc_B_matrix(ElementData &element, Controller &controller, double eta, double zeta);
	~calc_B_matrix();

	//Functions
	double** getBmatrix();
	double** getBtranspose();
	double getJacobianDet();
	void printData(ostream &out) const;
};
