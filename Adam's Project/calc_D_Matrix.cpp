#include "stdafx.h"
#include "calc_D_matrix.h"

calc_D_matrix::calc_D_matrix(int val1, double val2, double val3, Controller &controller)
{
	stiffness = MatrixFunctions::allocateMatrix(4, 4);
	D_matrix = MatrixFunctions::allocateMatrix(4, 4);

	ProblemType = val1;
	YM = val2;
	Poisson = val3;


	// calc_D_matrix matrix(.5, .7, controller);
	// calc_D_matrix *matrix = new calc_D_matrix(.5, .7, controller);

	if (ProblemType == 1)
	{
		coeff = YM / (1 - Poisson*Poisson);
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
		stiffness[3][3] = (1 - Poisson) / 2;

		//multiply coeff my stiffness
		for (int i = 0; i<4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				D_matrix[i][j] = coeff*stiffness[i][j];
			}
		}
	}

	else if (ProblemType == 2)
	{
		coeff = YM / ((1 + Poisson)*(1 - 2 * Poisson));
		stiffness[0][0] = (1 - Poisson);
		stiffness[0][1] = Poisson;
		stiffness[0][2] = Poisson;
		stiffness[0][3] = 0;
		stiffness[1][0] = Poisson;
		stiffness[1][1] = (1 - Poisson);
		stiffness[1][2] = Poisson;
		stiffness[1][3] = 0;
		stiffness[2][0] = Poisson;
		stiffness[2][1] = Poisson;
		stiffness[2][2] = (1 - Poisson);
		stiffness[2][3] = 0;
		stiffness[3][0] = 0;
		stiffness[3][1] = 0;
		stiffness[3][2] = 0;
		stiffness[3][3] = (1 - 2 * Poisson) / 2;

		//multiply coeff my stiffness
		for (int i = 0; i<4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				D_matrix[i][j] = coeff*stiffness[i][j];
			}
		}
	}

	else
	{
		cout << "Problem Type " << ProblemType << " not recognised." << endl;
	}
}

calc_D_matrix::~calc_D_matrix()
{
	MatrixFunctions::deleteMatrix(stiffness, 4, 4);
	MatrixFunctions::deleteMatrix(D_matrix, 4, 4);
}

double** calc_D_matrix::getDmatrix()
{
	return D_matrix;
}

void calc_D_matrix::printData(ostream &out) const
{
	for (int i = 0; i <4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			out << D_matrix[i][j] << " ";
		}
		out << endl;
	}
}