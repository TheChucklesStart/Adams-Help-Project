#include "stdafx.h"
#include "Controller.h"
#include "Element.h"
#include "calc_B_matrix.h"
#include <iostream>
#include "calc_load_vector.h"
using namespace std;

calc_load_vector::calc_load_vector(ElementData &element, Controller &controller, calc_B_matrix &calc_B_matrix, double zeta, double eta)
{
	//define component and solution vectors and matrices
	NodeEqnMatrix = MatrixFunctions::allocateMatrix(16, 2);
	double ForceVector[16];
	double LoadVector[16];
	numPFs = controller.getPFs();

	//RETRIEVE JACOBIAN DETERMINANT FROM CALC_B_MATRIX!!!!!!
	detJacob = calc_B_matrix.getJacobianDet();
	
	//define node equations
	double N1 = (-1 / 4)*(1 - zeta)*(1 - eta)*(zeta + eta + 1);
	double N2 = (1 / 2)*(1 - zeta*zeta)*(1 - eta);
	double N3 = (1 / 4)*(1 + zeta)*(1 - eta)*(zeta - eta - 1);
	double N4 = (1 / 2)*(1 - eta*eta)*(1 + zeta);
	double N5 = (1 / 4)*(1 + zeta)*(1 + eta)*(zeta + eta - 1);
	double N6 = (1 / 2)*(1 - zeta*zeta)*(1 + eta);
	double N7 = (-1 / 4)*(1 - zeta)*(1 + eta)*(zeta - eta + 1);
	double N8 = (1 / 2)*(1 - eta*eta)*(1 - zeta);

	//populate NodeEqnMatrix
	NodeEqnMatrix[0][0] = N1;
	NodeEqnMatrix[0][1] = 0;
	NodeEqnMatrix[1][0] = 0;
	NodeEqnMatrix[1][1] = N1;
	NodeEqnMatrix[2][0] = N2;
	NodeEqnMatrix[2][1] = 0;
	NodeEqnMatrix[3][0] = 0;
	NodeEqnMatrix[3][1] = N2;
	NodeEqnMatrix[4][0] = N3;
	NodeEqnMatrix[4][1] = 0;
	NodeEqnMatrix[5][0] = 0;
	NodeEqnMatrix[5][1] = N3;
	NodeEqnMatrix[6][0] = N4;
	NodeEqnMatrix[6][1] = 0;
	NodeEqnMatrix[7][0] = 0;
	NodeEqnMatrix[7][1] = N4;
	NodeEqnMatrix[8][0] = N5;
	NodeEqnMatrix[8][1] = 0;
	NodeEqnMatrix[9][0] = 0;
	NodeEqnMatrix[9][1] = N5;
	NodeEqnMatrix[10][0] = N6;
	NodeEqnMatrix[10][1] = 0;
	NodeEqnMatrix[11][0] = 0;
	NodeEqnMatrix[11][1] = N6;
	NodeEqnMatrix[12][0] = N7;
	NodeEqnMatrix[12][1] = 0;
	NodeEqnMatrix[13][0] = 0;
	NodeEqnMatrix[13][1] = N7;
	NodeEqnMatrix[14][0] = N8;
	NodeEqnMatrix[14][1] = 0;
	NodeEqnMatrix[15][0] = 0;
	NodeEqnMatrix[15][1] = N8;
	
	//populate force vector
	ForceVector[0] = fx1;
	ForceVector[1] = fy1;
	ForceVector[2] = fx2;
	ForceVector[3] = fy2;
	ForceVector[4] = fx3;
	ForceVector[5] = fy3;
	ForceVector[6] = fx4;
	ForceVector[7] = fy4;
	ForceVector[8] = fx5;
	ForceVector[9] = fy5;
	ForceVector[10] = fx6;
	ForceVector[11] = fy6;
	ForceVector[12] = fx7;
	ForceVector[13] = fy7;
	ForceVector[14] = fx8;
	ForceVector[15] = fy8;

	//define element node array
	int Node[8];
	Node[0] = element.Node1;
	Node[1] = element.Node2;
	Node[2] = element.Node3;
	Node[3] = element.Node4;
	Node[4] = element.Node5;
	Node[5] = element.Node6;
	Node[6] = element.Node7;
	Node[7] = element.Node8;

	//apply point forces to force vector
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < numPFs; j++)
		{
			if (Node[i] == controller.getPFNode(j))
			{
				if (strcmp(controller.getPFdirection(j), "UX") == 0)
				{
					ForceVector[i * 2 - 1] = controller.getPFvalue(j);
				}
				if (strcmp(controller.getPFdirection(j), "UY") == 0)
				{
					ForceVector[i * 2] = controller.getPFvalue(j);
				}
			}
		}
	}

	//combine terms
	MatrixFunctions::multiply(2, 2, NodeEqnMatrix, ForceVector, LoadVector);
}

calc_load_vector::~calc_load_vector()
{

}

double calc_load_vector::getLoadVector()
{
	return LoadVector[16];
}

void calc_load_vector::printData(ostream &out) const 
{
	//out << detJacob << endl;
	for (int j = 0; j < 16; j++)
	{
		out << LoadVector[j] << endl;
	}
}