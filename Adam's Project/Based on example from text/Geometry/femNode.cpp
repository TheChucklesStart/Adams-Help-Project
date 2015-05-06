//femNode Object

#include "stdafx.h"
#include "femNode.h"

femNode::femNode(int id)
{
	//Save object data
	d_id = id;
}

femNode::~femNode()
{
}

void femNode::setCoords(double x, double y)
{
	d_x = x;
	d_y = y;
}

double femNode::getX():
{
	return d_x;
}

double femNode::getY()
{
	return d_y;
}

//Print data to file
void femNode::printData(ostream &out) const
{
	out << " ********************** Nodal Data ********************************" << '\n' << '\n';
	out << " ID =      " << d_id << "  X =   " << d_x << "  Y =   " << d_y << '\n';
}
