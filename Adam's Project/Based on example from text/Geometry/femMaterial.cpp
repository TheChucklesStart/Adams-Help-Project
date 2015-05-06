//femMaterialt Object

#include "stdafx.h"
#include "femMaterial.h"

femMaterial::femMaterial(int id)
{
	//Save object data
	d_id = id;
}

femMaterial::~femMaterial()
{
}

//Print data to file
void femMaterial::printData(ostream &out) const
{
	out << " ********************* Material Data ******************************" << '\n' << '\n';
	out << " ID =    " << d_id << "  E =   " << XXXXXX << "  Nu =   " << XXXXXX << '\n';
	//for loop for nodes?
}
