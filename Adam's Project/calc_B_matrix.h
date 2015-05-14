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
	double x1;
	double y1;
	//double Jacobian[2][2];
	//double B_transpose[16][4];
	//double B_matrix[4][16];
	//double det_Jacob;

public:
	calc_B_matrix(int val1, Controller &controller);
	//~calc_D_matrix();

	//Functions
	void printData(ostream &out) const;
};
