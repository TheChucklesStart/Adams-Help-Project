#include "stdafx.h"
#include "Controller.h"
#include "Element.h"
#include "calc_ke_matrix.h"
#include "calc_global.h"
#include "MatrixFunctions.h"

calc_global::calc_global(Controller &controller, ElementData &element, calc_D_matrix &calc_D_matrix, calc_Ke_matrix &calc_Ke_matrix)
{
	//define global matrix size as numNodes*2
	arraySize = controller.getNumNodes()*2;
	numElems = controller.getNumElements();
	K_matrix = MatrixFunctions::allocateMatrix(16, 16);

	//create and initialize global matrix outside of element loop
	global_matrix = MatrixFunctions::allocateMatrix(arraySize, arraySize);
	for (int i = 0; i<arraySize; i++)
	{
		for (int j = 0; j<arraySize; j++)
		{
			global_matrix[i][j] = 0;
		}
	}
	
	//for each element get K matrix, create a vector of nodes and put K values in global matrix
	for (int p = 0; p < numElems; p++)
	{
		
		element.get_Ke_matrix(calc_D_matrix);
		//get K matrix
		for (int n = 0; n<16;n++)
		{
			for (int m = 0;m<16;m++)
			{
				K_matrix[n][m] = calc_Ke_matrix.getKematrix()[n][m];
			}
		}
		
		//initializae an array of element nodes
		int Node[8];
		Node[0] = controller.getNode1(p);
		Node[1] = controller.getNode2(p);
		Node[2] = controller.getNode3(p);
		Node[3] = controller.getNode4(p);
		Node[4] = controller.getNode5(p);
		Node[5] = controller.getNode6(p);
		Node[6] = controller.getNode7(p);
		Node[7] = controller.getNode8(p);

		//put K values in global matrix
		for (int j = 0; j<8; j++)
		{
			for (int i = 0; i<8; i++)
			{
				global_matrix[Node[j] * 2 - 2][Node[i] * 2 - 2] = global_matrix[Node[j] * 2 - 2][Node[i] * 2 - 2] + K_matrix[2 * j][2 * i];
				global_matrix[Node[j] * 2 - 2][Node[i] * 2 - 1] = global_matrix[Node[j] * 2 - 2][Node[i] * 2 - 1] + K_matrix[2 * j][2 * i + 1];
				global_matrix[Node[j] * 2 - 1][Node[i] * 2 - 2] = global_matrix[Node[j] * 2 - 1][Node[i] * 2 - 2] + K_matrix[2 * j + 1][2 * i];
				global_matrix[Node[j] * 2 - 1][Node[i] * 2 - 1] = global_matrix[Node[j] * 2 - 1][Node[i] * 2 - 1] + K_matrix[2 * j + 1][2 * i + 1];
			}
		}
	}

	//apply boundary conditions
/*	numEBCs = controller.getNumEBCs();
	for (int i = 0; i < numEBCs; i++)
	{
		controller.getEssentialBCClass(i);
		if (strcmp(essentialBC.direction, "UX")==0)
		{
			for (int j = 0; j < essentialBC.node; j++)
			{
				global_matrix[essentialBC.node * 2 - 1][j] = essentialBC.value;
			}
			for (int j = 0; j < essentialBC.node; j++)
			{
				global_matrix[j][essentialBC.node * 2 - 1] = essentialBC.value;
			}
		}
		if (strcmp(essentialBC.direction, "UY") == 0)
		{
			for (int j = 0; j < essentialBC.node; j++)
			{
				global_matrix[essentialBC.node * 2][j] = essentialBC.value;
			}
			for (int j = 0; j < essentialBC.node; j++)
			{
				global_matrix[j][essentialBC.node * 2] = essentialBC.value;
			}
		}
	}*/

}

calc_global::~calc_global()
{
	MatrixFunctions::deleteMatrix(global_matrix, arraySize, arraySize);
}

double calc_global::getGlobal()
{
	return global_matrix[arraySize][arraySize];
}

void calc_global::printData(ostream &out) const
{
	for (int i = 0; i <arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			out << global_matrix[i][j] << " ";
		}
		out << endl;
	}
}
