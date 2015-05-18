// ReadFile.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "calc_D_matrix.h"
#include "calc_M_matrix.h"
#include "calc_B_matrix.h"
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

	system("pause");
	calc_D_matrix test(controller.getProbType(), controller.getYM(), controller.getPoisson(), controller);
	calc_B_matrix trial(controller.getElemID(0), controller);
	calc_M_matrix value(trial, test);
	test.printData(cout);
	trial.printData(cout);
	//cout << controller.getProbType() << endl;
	//cout << controller.getYM() << endl;
	//cout << controller.getPoisson() << endl;

	controller.writeData("final_finite.out");

	return 0;
}


