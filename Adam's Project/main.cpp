// ReadFile.cpp : Defines the entry point for the console application.
#include "Controller.h"



int main(int argc, char* argv[])
{
	// define our controller for this program 
		// (it is being created on the stack so we don't have to worry about deleting it)
		// (because its constructor is argumentless, we cannot call it explicitly, but it is called implicitly)
	Controller controller;

	// read in our input file
	controller.readData("e4plate.inp");
	
	system("pause");
	
	controller.writeData("output.txt");
	
	return 0;
}
