#include "stdafx.h"
#include <iostream>
#include "MatrixFunctions.h"

using namespace std;

double MatrixFunctions::invert(int n, double **m_coeff, double b[], double x[])
// this function uses the Gauss-Jordan elimination with pivoting to solve simultaneous linear equations
{
	/*
	Here is the routine for Gauss-Jordan elimination with full pivoting:
	Never use Gauss-Jordan elimination without pivoting!
	It solves equation [a]{x}={b} where matrix [a] is n by n
	Once done, the solution {x}=inverse([a])*{b} is stored in {b} vector
	and the inverse([a]) in [a] matrix
	*/

#define SWAP(a,b) {temp=(a);(a)=(b);(b)=temp;}

	int i, icol, irow, j, k, l, ll;
	double big, dum, pivinv, temp, hold;
	/*	dynamially create 3 integer arrays. The integer arrays
	ipiv, indxr, and indxc are used for bookkeeping on the pivoting.
	*/
	int *indxc = new int[n];
	int *indxr = new int[n];
	int *ipiv = new int[n];

	for (j = 0; j < n; j++) ipiv[j] = 0;
	for (i = 0; i < n; i++)
	{ // This is the main loop over the columns to be reduced. 
		big = 0.0;
		for (j = 0; j < n; j++)
		{// This is the outer loop of the search for a pivot element. 
			if (ipiv[j] != 1)
			{
				for (k = 0; k < n; k++)
				{
					if (ipiv[k] == 0)
					{
						if (fabs(m_coeff[j][k]) >= big)
						{
							big = fabs(m_coeff[j][k]);
							irow = j;
							icol = k;
						}
					}
					else if (ipiv[k] > 1)
					{
						// if this condition is true, the matrix is singnular and a solutiuon is impossible
						cout << "gaussj: Singular Matrix -- 1!" << endl;
						return 1;
					}
				}
			}
		}
		++(ipiv[icol]);

		/* We now have the pivot element, so we interchange rows, if needed, to put the pivot
		element on the diagonal. The columns are not physically interchanged, only relabeled:
		indxc[i], the column of the ith pivot element, is the ith column that is reduced, while
		indxr[i] is the row in which that pivot element was originally located. If indxr[i]
		6 = indxc[i] there is an implied column interchange. With this form of bookkeeping, the
		solution b's will end up in the correct order, and the inverse matrix will be scrambled
		by columns. */
		if (irow != icol)
		{
			for (l = 0; l < n; l++) SWAP(m_coeff[irow][l], m_coeff[icol][l]);
			hold = b[irow];
			b[irow] = b[icol];
			b[icol] = hold;
		}

		// We are now ready to divide the pivot row by the pivot element, located at irow and icol.
		indxr[i] = irow;
		indxc[i] = icol;
		if (abs(m_coeff[icol][icol]) < 1.e-12)
			//note: theoretically, if m_coeff[icol][icol] is 0, then the matrix is singular
			//but numerically, 1e-12 is small enough
		{
			cout << "f_gauss_elim: Singular Matrix -- 2!" << endl;
			return 1;
		}
		pivinv = 1.0 / m_coeff[icol][icol];
		m_coeff[icol][icol] = 1.0;
		for (l = 0; l < n; l++) { m_coeff[icol][l] *= pivinv; }
		b[icol] = b[icol] * pivinv;
		for (ll = 0; ll < n; ll++) //Next, we reduce the rows... except for the pivot one, of course.
		{
			if (ll != icol)
			{
				dum = m_coeff[ll][icol];
				m_coeff[ll][icol] = 0.0;
				for (l = 0; l < n; l++) m_coeff[ll][l] -= m_coeff[icol][l] * dum;
				b[ll] = b[ll] - dum*b[icol];
			}
		}
	}

	/* This is the end of the main loop over columns of the reduction. It only remains to unscram-
	ble the solution in view of the column interchanges. We do this by interchanging pairs of
	columns in the reverse order that the permutation was built up. */
	for (l = n - 1; l >= 0; l--)
	{
		if (indxr[l] != indxc[l])
		{
			for (k = 0; k < n; k++)
			{
				SWAP(m_coeff[k][indxr[l]], m_coeff[k][indxc[l]]);
			}
		}
	} // And we are done.
	delete[] indxc; //delete dynamically created arrays
	delete[] indxr;
	delete[] ipiv;

	for (i = 0; i < n; i++) {	//copy the solution vector to x
		x[i] = b[i];
	}
}

void MatrixFunctions::multiply(int r, int s, double **inMatrix, double *inVector, double *outVector)
{
	for (int i = 0; i < r; i++)
		outVector[i] = 0;

	for (int i = 0; i < r; i++)
		for (int k = 0; k < s; k++)
		{
			outVector[i] += inMatrix[i][k] * inVector[k];
		}
}

void MatrixFunctions::multiply(int r, int s, int t, double **inMatrix1, double **inMatrix2, double **outMatrix)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < t; j++)
		{
			outMatrix[i][j] = 0;
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < t; j++)
		{
			for (int k = 0; k < s; k++)
			{
				outMatrix[i][j] += inMatrix1[i][k] * inMatrix2[k][j];
			}
		}
	}
}

double** MatrixFunctions::allocateMatrix(int rows, int columns)
{
	double** result = new double*[rows];
	for (int i = 0; i < rows; i++)
		result[i] = new double[columns];
	return result;
}

void MatrixFunctions::deleteMatrix(double** &matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = NULL;
}

void MatrixFunctions::printMatrix(double **& matrix, int rows, int columns, std::ostream &out)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			out << matrix[i][j] << "\t";
		}
		out << std::endl;
	}
}
