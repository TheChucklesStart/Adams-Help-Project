
// ReadFile.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//Define parameters and vlaues taken from .inp file
	string line;
	int numNodes;
	int numElems;
	int numMatls;
	int prodType;
	ifstream myfile("e4plate.inp");
	if (myfile.is_open())
	{
		//Skip title line
		getline(myfile, line);

		//Get geometric values
		myfile >> numNodes;
		myfile >> numElems;
		myfile >> numMatls;
		myfile >> prodType;
		//Get material properties
		//Material properties always start on line 3 and contain 13 values each
		//Want to store material properties in an [numMatls][13] array
		double Matl[numMatls][13];
		for (int i = 0; i < 2 + numMatls; i++)
			for (int j = 0; i < 13; j++)
			Matl[i][j] = myfile;

		//Get element properties
		//Element properties always start on line 3+numMatls and contain 10 values each
		//Want to store element properties in an [numElems][10] array
		//for(int i = 0; i < 1+numMatls+numElems; i++)
		//getline(myfile,line);

		//Get node properties
		//Node properties always start on line 3+numMatls+numElems and contain 3 values each
		//Want to store node properties in an [numNodes][3] array
		//for(int i = 0; i < 1+numMatls+numElems; i++)
		//getline(myfile,line);
	}
	else cout << "Unable to open file.";

	//couts to check if the right values got pulled 
	cout << numNodes << '\n' << numElems << '\n' << numMatls << '\n' << prodType << '\n';
	cout << line << '\n';
	myfile.close();
	return 0;
}