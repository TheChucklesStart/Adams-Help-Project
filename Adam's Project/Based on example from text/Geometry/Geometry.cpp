// Geometry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "femdata.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string file_name;
	femData data;
	ifstream input_file;
	ofstream output_file;

	//User interface
	cout << "Please input file name, including extension" << endl;
		
	getline(cin, file_name);

	//Create file streams
	input_file.open(file_name);
	output_file.open("finte_project.out");

	//Read and write data
	data.readData(input_file);
	data.writeData(output_file);

	//Close files
	input_file.close();
	output_file.close();

	return 0;
}

