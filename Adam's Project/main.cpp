// ReadFile.cpp : Defines the entry point for the console application.
#include "stdafx.h"
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

	controller.writeData("final_finite.inp");

	return 0;
}
