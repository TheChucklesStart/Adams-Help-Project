/*
code for calculating M matrix from B_transpose, D, B, and det(J) based on the pseudo code from the professor
Needs zeta[i] and eta[j]
*/

//multiply B_transpose matrix by D matrix NEED TO CREATE MULTIPLICATION FUNCTION
mmult_function(D_matrix, B_matrix, 4, 4, 16, temp_matrix1)
mmult_function(B_transpose, temp_matrix1, 16, 4, 16, temp_matrix2)

//double loop to for M matrix
for (int i = 0; i<16; i++)
{
	for (int j = 0; j<16; j++)
	{
		M_matrix[i][j] = temp_matrix2[i][j]*det_J;
	}
}
