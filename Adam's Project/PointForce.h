#pragma once
#include "Controller.h"
#include "BasicStructures.h"

class Controller;
class PointForceData
{
public:
	Controller *controller;

	int id;
	int node;
	char direction[2];
	double value;
};

