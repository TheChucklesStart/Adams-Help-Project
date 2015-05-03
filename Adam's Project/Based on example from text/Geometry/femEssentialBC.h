/* 
 femEssentialBC

 This class stores the essential boundary conditions.
*/

#ifndef femEssentialBC_h
#define femEssentialBC_h

#include "femDOF.h"
#include "femNode.h"
//#include <iostream.h>

using namespace std;

class femEssentialBC
{
  private:
	femNode* d_node;	//ptr to node (class femNode)
	DOFType d_dof;		//enum DOFType {UX=0, UY}; d_dof is either UX or UY
	double d_value;		//	d_value = prescribed displ. value

	//never used constructors
	femEssentialBC();
	femEssentialBC (femEssentialBC &ebc);

  public:
	// Constructors
	femEssentialBC(femNode* node, DOFType dof, double value);
    //Destructor
    virtual ~femEssentialBC();
    // Functions
	femNode* getNode() const;	//	return d_node;
	DOFType getDof() const;		//	return d_dof;
	double getValue() const;	//	return d_value;
	void printData(ostream &out) const;	//print useful info, e.g UY and UY
};

#endif
