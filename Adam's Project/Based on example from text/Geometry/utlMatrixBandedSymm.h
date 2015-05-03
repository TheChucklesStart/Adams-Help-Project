/* 
 utlMatrixBandedSymm

 This implements the matrix as a banded, symmetric matrix.  This internal storage
 is transparent to the user.
*/

#ifndef utlMatrixBandedSymm_h
#define utlMatrixBandedSymm_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "utlMatrix.h"
//#include "femDefine.h"

class utlMatrixBandedSymm: public utlMatrix{	//this is the banded, symmetric matrix class. It is irrelevant to us.
  protected:
	//never to be used constructors
	utlMatrixBandedSymm();
    utlMatrixBandedSymm(const utlMatrixBandedSymm &matrix);
  public:
	// Constructors
    utlMatrixBandedSymm(int nr, int nc);
    //Destructor
    virtual ~utlMatrixBandedSymm();
    // Functions
	virtual void setCoeff(int i, int j, double value);
	virtual void addCoeff(int i, int j, double value);
	virtual double getCoeff(int i, int j);
	virtual void mult(utlMatrix &b, utlMatrix &c);
	virtual void mult(utlVector &b, utlVector &c);
    virtual void trans(utlMatrix &a);
	virtual void gauss(utlVector *b, utlVector *x);
};

#endif
