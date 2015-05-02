#pragma once
// The above preprocessor command tells the preprocessor not to include this file more than once.

// This class is supposed to contain all of the data that belongs to a material that we read from the file.
// The names a-l are currently place holders so we can replace them with ones that have more semantic meaning later.
class MaterialData
{
public:
	int id;
	// TODO give these proper names and comments, visual studio should do start renaming
	double a;
	double b;
	double c;
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
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i;
};

// this is a class that represents nodes as it seems they are defined in the input data.
class NodeData
{
public:
	int id;
	double x;
	double y;
};