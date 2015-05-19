#include "stdafx.h"
#include "calc_Ke_matrix.h"
#include "Controller.h"
#include "calc_M_matrix.h"
#include "MatrixFunctions.h"

calc_Ke_matrix::calc_Ke_matrix(Controller &controller, calc_M_matrix &calc_M_matrix)
{
	Ke_matrix = MatrixFunctions::allocateMatrix(16, 16);
	thickness = controller.getThickness();
	M_matrix = calc_M_matrix.getMmatrix();
		
	//define gaussian points and weights THESE WILL BE NEEDED BY AT LEAST 3 FUNCTIONS :THIS ONE (CAL_STIFFNESS_MATRIX), CAL_BMATRIX, and CAL_MMATRIX
	double zeta[2];
	double eta[2];
	double weight[2];

	zeta[0] = 0.577350269189626; // ~1/sqrt(3)
	zeta[1] = -0.577350269189626; // ~-1/sqrt(3)
	eta[0] = 0.577350269189626; // ~1/sqrt(3)
	eta[1] = -0.577350269189626; // ~-1/sqrt(3)
	weight[0] = 1;
	weight[1] = 1;

	//Initialize ke_matrix to zero
	for (int p = 0; p < 16; p++)
	{
		for (int q = 0; q < 16; q++)
		{
			Ke_matrix[p][q] = 0;
		}
	}

	//Double loop to go though all 2x2 gaussian points
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			//double loop to go through all 16x16 coeffs for ke_matrix and add contribution from each Gaussian point
			for (int p = 0; p < 16; p++)
			{
				for (int q = 0; q < 16; q++)
				{
					Ke_matrix[p][q] = Ke_matrix[p][q] + thickness * M_matrix[p][q] * weight[i] * weight[j];
				}
			}
		}
	}
}
/*
calculating the element stiffness matrix ke_matrix, based on the pseudo code in q&a 3.docx provided by the professor
This is the point where zeta[i] and eta[j] from previous functions get definied.
*/
calc_Ke_matrix::~calc_Ke_matrix()
{
	MatrixFunctions::deleteMatrix(Ke_matrix, 16, 16);
}

double calc_Ke_matrix::getKematrix()
{
	return Ke_matrix[16][16];
}

void calc_Ke_matrix::printData(ostream &out) const
{
	for (int i = 0; i <16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			out << Ke_matrix[i][j] << " ";
		}
		out << endl;
	}
}
