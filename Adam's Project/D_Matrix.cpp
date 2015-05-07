/*
create the material matrix. this requires 4 pieces of information from the input file: probType, numMaterials, YM for each material and Poisson for each material.
Depending on the problem type, one of two matrices is created.
*/

#include "stdafx.h"
#include "D_matrix.h"
#include "Controller.h"

using namespace std;

D_matrix::D_matrix()
{
	coeff = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stiffness[i][j] = 0;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			d_matrix[i][j] = 0;
		}
	}
}
//getprobType(probType)
//getnumMaterials(numMaterials)

//double D_matrix::calc_Dmatrix(probType, materialData[1].YM, materialData[1].Poisson)
/*getYM(YM) //when defining getYM(), multiply by 1e7
getPoisson(Poisson)

if(probType == 1)
{
	coeff = YM/(1-Poisson*Poisson);
	stiffness[0][0] = 1;
	stiffness[0][1] = Poisson;
	stiffness[0][2] = Poisson;
	stiffness[0][3] = 0;
	stiffness[1][0] = Poisson;
	stiffness[1][1] = 1;
	stiffness[1][2] = Poisson;
	stiffness[1][3] = 0;
	stiffness[2][0] = Poisson;
	stiffness[2][1] = Poisson;
	stiffness[2][2] = 1;
	stiffness[2][3] = 0;
	stiffness[3][0] = 0;
	stiffness[3][1] = 0;
	stiffness[3][2] = 0;
	stiffness[3][3] = (1-Poisson)/2;

	//multiply coeff my stiffness
	for(int i = 0; i<4; i++)
	{
		for(int j = 0, j<4; j++)
		{
			D_matrix[i][j] = coeff*stiffness[i][j];
		}
	}
}

else if(probType == 2)
{
	coeff = YM/((1+Poisson)*(1-2*Poisson));
	stiffness[0][0] = (1-Poisson);
	stiffness[0][1] = Poisson;
	stiffness[0][2] = Poisson;
	stiffness[0][3] = 0;
	stiffness[1][0] = Poisson;
	stiffness[1][1] = (1-Poisson);
	stiffness[1][2] = Poisson;
	stiffness[1][3] = 0;
	stiffness[2][0] = Poisson;
	stiffness[2][1] = Poisson;
	stiffness[2][2] = (1-Poisson);
	stiffness[2][3] = 0;
	stiffness[3][0] = 0;
	stiffness[3][1] = 0;
	stiffness[3][2] = 0;
	stiffness[3][3] = (1-2*Poisson)/2;

	//multiply coeff my stiffness
	for(int i = 0; i<4; i++)
	{
		for(int j = 0, j<4; j++)
		{
			D_matrix[i][j] = coeff*stiffness[i][j];
		}
	}
}

else
{
	cout << "Problem Type " << probType << " not recognised." << endl.
}*/