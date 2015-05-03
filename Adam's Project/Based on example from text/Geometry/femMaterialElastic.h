/*
 femMaterialElastic

 This class implements an elastic material.
*/

#ifndef femMaterialElastic_h
#define femMaterialElastic_h

#include "femMaterial.h"
#include "utlMatrix.h"
#include <iostream.h>

class femMaterialElastic: public femMaterial
{
  protected:
	double d_e;		//young's modulus
	double d_nu;	//poisson's ration
	double d_k;		//conductivity, irrelevant for us
	double d_thick; //thickness
	int d_probType; //problem type

	// never used copy constructor
	femMaterialElastic(const femMaterialElastic &mat);

  public:
	// Constructors
	femMaterialElastic();
	femMaterialElastic(int id, double e, double nu,
		double thick, int probType);
    //Destructor
    virtual ~femMaterialElastic();

    // Functions
	virtual void printData(ostream &out) const;	//print useful info such as id, Young's modulus etc.
	virtual void getDMatrixStress(utlMatrix &d);	//this sets the value of material stiffness matrix in d (4 by 4)
	//For elastic plane strain the stresses are sigx, sigy, sigz, sigxy
	// The D matrix is a 4x4 matrix

//	virtual void getDMatrixHeat(utlMatrix &d);
};

#endif
