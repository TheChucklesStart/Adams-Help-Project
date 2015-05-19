#pragma once

#include "stdafx.h"
#include "Controller.h"
#include <iostream>
using namespace std;

class calc_B_matrix : public Controller
{
protected:
	int elem_id;
	int Node1;
	int Node2;
	int Node3;
	int Node4;
	int Node5;
	int Node6;
	int Node7;
	int Node8;
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
	calc_B_matrix(int val1, Controller &controller, double eta, double zeta);
	~calc_B_matrix();

	//Functions
	double** getBmatrix();
	double** getBtranspose();
	double getJacobianDet();
	void printData(ostream &out) const;
};
