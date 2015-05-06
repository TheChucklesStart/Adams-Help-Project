#include "stdafx.h"

using namespace std;

//define gaussian points and weights
double zeta[3];
double eta[3];
double weight[3];

zeta[0] = 0.77459669241483;
zeta[1] = -0.77459669241483;
zeta[2] = 0;
eta[0] = 0.77459669241483;
eta[1] = -0.77459669241483;
eta[2] = 0;
weight[0] = 5/9;
weight[1] = 5/9;
weight[2] = 8/9;

//initialize ke_matrix to 0
for (int p = 0; p<15; p++)
{
	for (int q = 0; q<15; q++)
	{
		ke_matrix[p][q] = 0;
	}
}

//gauss loop
for (int j = 0; j<1; j++)
{
	for (int i = 0; i<1; i++)
	{
		cal_bmatrix_function(zeta[i], eta[j], b_matrix, b_inverse, det_jacob)
		cal_mmatrix_function(zeta[i], eta[j], b_matrix, b_inverse, det_jacob, m_matrix)
		for (int p = 0; p<15; p++)
		{
			for (int q = 0; q<15; q++)
			{
				ke_matrix[p][q] = ke_matrix[p][q]+t*m_matrix[p][q]*weight[i]*weight[j];
			}
		}
	}
}