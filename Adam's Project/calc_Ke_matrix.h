#pragma once

#include "stdafx.h"
#include "Controller.h"
#include "calc_B_matrix.h"
#include "calc_D_matrix.h"
#include "calc_M_matrix.h"
#include "Element.h"
#include <iostream>
using namespace std;

class calc_Ke_matrix
{
protected:
	//int elem_id;
	double **Ke_matrix;

public:
	calc_Ke_matrix(ElementData &element, double thickness, calc_D_matrix &D_matrix);
	~calc_Ke_matrix();

	//Functions
	double getKematrix();
	void printData(ostream &out) const;
};
