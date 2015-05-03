/* 
 utlVector

 This class implements a vector.
*/

#ifndef utlVector_h
#define utlVector_h

#include <stdio.h>
#include <stdlib.h>
//#include <ostream.h>
//#include "femDefine.h"

using namespace std;

class utlVector{
  protected:
    double *m_coeff;		// Coefficients of matrix
    int m_nr;				// Number of rows
	//never to be used copy constructor
	utlVector(const utlVector &vector);
  public:
	// Constructors
	utlVector();
	utlVector(int nr);

    //Destructor
    virtual ~utlVector();
    // Functions
	void zero();	//initialize all coefficient of the vector to be zero
	int getNumRows() const;	//	return m_nr;
	void setCoeff(int i, double value);	//set m_coeff[i] = value;
	void addCoeff(int i, double value);	//add value to m_coeff[i];
	double getCoeff(int i);	//	return m_coeff[i];
	void print(ostream &out);	//print useful info
};

#endif
