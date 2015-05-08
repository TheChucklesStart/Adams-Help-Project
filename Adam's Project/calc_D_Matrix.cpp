#include "stdafx.h"
#include "calc_D_matrix.h"
#include "Controller.h"

calc_D_matrix::calc_D_matrix(int val1, float val2, float val3, Controller &controller)
{
	ProblemType = val1;
	YM = val2;
	Poisson = val3;
	
	ProblemType = controller.getProbType();
	YM = controller.getYM();
	Poisson = controller.getPoisson();

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
		cout << "Problem Type " << probType << " not recognised." << endl;
	}
}

void calc_D_matrix::printData(cout) const
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << D_matrix[i][j] << " ";
		}
		cout << endl;
	}
}