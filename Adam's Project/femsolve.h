/* 
 femSolve

 This class manages the solution.
*/

#ifndef femSolve_h
#define femSolve_h

//#include <iostream.h>
#include "femData.h"
#include "utlMatrix.h"
#include "utlVector.h"

using namespace std;

class femSolve
{
  private: 
    utlMatrix *m_k;	//ptr to a utlMatrix object. Use dynamic allocation to form a m_neq by m_neq global stiffness matrix
					// e.g m_k = new utlMatrixFull(m_neq,m_neq); 
    utlVector *m_f;	//ptr to a utlVector object. It contains the right hand side vector. Use dynamic allocation to form a m_neq right hand side vector
					//e.g. m_f = new utlVector(m_neq);
    utlVector *m_sol;	//ptr to a utlVector object. It contains the solution (solved displacement vector)
	int m_neq;	//total number of equations.  Note that the eqns run from 0 to m_neq-1
	int m_bandw;	//bandwidth, irrelevant for us.

	int setEquationNumbers(femData &dat);	//this calculates the total number of equations which is equal to (node number)*2 - (total number of inactive dofs)
	int getBandwidth(femData &dat);			//get bandwidth, irrelevant for us
    void assembleRHS(femData &dat, utlVector *f, ostream &out);		//assemble the global right hand side vector
	void assembleK(femData &dat, utlMatrix *k, utlVector *f,
        ostream &out);		//assemble the global stiffness matrix. Only active dofs contribute to m_k
    void saveSolution(femData &dat, utlVector *sol);	//save the solution (m_sol) into the d_value of each active dof
	void calcData(femData &dat);		//calculate useful data

  public:
	// Constructors
	femSolve();
    //Destructor
    virtual ~femSolve();
	void solve(femData &dat, ostream &out);
	/*
	this function solves the system equations.
	it first sets the dofs with essential b.c. to inactive, calculate the 
	number of equations, then allocate the mamery for the global stiffness matrix and right hand vector,
	assemble RHS vector and global stiffness matrix, then solve the system equation using Gauss elimination
    It then saves the solution and calculate useful information
	*/
};

#endif
