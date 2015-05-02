/* 
 utlMatrix

 This class is the interface to the derived matrix classes.
*/

#ifndef utlMatrix_h
#define utlMatrix_h

#include <stdio.h>
#include <stdlib.h>
//#include <iostream.h>
#include <math.h>
//#include "femDefine.h"
#include "utlVector.h"

using namespace std;

class utlMatrix{
  protected:
    double **m_coeff;		// Coefficients of the matrix
    int m_nr, m_nc;        // Number of columns and rows
	// Never to be used copy constructor
	utlMatrix(const utlMatrix &matrix);
	// Never to be used Constructor
	utlMatrix();
  public:
    //Destructor
    virtual ~utlMatrix();
    // Functions
	void zero();		//initialize all coefficients of the matrix to zero
	int getNumRows() const;	//	return m_nr;
	int getNumCols() const;	//	return m_nc;
	void print(ostream &out);	//print useful info;
    virtual void setCoeff(int i, int j, double value) = 0;	//pure virtual, provide implementation in derived class
	virtual void addCoeff(int i, int j, double value) = 0;
	virtual double getCoeff(int i, int j) = 0;
	virtual void mult(utlMatrix &b, utlMatrix &c) = 0;
	virtual void mult(utlVector &b, utlVector &c) = 0;
	virtual void trans(utlMatrix &a) = 0;
	virtual void gauss(utlVector *b, utlVector *x) = 0;
};

#endif
