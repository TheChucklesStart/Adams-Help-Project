#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// The above preprocessor command tells the preprocessor not to include this file more than once.

// This class is supposed to contain all of the data that belongs to a material that we read from the file.
// The names a-l are currently place holders so we can replace them with ones that have more semantic meaning later.
class MaterialData
{
public:
	int id;
	// TODO give these proper names and comments, visual studio should do start renaming
	double YM;
	double Poisson;
	double thickness;
	double d;
	double e;
	double f;
	double g;
	double h;
	double i;
	double j;
	double k;
	double l;
};

// this class is supposed to contain all of the data that belongs to the element rows in the source file.
class ElementData
{
public:
	int id;
	// TODO give these proper names and comments, visual studio should do start renaming
	int matl;
	int Node1;
	int Node2;
	int Node3;
	int Node4;
	int Node5;
	int Node6;
	int Node7;
	int Node8;
};

// this is a class that represents nodes as it seems they are defined in the input data.
class NodeData
{
public:
	int id;
	double x;
	double y;
};

class EssentialBCData
{
public:
	int id;
	// TODO give these proper names and comments, visual studio should do start renaming
	int node;
	string direction;
	double value;
};

class PointForceData
{
public:
	int id;
	// TODO give these proper names and comments, visual studio should do start renaming
	int node;
	string direction;
	double value;
};

class NaturalBCData
{
public:
	int id;
	// TODO give these proper names and comments, visual studio should do start renaming
	int leftnode;
	int midnode;
	int rightnode;
	double value;
};