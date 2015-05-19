#pragma once

#include "Controller.h"
#include "BasicStructures.h"

// this class is supposed to contain all of the data that belongs to the element rows in the source file.

class Controller;
class calc_B_matrix;
class calc_D_matrix;
class calc_M_matrix;
class calc_Ke_matrix;
class ElementData
{
private:
public:
	Controller *controller;

	int id;
	// TODO give these proper names and comments, visual studio should do start renaming
	int material;
	int Node1;
	int Node2;
	int Node3;
	int Node4;
	int Node5;
	int Node6;
	int Node7;
	int Node8;

	calc_B_matrix get_B_matrix(double eta, double zeta);
	calc_M_matrix get_M_matrix(calc_B_matrix &calc_B_matrix, calc_D_matrix &calc_D_matrix);
	calc_Ke_matrix get_Ke_matrix(calc_D_matrix &calc_D_matrix);
};

#include "calc_B_matrix.h"
#include "calc_M_matrix.h"
#include "calc_Ke_matrix.h"