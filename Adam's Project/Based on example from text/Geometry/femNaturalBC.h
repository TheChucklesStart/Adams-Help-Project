/* 
 femNaturalBC

 This class stores the natural boundary condition data.
*/

#ifndef femNaturalBC_h
#define femNaturalBC_h

#include "femDOF.h"
#include "femNode.h"

#include "utlVector.h"
#include "utlMatrixFull.h"
//#include <iostream.h>

using namespace std;

class femNaturalBC	//this is for natural (traction) boundary condition
{
  private:
	femNode* d_node1;	//for Q8 element, there are three nodes for each side. this is node 1
	femNode* d_node2;	//node2
	femNode* d_node3;	//node3
	double d_value;		//the constant traction value

	//never used constructors
	femNaturalBC();
	femNaturalBC (femNaturalBC &ebc);

  public:
	// Constructors
	femNaturalBC(femNode* node1, femNode* node2, femNode* node3, double value);
    //Destructor
    virtual ~femNaturalBC();
    // Functions
	void printData(ostream &out) const;		//print useful info
	virtual void getNaturalBCF(utlVector &f, femDof* dofs[],
		ostream &out);		//calculate the equivalent nodal forces from given traction. To be used in forming the right hand side vector
};

#endif
