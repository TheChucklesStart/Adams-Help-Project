/*
 femElementQ8

 Class femElementQ8 implements the eight-noded quadrilateral element.
*/

#ifndef femElementQ8_h
#define femElementQ8_h

#include "femElement.h"
#include "femMaterial.h"
#include "utlStress2D.h"
#include <iostream.h>

class femElementQ8: public femElement	//this is a derived class from femElement
{
  private:
	utlStress2D d_stress[3][3];	//d_stress is an 3 by 3 matrix, each element is a utlStress2D class object. d_stress stores the stresses at the 3 by 3 Gaussian points

	// Never to be used constructors.
	femElementQ8();
	femElementQ8(const femElementQ8 &elem);

  public:

	// Constructors
	femElementQ8(int id, femMaterial* mat, 
		int numNodes, femNode* enodes[]);

    // Destructor
    virtual ~femElementQ8();

    // Functions
	virtual int getNumDofs() const;	//	for Q8 element, return 16; the "virtual" here is just a reminder that this function has been declared virtual in the base class
    virtual int getBandwidth() const;	//irrelevant
	virtual void getElementK(utlMatrix &k, femDof* dofs[], ostream &out);	
	//calculate the element stiffness matrix.
	//here k stores the 16 by 16 stiffness matrix
	//femSolve::assembleK will call this function to obtain k, and assemble the global matrix
	void calcData(); //Calculate useful info, e.g. stresses at the 3 by 3 gauss points.
	void getNodalData(utlStress2D stresses[]); //This function calculates nodal stresses
	virtual void printResults(ostream &out) const;	//print useful results such as stresses

  private:
	void getBMatrix(double r, double s, utlMatrix &b, double &detj);
	/*This function calculate the B matrix.
	You need to evaluate the shape function derivatives with respect to r and s, the
	natural coordinates, and then global deriv of shape functions
	Calculate the determinant of the Jacobian and evaluate the B matrix.  Note that we write out the inverse of the
	Jacobian matrix.
	*/
};

#endif
