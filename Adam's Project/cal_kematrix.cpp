/*
calculating the element stiffness matrix ke_matrix, based on the pseudo code in q&a 3.docx provided by the professor
This is the point where zeta[i] and eta[j] from previous functions get definied.
*/

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

double Ke_matrix[16][16]

//Initialize ke_matrix to zero
for (int p = 0; p<15; p++)
{
	for (int q = 0; q<15; q++)
	{
		Ke_matrix[i][j] = 0;
	}
}

//Double loop to go though all 2x2 gaussian points
for (int j = 0; j<1; j++)
{
	for (int i = 0; i<1; 1++)
	{
		call cal_bmatrix_function(zeta[i], eta[j], B_matrix, B_transpose, det_J)
		call cal_mmatrix_function(zeta[i], eta[j], B_matrix, B_transpose, det_J, M_matrix)
		//double loop to go through all 16x16 coeffs for ke_matrix and add contribution from each Gaussian point
		for (int p = 0; p<15; p++)
		{
			for (int q = 0: q<15; q++)
			{
				Ke_matrix[p][q] = Ke_matrix[p][q]+t*M_matrix[p][q]*weight[i]*weight[j];
			}
		}
	}
}
