#pragma once
#include "stdafx.h"
#include "Controller.h"
#include "calc_B_matrix.h"
#include "calc_D_matrix.h"
#include "calc_M_matrix.h"
#include "calc_Ke_matrix.h"
#include "Element.h"
#include <iostream>
using namespace std;

class calc_global
{
protected:
	int arraySize;
	int numElems;
	double **K_matrix;
	double **global_matrix;
	int numEBCs;

public:
	calc_global(Controller &controller, ElementData &element, calc_D_matrix &calc_D_matrix, calc_Ke_matrix &calc_Ke_matrix);
	~calc_global();

	//Functions
	double getGlobal();
	void printData(ostream &out) const;
};