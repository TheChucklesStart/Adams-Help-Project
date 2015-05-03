/* 
 utlMatrixFull

 This class stores all the coefficients of the matrix. 
*/

#ifndef utlMatrixFull_h
#define utlMatrixFull_h

#include <stdio.h>
#include <stdlib.h>
//#include <iostream.h>
#include "utlMatrix.h"
//#include "femDefine.h"

using namespace std;

class utlMatrixFull: public utlMatrix{	//this is a matrix class which can be unsymmetric and full
  protected:
	//never to be used constructors
	utlMatrixFull();
    utlMatrixFull(const utlMatrixFull &matrix);
  public:
	// Constructors
    utlMatrixFull(int nr, int nc);	//construct a nr by nc matrix
    //Destructor
    virtual ~utlMatrixFull();
    // Functions
	virtual void setCoeff(int i, int j, double value);	//set m_coeff[i][j] = value;
	virtual void addCoeff(int i, int j, double value);	//add value to m_coeff[i][j]
	virtual double getCoeff(int i, int j);	//return m_coeff[i][j];
	virtual void mult(utlMatrix &b, utlMatrix &c);	//multiply matrix m_coeff of this class with the matrix data member of class b, store the result in the matrix data member of class c
	virtual void mult(utlVector &b, utlVector &c);	//multiply matrix m_coeff of this class with the vector data member of class b, store the result in the vector data member of class c
    virtual void trans(utlMatrix &a);	//transpose the matrix data member of class c, store the result in the matrix m_coeff of this class
	virtual void gauss(utlVector *b, utlVector *x);
	/*
	This function solves a linear system of equations.  The stiffness matrix is 
	the matrix data member m_coeff of this class, the vector data member of 
	class b is the RHS vector, and the vector data member of class x will store 
	the solution.
	Here is the place that you should use the solve function in the solver class 
	I provided to you a few weeks ago. But you need to modify the functional 
	variable list. The solve function uses a Gauss elimination with full pivoting;
	it works for any full, unsymmetric matrix.
	*/

};

#endif
