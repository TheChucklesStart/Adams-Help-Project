// ReadFile.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "calc_D_matrix.h"
#include "calc_M_matrix.h"
#include "calc_B_matrix.h"
#include "calc_Ke_matrix.h"
#include "calc_load_vector.h"
#include "calc_global.h"
#include "Controller.h"



int main(int argc, char* argv[])
{
	// define our controller for this program 
	// (it is being created on the stack so we don't have to worry about deleting it)
	// (because its constructor is argumentless, we cannot call it explicitly, but it is called implicitly)
	Controller controller;


	//Interface
	string file_name;
	cout << "Please enter file name:\n";
	getline(cin, file_name);

	// read in our input file
	controller.readData(file_name);
	/*
	double **the = MatrixFunctions::allocateMatrix(3, 3);
	double **teh = MatrixFunctions::allocateMatrix(3, 3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			the[i][j] = 3 * i + j;
		}
	}

	MatrixFunctions::printMatrix(the, 3, 3, cout);
	cout << endl;

	MatrixFunctions::multiply(3, 3, 3, the, the, teh);


	MatrixFunctions::printMatrix(the, 3, 3, cout);
	cout << endl;
	MatrixFunctions::printMatrix(teh, 3, 3, cout);
	cout << endl;
	*/
	system("pause");
	//Calculate D matrix
	calc_D_matrix test(controller.getProbType(), controller.getYM(), controller.getPoisson(), controller);
	
	//Calculate element stiffness matrices (K matrices) 
	calc_Ke_matrix** results = new calc_Ke_matrix*[controller.getNumElements()];
	for (int i = 0; i < controller.getNumElements();i++)
	{
		results[i] = new calc_Ke_matrix(controller.getElemenetClass(i), controller.getThickness(), test);
		results[i]->printData(cout);
		cout << endl << endl << endl;
		/*calc_global global(controller, controller.getElemenetClass(i), test, result);
		global.printData(cout);
		cout << endl << endl;*/
	}
	/*for (int j = 0; j < controller.getNumElements(); j++)
	{
		calc_B_matrix trial(controller.getElemenetClass(j), controller, 1, 1);
		calc_load_vector vec(controller.getElemenetClass(j), controller, trial, 1, 1);
		trial.printData(cout);
		vec.printData(cout);
	}*/
	
	//calc_B_matrix trial(controller.getElemID(0), controller,1,1);
	//calc_M_matrix value(trial, test);
	

	//controller.getElemID(0)

	//test.printData(cout);

	//cout << controller.getProbType() << endl;
	//cout << controller.getYM() << endl;
	//cout << controller.getPoisson() << endl;

	controller.writeData("final_finite.out");

	return 0;
}


