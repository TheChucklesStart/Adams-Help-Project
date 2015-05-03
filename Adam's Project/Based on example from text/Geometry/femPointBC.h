/* 
 femPointBC

 This class stores the point load boundary conditions.
*/

#ifndef femPointBC_h
#define femPointBC_h

#include "femDOF.h"
#include "femNode.h"
//#include <iostream.h>

using namespace std;

enum PointBCType {FX=0, FY};

class femPointBC	//this is the point force B.C. class
{
  private:
	femNode* d_node;	//ptrs to node class whose node has point force b.c.
	PointBCType d_dof;	//type of point force, i.e. FX or FY
	double d_value;		//value of the point force

	//never used constructors
	femPointBC();
	femPointBC (femPointBC &ebc);

  public:
	// Constructors
	femPointBC(femNode* node, PointBCType dof, double value);
    //Destructor
    virtual ~femPointBC();
    // Functions
	femNode* getNode() const;	//	return d_node;
	PointBCType getDof() const;	//	return d_dof;
	double getValue() const;	//	return d_value;
	void printData(ostream &out) const;		//print useful data
};

#endif
