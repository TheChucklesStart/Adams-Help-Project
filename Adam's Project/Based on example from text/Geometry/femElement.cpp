//femElement Object

#include "stdafx.h"
#include "femElement.h"

femElement::femElement(int id, femMaterial* mat, int numNodes, femNode* nodes[]);
{
	//Save object data
	d_id = id;
	d_material = mat;
	d_numNodes = numNodes;
	d_nodes = nodes[];
}

~femElement()
{
}

//Print data to file
void femElement::printData(ostream &out) const
{
	out << " ********************* Element Data *******************************" << '\n' << '\n';
	out << " ElemID  Material           Node Connectivity" << '\n';
	out << " " << d_id << "     " << d_material << "     " << d_nodes << '\n';
	//for loop for nodes?
}
